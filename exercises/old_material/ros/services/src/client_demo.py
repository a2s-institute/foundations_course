#!/usr/bin/env python

from services.srv import two_ints
import rospy

class client:
    def __init__(self):
        #Initialize the client node
        rospy.init_node("client_demo")

        #Show in the console the message
        rospy.loginfo("Client initiated")

        #Pause the node untill the service specified(service_label) is active
        rospy.wait_for_service("add_two_ints")

        """
        Create client

        structure of the client ->
            name_of_client = rospy.ServiceProxy("service_label", service_name)
        """

if __name__=='__main__':
    n = client()

    while not rospy.is_shutdown():
        """
            Request two number from the terminal
            To assure that you get only numbers, use the try except structure
            try:
                a =
            except ValueError:
                rospy.logerr("Invalid input")
                a =

            try:
                b =
            except ValueError:
                rospy.logerr("Invalid input")
                b =

            Collect the value from the client service

            result = n.name_of_client(parameter_1, parameter_2)

            HINT: To collect specifically the value write:
                result.sum
            Tasks:
            1. Display the result of the sum, the multiplication, the substraction,
            and division

        """
        rospy.spin()
