# Homework assignment

In this assignment, you are asked to create a node, which for a given 
coordinates and a given map, it tells whether the given location is occupied (there is an obstacle), free, or unknown. This is needed when a robot wants to avoid obstacles or plan a safe path to a target location.

## Map file
The map you will use for testing is shon below.

![example](figures/map.png)

This is a 2D occupancy grid map. It represents the environmet as a grid that consists of cells, each cell corresponds to a location in the physical space. Each cell can have a value of **100** representing occupied space, **0** representing free space, or **-1** representing unknown space. It looks like a floor plan. Before going any further, read [here](occupancy_grid_maps.md) about occupancy grid map.

First, place the ```home_work``` folder in your workspce (inside ```catkin_ws/src```), and build it using ```catkin build``` command.


- The map is saved in the ```map``` folder (```../home_work/map```). ROS comes with a package (```map_server``` package) which can be used to read map files, and publish the map as a ROS message. There is launch file which runs ```map_server``` node with the given map file.

```
roslaunch home_work map.launch
```

- If you list the topics, you can find ```/map``` topic.
- Check the message type of this topic. 
- You'll find that it's type is: [OccupancyGrid](http://docs.ros.org/kinetic/api/nav_msgs/html/msg/OccupancyGrid.html). Read more about it and what fields it has.
- Note that, it has a field named ```data```, which is an array of integers (in python it is a list of integers). 
  
## Rviz
