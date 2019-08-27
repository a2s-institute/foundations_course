#!/usr/bin/env python

import rospy


rospy.init_node('print_text')  
rate = rospy.Rate(1) # an isntance of Rate class with 1 Hz as argument

while not rospy.is_shutdown():  # checks when the node receives a shutdown request (ex. Ctrl+C)
    print "Hello world!"
    rate.sleep()  # makes sure the time between each call is at the specified rate