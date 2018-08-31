#!/bin/bash

# ROS installation and catkin initialization script

function update_keys {
	echo
	echo "Updating keys and updating apt-get"
	sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
	sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
	sudo apt-get update
}

function ros_install {
	echo
	echo "Installing ROS Kinetic Kame"
	sudo apt-get -y install ros-kinetic-desktop-full
	sudo rosdep init
	rosdep update
	echo "Installing Smach Viewer"
	sudo apt-get -y install ros-kinetic-smach-viewer
	echo "Installing Map Server"
	sudo apt-get -y install ros-kinetic-map-server
	sudo apt-get -y install python-rosinstall python-rosinstall-generator python-wstool build-essential
	sudo apt-get -y install python-pyside
	sudo apt-get -y install gnuplot
	source /opt/ros/kinetic/setup.bash
	sudo chown -R $SUDO_USER:$SUDO_USER ~/.ros/
	
}

function ros_bashrc {
	echo
	echo "Please choose if you want to add ROS to your bashrc."
	echo "If you choose No you have to run the following in every terminal you want to use ROS in."
	echo "source /opt/ros/kinetic/setup.bash"
	PS3='Would you like to add ROS to your bashrc?: '
	options=("Yes" "No")
	select opt in "${options[@]}"
	do
	case $opt in
		"Yes")
			if grep -q 'source /opt/ros/kinetic/setup.bash' ~/.bashrc; then
				echo "ROS Kinetic is already present in your bashrc."
			else	
				echo "Adding ROS to .bashrc. A backup file is created as .bashrc_before_ros"
				cp ~/.bashrc ~/.bashrc_before_ros
				echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
				echo "Sourcing .bashrc"
				source ~/.bashrc
			fi
			break
			;;
		"No")
			break
			;;
		esac
	done
}

function ros_amr_bugfix {
	echo
	echo "Applying ROS bugfix"
	cd $DIR
	echo "Fixing stage.hh in opt/ros/kinetic/include/Stage-4.1/"
	sudo cp bugfix/stage.hh /opt/ros/kinetic/include/Stage-4.1/stage.hh
	echo "Fixing joint.hpp in opt/ros/kinetic/include/kdl/"
	sudo cp bugfix/joint.hpp /opt/ros/kinetic/include/kdl/joint.hpp
	echo "Applied bugfix."
}

function create_catkin_workspace {
	source /opt/ros/kinetic/setup.bash
	echo
	echo "Initializing catkin workspace"
	cd $HOME
	echo "Creating directories"
	mkdir catkin_ws
	cd catkin_ws
	mkdir src
	cd src
	catkin_init_workspace
	cd ..
	catkin_make
	echo "Sourcing the workspace"
	source devel/setup.bash
	sudo chown -R $SUDO_USER:$SUDO_USER ~/catkin_ws/
}

function catkin_bashrc {
	echo
	echo "Please choose if you want to add Catkin to your bashrc."
	echo "If you choose No you have to run the following in every terminal you want to use catkin commands in."
	echo "source ~/catkin_ws/devel/setup.bash"
	PS3='Would you like to add Catkin to your bashrc?: '
	options=("Yes" "No")
	select opt in "${options[@]}"
	do
	case $opt in
		"Yes")
			if grep -q 'catkin_ws/devel/setup.bash' ~/.bashrc; then
				echo "A catkin workspace is already present in your bashrc."
			else
				echo "Adding catkin to .bashrc. A backup file is created as .bashrc_before_catkin"
				cp ~/.bashrc ~/.bashrc_before_catkin
				echo "Adding catkin workspace to bashrc"
				echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
				echo "Sourcing .bashrc"
				source ~/.bashrc
			fi
			break
			;;
		"No")
			break
			;;
		esac
	done
}

function main_menu {
	echo 
	echo "Please select an option:"
	echo
	PS3='What would you like to do?: '
	options=("Install ROS" "Apply ROS bugfix" "Create catkin workspace" "Install everything" "Quit")
	select opt in "${options[@]}"
	do
	case $opt in
		"Install ROS")
			update_keys
			ros_install
			ros_bashrc
			main_menu
			break
			;;
		"Apply ROS bugfix")
			ros_amr_bugfix
			main_menu
			break
			;;
		"Create catkin workspace")
			create_catkin_workspace
			catkin_bashrc
			main_menu
			break
			;;
		"Install everything")
			update_keys
			ros_install
			ros_bashrc
			ros_amr_bugfix
			create_catkin_workspace
			catkin_bashrc
			echo
			echo "Installed everything"
			echo "Goodbye !"
			exit 0
			;;
		"Quit")
			echo "Goodbye !"
			exit 0
			;;	
		esac
	done
}

if [[ $(/usr/bin/id -u) -ne 0 ]]; then
    echo "Please execute this script as sudo!"
    exit
fi
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
main_menu
