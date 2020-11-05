#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>

using namespace std;
using namespace pcl;
using namespace io;

// string to float
float stringToFloat(string num)
{
    float res;
    stringstream stream(num);
    stream >> res;
    return res;
}

void txtViewer(char * txtfile)
{
    // 自定义读取txt的Point点类型
    typedef struct tagPOINT_3D
    {
        double x; //mm world coordinate x
        double y; //mm world coordinate y
        double z; //mm world coordinate z
    } POINT_WORLD;

    int number_Txt;
    FILE *fp_txt;
    tagPOINT_3D TxtPoint;
    vector<tagPOINT_3D> m_vTxtPoints;

    // 加载txt数据
    // string f = path[1] + pcdfile;
    // char *chr = const_cast<char *>(f.c_str());
    fp_txt = fopen(txtfile, "r");
    if (fp_txt)
    {
        while (fscanf(fp_txt, "%lf %lf %lf", &TxtPoint.x, &TxtPoint.y, &TxtPoint.z) != EOF)
        {
            m_vTxtPoints.push_back(TxtPoint);
        }
    }
    else
        cout << "failed to load txt file！" << endl;
    number_Txt = m_vTxtPoints.size();

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    // Fill in the cloud data
    cloud->width = number_Txt;
    cloud->height = 1;
    cloud->is_dense = false;
    cloud->points.resize(cloud->width * cloud->height);
    for (size_t i = 0; i < cloud->points.size(); ++i)
    {
        cloud->points[i].x = m_vTxtPoints[i].x;
        cloud->points[i].y = m_vTxtPoints[i].y;
        cloud->points[i].z = m_vTxtPoints[i].z;
    }

    //PCL Visualizer
    // pcl::visualization::PCLVisualizer viewer("Cloud Viewer");
    // viewer.addPointCloud(cloud);
    // viewer.setBackgroundColor(255, 255, 255);
    // viewer.spin();


    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));

    // 设置背景颜色
    viewer->setBackgroundColor(0, 0, 0);
    
    // 设置点云颜色
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 255, 255, 255); // green
    
    viewer->addPointCloud<pcl::PointXYZ>(cloud, single_color, "3D Viewer");
    
    // 设置点云大小
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "3D Viewer");

    while (!viewer->wasStopped())
    {
        viewer->spinOnce(100);
        // boost::this_thread::sleep(boost::posix_time::microseconds(100000));
    }
    // return 0;

    // system("pause");
}

//read pts and save to ply and pcd
// read pts，save as pcd and ply，then visualizative
void txtReader(string pts_path, string save_pcd_path, string save_ply_path)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    //numbers of point
    cloud->width = 2816;
    cloud->height = 1;
    cloud->is_dense = false;
    cloud->points.resize(cloud->width * cloud->height);

    ifstream pts_file(pts_path);
    string line;
    int point_count = 0;
    while (!pts_file.eof())
    {
        getline(pts_file, line);
        cout << line << endl;
        if (strlen(line.c_str()) > 0)
        {
            istringstream iss(line);
            string x, y, z;
            iss >> x >> y >> z;
            // cout << x << y << z << endl;
            cloud->points[point_count].x = stringToFloat(x);
            cloud->points[point_count].y = stringToFloat(y);
            cloud->points[point_count].z = stringToFloat(z);
            point_count++;
        }
        // cout << cloud->points[point_count].x << "  " << cloud->points[point_count].y << "  " << cloud->points[point_count].z << endl;
    }
    pts_file.close();
    pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");
    viewer.showCloud(cloud);
    system("PAUSE");
    //save to pcd and ply
    // pcl::io::savePCDFileASCII(save_pcd_path, *cloud);
    // pcl::io::savePLYFile(save_ply_path, *cloud);
    // std::cerr << "Saved " << cloud->points.size() << " data points to test_pcd.pcd." << std::endl;
}

int main(int argc, char **argv)
{
    // string pts_path = "/home/vistar/Desktop/source/pointnet.pytorch/shapenetcore_partanno_segmentation_benchmark_v0/02691156/1a04e3eab45ca15dd86060f189eb133.pts";
    // string save_pcd_path = "./";
    // string save_ply_path = "./";
    // txtReader(pts_path, save_pcd_path, save_ply_path);

    txtViewer(argv[1]);
    return 0;
}