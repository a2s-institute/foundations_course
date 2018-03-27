# Encountered Problems
This sheet contains a list of problems, which have been encountered during the lecture. Additionally also solutions or suggestions are provided. The idea of this list is to provide a look up for future courses and to avoid time-consuming debugging.

The problems are organized in the sections of the lecture in which they occured.

## Setting up a new ROS Project

1. Problem
* Problem: *catkin_make* could not be found or executed. 
* Solution 1: *sudo apt-get install python-catkin-tools*
* Solution 2: *pip install catkin_pkg*

## Hello World

1. Problem
* Problem: *rosrun hello_world talker.py* was throwing the following error: *usr/bin/env: bad interpreter: No such file or directory*
* Solution: The reason for this error message was a typo in the *talker.py*file. Wrong: *#!usr/bin/env python2*; Correct: *#!/usr/bin/env python2*; Please notice that a slash in front of *usr* is missing.


