#include "ros/ros.h"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <nav_msgs/Odometry.h>




class TfOdom
{
public:
  TfOdom() {
    sub = n.subscribe("/odom", 1000, &TfOdom::callback_tf, this);

  }

  void callback_tf(const nav_msgs::Odometry::ConstPtr& msg){ //to change
    // set header
    transformStamped.header.stamp = ros::Time::now();
    transformStamped.header.frame_id = "map";
    transformStamped.child_frame_id = "odom";
    // set x,y
    transformStamped.transform.translation.x = msg->pose.pose.position.x;
    transformStamped.transform.translation.y = msg->pose.pose.position.y;
    transformStamped.transform.translation.z = 0.0;
    transformStamped.transform.rotation.x = msg->pose.pose.orientation.x;
    transformStamped.transform.rotation.y = msg->pose.pose.orientation.y;
    transformStamped.transform.rotation.z = msg->pose.pose.orientation.z;
    transformStamped.transform.rotation.w = msg->pose.pose.orientation.w;
    // send transform
    br.sendTransform(transformStamped);

    // set header
    transformStamped2.header.stamp = ros::Time::now();
    transformStamped2.header.frame_id = "odom";
    transformStamped2.child_frame_id = "base_footprint";
    // set x,y
    transformStamped2.transform.translation.x = msg->pose.pose.position.x;
    transformStamped2.transform.translation.y = msg->pose.pose.position.y;
    transformStamped2.transform.translation.z = 0.0;
    transformStamped2.transform.rotation.x = msg->pose.pose.orientation.x;
    transformStamped2.transform.rotation.y = msg->pose.pose.orientation.y;
    transformStamped2.transform.rotation.z = msg->pose.pose.orientation.z;
    transformStamped2.transform.rotation.w = msg->pose.pose.orientation.w;
    // send transform
    br.sendTransform(transformStamped2);

    // set header
    transformStamped3.header.stamp = ros::Time::now();
    transformStamped3.header.frame_id = "base_link";
    transformStamped3.child_frame_id = "laser_front";
    // set x,y
    transformStamped3.transform.translation.x = msg->pose.pose.position.x;
    transformStamped3.transform.translation.y = msg->pose.pose.position.y;
    transformStamped3.transform.translation.z = 0.0;
    transformStamped3.transform.rotation.x = msg->pose.pose.orientation.x;
    transformStamped3.transform.rotation.y = msg->pose.pose.orientation.y;
    transformStamped3.transform.rotation.z = msg->pose.pose.orientation.z;
    transformStamped3.transform.rotation.w = msg->pose.pose.orientation.w;
    // send transform
    br.sendTransform(transformStamped3);

    // set header
    transformStamped4.header.stamp = ros::Time::now();
    transformStamped4.header.frame_id = "base_link";
    transformStamped4.child_frame_id = "laser_rear";
    // set x,y
    transformStamped4.transform.translation.x = msg->pose.pose.position.x;
    transformStamped4.transform.translation.y = msg->pose.pose.position.y;
    transformStamped4.transform.translation.z = 0.0;
    transformStamped4.transform.rotation.x = msg->pose.pose.orientation.x;
    transformStamped4.transform.rotation.y = msg->pose.pose.orientation.y;
    transformStamped4.transform.rotation.z = msg->pose.pose.orientation.z;
    transformStamped4.transform.rotation.w = msg->pose.pose.orientation.w;
    // send transform
    br.sendTransform(transformStamped4);
  }

private:
  ros::NodeHandle n; 
  tf2_ros::TransformBroadcaster br;
  geometry_msgs::TransformStamped transformStamped;
  geometry_msgs::TransformStamped transformStamped2;
  geometry_msgs::TransformStamped transformStamped3;
  geometry_msgs::TransformStamped transformStamped4;
  ros::Subscriber sub;
};


int main(int argc, char **argv) {
  ros::init(argc, argv, "tf_broadcast");
  TfOdom my_tf_broadcaster;
  ros::spin();
  return 0;
}
