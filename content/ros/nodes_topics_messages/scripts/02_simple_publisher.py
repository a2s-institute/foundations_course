#!/usr/bin/env python

import rospy

# import ROS String message. String is a class and located inside std_msgs
# package, inside msg folder
from std_msgs.msg import String

rospy.init_node('talker')

# define a variable of type Publisher (class)
pub = rospy.Publisher('myFirstTopic', String, queue_size=10)

rate = rospy.Rate(1)

# define a variable of type String (class). So to fill it and then publish it
my_message = String()
my_message.data = "Hello there! How are you?"

while not rospy.is_shutdown():
    # using the publish function inside Publisher class to publish the data.
    pub.publish(my_message)
    rate.sleep()
