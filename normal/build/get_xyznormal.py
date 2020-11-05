'''
当前代码所读pcd格式为 x y z intensity normal_x normal_y normal_z curvature
'''
import os
from itertools import islice


def get_xyznormal(pcd_name):
    '''
    获取 x y z normal_x normal_y normal_z 格式文件
    '''
    # 冗余点云文件
    pcd = open("./xyznormal_/" + pcd_name, 'r')
    # 点云xyznormal文件
    # xyz = open("./xyznormal/" + pcd_name.replace(".pcd", ".pts"), 'a')
    xyz = open("./xyznormal/" + pcd_name.replace(".pts", ".txt"), 'a')
    labels = open("./label/" + pcd_name.replace(".pts", ".seg"), 'r')

    # 此 pcd 的 header 为11行,从第12行开始读
    # islice(iterable, start, stop, step)
    # iterable(可迭代对象), start(开始迭代位置), stop(结束迭代位置), step(迭代步长)
    for line, label in zip(islice(pcd, 11, None),labels):
        # 检查是否到文件尾
        if not line:
            break
        item = line.split(" ")
    # for label in labels:
        # 前三项xyz保存到点云文件
        xyz.write(item[0] + " " + item[1] + " " + item[2] + " " + item[4] + " " + item[5] + " " + item[6] + " " + label)
        
    pcd.close()



if __name__ == "__main__":
    # 获取指定目录下的文件名存入列表
    pcds = os.listdir('./xyznormal_')

    i = 0
    for pcd_name in pcds:
        print("[", i+1 , "]" + pcd_name + "... ", end=" ")
        get_xyznormal(pcd_name)
        print(" done.")
        i += 1
    print(str(i) + " files have done.")
