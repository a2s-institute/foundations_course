#!/usr/bin/env python

import rospy
from turtlesim.srv import SetPen

if __name__ == '__main__':

    rospy.init_node('I_am_client')
    rospy.wait_for_service('/turtle1/set_pen')
    pen = rospy.ServiceProxy('/turtle1/set_pen', SetPen)
    
    # put service call inside a try block to catch exceptions
    # in case call fails
    try:
        pen(255,0,0,10,0)
    # catch service exception        
    except rospy.ServiceException, error:
        print "ops! call has failed with this error: ", error 
