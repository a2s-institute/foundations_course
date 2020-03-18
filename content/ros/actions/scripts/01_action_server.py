#!/usr/bin/env python

import rospy
from actionlib import SimpleActionServer
from my_third_package.msg import MoveTurtleAction
from my_third_package.msg import MoveTurtleFeedback
from my_third_package.msg import MoveTurtleResult


class FakeTurtle:

    def __init__(self):
        # define the server, aut-start is set to false so we control when to
        # start it
        self.server = SimpleActionServer('move_turtle_action',
                                         MoveTurtleAction,
                                         execute_cb=self.action_cb,
                                         auto_start=False)
        # deine feedback msg object to be used for publishing feedback
        self.feedback_msg = MoveTurtleFeedback()
        # deine result msg object to be used for publishing result
        self.result_msg = MoveTurtleResult()
        self.server.start()
        print("action server started ..")
        self.rate = rospy.Rate(2)

    def turtle_is_up_side_down(self):
        # this turtle never goes up side down
        # it can always move!
        # (this is a dummy function, in real application you might be checking
        # your robot status, for example the battery level,
        # or motor temperature, etc..)
        return False

    def action_cb(self, goal):
        print("moving turtle to pose: ", goal)
        # Write here the logic to control turtle

        # this "for" loop is just a demostration, in real application, you
        # would be controlling the robot, publish velocity commands, read
        #  current pose and do some computation..
        for _ in range(20):
            print('executing goal')
            # during execution of the goal, publish feedback msg to the client
            self.server.publish_feedback(self.feedback_msg)

            # always check if the client has sent a cancel msg. This way the
            # task becomes preemtable
            if self.server.is_preempt_requested():
                # update goal status accordingly
                self.server.set_preempted()
                print('goal preempted')
                # exit from the action_cb method
                return None

            # check if we need to abort for some reason. Here we abort if
            # the node has been killed (ctrl+C) or if the turtle is laying on
            #  it's back and cannot move anyomre ;)
            if rospy.is_shutdown() or self.turtle_is_up_side_down():
                # update goal status accordingly
                self.server.set_aborted()
                print('Turtle cannot move sir! goal aborted')
                return None

            self.rate.sleep()

        # if execution finished, set goal status to SUCCEED and publish the
        # result msg
        print('done')
        self.server.set_succeeded(result=self.result_msg,
                                  text="Mission completed")


if __name__ == '__main__':

    rospy.init_node('move_turtle')
    myturtle = FakeTurtle()
    node_rate = rospy.Rate(0.5)
    while not rospy.is_shutdown():
        print('node is running..')
        node_rate.sleep()
    print('node terminated')
