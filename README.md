# Robotics-Project-2

##### GROUP MEMBERS #####





Gabriele Pagano (10578117)
Jody Roberto Battistini (10691667)





##### DESCRIPTION OF FILES #####





### 'launch' FOLDER ###




We put inside this folder the launch file and XML files used to run our nodes.

# 'amcl.launch.xml' #

It is a file containing some basic settings and some parameters useful to perform AMCL-based localization.

# 'locLaunch.launch' #

In this file we start some files used during the localization phase. First of all we set the synchronization parameter (useful to synchronize with bags time) and the meta data of the image created after the mapping phase. Then we start the AMCL settings file, the file containing the RVIZ settings (to let the user visualize the correct topics), a Python script that draws the path of the robot, the node to publish the TF tree, a Python file that draws a smoother version of the map, a Python file that let a user save the map and the path followed by the robot during its navigation and the node for the map_sserver command.

# 'map.launch.xml' #

In this file we have some settings for laser merging some static transformations made taking into account the robot features.

# 'mappingLaunch.launch' 

As the localization launch file, first of all we set the synchronization parameter. Then we start some files used during the mapping phase: the 'map.launch.xml' file, the file containing RVIZ settings, the TF tree node and the Python file used to draw a smoother map.



### 'maps' FOLDER ###



Here will be saved the images of the maps. Moreover, in this folder is also present the file that contains the meta-data of the image saved after the mapping phase.



### 'rviz' FOLDER ###



Here there is just one file, Project2.rviz, in which there are some settings useful for a correct visualization of the topics in RVIZ.



### 'scripts' FOLDER ### 



Here there are the source codes of some Python scripts.

# 'draw.py' #

A Python script that, given the robot odometry, publishes the path followed by the robot during its navigation.

# 'occupancy_grid_processing.py' #

A file used for draw a smoother and more highlighted map given the original one.

# 'save_map.py' #

A file that handles the case in which the user calls the service to save the current map and the path followed by the robot.



### 'src' FOLDER ###



# 'Odometry_TF.cpp' #

The file that given the odometry constructs the TF tree.



### 'srv' FOLDER ###



# 'Trajectory.srv' #

The service file that let a user call a ROS service to save the map and the path followed by the robot.





##### TF TREE #####

- Our TF tree has the following structure (there are two different branches):

map -> odom -> base_footprint -> base_link -> laser_front

map -> odom -> base_footprint -> base_link -> laser_rear





##### BAGS FOR MAPPING AND LOCALIZATION #####

- After have performed some tests with all of the three provided bags, we decided to use bag1 for mapping because after have run occupancy_grid_processing.py it gave an even smoother map with respect to other two. Thus, we used bags 2 and 3 for localization.





##### DESCRIPTION ON HOW TO START AND USE THE NODES #####



### MAPPING ###

The mapping process is performed using gmapping for mapping computation and ira_laser_tools for laser merging. In particular, the parameters to merge the two lasers have been computed taking into account the values of the parameters of /front/scan and /rear/scan topics.
Here we have the steps for perform mapping in our project:

- First of all, open the terminal and type 'roslaunch Project_2 mappingLaunch.launch'. After this, the files will be launched and the RVIZ window with an empty grid will be open.
- Launch the bag1 file by the command 'rosbag play --clock <bag_name>.bag' (The --clock, paired with the synchronization parameter set to true, allows to perform time sychronization).
- At this point the TF tree will appear on RVIZ. From now, wait some seconds to see the first draft of the map (The occupancy_grid_processing.py file has to finish its computations).
- When the bag will be finished, you will see a file named 'grid_mapping.png' saved inside the 'maps' folder. This will be the final map computed by gmapping.



### LOCALIZATION ###

The localization procedure starts taking into account the map generated at the previous point (grid_mapping) by giving, thanks to the map_server service, its YAML meta-data as input of the localization node.
Here we have the steps to perform localization:


- Open the terminal and type 'roslaunch Project_2 locLaunch.launch'. After this, like for the mapping, the files will be launched and the RVIZ window with an empty grid will be open.
- Launch the bag2 file by the command 'rosbag play --clock <bag_name>.bag' and see in real time the path followed by the robot.
- To call the service for the map+path saving, open a new terminal and type 'rosservice call /save_map <name_you_chose_for_the_map>' 
- The map will be saved in the 'maps' folder.


