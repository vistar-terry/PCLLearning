## 问题描述

RealSense保存的ply文件，用PCL可视化时，会报错，是因为RealSense保存的ply文件格式有问题。

![Screenshot from 2020-07-05 21-12-00](https://i.loli.net/2020/07/05/BHmeSRPsOIJQF8j.png)

RealSense保存的ply文件格式是这样的：

```
ply
format ascii 1.0
comment pointcloud saved from Realsense Viewer
element vertex 87748
property float32 x
property float32 y
property float32 z
property float32 nx
property float32 ny
property float32 nz
property uchar red
property uchar green
property uchar blue
element face 173974
property list uchar int vertex_indices
end_header
-0.623535 0.499023 -0.870117 
-0.177295 0.166866 0.969908 
90 91 87 
-0.618652 0.498535 -0.869141 
-0.176508 0.172906 0.968994 
90 91 82 
-0.61377 0.497803 -0.868164 
-0.20753 0.223017 0.952468 
91 91 87
...
```

下面是斯坦福官方(ply格式是斯坦福编制的)的例子：

```
ply
format ascii 1.0
comment author: anonymous
comment object: another cube
element vertex 8
property float32 x
property float32 y
property float32 z
property red uint8                     { start of vertex color }
property green uint8
property blue uint8
element face 7
property list uint8 int32 vertex_index { number of vertices for each face }
end_header
0 0 0 255 0 0                          { start of vertex list }
0 0 1 255 0 0
0 1 1 255 0 0
0 1 0 255 0 0
1 0 0 0 0 255
1 0 1 0 0 255
1 1 1 0 0 255
1 1 0 0 0 255
...
```

对比一下，

先看header部分，Stanford的点云每个点有6个属性(x,y,z,red,green,blue)，RealSense的点云每个点有9个属性(x,y,z,nx,ny,nz,red,green,blue)；

然后看数据部分，Stanford的每行有6个数字，很明显，分别代表 x,y,z,red,green,blue。RealSense的从数据格式可以看出，每三行为一组，看出每三行一组然后就很明了了，三行一共9个数，分别代表x,y,z,nx,ny,nz,red,green,blue。

RealSense保存的ply文件问题就在这里，每个点的数据应该在同一行(即是以换行符区分点的)，所以将RealSense的ply文件每一组放到一行就可以了。

像这样：

```
-0.623535 0.499023 -0.870117 -0.177295 0.166866 0.969908 90 91 87 
-0.618652 0.498535 -0.869141 -0.176508 0.172906 0.968994 90 91 82 
-0.61377 0.497803 -0.868164 -0.20753 0.223017 0.952468 91 91 87
...
```

从header中的 `element vertex 87748` 可以看到，一共有87748个点，手动改简直就是灾难，所以写了脚本，大家可以参考。

## 使用方法

1.建立如下的文件结构：

.
├── fix_realsense_ply.py
├── fixed
└── src

2.将需要修改的RealSense文件放到 src 文件夹中，然后执行命令：

```
python fix_realsense_ply.py
```

3.最后修改好的文件在 fixed 文件夹中

## 注意

如果你的ply和上面例子的一样(3行一组)，则直接执行，如果是2行一组，需要将源码中`vertex_size = vertex_size*3`改为`vertex_size = vertex_size*2`，并且将fix_ply()函数里的get_fixed_vertex3()函数改为get_fixed_vertex2()。