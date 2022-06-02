#include "ros/ros.h"
#include "Project_2/lidars.h"
#include <sensor_msgs/LaserScan.h>



class Lidars
{
public:
  	Lidars() {
	  sub_front = n.subscribe("/front/scan", 1000, &Lidars::frontCallback, this);
	  sub_rear = n.subscribe("/rear/scan", 1000, &Lidars::rearCallback, this);
	  pub = n.advertise<Project_2::lidars>("/lidars_merged", 1000);
  	}

  	void frontCallback(const sensor_msgs::LaserScanConstPtr& msg) {
		lidars_msg.header.seq = msg->header.seq;
		lidars_msg.header.stamp = msg->header.stamp;
		lidars_msg.angle_min_F = msg->angle_min;
		lidars_msg.angle_max_F = msg->angle_max;
		lidars_msg.angle_increment_F = msg->angle_increment;
		lidars_msg.time_increment_F = msg->time_increment;
		lidars_msg.scan_time_F = msg->scan_time;
		lidars_msg.range_min_F = msg->range_min;
		lidars_msg.range_max_F = msg->range_max;
		pub.publish(lidars_msg);
	}

	void rearCallback(const sensor_msgs::LaserScanConstPtr& msg) {
		lidars_msg.header.seq = msg->header.seq;
		lidars_msg.header.stamp = msg->header.stamp;
		lidars_msg.angle_min_R = msg->angle_min;
		lidars_msg.angle_max_R = msg->angle_max;
		lidars_msg.angle_increment_R = msg->angle_increment;
		lidars_msg.time_increment_R = msg->time_increment;
		lidars_msg.scan_time_R = msg->scan_time;
		lidars_msg.range_min_R = msg->range_min;
		lidars_msg.range_max_R = msg->range_max;
		pub.publish(lidars_msg);
	}

private:
  ros::NodeHandle n;
  ros::Subscriber sub_front;
  ros::Subscriber sub_rear;
  ros::Publisher pub;
  Project_2::lidars lidars_msg;
};


int main(int argc, char **argv) {
  ros::init(argc, argv, "lidars");
  Lidars my_lidars;
  ros::spin();
  return 0;
}



