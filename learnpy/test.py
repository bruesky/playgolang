import os
import os.path
os.system("pwd")
def run(file_dir):
         for root, dirs, files in os.walk(file_dir):
             print(root)  # 当前目录路径
             print(dirs)  # 当前路径下所有子目录
             print(files)  # 当前路径下所有非目录子文件
             for dir in dirs:
                 print(dir)


run(os.path.abspath("."))
