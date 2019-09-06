#!/usr/bin/env python

import rospy
from std_msgs.msg import String

# a callback function to be called by the Subscriber class
def my_callback_function(msg):
    print msg


rospy.init_node('listener')
rate = rospy.Rate(100)

# define a variable of type Subscriber
sub = rospy.Subscriber('myFirstTopic', String, callback=my_callback_function)


# holds the script from exiting to wait for any message
while not rospy.is_shutdown():
    pass  # do nothing
