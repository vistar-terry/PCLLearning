#include <iostream>
#include <vector>
#include <string>
#include <dirent.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>

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

void ply2pcd(char **path, string plyfile)
{
    pcl::PCLPointCloud2 point_cloud2;
    pcl::PLYReader reader;
    reader.read(path[1] + plyfile, point_cloud2);
    pcl::PointCloud<pcl::PointXYZRGB> point_cloud;
    pcl::fromPCLPointCloud2(point_cloud2, point_cloud);
    pcl::PCDWriter writer;
    int index = plyfile.rfind('.');
    writer.writeASCII(path[2] + plyfile.replace(index + 1, 3, "pcd"), point_cloud);
}

int main(int argc, char **argv)
{
    vector<string> files;
    files = getfiles(argv);
    for (int i = 0; i < files.size(); ++i)
    {
        ply2pcd(argv, files[i]);
        cout << files[i] << " covented." << endl;
    }
    cout << files.size() << " files have convented." << endl;
    return 0;
}