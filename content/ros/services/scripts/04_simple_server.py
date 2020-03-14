#!/usr/bin/env python

import rospy
from std_srvs.srv import SetBool, SetBoolResponse

# Service handler function
def destroy(req):
    print "received this request: ", req
    print "Roger that!.."
    # do your logic here and send a respinse after it
    response = SetBoolResponse()
    response.success = True
    if req.data:
        response.message = "You are victorious!"
    else:
        response.message = "enemy spared!"
    return response

if __name__ == '__main__':

    rospy.init_node('red_alert_server')
    print("Ready for melt-down!")
    
    # Declare a ROS service. Service requests are passed to the specified handler
    serv = rospy.Service('destroy_enemy', SetBool, destroy)
    
    # Let service run and take over thread until service or node shutdown
    serv.spin()