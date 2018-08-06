#coding:utf-8
import os

readme = open('./README.md','w',encoding='utf8')
menu = []
menu.append("# Job-Interview\n> 准备秋招\n\n## 刷题\n\n")
for file in os.listdir("./刷题记录"):
    name,ext = os.path.splitext(file)
    if ext == '.md':
        menu.append("[%s](https://github.com/glamourzc/Job-Interview/tree/master/刷题记录/%s)\n\n"%(name,file))
readme.writelines(menu)
readme.close()