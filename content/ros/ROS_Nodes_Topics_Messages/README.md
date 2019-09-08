# Practical part

## Creating a ROS package

- Navigate to workspace. Example:

```
cd ~/catkin_ws/src/
``` 
- Create a package named ```my_first_package```, with ```std_msgs``` and ```rospy``` as dependencies:
```
catkin_create_pkg my_first_package std_msgs rospy 
```
- Complie:
```
catkin build
```

<details><summary>More details:</summary>

<br/>

In order to let ROS commands find your scripts, launch files, source files, etc.., you have to create a package and put it inside the ```src``` folder of your workspace (ex. ```catkin_ws/src```).

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

This command assumes the workspace is located in the home directory and named as ```catkin_ws```. The ROS installation script which you used for installing ROS, lets you choose a name for this workspace. If you don't have a workspace for some reason, see the [installation page](https://github.com/mas-group/foundations_course/tree/master/content/ros/ROS%20Installation).

- Use the ```catkin_create_pkg``` command to create the package for you. This 
command has the following syntax:

```
catkin_create_pkg <package_name> [depend1] [depend2] [depend3]
```
Where ```depend1, depend2, depend3```  are [dependencies](#dependencies) you might use in your package.  



Create a package named as ```my_first_package``` with ```rospy``` and ```std_msgs``` as dependencies:
```
catkin_create_pkg my_first_package std_msgs rospy 
```
- [Compile](#compilation) using ```catkin build``` command:
```
catkin build
```
You're done!  
In a new terminal (to source the workspace's setup.bash file after our changes), you can navigate now to this package direclty using ```roscd```:

- One more thing:

ROS uses the ```ROS_PACKAGE_PATH``` environment variable when it looks up for packages and nodes. Try to see where it points at:

```
echo $ROS_PACKAGE_PATH
```

</details>




## Using ```rosrun``` to run a node
:warning: Don't forget to run ROS master before doing any of the instructions that follows. To run the master, use the following command:

```
roscore
```

```rosrun``` can be used to run a node directly without the need to navigate to it's directory. 

```
rosrun <package> <executable> 
```
- create a ```scripts``` folder inside ```my_first_package``` and place our scripts there.
- In a terminal (<kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>t</kbd>), navigate to the ```scripts``` folder.
```
roscd my_first_package/scripts/
```

- Make the script executable. Example:
```
sudo chmod +x 01_simple_node.py
```
:bulb: you can do that for all the files ending with ```.py``` in one command:
```
sudo chmod +x *.py
```
- use ```rosrun``` (did you run the master first!):
```
rosrun my_first_package 01_simple_node.py
```


<details><summary>More details:</summary>

<br/>

- ```rosrun``` searches withing the directory tree of the given package. The scripts doesn't even have to be located in the ```scripts``` folder. It's only common between ROS users to place Python scripts inside the ```scripts``` folder.
  
- :warning:  ```rosrun``` will not find your Python scripts if you don't change their access permession to executable.

- ```rosrun``` takes options and more arguments that will be covered later.

### How does ```rosrun``` find my files?
It searches the directories listed in the ```ROS_PACKAGE_PATH``` environment variable. Try to see to where it points at:

```
echo $ROS_PACKAGE_PATH
```

### ```rosnode``` command:
- List all the running nodes:
```
rosnode list
```
- Get more info about a certain node:
```
rosnode info <node name>
```
- Others:
```
rosnode kill <node name>
rosnode ping <node name>
```
...etc
</details>


## Some of ROS commands:
- put the script (```02_simple_publisher.py```) inside our package (```my_first_package/scripts```). Give it execution permission.

- Run the script using ```rosrun```.
```
rosrun my_first_package 02_simple_publisher.py
```

- Let's see the current list of topics.  To do that we will use ```rostopic list``` command:
```
rostopic list
```
- Let's see the messages we are publishing. To do that we will use ```rostopic echo``` command:

```
rostopic echo /myFirstTopic
```

<details><summary>More details:</summary>

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
<br/>
</details>


## Simple subscriber

- Run our subscriber ```04_simple_subscriber.py``` node (after doing necessary steps):
  
```
rosrun my_first_package 04_simple_subscriber.py
```
- The script is listening but there are no messages being published.
- Run our publisher node in a second terminal:
```
rosrun my_first_package 02_simple_publisher.py
```
- You can also publish from the terminal directly using ```rostopic pub``` command:
```
rostopic pub /myFirstTopic std_msgs/String "data: 'hey there'"
```



## Using launch files

- Create a ```launch``` folder in your package ```my_first_package```.
- Place our launch files in it.
- Use the ```roslaunch``` command to run ```01_simple.launch```:

```
roslaunch my_first_package 01_simple.launch
```

- Check the topic names, and notice how our node name was changed.
```
rosnode list
```
<details><summary>More details:</summary>

- Launch files don't necessarily have to be placed in a ```launch``` folder, they just have to be placed anywhere inside the package. The ```roslaunch``` command will find them.

- When you run a launch file, it also brings up the master, so you don't have to run ```roscore``` command. However, if the launcher is stopped, the ROS master will be dead as well. (So it's recommended to run the ```roscore``` in a seperate terminal).

<br/>
</details>



## Custom ROS messages

You will learn how to create a message, and how to edit ```CMakeLists.txt``` and ```package.xml``` files in order to build the package.

- Go to [this repository](https://github.com/mas-group/minimal_ros_packages) and clone it inside your workspace:
  
```
cd ~/catkin_ws/src
```
```
git clone https://github.com/mas-group/minimal_ros_packages.git
```
- Build the package:
```
catkin build
```

- This is a meta-package, it consists of several packages. We will work with ```msg_minimal```.
- Go to [msg_minimal](https://github.com/mas-group/minimal_ros_packages/tree/master/msg_minimal) And do the instructions there (in the README of that package).

<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>


## Extra stuff

### Dependencies?
When you write a code, you probablly include some libraries. Every library you use is a dependency your code needs in order for it to be compiled successfully. In ROS, this is needed particularly when you write C++ nodes. For example, if you write a C++ node that includes the following:
```cpp
#include "std_msgs/String.h"
```
It measns your package has a dependency on ```std_msgs```.
 


### Compilation?


## References:
 - http://wiki.ros.org/ROS/Tutorials/CreatingPackage
 - ros commands help option



