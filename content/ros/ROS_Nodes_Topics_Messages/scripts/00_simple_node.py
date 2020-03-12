#!/usr/bin/env python


import rospy  # import ROS python library
from time import sleep  # for adding a delay

rospy.init_node('print_text')  # tell ROS master to register this node


while True:
    print "Hello world!"
    sleep(1)  # delay 1 second
