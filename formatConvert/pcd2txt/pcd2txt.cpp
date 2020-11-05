#include <iostream>
#include <vector>
#include <string>
#include <dirent.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

using namespace std;
using namespace pcl;
using namespace pcl::io;

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

int pcd2txt(char **path, string pcdfile)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    // Fill in the cloud data
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(path[1] + pcdfile, *cloud) == -1)
    {
        PCL_ERROR("Couldn't read file.\n");
        return (-1);
    }
    //for (size_t i = 0; i < cloud->points.size(); i++)
    //  std::cout << " " << cloud->points[i].x << " " << cloud->points[i].y
    //  <<" "<< cloud->points[i].z << std::endl;
    int Num = cloud->points.size();
    double *X = new double[Num]{0};
    double *Y = new double[Num]{0};
    double *Z = new double[Num]{0};
    for (size_t i = 0; i < cloud->points.size(); ++i)
    {
        X[i] = cloud->points[i].x;
        Y[i] = cloud->points[i].y;
        Z[i] = cloud->points[i].z;
    }

    int index = pcdfile.rfind('.');
    ofstream zos(path[2] + pcdfile.replace(index + 1, 3, "txt"));
    for (int i = 0; i < Num; i++)
    {   
        // 将数据写入文件
        zos << X[i] << " " << Y[i] << " " << Z[i] << endl;
    }
    // cout << path[2] + pcdfile.replace(index + 1, 3, "txt") << endl;

    return 0;
}

int main(int argc, char **argv)
{
    // 存储指定目录下的所有文件名
    vector<string> files;
    files = getfiles(argv);
    for (int i = 0; i < files.size(); ++i)
    {
        pcd2txt(argv, files[i]);
        cout << files[i] << " covented." << endl;
    }
    cout << files.size() << " files have convented." << endl;
    return 0;
}