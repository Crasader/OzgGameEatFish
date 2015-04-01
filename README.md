OzgGame—大鱼吃小鱼

================

本游戏主要用于技术的研究和积累，游戏中所用的图片和声音文件均来自互联网

================

编译前需要把cocos2d-x的文件复制到OzgGameEatFish/cocos2d里面，或新建一个游戏项目然后将cocos2d文件夹复制到本游戏的对应目录，也可以使用 https://github.com/ouzhigang/OzgTools/blob/master/2dx_v3_proj_helper.py 来进行（使用前需要将本游戏的cocos2d文件夹删除，否则会报错）

================

win32平台使用vs2013。编译前需要在vs里面将libui项目以下的文件删除：UIWidgets/UIWebViewImpl-win32.h、UIWidgets/UIWebViewImpl-win32.cpp、UIWidgets/UIEditBox/UIEditBoxImplWin.h、UIWidgets/UIEditBox/UIEditBoxImplWin.cpp、UIWidgets/UIEditBox/Win32InputBox.h、UIWidgets/UIEditBox/Win32InputBox.cpp。在UIWidgets/UIEditBox下面添加UIEditBoxImpl-win32.h和UIEditBoxImpl-win32.cpp。Classes文件夹下的所有文件转换为GBK编码，把Resources目录下的所有文件复制到exe主程序的位置。

ios、mac平台使用xcode6.1

android平台直接在OzgGameEatFish目录下执行cocos compile -p android -j 4，真机可运行

linux平台直接在OzgGameEatFish目录下执行cocos compile -p linux -j 4，ubuntu测试通过

================

本游戏的cocos2d-iphone版本：https://github.com/ouzhigang/ozggame_eat_fish

本游戏的cocos2d-js版本：https://github.com/ouzhigang/OzgGameEatFishJS

本游戏的swift版本：https://github.com/ouzhigang/OzgGameEatFishSwift

================

运行状况：

![](https://raw.github.com/ouzhigang/OzgGameEatFish/master/screenshot.jpg)
