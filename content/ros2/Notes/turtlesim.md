## Turtlesim

<!-- install turtlesim -->
### Install turtlesim
`sudo apt install ros-rolling-turtlesim`

<!-- start turtlesim -->
### Start turtlesim
`ros2 run turtlesim turtlesim_node`

<!-- use turtlesim -->
### Use turtlesim
`ros2 run turtlesim turtle_teleop_key`

<!-- check concepts -->
### Check concepts
```
ros2 node list
ros2 topic list
ros2 service list
ros2 action list
```

## rqt

<!-- Install rqt -->
### Install rqt
`sudo apt install ~nros-rolling-rqt*`

<!-- Start rqt -->
### Start rqt
`rqt`

> Plugins > Services > Service Caller

<!-- Note -->
#### Note - to locate the plugins
`rqt --force-discover`

## Nodes
<!-- list nodes -->
### List nodes
`ros2 node list`

<!-- check node info -->
### Check node info
`ros2 node info /turtlesim`

<!-- rqt_graph -->
### rqt_graph
`rqt_graph`

> You can also open rqt_graph by opening rqt and selecting Plugins > Introspection > Node Graph.


