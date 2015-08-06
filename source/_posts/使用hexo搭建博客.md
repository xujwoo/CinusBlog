title: 使用hexo搭建博客
date: 2015-08-03 22:59:25
tags: 
- hexo
- Linux
- 架站
categories:
- 技术

---

在网上参考了一些使用hexo来搭建博客的文章，大部分是托管在github page上的，但是我本身有一台vps，所以我打算将blog搭建在自己的vps上，其它人说搭建在vps上有什么什么好处我也没想.  
我想的是：既然有为什么不用呢？而且我将专注于hexo在本机的配置和在vps上的部署，vps的域名购买和dns设置这里都不会涉及。  
现在就记录一下我的搭建的过程，我走了许多弯路，最后选择了一下做法。

# 整体思路
在本机使用hexo生成网站，使用git hook 推送到vps上，直接使用nginx来部署网站。
这个做法避免了在vps上安装nodejs和hexo(vps 性能堪忧)，至于缺点，暂时没找到...

# 本机配置（linux）

详细使用请访问[hexo](https://hexo.io/zh-cn/)

## 安装[node.js](https://nodejs.org/)

### For ArchLinus:

	$ sudo pacman -S npm nodejs
### For Debian:

	$ sudo apt-get install nodejs
## 安装hexo

	$ npm install hexo-cli -g
	$ mkdir blog #创建一个目录作为博客的目录
	$ cd blog
	$ hexo init  #使用hexo初始化该目录
	$ npm install #安装必要的依赖
此时的hexo算是安装好了，你也可以按照下面的方法来测试一下：

	$ cd blog
	$ hexo g
	$ hexo s
接下来在浏览器中输入[localhost:4000](http://localhost:4000)看看你博客的雏形:)
## 本机git配置
### git安装
使用git的前置条件是安装了git，可以使用这个命令看看你有没有安装git

	$ git version
如果输出git的版本信息，表示git是安装了的。如果出现：

	git：command not found
表示git未安装，你需要安装git：

#### For ArchLinux

	$ sudo pacman -S git
#### For Debian

	$ sudo apt-get install git-core
#### For Centos

	$ sudo yum install git-core
再次执行:

	$ git version
看到版本信息就ok了。
### git简单配置
设置用户名：

	$ git config --globle user.name YourGitName
设置用户邮箱:

	$ git config --globle user.email YourEmail
基本配置完成，可以使用:

	$ git config --list
查看配置信息。
### 使用git来控制blog版本

	$ cd ~/blog
	$ git init
	$ git add .
	$ git commit -m "Initial commit"
### 为该blog仓库设置远程仓库
在设置vps后进行配置。
# vps配置
ssh 设置啊，登录操作啊这些就不说了，默认大家知道这些基本操作的，或者以后专门写写。

vps的配置主要有两个方面：

- nginx配置
- git配置

都非常的简单。
## nginx配置
### nginx安装
#### For Debian：

    $ sudo apt-get install nginx
#### For Centos：

    $ sudo yum install nginx
### nginx配置
#### 将nginx的根目录改为/var/www/html/public

    $ vim /etc/nginx/sites-available/default
将

    root /var/www/html;
改为

    root /var/www/html/public;
我没有做更多的设置，以后有配置上的改动，我将补上来。
#### 启动nginx
注意：我的vps使用的是systemd，以下两个操作都是在systemd系统上才有效。

    $ sudo systemctl start nginx
#### 设置nginx开机启动

    $ sudo systemctl enable nginx

## git设置
### git安装
前置条件是安装了git，可以使用这个命令看看你有没有安装git

	$ git version
如果输出git的版本信息，表示git是安装了的。如果出现：

	git：command not found
表示git未安装，你需要安装git：
#### For ArchLinus

	$ sudo pacman -S git
#### For Debian 

	$ sudo apt-get install git-core
#### For Centos

	$ sudo yum install git-core
接下来是配置git hook，git hook 的使用我还不是太熟悉，但是按照这个步骤下来是没有问题的。
### git hook 设置
在本地创建一个目录，用于同步仓库。

    # cd ~
    # mkdir -p repos/Cinus.me.git && cd repos/Cinus.me.git //Cinus.me替换成你想要的名称
    # git init --bare
    # cd hooks
    # touch post-receive
    # vim post-receive
输入一下内容:

```bash
#!/bin/bash -l
GIT_REPO=$HOME/repos/Cinus.me.git
TMP_GIT_CLONE=$HOME/tmp/git/Cinus.me
PUBLIC_WWW=/var/www/html/public

rm -rf ${TMP_GIT_CLONE}
git clone $GIT_REPO $TMP_GIT_CLONE
rm -rf ${PUBLIC_WWW}/*
cp -rf ${TMP_GIT_CLONE}/public ${PUBLIC_WWW}
exit
```
保存退出，为post-receive添加执行权限

    # chmod u+x post-receive
# 本机配置
接上面本机配置最后，为本地blog仓库设置远程仓库到vps

    $ git remote add Cinus.me ssh://root@YourVpsIp:YourSSHPort/root/repos/Cinus.me.git
    $ git push Cinus.me master
此时使用域名或ip访问你的vps应该就能看到你的blog的雏形了。
# 后话 
我采用的方式是在本地写好博客，使用hexo g生成网站文件，然后把整个项目push到vps上，vps上的git hooks 在运行post-receive这个脚本将public目录下的文件复制到/var/www/html/public下，也就是nginx的根目录。
现在还有图片等资源未规划，以上的post-receive脚本可能需要更改。
有什么问题或本博客有错误的地方欢迎与我联系
<xyCinus@gmail.com>
