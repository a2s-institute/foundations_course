
<!-- Topics -->
## Topics

<!-- list topics -->
### List topics
`ros2 topic list`

```
/parameter_events - changes in parameters are published to this
/rosout - when used in ros2 logging
```

<!-- list topics with their type -->
### List topics with their type
`ros2 topic list -t`

<!-- echo topic -->
### Echo topic
`ros2 topic echo /turtle1/cmd_vel`

<!-- check topic info -->
### Check topic info
`ros2 topic info /turtle1/cmd_vel`

<!-- check topic info with verbose -->
### Check topic info with verbose
`ros2 topic info /turtle1/cmd_vel --verbose`

<!-- interface show -->
### Interface show
`ros2 interface show geometry_msgs/msg/Twist`

<!-- publish to a topic -->
### Publish to a topic
`ros2 topic pub  --once /turtle1/cmd_vel geometry_msgs/msg/Twist '{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0,y: 0.0,z: 1.8}}'`

Loop continuously

`ros2 topic pub --rate 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"`
