#include <pcl/common/common_headers.h>
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/io/io.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread/thread.hpp>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/statistical_outlier_removal.h>

using namespace std;
using namespace pcl;
using namespace io;

int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_medium(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>);
    //读取点云文件
    // cloud->points.clear();
    std::string pcd_file_name = "/home/vistar/Desktop/ply/fixed/00001_1.ply";
    std::string pcd_file_name_filtered = "gg.ply";
    // std::cout<<"please input pcd file name:"<<endl;
    // std::cin>>pcd_file_name;
    // std::cout<<"the filtered pcd named *_filtered.pcd "<<endl;
    io::loadPLYFile(pcd_file_name, *cloud);

    
    //// 创建体素滤波器
    // Create the filtering object
    // pcl::VoxelGrid<pcl::PointXYZRGB> sor;
    // sor.setInputCloud(cloud);
    // sor.setLeafSize(0.01f, 0.01f, 0.01f);
    // sor.filter(*cloud_filtered);


    //滤波之后，有序点云会变成无序点云
    //直通滤波器，在Z轴方向上剪除多余的点
    pcl::PassThrough<pcl::PointXYZRGB> pass;  //创建滤波器对象
    pass.setInputCloud(cloud);                //设置待滤波的点云
    pass.setFilterFieldName("z");             //设置在Z轴方向上进行滤波
    pass.setFilterLimits (-0.38, -0.2);             //设置滤波范围为0~1,在范围之外的点会被剪除
    pass.filter (*cloud_medium);               //存储

    //统计滤波器，删除离群点
    pcl::StatisticalOutlierRemoval<pcl::PointXYZRGB> Static;   //创建滤波器对象
    Static.setInputCloud(cloud_medium);                           //设置待滤波的点云
    Static.setMeanK (150);                               //设置在进行统计时考虑查询点临近点数
    Static.setStddevMulThresh (0.5);                      //设置判断是否为离群点的阀值
    Static.filter (*cloud_filtered);                    //存储

    //保存滤波后的点云
    pcl::PCDWriter writer;
    pcd_file_name_filtered.assign(pcd_file_name,0,pcd_file_name.length()-4);
    pcd_file_name_filtered.append("_filtered.pcd");
    writer.write (pcd_file_name_filtered, *cloud_filtered);

    //双视口
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("filter Viewer"));
    viewer->initCameraParameters();
    int v1(0), v2(0);
    //原始点云窗口
    viewer->createViewPort(0.0, 0.0, 0.5, 1.0, v1);
    viewer->setBackgroundColor(0, 0, 0, v1);
    viewer->addText("original", 10, 10, "v1 text", v1);
    viewer->addPointCloud<pcl::PointXYZRGB>(cloud, "original cloud1", v1);
    // viewer->addCoordinateSystem(1.0);        //显示坐标轴
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "original cloud1");
    //滤波窗口
    viewer->createViewPort(0.5, 0.0, 1.0, 1.0, v2);
    viewer->setBackgroundColor(0, 0, 0, v2);
    viewer->addText("after filtered", 10, 10, "v2 text", v2);
    viewer->addPointCloud<pcl::PointXYZRGB>(cloud_filtered, "filted cloud2", v2);
    // viewer->addCoordinateSystem(1.0);        //显示坐标轴
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "filted cloud2");

    while (!viewer->wasStopped ())
    {
     viewer->spinOnce (100);  //刷新
     boost::this_thread::sleep (boost::posix_time::microseconds (100000));
    }
    return 0;
}
