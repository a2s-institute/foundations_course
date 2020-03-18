#!/usr/bin/env python

import rospy

# importing needed msg classes
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from turtlesim.msg import Color
from turtlesim.srv import SetPen
# importing numpy
import numpy as np


# define a class named turtle
class Turtle:
    # constructor
    def __init__(self, turtle_number=1):
        """Turtle class provides interface to control the turtle and get
           feedback

        Keyword Arguments:
            turtle_number {int} -- turtle's number (default: {1})
        """
        # define a private variable of type Publisher (an instance of
        # Publisher)
        self.__pub = rospy.Publisher('turtle'+str(turtle_number)+'/cmd_vel',
                                     Twist, queue_size=10)
        self.__vel_msg = Twist()
        # define subscribers for pose and color topics, and assign callbacks
        rospy.Subscriber('turtle'+str(turtle_number)+'/pose', Pose,
                         callback=self.__pose_cb)

        rospy.Subscriber('turtle'+str(turtle_number)+'/color_sensor', Color,
                         callback=self.__color_cb)

        rospy.wait_for_service('turtle'+str(turtle_number) + '/set_pen')
        try:
            self.__set_pen = rospy.ServiceProxy('turtle'+str(turtle_number)+'/set_pen', SetPen)
        except rospy.ServiceException, e:
            rospy.logwarn("Service call failed, setpen") 

        # private attribute to hold the turtle pose
        self.__pose = np.array([[0.0],
                               [0.0],
                               [0.0]])
        # private attribute to hold the turtle velocity
        self.__velocity = np.array([[0.0],
                               [0.0],
                               [0.0]])
        # private attribute to hold the color sensor of the turtle
        self.__color = [0,0,0]

    # define a private method to be used as the callback function for the pose
    # msg
    def __pose_cb(self, msg):
        self.__pose = np.array([[msg.x],
                               [msg.y],
                               [msg.theta]])

        self.__velocity = np.array([[msg.linear_velocity],
                                   [0.0],
                                   [msg.angular_velocity]])

    # define a private method to be used as the callback function for the color
    # msg
    def __color_cb(self, msg):
        self.__color = [msg.r, msg.g, msg.b]

    # a public method to be used by the user to get pose
    def get_pose(self):
        """get the current pose (position and orientation) of the turtle

        Returns:
            numpy array -- 3x1 array: x (m),y (m),theta (rad)
        """
        return self.__pose

    # a public method to be used by the user to get velocity
    def get_velocity(self):
        """get the current velocity of the turtle

        Returns:
            numpy array -- 3x1 array: linear velocity in x (m/s), linear
                           velocity in y (always zero), angular velocity around
                           the z (rad/s)
        """
        return self.__velocity

    # a public method to be used by the user to get color reading
    def sense_color(self):
        """returns color reading of the turtle's color sensor

        Returns:
            list -- [r,g,b] representing RGB values
        """
        return self.__color

    # a public method to be used by the user to set the velocity
    def set_velocity(self, v, w):
        """sends a velocity command to the turtle

        Arguments:
            v {float} -- linear velocity (m/s)
            w {float} -- angular velocity (rad/s)
        """
        self.__vel_msg.linear.x = v
        self.__vel_msg.angular.z = w
        self.__pub.publish(self.__vel_msg)

    def set_pen(self, width, color="normal", state='off'):
        """Sets pen color of the turtle

        Arguments:
            width {int} -- line width of the pen

        Keyword Arguments:
            color {str} -- can have these values: "black",
                                                  "red",
                                                  "green",
                                                  "blue",
                                                  "yellow",
                                                  "erase",
                                                  or "normal".
                                                  (default: {"normal"})

            state {str} -- if set to "off" the pen will not write,
                           otherwise it will. (default: {'off'})
        """
        if color == "black":
            r = 0
            g = 0
            b = 0
        elif color == "red":
            r = 255
            g = 0
            b = 0
        elif color == "green":
            r = 0
            g = 255
            b = 0
        elif color == "blue":
            r = 0
            g = 0
            b = 255
        elif color == "yellow":
            r = 255
            g = 255
            b = 0
        elif color == "erase":
            r = 69
            g = 86
            b = 255
        else:
            r = 179
            g = 184
            b = 255

        if state == 'off':
            off = 1
        else:
            off = 0
        self.__set_pen(r, g, b, width, off)
