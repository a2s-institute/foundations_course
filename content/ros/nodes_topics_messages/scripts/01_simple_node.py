#!/usr/bin/env python

import rospy


rospy.init_node('print_text')

# an isntance of Rate class with 1 Hz as argument
rate = rospy.Rate(1)

# checks when the node receives a shutdown request (ex. Ctrl+C)
while not rospy.is_shutdown():
    print "Hello world!"
    # make sure the time between each call is at the specified rate
    rate.sleep()
