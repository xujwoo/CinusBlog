title: oh-my-zsh插件
tags:
  - zsh
  - plugins
categories:
  - Tech
date: 2016-01-04 11:18:29

---
## Zsh
宇宙神器:[Z Shell](http://www.zsh.org)
配合[Oh-My-Zsh](http://ohmyz.sh)食用风味更佳呦
接下来就是介绍几款插件，来提供我们的工作效率啦。
 
## Zsh-syntax-highlighting
推荐一款zsh的插件：[zsh-syntax-highlighting](https://github.com/zsh-users/zsh-syntax-highlighting),安装该插件后，在zsh里面输入正确的命令将有绿色高亮该命令，如果命令输入错误，那么该命令将被高亮为红色，也算是能提高我们输入命令的效率把，不用等到输入了回车才发现命令输入不正确。
<!--more-->
![效果图](http://7xl4y6.com1.z0.glb.clouddn.com/cinus.me%2Foh-my-zsh-pluginsScreenshot%20from%202016-01-04%2011-05-24.png)
### Quick start 
详细文档见[Install.md](https://github.com/zsh-users/zsh-syntax-highlighting/blob/master/INSTALL.md)
#### With oh-my-zsh
1. 克隆插件到oh-my-zsh的插件目录下
```
git clone git://github.com/zsh-users/zsh-syntax-highlighting.git ~/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting
```
2. 在`~/.zshrc`里面启用该插件
```
echo 'plugins=(zsh-syntax-highlighting)' >> ~/.zshrc
```
3. 重新加载`~/.zshrc`配置文件，使配置生效
```
source ~/.zshrc
```
注意：`zsh-syntax-highlighting`插件必须要是最后一个加载的插件，所以请把它放到plugins列表的最后一个。
#### Without oh-my-zsh
1. 将插件目录克隆下来
```
git clone git://github.com/zsh-users/zsh-syntax-highlighting.git
```
2. 将插件脚本写入`.zshrc`中
```
echo "source ${(q-)PWD}/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh" >> ~/.zshrc
```
3. 重新加载`.zshrc`使配置生效
```
source ~/.zshrc
```

## Autojump

