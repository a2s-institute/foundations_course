# Pracical part

<style>
   div
   {
     display: inline-block;
   }
   
/* Tooltip container */
.tooltip {
  position: relative;
  display: inline-block;
  border-bottom: 1px dotted black; /* If you want dots under the hoverable text */
}

/* Tooltip text */
.tooltip .tooltiptext {
  visibility: hidden;
  width: 120px;
  background-color: black;
  color: #fff;
  text-align: center;
  padding: 5px 0;
  border-radius: 6px;
 
  /* Position the tooltip text - see examples below! */
  position: absolute;
  z-index: 1;
}

/* Show the tooltip text when you mouse over the tooltip container */
.tooltip:hover .tooltiptext {
  visibility: visible;
    width: 120px;
  top: 100%;
  left: 50%; 
  margin-left: -60px; 
}

</style>

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

This command assumes the workspace is located in the home directory and named as ```catkin_ws```. The ROS installation script which you used for installing ROS, let's you choose a name for this workspace. If you don't have a workspace for some reason, see the [installation page](../ROS\ Installation/).

- Use the ```catkin_create_pkg``` command to create the package for you. This 
commad has the following syntax:

```
catkin_create_pkg <package_name> [depend1] [depend2] [depend3]
```
<div>Where <code>depend1, depend2, depend3 </code> are <div style="display: inline-block" class="tooltip">dependencies<span class="tooltiptext">dependencies are ..</span>
</div> </div> 
you might use in your package.  

### Why?


 ## References:
 - http://wiki.ros.org/ROS/Tutorials/CreatingPackage

