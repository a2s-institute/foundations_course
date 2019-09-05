#!/usr/bin/env python

import rospy


from std_msgs.msg import String


def cb(msg):
    print type(msg.data)


rospy.init_node('talker')

rospy.Subscriber('topic', String, cb)


rospy.spin()