# -*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.pyplot import MultipleLocator

# 设置窗口初始大小
# plt.figure(figsize=(8, 8))
# my_data = np.loadtxt('/home/thz/Desktop/tomato_weight/myDataSet/tomatoPoint/segment/00008_5.pcd')
my_data = np.loadtxt('rel.txt')
x, y, z = my_data[:, 0], my_data[:, 1], my_data[:, 2]

print("D: {}".format((z.max()-z.min())*100))
print("dx: {}".format((x.max()-x.min())*100))
print("dy: {}".format((y.max()-y.min())*100))

######################## 三维图 ########################
# fig = plt.figure()
# ax = fig.add_subplot(111, projection='3d')
# flag = True
flag = False
if flag:
    lidd=['autumn', 'autumn_r','gist_earth', 'gist_earth_r', 'ocean', 'ocean_r', 'viridis', 'viridis_r']
    for cmap in lidd:
        fig = plt.figure()
        ax = fig.add_subplot(111, projection='3d')

        cm = plt.cm.get_cmap(cmap)
        ax.scatter(x, y, z, c=z, marker='.', cmap = cm)
        print(cmap)
        # #把x轴的刻度间隔设置为1，并存在变量里
        # z_major_locator = MultipleLocator(0.005)
        # ax.zaxis.set_major_locator(z_major_locator)

        # 设置坐标轴刻度范围
        # ax.set_xlim(-0.05, 0.04)
        # ax.set_ylim(-0.06, 0.04)
        # ax.set_zlim(-0.395, -0.360)

        # 添加坐标轴标签
        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.set_zlabel('Z')

        # 缩放坐标轴比例
        ax.get_proj = lambda: np.dot(Axes3D.get_proj(ax), np.diag([1.8, 1.8, 1, 1]))
        plt.show()



######################## 二维图 ########################
flag = True
# flag = False
if flag:
    # 设置子图位置，121代表，在一个1行2列的图阵中位于第2个位置
    plt.subplot(121)
    # 绘制散点图
    plt.scatter(x, y, marker='.', color='red', s=10)
    # 为图添加标题
    plt.title('(A)', fontsize=16)
    # 添加坐标轴标签
    plt.xlabel('x/m', fontsize=14)
    plt.ylabel('y/m', fontsize=14)
    # 刻度字号
    plt.tick_params(labelsize=13)

    # 设置子图位置，222代表，在一个2行2列的图阵中位于第2个位置
    plt.subplot(222)
    plt.scatter(x, z, marker='.', color='red', s=10)
    plt.title('(B)', fontsize=16)
    plt.xlabel('x/m', fontsize=14)
    plt.ylabel('z/m', fontsize=14)
    # 刻度字号
    plt.tick_params(labelsize=13)

    plt.subplot(224)
    plt.scatter(y, z, marker='.', color='red', s=10)
    plt.title('(C)', fontsize=16)
    plt.xlabel('y/m', fontsize=14)
    plt.ylabel('z/m', fontsize=14)
    # 刻度字号
    plt.tick_params(labelsize=13)

    # 调整子图位置
    # left, bottom, right, top 调整子图与外边界距离
    # wspace、hspace 调整子图间距
    # wspace 调整左右关系子图的间距
    # hspace 调整上下关系子图的间距
    plt.subplots_adjust(left=None, bottom=None, right=None,
                        top=None, wspace=0.18, hspace=0.35)

    # 设置坐标轴刻度范围
    # plt.xlim(-0.06, 0.04)  # 设置x轴范围
    # plt.ylim(-0.395, -0.360)  # 设置y轴范围

    # 显示图表
    plt.show()
