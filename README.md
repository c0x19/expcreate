# expcreate

做pwn题时，避免每次都要重复写代码，或者复制其他exp模板，写了一个c语言程序，把常用的指令写入exp.py并用sublime打开

## requirement

需要安装sublime，安装教程网上有很多
也可以修改c语言代码中最后的sysem命令，删除掉或使用其他编辑器即可

## 安装
- `git clone https://github.com/c0x19/expcreate.git`
- `cd expcreate`
- `sudo ./install`

## 使用

在题目目录下运行

- `exp`

即可用subl打开exp.py

## 个人修改

- exp命令是在install.sh中配置的，可以修改-o参数后面的程序名字，修改为自己喜欢的命令
- c语言代码很简单，自己随便修改即可
