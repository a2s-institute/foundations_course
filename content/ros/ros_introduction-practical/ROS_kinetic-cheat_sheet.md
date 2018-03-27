# ROS Kinetic - Cheat Sheet

## ROS Dictionary
* **roscore**: The roscore is a collection of nodes and programs that are pre-requisites of a ROS-based system. A roscore needs to run in order to enable the communication between ROS nodes.
* **roslaunch**: Tool to launch multiple ROS nodes. Roslaunch starts the roscore automatically, too.
* **rosnode**: Command-line tool for displaying debug information about ROS nodes.
* **rosrun**: Command to start an executable in an arbitrary package. 
* **rostopic**: Command-line tool for displaying debug information about ROS topics.


## Create a ROS Workspace
The following steps will remind you how to create a ROS workspace from scratch.

1. Prepare the directory in which you would like to create your workspace. In this example the workspace will be created in the user's home directory.
```
mkdir -p ~/catkin_ws/src
```
Please note, that this command creates a folder and a subfolder simultaneously. The folder catkin_ws sets the name of the workspace. It can be chosen freely. However is the src folder necessary for the process of creating a ROS workspace and the name of the folder must be kept the same.

2. Switch to the newly created folder.
```
cd ~/catkin_ws
```

3. Set up and initialize your ROS workspace.
    1. ```catkin_make```
    2. ```catkin init```
By running this commands, additional folders and files are added to the workspace. Once the environment is configured, the workspace is ready to go.

Please note, that other ways of initializing a ROS workspace exist. However the tools can not be used at the same time. Their build artifacts are incompatible. 

If you are unsure which tool you used to set up your workspace you can run ```catkin config``` to receive further information. In case you want to switch the toolset run ```catkin clean``` first and then rebuild your workspace with the toolset of your choice.

## Configure Your Environment
Once you have set up your workspace, it is necessary to overlay it on top of your default environment and make it your active working environment. Only if this step is done ROS can find and execute the packages of this workspace.

Two possibilities exist for sourcing your workspace: You can either source your environment temporarily (valid until your next log out/ reboot) or you set it up as new default environment by editing your .bashrc.

* Temporal configuration:
```
source ~/catkin_ws/devel/setup.bash
```
* Permanent configuration:
```
echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
```

Once you have sourced the setup.bash file, please check if the environment overlayed the default environment correctly:
```
echo $ROS_PACKAGE_PATH
```

Expected: ```/home/<YOUR_NAME>/catkin_ws/src:/opt/ros/kinect/share```

## Create a catkin Package
ROS is organized in packages. They represent the software organization units and can contain libraries, executables, scripts, or other artifacts.

A package can be created manually by creating a folder in the src directory including the following files:
* package.xml - Provides meta information about the package.
* CMakeLists.txt - Input to the CMake build system for building software packages.

However a more convenient way for creating a package (called hello_world here)is to run
```
catkin_create_pkg hello_world
```
This command takes care of the beforementioned, necessary files and their content. In a more ambitious project it is also possible to define the dependencies of the package at the time of creation:
```
catkin_create_pkg <package_name> <dependency1> <dependency2> <dependency3>
```

## Run the Code inside Your Package
For running the code in your package a few prerequists need to be satisfied: 

1. Make sure that $ROS_PACKAGE_PATH lists the workspace that contains the package of your interest. Otherwise check section 'Configure Your Environment'.

2. Run **roscore** in a second terminal.

Once you are sure that both points are set up correctly. Run the following command to exectute your code (here we are talking about package hello_world and script talker.py):
```
rosrun hello_world talker.py
```

## Debug Running Processes
Once you booted the robot or you executed your code, you would like to check whether everything is communicating the right way. ROS provides several tools to display, analyse and monitor the communication.

To display information about currently running ROS topics the tool **rostopic** provides useful options:
* **rostopic list**: Displays a list of current topics.
* **rostopíc info <topic_name>**: Prints information about a topic.
* **rostopic echo <topic_name>**: Displays messages published by the topic.
* **rostopic pub <topic_name> <message_type> <data>**: Publishes data to the a topic.

To display information about currently running ROS nodes the tool **rosnode** provides useful options:
* **rosnode list**: Displays a list of current nodes.
* **rosnode info <node_name>**: Prints information about a node.

Please note that for both tools further options exist. They can either be looked up on http://wiki.ros.org/ or by typing rostopic or rosnode into the console and using the TAB key to receive the a list of options for autocompletion.

 
