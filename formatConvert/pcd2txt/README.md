## point cloud pcd to txt

建立如下目录结构:

.
├── build
├── CMakeLists.txt
├── pcd
├── pcd2txt.cpp
├── README.md
└── txt

./pcd 中存放要转换的文件.

cmake编译

执行:

```
cd build
cmake ..
make
./pcd2txt [pcd路径] [txt路径]
例如:
./pcd2txt ../pcd/ ../txt/
```

注意路径最后要加 "/"

处理后的文件存放在 txt 目录下.

