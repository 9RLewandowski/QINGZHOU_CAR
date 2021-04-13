#ifndef __AI_H__
#define __AI_H__

#include <ros/ros.h>
#include <ros/time.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <boost/asio.hpp>
#include <geometry_msgs/Twist.h>

namespace robot
{
    class robot
    {
        public:
            robot();
            ~robot();
            bool init();                  
            bool deal(double RobotV, double RobotYawRate);
                                
        private:
            void calcOdom();               //��̼Ƽ���
            void pubOdomAndTf();           //����Odom��tf
        
        private:
            ros::Time current_time_, last_time_; //ʱ��

            double x_;                     //������λ��
            double y_;
            double th_;

            double delta_Distance;
            double delta_th;

            double vx_;                    //������x�����ٶ�
            double vy_;                    //������y�����ٶ�
            double vth_;                   //�����˽��ٶ�


            
            ros::NodeHandle nh;
            ros::Publisher pub_;
            tf::TransformBroadcaster odom_broadcaster_;
    };
    
}

#endif 


