# colorful_rain：池塘夜降彩色雨

------

[![release](https://img.shields.io/badge/release-1.0.0-green)](https://github.com/misterchaos/HotelSystem/releases)[![release](https://img.shields.io/badge/version-beta-orange)](https://github.com/misterchaos/HotelSystem/releases)[![release](https://img.shields.io/badge/build-passing-green)](https://github.com/misterchaos/HotelSystem/releases)

## :triangular_flag_on_post:题目要求

```
[问题描述]
    设计一个程序，演示美丽的“池塘夜雨”景色：色彩缤纷的雨点飘飘洒洒地从天而降，滴滴入水有声，溅起圈圈微澜。
[基本要求]
    （1）雨点的空中出现位置、降落过程的可见程度、入水位置、颜色、最大水圈等等，都是随机确定的；
    （2）多个雨点按照各自的随机参数和存在状态，同时演示在屏幕上。
[测试数据]
    适当调整控制雨点密度、最大水圈和状态变化的时间间隔等参数。
[实现提示]
    （1）每个雨点的存在周期可分为三个阶段：从天而降、入水有声和圈圈微澜，需要一个记录存储其相关参数、当前状态和下一状态的更新时刻；
    （2）在图形状态编程。雨点下降的可见程度应是断断续续、依稀可见；圈圈水波应是由里至外逐渐扩大和消失。
    （3）每个雨点发生时，生成其记录，并预置下一个雨点的发生时间；
    （4）用一个适当的结构管理当前存在的雨点，使系统能利用它按时更新每个雨点的状态，一旦有雨点的水圈全部消失，就从结构中删去。
[选做内容]
    （1）增加“电闪雷鸣”景象。
    （2）增加风的效果，展现“风雨飘摇”的情景。
    （3）增加雨点密度的变化：时而“和风细雨”， 时而“暴风骤雨”。
    （4）将“池塘”改为“荷塘”，雨点滴在荷叶上的效果是溅起四散的水珠，响声也不同。
```



## :bulb:开发者信息

```html
开发者：黄钰朝 
联系邮箱：kobe524348@gmail.com
项目开发时间：2019-11-27至2020-01-04
版本号：1.0.0
开源许可：Apache License 2.0
```

## :heavy_check_mark:用户使用说明

#### 1.键盘操作说明

- 方向上键：加快雨滴下落速度

- 方向下键：减慢雨滴下落速度

- 方向左键：加大向左风力

- 方向右键：加大向右风力

- 加号键：增加雨点数量

- 减号键：减少雨点数量

- 回车和ESC键：退出程序

#### 2.模式说明

- 默认设置：使用默认的初始化参数

- 手动设置：由用户手动输入初始化参数

#### 3.图形界面演示

![](\image\menu.jpg)

​                      														图1-1：菜单页面

![](\image\rain.jpg)

​																			 图1-2：下雨页面				



## :zap:程序结构

#### 1.开发环境说明

```json
操作系统：Windows10
IDE：Visual Studio Community 2017
图形库：easyX图形库(2019-5-29测试版)
开发语言：C++
开发时间：2019年11月27日至2020年1月4日
```

#### 2.程序流程图

![](\image\structure.png)

## :page_facing_up:心得体会

#### 1.问题解决

(1)**性能问题**：一开始对于下雨速度的控制是通过遍历每个雨滴的时候做时间延迟，通过调整时间延迟的大小来控制速度，但是后来发现时间延迟稍微加大一点点，整个下雨的画面就十分卡顿了，所以放弃了这种方案，改为使用雨滴每次下落的垂直距离作为雨滴的速度，这样在不影响绘图性能的情况下可以实现雨滴的速度控制的效果

(2)**风向问题**：加入风的效果的时候遇到了很多问题，主要是和雨滴下落速度的协调上。在计算雨滴的下个位置时，一开始使用的算法效果不佳，出现了雨滴斜着下落，但是雨滴线的方向垂直指向地面的现象，后来在纸上仔细研究了位置计算算法，才改良出现在的效果。

(3)**线程问题**：因为考虑到用户体验方面，每次启动程序时输入参数来使用十分不方便，因此想要实现在运行过程中动态修改参数的效果，这个功能引出一个问题，需要引入多线程编程，同时还要处理线程并发的问题，这里面耗费了我大量的时间，尝试了自己手写线程锁等等操作，仍然没有解决少数情况下的访问冲突问题，后来改为了异步增删的结构才得以解决。

(4)**闪电问题**：早期加入闪电的功能时，参考了网上流传的方案，生成一组点来绘制一个封闭的闪电图形，然后填充黄色。后来觉得这种效果太普通，没有模拟到现实中闪电的效果，于是想要改进。为此我下载了几组打雷的照片，获取到其中闪电的RGB值，并且根据实际闪电的形状，设计了一个随机模拟闪电路径的算法，随机生成一组点，然后使用不封闭连线的方式绘图，闪电停留时间改短，效果大大提高。

#### 2.经验和体会

(1)**耐心和细心**：做课设的过程中遇到很多问题，即使即使使图形库也是从使用turboC上面的graphics.h再到使用移植版的easyX来实现，在存储结构上，一开始使用的使队列的结构，后来发现队列无法满足随机删除一些已经落水的雨滴，所以改成了链表的结构，还有多线程问题的处理，风向的处理，键盘事件的监听，闪电的绘制等等过程都耗费了不少精力，debug的过程更是非常消磨我的耐心，有时候找一个指针异常就会花费一两个小时的时间，和自己平时惯用的Java语言相比，C语言开发确实非常容易出错，尤其是在指针上面，并且C语言排错的难度也比Java语言高很多。所以这个课设让我再一次体会到耐心和细心的重要性。

(2)**高要求**：按照课设的要求，可以在网上找到一些现成的代码，我也很大程度上参考了网上的思路，但是总会对效果提出更高的要求，不断改进，很大程度上重构了代码，实现效果的提升。所以这次课设让我体会到高标准严要求的重要性。

## :star:License

本软件仅供交流学习，不得用于商业用途

Copyright 黄钰朝 

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

```
   http://www.apache.org/licenses/LICENSE-2.0
```

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.