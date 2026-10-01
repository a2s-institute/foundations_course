#!/usr/bin/env python

from services.srv import two_ints
import rospy

class server:
    def __init__(self):
        #initialize the server node
        rospy.init_node("server_demo")

        #Display in the console the message
        rospy.loginfo("Server initiated")

        """
        Create the server
        Structure for server ->
            name_of_server = rospy.Service("service_label", service_name, \
                                        service_function)

        Create the server function where the response is processed

        Structure ->
            def name_server_function(request)

        HINT:
            -To access one of the components of the request write request.a for
            the component a.
            -To return the operation result write return response
            -You could also return several operations. E.g. return a+b, c*d

        Tasks:
        1. Add the two numbers
        2. Multiply the two numbers
        3. Substract the two numbers
        4. Divide the two numbers (Make sure to calculate exact values)
        """



if __name__ == '__main__':
    n = server()

    rospy.spin()
