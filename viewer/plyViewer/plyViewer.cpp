#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/gp3.h>

using namespace std;
using namespace pcl;
using namespace io;


// 按不同深度值显示不同颜色
int viewer1(char *path)
{
    PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>);

    if (io::loadPLYFile(path, *cloud) == -1)
    { // 读取.ply文件
        cerr << "can't read file bunny.pcd" << endl;
        return -1;
    }

    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));

    // 沿z方向进行渲染
    pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZ> fildColor(cloud, "z");

    viewer->addPointCloud<pcl::PointXYZ>(cloud, fildColor, "sample cloud");
    // viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud"); // 设置点云大小

    while (!viewer->wasStopped())
    {
        viewer->spinOnce(100);
        // boost::this_thread::sleep(boost::posix_time::microseconds(1000));
    }

    return 0;
}

// 自定义颜色
// 任何点云格式均可，不要求点云带有RGB字段
int viewer2(char *path)
{
    PointCloud<PointXYZRGB>::Ptr cloud(new PointCloud<PointXYZRGB>);
    pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);

    if (io::loadPLYFile(path, *cloud) == -1)
    { // 读取.ply文件
        cerr << "can't read file bunny.pcd" << endl;
        return -1;
    }

    // 计算法线
    // pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> n;
    // //建立kdtree来进行近邻点集搜索
    // pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGB>);
    // //为kdtree添加点运数据
    // tree->setInputCloud(cloud);
    // n.setInputCloud(cloud);
    // n.setSearchMethod(tree);
    // //点云法向计算时，需要所搜的近邻点大小
    // n.setKSearch(20);
    // //开始进行法向计算
    // n.compute(*normals);

    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));

    // 自定义颜色
    // pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGBNormal> single_color(cloud,0,0,0); // white

    viewer->addPointCloud<pcl::PointXYZRGB>(cloud, "sample cloud");
    viewer->addPointCloudNormals<pcl::PointXYZRGB, pcl::Normal>(cloud, normals, 20, 0.03, "normals");

    // 设置点云大小
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
    // viewer->setBackgroundColor(255,255,255);

    while (!viewer->wasStopped())
    {
        viewer->spinOnce(100);
        // boost::this_thread::sleep(boost::posix_time::microseconds(1000));
    }

    return 0;
}

// run:    plyViewer file [command]
// command:     0    自带RGB
//              1    按不同深度值显示不同颜色
int main(int argc, char **argv)
{
    switch (*argv[2])
    {
    // 自带RGB
    case '0':
        viewer2(argv[1]);
        break;
    // 按不同深度值显示不同颜色
    case '1':
        viewer1(argv[1]);
        break;

    default:
        viewer2(argv[1]);
        break;
    }

    return 0;
}