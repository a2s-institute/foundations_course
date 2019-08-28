# ROS Commands

## Creating a package

```
catkin_create_pkg <package_name> [depend1] [depend2] [depend3]
```
Example:
```
catkin_create_pkg myFirstPackage std_msgs rospy 
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




## References:
- ROS wiki.
- ros commands help option