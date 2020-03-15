import os
filePath = '/Volumes/Untitled/BlackVue'
targetPath = '/Users/Xiangkui/Documents/MSCS/English2/'
def cpFile(filePath, targetPath):
    path = os.listdir(filePath)
    for p in path:
        if os.path.isdir(os.path.join(filePath,p)):
            os.makedirs(os.path.join(targetPath,p))
            cpFile(os.path.join(filePath,p),os.path.join(targetPath,p))
        else:
            f = open(os.path.join(targetPath,p),'w')
            f.close()
cpFile(filePath,targetPath)