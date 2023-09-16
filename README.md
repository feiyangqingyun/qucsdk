
## 0 前言说明
1. **项目作品：[https://qtchina.blog.csdn.net/article/details/97565652](https://qtchina.blog.csdn.net/article/details/97565652)**
2. **视频主页：[https://space.bilibili.com/687803542](https://space.bilibili.com/687803542)**
3. **网店地址：[https://shop244026315.taobao.com](https://shop244026315.taobao.com)**
4. **联系方式：QQ（517216493）微信（feiyangqingyun）推荐加微信。**
5. **公 众 号：Qt教程（民间）  Qt软件（官方）**
6. **版本支持：所有项目已经全部支持Qt4/5/6所有版本以及后续版本。**
7. 监控作品体验：[https://pan.baidu.com/s/1d7TH_GEYl5nOecuNlWJJ7g](https://pan.baidu.com/s/1d7TH_GEYl5nOecuNlWJJ7g) 提取码：01jf
8. 其他作品体验：[https://pan.baidu.com/s/1ZxG-oyUKe286LPMPxOrO2A](https://pan.baidu.com/s/1ZxG-oyUKe286LPMPxOrO2A) 提取码：o05q
9. 监控系统在线文档：[https://feiyangqingyun.gitee.io/QWidgetDemo/video_system/](https://feiyangqingyun.gitee.io/QWidgetDemo/video_system/)
10. 大屏系统在线文档：[https://feiyangqingyun.gitee.io/QWidgetDemo/bigscreen/](https://feiyangqingyun.gitee.io/QWidgetDemo/bigscreen/)
11. 物联网系统在线文档：[https://feiyangqingyun.gitee.io/QWidgetDemo/iotsystem/](https://feiyangqingyun.gitee.io/QWidgetDemo/iotsystem/)

## 1 项目介绍
Qt编写的自定义控件插件的sdk集合，包括了多个操作系统的动态库文件、控件头文件、sdk使用demo、使用说明等。

## 2 下载地址
- 视频演示：[https://www.bilibili.com/video/BV1Go4y1P7nX](https://www.bilibili.com/video/BV1Go4y1P7nX)
- 使用示例：[https://qtchina.blog.csdn.net/article/details/121188343](https://qtchina.blog.csdn.net/article/details/121188343)
- 下载地址：[https://pan.baidu.com/s/1A5Gd77kExm8Co5ckT51vvQ](https://pan.baidu.com/s/1A5Gd77kExm8Co5ckT51vvQ)  密码：877p
- 文件名称：控件演示 bin_quc.zip ，其余为各个日期对应生成的动态库和头文件。
- 特别提示：**由于开源平台上传大小有限，后期更新一直在网盘，这里找不到对应版本请到网盘下载。**
- 郑重提示：**mingw版本请到github或者网盘下载。**
- 尊贵提示：可付费购买控件完整源码，每个控件都有独立的使用demo。
- 联系方式：**QQ（517216493）微信（feiyangqingyun）推荐加微信。**

## 3 版本说明
1. sdk分带日期的目录，建议用新版本。
2. 其他文件夹为对应日期的版本，而且同时提供了debug和release的动态库。
3. 头文件请使用对应文件夹下的头文件，因为控件一直在升级完善。
4. 强烈推荐使用最新版，目前共205个控件。
5. 理论上小版本向上向下兼容的，比如5.12.3的dll可以放到5.12.0中使用。
6. 2021-10-10开始只提供最新自定义控件的sdk。

## 4 目录说明
1. include目录为控件对应的头文件。
2. shared目录为各个Qt版本对应的动态库文件。如果找不到自己安装的Qt版本的，可以用静态库。
3. static目录为对应的静态库，基本上用的低版本的Qt库和编译器编译，以便支持对应大版本比如Qt5/Qt6全系列的Qt套件。比如qt5_linux_gcc_32支持所有32位的linux上的Qt5全系列套件，qt6_win_mingw_64支持所有64位的使用mingw64编译器的Qt6全系列套件。
4. sdkdemo目录为演示如何调用动态库文件。
5. snap目录为各个控件的运行效果图，一直更新。

## 5 使用说明
1. 第一步：前提是qt版本、编译器类型、编译器版本、编译器位数必须完全一致。
2. 第二步：找到qt安装目录的库所在的bin目录，同级有个plugins文件夹，plugins文件夹下有个designer目录，将对应插件文件例如 quc_5_7_0_msvc2013_32.dll 放到此目录即可。
3. 第三步：双击bin目录下的designer.exe，打开提供的demo.ui，即可看到效果。或者新建个空白UI然后从左边的控件栏里面拖动过去。
4. 如果想集成到qtcreator中，则必须保证你下载的库版本必须和你的qtcreator所用的qt版本+编译器+位数完全一致才行，很可能集成安装包中的qtcreator版本是上一个qt版本编译的，这样是无法集成进去的，推荐用qt5.12.3这个集成安装包，如果你是msvc编译器那是可以顺利集成进去的。
5. windows系统上Qt Designer设计师动态库存放的地址一般是 C:\Qt\Qt5.15.2\5.15.2\mingw81_64\plugins\designer，Qt Creator动态库存放的地址一般是 C:\Qt\Qt5.15.2\Tools\QtCreator\bin\plugins\designer。
6. linux系统上Qt Designer设计师动态库存放的地址一般是 /home/liu/Qt/Qt5.14.0/5.14.0/gcc_64/plugins/designer，Qt Creator动态库存放的地址一般是 /home/liu/Qt/Qt5.14.0/Tools/QtCreator/lib/Qt/plugins/designer。
7. mac系统上Qt Designer设计师动态库存放的地址一般是 /Users/liu/Qt/5.15.2/clang_64/plugins/designer，Qt Creator动态库存放的地址一般是 /Users/liu/Qt/Qt Creator.app/Contents/PlugIns/designer。
8. 非官方使用图文教程 [https://blog.csdn.net/u014779536/article/details/106923566](https://blog.csdn.net/u014779536/article/details/106923566)

## 6 特别说明
1. **动态库和对应的头文件会一直更新完善修复BUG，由于作者精力有限，不保证所有的插件都是最新的，只保证qt_5_7_0_mingw530_32这个版本永远是最新的正确的，为什么选择这个版本，因为5.7.0是最后一个支持XP的版本。谢谢信任和理解。**
2. **务必记得要集成到QtCreator就必须和QtCreator的版本保持一致，要编译项目成功就必须和你使用的构建套件的版本保持一致，比如安装的5.12.3的qt集成开发环境，你需要拷贝qt_5_12_3_msvc2017_32.zip这个下面的dll到对应的目录，而如果你使用的是5.12.3+mingw32编译器的话，在编译sdkdemo的时候需要拷贝qt_5_12_3_mingw730_32.zip这个下面的dll到sdkdemo目录下同文件替换dll，切记qt和qtcreator是两个东西，不一样，一个creator可以加载多个不同的qt构建套件。千万别把QtCreator的dll拷贝到sdkdemo目录。**

## 7 功能特点
1. 超过202个精美控件并持续不断迭代更新升级，种类超多，控件类型极其丰富。
2. 涵盖了各种仪表盘、进度条、进度球、指南针、曲线图、标尺、温度计、导航条、导航栏，flatui、高亮按钮、滑动选择器、农历、广告轮播、饼状图、环形图、时间轴、拓展控件、增强控件等。
3. 每个类都是独立的一个.h头文件和.cpp实现文件组成，零耦合，不依赖其他文件，方便单个控件独立出来以源码形式集成到项目中，方便直观。
4. 控件数量远超其他第三方控件库比如qwt集成的控件数量，使用方式也比其简单友好零耦合。
5. 支持任意Qt版本，亲测Qt4.6到Qt5.15的所有版本，全部纯Qt编写，QWidget+QPainter绘制。
6. 支持任意编译器，包括但不限于mingw、msvc、gcc、clang等编译器。
7. 支持任意操作系统，包括但不限于windows、linux、mac、android、uos、银河麒麟、各种国产linux、嵌入式linux、树莓派、香橙派、全志H3等。
8. 支持编译生成设计师插件，可直接集成到QtCreator的控件栏中，和自带的控件一样使用，大部分效果只要设置几个属性即可，极为方便。
9. 支持编译生成独立的非插件形式的动态库文件，体积小，比如嵌入式linux不支持designer只需要动态库的形式。
10. 每个控件都有一个单独的完整的使用demo，方便参考学习单个控件使用，非常适合初学者。
11. 提供一个所有控件使用的集成的example，方便快速查看所有控件的效果。
12. 支持直接源码集成到example的方式，方便编译到安卓，for web套件等。
13. 支持编译成wasm文件，直接网页运行，可以在谷歌、火狐、edge等浏览器运行，原生性能。
14. 每个控件的源代码都有详细中文注释，都按照统一设计规范编写，方便学习自定义控件的编写。
15. 每个控件都内置默认配色，demo对应的配色都非常精美。
16. 部分控件提供多种样式风格选择，多种指示器样式选择。
17. 所有控件自适应布局和窗体拉伸变化，自动缩放。
18. 配套额外的自定义控件属性设计器，类似组态设计器，纯中文属性名称，支持拖曳设计，所见即所得，支持导入导出xml格式。
19. 集成fontawesome图形字体+阿里巴巴iconfont收藏的几百个图形字体，享受图形字体带来的乐趣。
20. 所有控件最后生成一个dll动态库文件，可以直接集成到qtcreator中拖曳设计使用。
21. 控件源码全部分门别类存放，pri模块形式集成，提供控件对照表快速查找对应控件和说明。

## 8 部分控件效果图
![avatar](snap/000.gif)
![avatar](snap/customring.gif)
![avatar](snap/gaugecar.gif)
![avatar](snap/gaugecolor.gif)
![avatar](snap/gaugemini.gif)
![avatar](snap/gaugepanel.gif)
![avatar](snap/gaugepercent.gif)
![avatar](snap/gaugespeed.gif)
![avatar](snap/progresspercent.gif)
![avatar](snap/telwidget.gif)
![avatar](snap/wavebar.gif)
![avatar](snap/switchbutton.gif)
![avatar](snap/progresstip.gif)
![avatar](snap/gaugeedit.gif)
![avatar](snap/timeaxis.gif)
![avatar](snap/shadowclock.gif)
![avatar](snap/shadowcalendar.gif)
![avatar](snap/progressshadow.gif)
![avatar](snap/wavewater.gif)
![avatar](snap/progressarc.gif)
![avatar](snap/scantantan.gif)
![avatar](snap/imageanimation.gif)
![avatar](snap/gaugecompasspan.gif)
![avatar](snap/progressbutton.gif)
![avatar](snap/lunarcalendarwidget.gif)
![avatar](snap/colorpanel.gif)
![avatar](snap/navlistview.gif)
![avatar](snap/navbutton.gif)
![avatar](snap/gaugecloud.gif)
![avatar](snap/gaugedial.gif)
![avatar](snap/rulerprogress.gif)
![avatar](snap/gaugeprogress.gif)
![avatar](snap/rulerslider.gif)

## 9 不同系统效果图
### 9.1 windows-mingw
 ![](snap/4-1-1.jpg)

### 9.2 windows-msvc
 ![](snap/4-2-1.jpg)
 ![](snap/4-2-2.jpg)

### 9.3 linux-ubuntu
 ![](snap/4-3-1.jpg)
 ![](snap/4-3-2.jpg)
 ![](snap/4-3-3.jpg)

### 9.4 linux-deepin
 ![](snap/4-4-1.jpg)

### 9.5 linux-uos
 ![](snap/4-5-1.jpg)

### 9.6 linux-kylin
 ![](snap/4-6-1.jpg)
 ![](snap/4-6-2.jpg)

### 9.7 linux-newstart
 ![](snap/4-7-1.jpg)

### 9.8 linux-fedoar
 ![](snap/4-8-1.jpg)
 ![](snap/4-8-2.jpg)

### 9.9 unix-mac
 ![](snap/4-9-1.jpg)

### 9.10 web-chromium
 ![](snap/4-10-1.jpg)
 ![](snap/4-10-2.jpg)
 ![](snap/4-10-3.jpg)
 ![](snap/4-10-4.jpg)
 ![](snap/4-10-5.jpg)
 ![](snap/4-10-6.jpg)
 ![](snap/4-10-7.jpg)