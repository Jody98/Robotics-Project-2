#!/usr/bin/env python
import rospy
from nav_msgs.msg import Path
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped

path = Path()
path_pub = rospy.Publisher('/path', Path, queue_size=100)

def odom_cb(data):
    global path
    path.header = data.header
    pose = PoseStamped()
    pose.header = data.header
    pose.pose = data.pose.pose
    path.poses.append(pose)
    path_pub.publish(path)



if __name__ == '__main__':
    rospy.init_node('path_node')
    rospy.Subscriber('/odom', Odometry, odom_cb)
    rospy.spin()