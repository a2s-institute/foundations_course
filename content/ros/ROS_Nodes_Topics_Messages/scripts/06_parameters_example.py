#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist


if __name__ == '__main__':
    rospy.init_node('commander')

    # Fetch needed paramters, set defaults values in case a paramters is not set
    freq = rospy.get_param('rate',100)
    r = rospy.get_param('radius', 1)
    w = rospy.get_param('angular_speed', 1)

    pub = rospy.Publisher('turtle1/cmd_vel', Twist, queue_size=10)

    rate = rospy.Rate(freq)
    msg = Twist()
    v = r*w

    msg.linear.x = v
    msg.angular.z = w

    while not rospy.is_shutdown():
        pub.publish(msg)
        rate.sleep()
