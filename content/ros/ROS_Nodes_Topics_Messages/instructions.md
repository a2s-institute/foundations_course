# Pracical part


## Creating a ROS package

In order to let ROS commands find your scripts, launch files, source files, binaries,
 etc.., you have to create a package and put it inside the ```src``` folder of your workspace (ex. ```catkin_ws/src```).

A package is nothing more than a folder with at least these two files:
    
    - package.xml
    - CMakeLists.txt

Normally, a package also includes Python scripts, C++ source files, launch files (we will see later), message definition files, service definition files, ...etc. It 
is common for a ROS package to have the structure shown below:

```
package/
├── CMakeLists.txt
├── include/
├── msg/
├── package.xml
├── scripts/
├── src/
└── srv/
```

 ### How?

- Navigate to the ```src``` folder of your ROS workspace.
```
cd ~/catkin_ws/src/
```

This command assumes the workspace is located in the home directory and named as ```catkin_ws```. The ROS installation script which you used for installing ROS, let's you choose a name for this workspace. If you don't have a workspace for some reason, see the [installation page](https://github.com/mas-group/foundations_course/tree/master/content/ros/ROS%20Installation).

- Use the ```catkin_create_pkg``` command to create the package for you. This 
commad has the following syntax:

```
catkin_create_pkg <package_name> [depend1] [depend2] [depend3]
```
Where ```depend1, depend2, depend3```  are [dependencies](#what-is-a-dependency) you might use in your package.  



Creat a package named as ```myFirstPackage``` with ```rospy``` and ```std_msgs``` as dependencies:
```
catkin_create_pkg myFirstPackage std_msgs rospy 
```
- [Compile](#compilation) using ```catkin build``` command:
```
catkin build
```





## Extra stuff

### Dependencies?
When you write a code, you probablly include some libraries. Every library you use is a dependency your code needs inorder for it to be compiled successfully. In ROS, this is needed particularly when you write C++ nodes. For example, if you write a C++ node that includes the following:
```cpp
#include "std_msgs/String.h"
```
It measns your package has a dependency on ```std_msgs```.
 


### Compilation?

## References:
 - http://wiki.ros.org/ROS/Tutorials/CreatingPackage

