#include <iostream>
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>

int main(int argc, char **argv)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::io::loadPCDFile(argv[1], *cloud);

  //create the normal estimation class, and pass the input dataset to it
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
  ne.setInputCloud(cloud);

  //create an empty kdtree representation, and pass it to the normal estimation object
  //its content will be filled inside the object, based on the given input dataset(as no other search surface is given)
  pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());
  ne.setSearchMethod(tree);

  //Output datasets
  pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);

  //use all neighbours in a sphere of radius 1cm
  ne.setRadiusSearch(0.01);

  //compute the features
  //cloud_normals->points.size() should have the same size as the input cloud->points.size
  ne.compute(*cloud_normals);

  //normal visualization
  pcl::visualization::PCLVisualizer viewer("PCL viewer");
  viewer.setBackgroundColor(0.0, 0.0, 0.0);
  viewer.addPointCloud<pcl::PointXYZ>(cloud, "s");
  viewer.addPointCloudNormals<pcl::PointXYZ, pcl::Normal>(cloud, cloud_normals, 5, 0.02);

  // save the xyznormal pointcloud
  pcl::PCDWriter writer;
  writer.write<pcl::PointXYZ>("xyz.pcd", *cloud, false);
  writer.write<pcl::Normal>("nxnynz.pcd", *cloud_normals, false);

  while (!viewer.wasStopped())
  {
    viewer.spinOnce();
  }

  return 0;
}
