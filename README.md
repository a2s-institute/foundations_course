# Foundations Course

## Tentative Schedule
[FC Schedule](https://docs.google.com/spreadsheets/d/1LsfJWwRvhkPgQox0MIep3S6L5Wi7NF0fC4IZSB0zUDQ/edit?usp=sharing)

## Requirements
In case you need any help installing any of this, please ask your study buddy or come to one of the b-it-bots labs (C025 and C069).

### Software
*   [Ubuntu 16.04](https://www.ubuntu.com/download/desktop)
*   [ROS Kinetic](http://wiki.ros.org/kinetic/Installation/Ubuntu)
*   LaTeX

    ```
    sudo apt-get install texlive-full

    ```

*   [texMaker](http://www.xm1math.net/texmaker/index.html)

*   python 2.7

*   Jupyter notebooks

    ```
    sudo pip install jupyter
    ```

* git

    ```
    sudo apt-get install git-all
    ```

* Java 8

    Please visit the Oracle wesbite and download the latest stable Java JDK version available.

    1. Download Java SE Development Kit 8
        The following link leads you to the download website for the Java SE Development Kit 8. Make sure you download one of the two versions:
        - 32-bit: jdk-8u161-linux-i586.tar.gz
        - 64-bit: jdk-8u161-linux-x64.tar.gz

    2. Move the extracted JDK files to /opt/Oracle_Java/
        - Extract the JDK files from the downloaded *tar.gz*.
        - Create the folder *Oracle_Java* in the directory */opt/*:
        ```
        sudo mkdir /opt/Oracle_Java
        ```
        - Move the folder *jdk1.8.0_161* to */opt/Oracle_Java/*:
        ```
        sudo mv ~/Downloads/jdk1.8.0_161/ /opt/Oracle_Java/
        ```

    3. Set up and configure the evironment variables
        Set up the environment variables by executing the following commands one by one:
        ```
        sudo update-alternatives --install "/usr/bin/java" "java" "/opt/Oracle_Java/jdk1.8.0_161/bin/java" 1

        sudo update-alternatives --install "/usr/bin/javac" "javac" "/opt/Oracle_Java/jdk1.8.0_161/bin/javac" 1

        sudo update-alternatives --install "/usr/bin/javaws" "javaws" "/opt/Oracle_Java/jdk1.8.0_161/bin/javaws" 1

        sudo update-alternatives --install "/usr/bin/jar" "jar" "/opt/Oracle_Java/jdk1.8.0_161/bin/jar" 1
        ```

        Configure the environment variables by executing the following commands one by one:
        ```
        sudo update-alternatives --set "java" "/opt/Oracle_Java/jdk1.8.0_161/bin/java"

        sudo update-alternatives --set "javac" "/opt/Oracle_Java/jdk1.8.0_161/bin/javac"

        sudo update-alternatives --set "javaws" "/opt/Oracle_Java/jdk1.8.0_161/bin/javaws"

        sudo update-alternatives --set "jar" "/opt/Oracle_Java/jdk1.8.0_161/bin/jar" 
        ```

    After finishing the aforementioned steps the Java JDK installation is complete and the development with Java can begin.

* Eclipse

    Eclipse is an Integrated Development Environment (IDE) that is  well suited for Java development. The following steps describe how to set it up.

    1. Download the latest Eclipse version
        - Visit https://www.eclipse.org/ and download Eclipse OXYGEN

    2. Set up Eclipse
        - Extract the content of the tar.gz folder and rund _eclipse-inst_.
        - Choose _Eclipse IDE for Java Developers_ and foolow the instructions.

    3. Lock Eclipse to your launcher (Optional)
        - Go to the folder in which you have installed Eclipse.
        - Run Eclipse and right click its icon in the launcher. Then choose the option _Lock to Launcher_.

## References
The sources of the files used in this repository can be found [here](https://github.com/mas-group/foundations_course/wiki/References)
