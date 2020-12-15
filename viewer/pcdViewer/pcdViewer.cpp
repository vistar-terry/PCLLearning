#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/io.h>

using namespace std;
using namespace pcl;
using namespace io;

int PCDViewerRGB(char *file)
{
    // 创建点云对象
    PointCloud<PointXYZRGB>::Ptr cloud(new PointCloud<PointXYZRGB>);

    // 加载点云文件，并判断是否加载成功
    if (io::loadPCDFile(file, *cloud) == -1)
    { // 读取.pcd文件
        cerr << "can't read file." << endl;
        return -1;
    }

    // 创建可视化对象
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("sample cloud"));

    // 可视化窗口背景颜色
    viewer->setBackgroundColor(0, 0, 0);

    viewer->addPointCloud<pcl::PointXYZRGB>(cloud, "sample cloud");

    // 设置点大小
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "sample cloud");

    while (!viewer->wasStopped())
    {
        viewer->spinOnce(100);
    }

    return 0;
}

int PCDViewer(char *file)
{
    // 创建点云对象
    PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>);

    // 加载点云文件，并判断是否加载成功
    if (io::loadPCDFile(file, *cloud) == -1)
    { // 读取.pcd文件
        cerr << "can't read file." << endl;
        return -1;
    }

    // 创建可视化对象
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("sample cloud"));

    // 可视化窗口背景颜色
    viewer->setBackgroundColor(0, 0, 0);

    // 设置点云颜色
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 255, 255, 255);

    viewer->addPointCloud<pcl::PointXYZ>(cloud, single_color, "sample cloud");

    // 设置点大小
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "sample cloud");

    while (!viewer->wasStopped())
    {
        viewer->spinOnce(100);
    }

    return 0;
}

int main(int argc, char **argv)
{
    if (*argv[2] == '0')
    {
        PCDViewerRGB(argv[1]);
        return 0;
    }

    PCDViewer(argv[1]);

    return 0;
}