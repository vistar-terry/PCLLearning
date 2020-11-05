#include <pcl/io/pcd_io.h>
#include <pcl/filters/voxel_grid.h>

#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/io.h>

int main(int argc, char** argv)
{
    // 创建点云对象
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr filteredCloud(new pcl::PointCloud<pcl::PointXYZ>);
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));

    // 读取PCD文件
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(argv[1], *cloud) != 0)
    {
        return -1;
    }

    // 创建滤波对象
    pcl::VoxelGrid<pcl::PointXYZ> filter;
    filter.setInputCloud(cloud);

    // 设置体素栅格的大小为 1x1x1cm
    filter.setLeafSize(0.01f, 0.01f, 0.01f);
    filter.filter(*filteredCloud);


    viewer->setBackgroundColor(0,0,0);
    // 设置点云颜色
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(filteredCloud, 255, 255, 255);
    
    viewer->addPointCloud<pcl::PointXYZ>(filteredCloud, single_color, "sample cloud");

    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "sample cloud");

    while (!viewer->wasStopped())
    {
        viewer->spinOnce(100);
        // boost::this_thread::sleep(boost::posix_time::microseconds(100000));
    }
}