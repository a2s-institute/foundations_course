# ROS Commands

## Creating a package

```
catkin_create_pkg <package_name> [depend1] [depend2] [depend3]
```
Example:
```
catkin_create_pkg my_first_package std_msgs rospy 
```
## ```rosrun``` command
```
rosrun [--prefix cmd] [--debug] <package> <executable> [ARGS]
```

  rosrun will locate ```<package>``` and try to find an executable named ```<executable> ``` in the ```<package>``` tree.
  If it finds it, it will run it with ```ARGS```.

Example:
```
rosrun turtlesim turtlesim_node /turtle1/cmd_vel:=/vel
```

Runs ```turtlesim_node``` from ```turtlesim``` package. And apply a name remapping from
```/turtle1/cmd_vel``` to ```/vel```.

## ```rosnode``` command
- List all the running nodes:
```
rosnode list
```
- Get more info. about a certain node:
```
rosnode info <node name>
```
- Others:
```
rosnode kill <node name>
rosnode ping <node name>
```
...etc

## ```rostopic``` command

- Get the current list of topics.
```
rostopic list
```
- Print published messages.

```
rostopic echo <topic name>
```

- Get field type of a topic:
```
rostopic type <topic name>
```
- Get information about ROS a topic:
```
rostopic info <topic name>
```
- Display publishing rate of topic:
```
rostopic hz <topic name>
```

## References:
- ROS wiki.
- ros commands help option