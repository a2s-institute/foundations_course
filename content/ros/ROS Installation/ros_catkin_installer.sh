#!/bin/bash

#####################################################################################
##                                                                                 ##
##  ROS Installation script                                                        ##
##                                                                                 ##
##  This script acts as a little tool to install all necessary ROS packages        ##
##  needed for the Autonomous Mobile Robots course at HBRS.                        ##
##  It can also set up a catkin workspace and add ROS and catkin to your basrc.    ##
##                                                                                 ##
##  Note: This has been tested on a fresh Ubuntu 16.04 and with ROS Kinetic Kame   ##
##  Tim Metzler 09/2018                                                            ##
##                                                                                 ## 
#####################################################################################

# ROS packages
# This is the ROS version that is used (i.e. indigo, kinetic, etc)
ROS_DISTRO=kinetic

# These are the core ROS packages that are installed.
# Each package in the array will be converted to ros-$ROS_DISTRO-pkg_name (ros-kinetic-desktop)
ROS_PKGS=(desktop stage smach-viewer map-server)

# These are the python packages needed.
# Each package in the array will be converted to python-pkg_name (e.g. python-rosinstall)
PYTHON_PKGS=(catkin-tools rosinstall rosinstall-generator wstool pyside)

# Additional packages to be installed
OTHER_PKGS=(build-essential gnuplot)

# Directory in which the script is executed
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

function is_installed {
  # Check if the package given as the first argument $1 is installed
  # For this the dpkg-query output is searched for the keyphrase 'install ok installed'
  PKG_INSTALLED=$(dpkg-query -W --showformat='${Status}' $1 2>/dev/null|grep "install ok installed")
  if [ "$PKG_INSTALLED" == "install ok installed" ];
  then
    return 0
  else
    return 1
  fi
}

function install_pkg {
  # Install the package given as the first argument $1
  # Check if it is already present and check after installation for success
  # If the installation is unsuccessful exit this script
  echo ""
  echo "Installing $1..."
  # Check if package is already installed
  if is_installed $1;
  then
    echo ""
    echo "$1 is already installed"
    return 0
  else
    # Install the package
    sudo apt-get -y install $1
    # Check if package was successfully installed
    if is_installed $1;
    then
      echo ""
      echo "Successfully installed package $1"
      return 0
    else
      echo ""
      echo "ERROR: Package $1 could not be installed!"
      echo "Installation aborted!"
      exit 1
    fi
  fi
}

function update_keys {
  # Update keys and add ROS to the list of known packages
  echo
  echo "Updating keys and updating apt-get"
  sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
  sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
  sudo apt-get update
}

function ros_install {
  # Install ROS and additional packages needed for the AMR course

  # Install ROS core packages
  for pkg in ${ROS_PKGS[*]}; do
    install_pkg ros-$ROS_DISTRO-$pkg
  done

  # Initialize rosdep
  sudo rosdep init
  rosdep update

  # Install python packages
  for pkg in ${PYTHON_PKGS[*]}; do
    install_pkg python-$pkg
  done
  
  # Install additional packages
  for pkg in ${OTHER_PKGS[*]}; do
    install_pkg $pkg
  done

  environment_setup_bashrc
}

function ros_amr_bugfix {
  # Fixes errors in the stage.hh and joint.hpp files
  echo
  echo "Applying ROS bugfix"
  cd "$DIR"
  echo "Fixing stage.hh in opt/ros/$ROS_DISTRO/include/Stage-4.1/"
  # Check if stage.hh exists
  if [ ! -f /opt/ros/$ROS_DISTRO/include/Stage-4.1/stage.hh ]
  then
    echo "ERROR: Could not find the original stage.hh file!" 
    echo "Bugfix could not be applied!"
    return
  fi
  sudo cp bugfix/stage.hh /opt/ros/$ROS_DISTRO/include/Stage-4.1/stage.hh

  echo "Fixing joint.hpp in opt/ros/$ROS_DISTRO/include/kdl/"
  # Check if joint.hpp exists
  if [ ! -f /opt/ros/$ROS_DISTRO/include/kdl/joint.hpp ]
  then
    echo "ERROR: Could not find the original joint.hpp file!" 
    echo "Bugfix could not be applied!"
    return
  fi
  sudo cp bugfix/joint.hpp /opt/ros/$ROS_DISTRO/include/kdl/joint.hpp
  echo "Applied bugfix."
}

function create_catkin_workspace {
  source /opt/ros/$ROS_DISTRO/setup.bash
  echo ""
  echo "Initializing catkin workspace"
  echo "The workspace is created in your home folder."
  read -e -p "Enter a name for the workspace (default is catkin_ws): " -i "catkin_ws" WORKSPACE
  echo ""
  cd $HOME
  echo "Creating directories"
  if [ -d $WORKSPACE ]; then
    echo "A catkin workspace with the name $WORKSPACE already exists in $HOME"
    echo "Nothing to do here."
    return
  else
    mkdir $WORKSPACE
    cd $WORKSPACE
    mkdir src
    cd src
    cd ..
    catkin config --extend /opt/ros/$ROS_DISTRO
    catkin build
    echo "Sourcing the workspace"
    source devel/setup.bash
    catkin_bashrc $WORKSPACE
  fi
}

function catkin_bashrc {
  echo "Adding the workspace $1 to your bashrc"
  # Check if an entry for the workspace already exists
  if grep -q "$1/devel/setup.bash" ~/.bashrc; then
    echo "A catkin workspace with the name $1 is already present in your bashrc."
    echo "Nothing to do here."
    return
  fi
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
      echo "Adding catkin to .bashrc. A backup file is created as .bashrc_before_catkin"
      cp ~/.bashrc ~/.bashrc_before_catkin
      echo "Adding catkin workspace to bashrc"
      echo "source ~/$1/devel/setup.bash" >> ~/.bashrc
      echo "Sourcing .bashrc"
      source ~/.bashrc
      break
      ;;
    "No")
      break
      ;;
    esac
  done
}

function environment_setup_bashrc {
  echo
  echo "Adding environment setup bash file to your bashrc"
  # Check if setup.bash source command was already added to bashrc
  if grep -q "/opt/ros/kinetic/setup.bash" ~/.bashrc; then
    echo "Environment setup source command was already added to your bashrc."
    echo "Nothing to do here."
    return
  fi
  echo
  echo "Please choose if you want to add ROS environment setup bash file to your bashrc. Choosing Yes is recommended unless you have more than one ROS distribution installed."
  echo "If you choose No you have to run the following in every terminal you want to use catkin commands in."
  echo "source /opt/ros/kinetic/setup.bash"
  PS3='Would you like to add Catkin to your bashrc?: '
  options=("Yes" "No")
  select opt in "${options[@]}"
  do
  case $opt in
    "Yes")
      echo "Adding ROS environment setup bash file to your bashrc. A backup file is created as .bashrc_before_ros"
      cp ~/.bashrc ~/.bashrc_before_ros
      echo "Adding ROS environment setup bash file to your bashrc"
      echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
      echo "Sourcing .bashrc"
      source ~/.bashrc
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
  options=("Install everything" "Install ROS" "Apply ROS bugfix" "Create catkin workspace" "Quit")
  select opt in "${options[@]}"
  do
  case $opt in
    "Install everything")
      update_keys
      ros_install
      ros_amr_bugfix
      create_catkin_workspace
      echo
      echo "Installed everything"
      echo "Goodbye !"
      exit 0
      ;;
    "Install ROS")
      update_keys
      ros_install
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
      main_menu
      break
      ;;
    "Quit")
      echo "Goodbye !"
      exit 0
      ;;  
    esac
  done
}

main_menu
