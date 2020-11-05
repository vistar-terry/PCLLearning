// #include <pcl/visualization/cloud_viewer.h>
// #include <iostream>
// #include <pcl/io/io.h>
// #include <pcl/io/pcd_io.h>
// int main()
//  {
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
//    pcl::io::loadPCDFile ("/home/vistar/Desktop/pcl/tomato/tomato_1/rgbd-dataset/tomato/tomato_1/tomato_1_4_1.pcd", *cloud);
//    pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");
//    viewer.showCloud (cloud);
//    while (!viewer.wasStopped ())
//    {
//    }
//    return 0;
//  }

#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/io.h>

using namespace std;
using namespace pcl;
using namespace io;

int main(int argc, char** argv) {
    // 创建点云对象
    PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>);

    // 加载点云文件，并判断是否加载成功
    if (io::loadPCDFile(argv[1], *cloud) == -1) { // 读取.ply文件
        cerr << "can't read file." << endl;
        return -1;
    }

    // 创建可视化对象
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("sample cloud"));
    
    // 可视化窗口背景颜色
    viewer->setBackgroundColor(0,0,0);

    // 设置点云颜色
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 255, 255, 255);
    
    viewer->addPointCloud<pcl::PointXYZ>(cloud, single_color, "sample cloud");

    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "sample cloud");

    while (!viewer->wasStopped())
    {
        viewer->spinOnce(100);
    }

    return 0;
}