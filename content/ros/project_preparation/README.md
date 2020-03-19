## Your ROS Arsenal :muscle:

**Concepts**:

- [x] Nodes
- [x] Topics and messages
- [x] Parameter Server
- [x] Launch files
- [x] Names in ROS (remapping and name resolution).
- [x] Services
- [x] Actions
- [ ] Bags

**Tools**

- [ ] Logging (today)
- [ ] Visualization (today)
- [ ] Simulation using Gazebo (today)

- [ ] ...

## Logging

#### In your scripts

We have been using Python `print` function in all our scripts. But there is actually a better way to provide the status of your node, using `rospy` logging built-in functions:

*(source: `rospy` API documentation)*

- `rospy.loginfo("info msg")`
- `rospy.logwarn("warning msg")`
- `rospy.logerr("error msg")`
- `rospy.logdebug("debug msgs")`. :bulb: in launch files, you can choose to hide debug messages.
- `rospy.logfatal("critical msgs")`.

#### Where to find log messages 

*(source: ROS wiki/logging)*

|                     | **Debug** | **Info** | **Warn** | **Error** | **Fatal** |
| :------------------ | --------- | -------- | -------- | --------- | --------- |
| **stdout**          |           | X        |          |           |           |
| **stderr**          |           |          | X        | X         | X         |
| **Node log file**   | X         | X        | X        | X         | X         |
| **`/rosout`** topic | o         | X        | X        | X         | X         |



## RViz

- **RViz** is a tool that comes with ROS which you can use to visualize popular ROS message types. Examples:
  - it can show you maps (occupancy grid maps, point clouds).
  - Laser scanner message.
  - Images
  - robot 3D model.
  - you can also use it to draw lines, and different shapes...
- How to run:

```bash
rosrun rviz rviz
```



## Installing Packages

You can install ROS packages that are developed by others using two ways:

#### 1- Install from source

- that's what we were doing for our own packages. Installing from source means garbing the actual package (the source files) and putting the package inside your workspace, and then building it using **Catkin**.

- Sometimes, installing from source requires more effort (especially with poorly maintained packages). This is because, to successfully build a package from source, your computer must have all the dependencies installed.

#### 2- Install binaries Using **APT** package manager

- This method is straight forward, let's say we want to install the [`gmapping`](http://wiki.ros.org/gmapping) package:

```bash
sudo apt-get install ros-kinetic-gmapping
```

- That's it! many ROS packages are available in APT. The format in general is as follows: 

```bash
sudo apt-get install ros-<distro>-<package name>
```

- With this method however, you don't install source files, and therefore cannot change the code in the package.

:bulb: Any user can publish a package on **APT**, there is a [process](http://wiki.ros.org/ROS/ReleasingAPackage) however you need to follow..

#### Let's install the [Navigation Stack](http://wiki.ros.org/navigation)!

```bash
sudo apt-get install ros-kinetic-navigation*
```



## YouBot Gazebo Simulation

### Installation

- **Install dependencies:**

  - Install `youbot-driver` package:

  ```bash
  sudo apt-get install ros-kinetic-youbot-driver
  ```
  - Clone `youbot_description` package into your workspace (inside `/src` !):

  ```bash
  git clone https://github.com/mas-group/youbot_description.git
  ```

- Install the actual simulation meta-package:
  - Clone `youbot_simulation` meta-package into your workspace:

  ```bash
  git clone https://github.com/mas-group/youbot_simulation.git
  ```

  
  - build you workspace.



### Usage

- Launch robot simulation (without the GUI client):

  ```bash
   roslaunch youbot_gazebo_robot youbot.launch
  ```

- Run Gazebo GUI client:

  ```bash
  rosrun gazebo_ros gazebo
  ```

- Play with the robot!