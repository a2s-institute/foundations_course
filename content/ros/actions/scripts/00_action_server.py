#!/usr/bin/env python

import rospy
from actionlib import SimpleActionServer
from my_third_package.msg import MoveTurtleAction


def action_cb(goal):
    print("moving turtle to pose: ", goal)
    # Write here the logic to control turtle
    print('done')
    # Set the status of the active goal to succeeded
    server.set_succeeded()


if __name__ == '__main__':
    rospy.init_node('move_turtle')
    # define a MoveTurtleAction server, and assign a callback function to
    # execute action goals (runs in a seperate thread)
    server = SimpleActionServer('move_turtle_action',
                                MoveTurtleAction,
                                execute_cb=action_cb)
