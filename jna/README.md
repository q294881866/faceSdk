﻿
### 使用
* 用GenCode.exe获取license
* 安装好程序，调用java接口即可使用
* 32/64bit 例子要使用不同的jdk运行版本。下面是详细


#### faceEngine
> 检测人脸，比较两个人脸的相似度。目前提供32、64位版本

* 将dll目录文件加到当前工程根目录，或者其它能加载到dll文件的目录
* license文件保存在 JAVA\_HOME\bin （32bit）目录下，即可执行文件java（.exe）同一目录
* 将dll目录下java\_32\_bin目录文件，放到执行本示例的32位java.exe对应目录(./bin)
* [haarcascades](./haarcascades) 文件夹是检测眼镜的模型文件
* [jar](./jar) 文件夹提供了直接可以导入的jar，
  - QsFace4Java-1.0.1-jar-with-dependencies.jar 包含了所有依赖的jar
  - QsFace4Java-1.0.1.jar 只包含源码
* demo Test

> 注意

* dll目录文件,在x86\_32或者x86\_64目录
* 64位版本同32位操作不过放到相应的64位执行环境下，注意切换不同的jdk
* 建议直接将x86\_32或者x86\_64目录下所有文件（包括x64/x86目录下的所有文件） 以及license放到java/bin目录下。
