#!/usr/bin/env python

import rospy
from turtlesim.srv import SetPen


if __name__ == '__main__':

    rospy.init_node('I_am_client') 

    # blocks execution until service is available
    # usually service waiting is used at the beginning of node, so
    # the nodes waits until all services you depend on are available
    rospy.wait_for_service('/turtle1/set_pen')

    # define an object of class ServiceProxy 
    # this object (class instance) will be used to make calls to
    # the service.
    pen = rospy.ServiceProxy('/turtle1/set_pen', SetPen)

    # make a call to the service, here we are 
    # calling the __call__ method defined in class ServiceProxy
    # check this https://stackoverflow.com/questions/9663562/what-is-the-difference-between-init-and-call
    response = pen(255,0,0,10,0)
    print response
