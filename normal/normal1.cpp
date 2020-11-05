#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/search/kdtree.h>
#include <pcl/features/normal_3d.h>
 
int main(int argc, char* argv[])
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr inCloud(new pcl::PointCloud<pcl::PointXYZ>);

    pcl::PointXYZ cloud;

    cloud.x = x;
    cloud.y = y;
    cloud.z = 1 - x - y;
    inCloud->push_back(cloud);

 
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
	pcl::PointCloud<pcl::Normal>::Ptr pcNormal(new pcl::PointCloud<pcl::Normal>);
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
	tree->setInputCloud(inCloud);
	ne.setInputCloud(inCloud);
	ne.setSearchMethod(tree);
	ne.setKSearch(50);
	ne.compute(*pcNormal);	
 
	pcl::PointCloud<pcl::PointXYZINormal>::Ptr cloud_with_normals(new pcl::PointCloud<pcl::PointXYZINormal>);
	pcl::concatenateFields(*inCloud, *pcNormal, *cloud_with_normals);
 
	pcl::io::savePCDFile("plane_cloud_out.pcd", *cloud_with_normals);
 
	return 0;
}
 