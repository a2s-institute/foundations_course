#!/usr/bin/env python

import rospy
from turtlesim.srv import SetPen

if __name__ == '__main__':

    rospy.init_node('I_am_client') 
    pen = rospy.ServiceProxy('/turtle1/set_pen', SetPen)
    
    # use the wait method inside the ServiceProxy class
    pen.wait_for_service()
    
    try:
        pen(255,0,0,10,0)      
    except rospy.ServiceException, error:
        print "ops! call has failed with this error: ", error 
