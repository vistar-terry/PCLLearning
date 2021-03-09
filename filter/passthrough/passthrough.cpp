#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/passthrough.h>

using namespace std;

int main(int argc, char **argv)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>);

	// 读入点云数据
	pcl::PCDReader reader;
	reader.read<pcl::PointXYZRGB>(argv[1], *cloud);
	std::cerr << "Cloud before filtering: " << std::endl;
	std::cerr << *cloud << std::endl;

	// 创建可视化窗口
	pcl::visualization::PCLVisualizer viewer("滤波");
	//设置左右窗口
	int v1(0);
	int v2(1);
	viewer.createViewPort(0.0, 0.0, 0.5, 1, v1);
	viewer.setBackgroundColor(0.5, 0.5, 0.5, v1);

	viewer.createViewPort(0.5, 0.0, 1, 1, v2);
	viewer.setBackgroundColor(0.5, 0.5, 0.5, v2);

	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> cloud_out_green(cloud, 20, 180, 20);
	// 显示原始点云
	viewer.addPointCloud<pcl::PointXYZRGB>(cloud, "cloud_out1", v1);

	pcl::PassThrough<pcl::PointXYZRGB> pass;

	//创建滤波器 pass
	pass.setInputCloud(cloud);
	pass.setFilterFieldName("x");
	pass.setFilterLimits(-0.00731989, -0.00538736);
	pass.filter(*cloud_filtered);
	std::cerr << "Cloud after filtering: " << std::endl;
	std::cerr << *cloud_filtered << std::endl;

	// 保存滤波后的点云
	pcl::PCDWriter writer;
	writer.write<pcl::PointXYZRGB>("re.pcd", *cloud_filtered, false);

	// pass.setFilterFieldName("y");
	// pass.setFilterLimits(-0.067, 0.36);
	// pass.setFilterLimitsNegative (true);

	//显示滤波后的点云
	viewer.addPointCloud(cloud_filtered, "cloud_out2", v2);
	//viewer.setSize(960, 780);
	while (!viewer.wasStopped())
	{
		viewer.spinOnce();
	}
	return 0;
}