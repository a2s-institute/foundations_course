<!-- actions -->
## Actions

<!-- check node info -->
### Check node info
`ros2 node info /turtlesim`
`ros2 node info /teleop_turtle`

<!-- get action list -->
### Get action list
`ros2 action list`

<!-- get action list with type -->
### Get action list with type
`ros2 action list -t`

<!-- get action info -->
### Get action info
`ros2 action info /turtle1/rotate_absolute`

<!-- get action interface -->
### Get action interface
`ros2 interface show turtlesim/action/RotateAbsolute`

<!-- send action goal -->
### Send action goal
`ros2 action send_goal /turtle1/rotate_absolute turtlesim/action/RotateAbsolute "{theta: 1.57}"`

<!-- send action goal with feedback -->
### Send action goal with feedback
`ros2 action send_goal /turtle1/rotate_absolute turtlesim/action/RotateAbsolute "{theta: 1.57}" --feedback`
