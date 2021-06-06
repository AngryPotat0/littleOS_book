# 环境配置

首先我们要配置好开发操作系统需要的环境

在ubuntu上（如果使用的是win10，则可以使用wsl安装ubuntu20.04），我们只需要在终端上执行下面这条命令：

```shell
sudo apt-get install build-essential nasm genisoimage bochs bochs-sdl
```

就可以安装好我们前期所需要的软件。

然后我们还需要配置交叉编译环境，当然，这个并不着急，以后再处理也行

交叉编译环境配置：
https://blog.csdn.net/weixin_40080866/article/details/89373262

