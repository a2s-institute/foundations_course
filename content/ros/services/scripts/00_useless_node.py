#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def myfunction(received_msg):
    msg.data = "Hey, I think heard: " + received_msg.data
    pub.publish(msg)

if __name__ == '__main__':

    rospy.init_node('useless_node')

    pub = rospy.Publisher('mouth', String, queue_size=1)
    sub = rospy.Subscriber('ears', String, callback=myfunction)

    msg = String()
    rospy.spin()
