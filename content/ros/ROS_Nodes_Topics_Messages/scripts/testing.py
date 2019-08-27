#!/usr/bin/env python


import rospy
from time import sleep
from std_msgs.msg import String

rospy.init_node('print_text')
pub = rospy.Publisher('myTopic', String, queue_size=10)

msg = String()
msg.data = "Hello world!"
while True:
    pub.publish("Hello world!")
    sleep(1)
