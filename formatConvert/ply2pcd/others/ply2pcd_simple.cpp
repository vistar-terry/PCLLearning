#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/console/time.h>
#include <pcl/io/vtk_lib_io.h>
#include <pcl/io/vtk_io.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <pcl/visualization/cloud_viewer.h>  
#include <pcl/conversions.h>

using namespace pcl;
using namespace pcl::io;
using namespace pcl::console;
 
int main()
{
    pcl::PCLPointCloud2 point_cloud2;
    pcl::PLYReader reader;
    reader.read("/home/vistar/Desktop/ply/ply/00001_1.ply", point_cloud2);
    pcl::PointCloud<pcl::PointXYZRGB> point_cloud;
    pcl::fromPCLPointCloud2( point_cloud2, point_cloud);
    pcl::PCDWriter writer;
    writer.writeASCII("data.pcd", point_cloud);  
 
    return 0;
}