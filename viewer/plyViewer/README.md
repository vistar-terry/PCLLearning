plyViewer.cpp：源码

test.ply：测试文件

build/plyViewer：linux下的可执行文件

测试：

在build目录下执行以下命令：

```bash
./plyViewer ../test.ply 1
```

命令说明：

```bash
./plyViewer ../test.ply 0  # 显示点云自带的RGB颜色
./plyViewer ../test.ply 1  # 沿z方向按不同深度值显示不同颜色，也可沿其他方向，需修改源码
```

结果：

![result](/home/thz/Desktop/tomato_weight/PCLLearning/viewer/plyViewer/result.png)