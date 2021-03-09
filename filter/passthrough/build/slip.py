# -*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.pyplot import MultipleLocator

# 设置窗口初始大小
# plt.figure(figsize=(658, 1069))
# my_data = np.loadtxt('/home/thz/Desktop/tomato_weight/myDataSet/tomatoPoint/segment/00008_5.pcd')
my_data = np.loadtxt('re.txt')
x, y, z = my_data[:, 0], my_data[:, 1], my_data[:, 2]

# 绘制散点图
plt.scatter(z, y, marker='.', s=10)
# 为图添加标题
# plt.title('(A)', fontsize=16)
# 添加坐标轴标签
plt.xlabel('z/m', fontsize=14)
plt.ylabel('y/m', fontsize=14)
# 刻度字号
plt.tick_params(labelsize=15)

# 显示图表
plt.show()