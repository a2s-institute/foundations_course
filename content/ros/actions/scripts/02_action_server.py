#!/usr/bin/env python

import rospy
from actionlib import SimpleActionClient
from my_third_package.msg import MoveTurtleAction, MoveTurtleGoal


def on_feedback(feedback_msg):
    print feedback_msg


def when_done(result_msg):
    print result_msg


if __name__ == '__main__':
    rospy.init_node('move_turtle')
    client = SimpleActionClient("move_turtle_action", MoveTurtleAction)
    client.wait_for_server()

    goal = MoveTurtleGoal()
    goal.target_pose.x = 2.0

    client.send_goal(goal, done_cb=when_done, feedback_cb=on_feedback)

    rospy.spin()
