'''
处理ply文件
'''
import os


def get_header(ply):
    '''
    获取ply文件的header
    '''
    header = ""
    ply.seek(0, 0)
    while True:
        line = ply.readline()
        header += line
        if line == "end_header\n":
            ply.seek(0, 0)
            return header


def get_header_size(header):
    '''
    获取header的行数
    '''
    return len(header.split("\n"))-1


def get_vertex_size(header):
    '''
    获取vertex的数量
    '''
    hlist = header.split("\n")
    for ele in hlist:
        if "element vertex" in ele:
            return ele.split(" ")[2]


def get_face_size(header):
    '''
    获取face的数量
    '''
    hlist = header.split("\n")
    for ele in hlist:
        if "element face" in ele:
            return ele.split(" ")[2]


def get_ply_size(header):
    '''
    获取ply文件size数据
    return: list[
        header_size,
        vertex_size,
        face_size]
    '''
    hlist = header.split("\n")
    size = []
    size.append(len(hlist)-1)
    for ele in hlist:
        if "element vertex" in ele:
            size.append(int(ele.split(" ")[2]))
        if "element face" in ele:
            size.append(int(ele.split(" ")[2]))
    return size


def get_vertex(ply, header_size, vertex_size):
    '''
    获取vertex部分的内容
    '''
    vertex = ""
    ply.seek(0, 0)
    for i in range(header_size):
        line = ply.readline()

    for j in range(vertex_size):
        line = ply.readline()
        vertex += line
    ply.seek(0, 0)
    return vertex


def get_face(ply, header_size, vertex_size, face_size):
    '''
    获取face部分的内容
    '''
    face = ""
    ply.seek(0, 0)
    for i in range(header_size+vertex_size):
        line = ply.readline()

    for j in range(face_size):
        line = ply.readline()
        face += line
    ply.seek(0, 0)
    return face


def get_fixed_vertex2(ply, header_size, vertex_size):
    '''
    对每个点的数据分布于2行的vertex进行修复
    '''
    vertex = ""
    ply.seek(0, 0)
    for i in range(header_size):
        line = ply.readline()

    for j in range(vertex_size):
        line = ply.readline()
        if j % 2 == 0:
            line = line.strip('\n')
        vertex += line
    ply.seek(0, 0)
    return vertex


def get_fixed_vertex3(ply, header_size, vertex_size):
    '''
    对每个点的数据分布于3行的vertex进行修复
    '''
    vertex = ""
    ply.seek(0, 0)
    for i in range(header_size):
        line = ply.readline()

    for j in range(vertex_size):
        line = ply.readline().strip('\n')
        if (j+1) % 3 == 0:
            line = line + '\n'
        vertex += line
    ply.seek(0, 0)
    return vertex


def fix_ply(src_file, fixed_file):
    '''
    修复ply文件
    '''
    # 打开源文件和修复后的文件
    src_ply = open(src_file, 'r')
    fixed_ply = open(fixed_file, 'a')

    # 获取源文件的header并写入修复后的文件
    header = get_header(src_ply)
    fixed_ply.writelines(header)

    # 获取源文件ply的大小信息
    [header_size,
     vertex_size,
     face_size] = get_ply_size(header)

    # print(header_size)
    # 获取源文件的vertex，进行修复并写入修复后的文件
    vertex_size = vertex_size*3
    vertex = get_fixed_vertex3(src_ply, header_size, vertex_size)
    fixed_ply.writelines(vertex)
    # print(vertex)

    # 获取源文件的face并写入修复后的文件
    face = get_face(src_ply, header_size, vertex_size, face_size)
    fixed_ply.writelines(face)

    # 关闭源文件和修复后的文件
    src_ply.close()
    fixed_ply.close()


if __name__ == "__main__":
    # 获取指定目录下的文件名存入列表
    plys = os.listdir('./src')
    # 判断文件夹是否存在
    if(not os.path.isdir("./fixed")):
        os.mkdir("./fixed")
        
    for src_file in plys:
        fix_ply('./src/'+src_file, "./fixed/"+src_file)
