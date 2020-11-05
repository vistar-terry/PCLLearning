#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/search/kdtree.h>
#include <pcl/features/normal_3d.h>
#include <pcl/visualization/pcl_visualizer.h>

using namespace std;

// 获取指定目录的所有文件名
vector<string> getfiles(char **path)
{
    struct dirent *ptr;
    vector<string> files;
    DIR *dir;
    dir = opendir(path[1]);
    while ((ptr = readdir(dir)) != NULL)
    { //跳过'.'和'..'两个目录
        if (ptr->d_name[0] == '.')
            continue;
        // 文件名存入vector
        files.push_back(ptr->d_name);
    }
    closedir(dir);
    return files;
}

// 单文件 txt2pcd
int txt2pcd(char **path, string pcdfile)
{
    // 自定义读取txt的Point点类型
    typedef struct tagPOINT_3D
    {
        double x; //mm world coordinate x
        double y; //mm world coordinate y
        double z; //mm world coordinate z
        double r;
    } POINT_WORLD;

    // 加载txt数据
    int number_Txt;
    FILE *fp_txt;
    tagPOINT_3D TxtPoint;
    vector<tagPOINT_3D> m_vTxtPoints;
    string f = path[1] + pcdfile;
    char *chr = const_cast<char *>(f.c_str());
    fp_txt = fopen(chr, "r");
    if (fp_txt)
    {
        while (fscanf(fp_txt, "%lf %lf %lf", &TxtPoint.x, &TxtPoint.y, &TxtPoint.z) != EOF)
        {
            m_vTxtPoints.push_back(TxtPoint);
        }
    }
    else
        cout << "txt数据加载失败！" << endl;
    number_Txt = m_vTxtPoints.size();
    //pcl::PointCloud<pcl::PointXYZ> cloud;
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

    pcl::PointCloud<pcl::PointXYZ>::Ptr inCloud(new pcl::PointCloud<pcl::PointXYZ>);
    inCloud = cloud;
    
    // add normal
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
    
    // save to pcd
	pcl::io::savePCDFile("./xyznormal/"+pcdfile, *cloud_with_normals);
}

// txt2pcd txt_path pcd_path
int main(int argc, char **argv)
{
    vector<string> files;
    files = getfiles(argv);
    for (int i = 0; i < files.size(); ++i)
    {
        txt2pcd(argv, files[i]);
        cout << "[" << i << "] " << files[i] << " ====> " << files[i].replace(files[i].end() - 3, files[i].end(), "pcd") << endl;
    }
    cout << "**************************************" << endl;
    cout << "Total " << files.size() << " files have convented." << endl;

    return 0;
}
