title: 使用hexo搭建博客(vps/github)
date: 2015-08-03 22:59:25
tags: 
- hexo
- Linux
- git
categories:
- 博客
---
*[2015/8/10 UPDATE:增加在github.io上的部署,修改推送到vps的方式]*  
在网上参考了一些使用hexo来搭建博客的文章，大部分是托管在github page上的，但是我本身有一台vps，所以我打算将blog搭建在自己的vps上，其它人说搭建在vps上有什么什么好处我也没想.  
我想的是：既然有为什么不用呢？而且我将专注于hexo在本机的配置和在vps(github.io)上的部署，vps的域名购买和dns设置这里都不会涉及。  
现在就记录一下我的搭建的过程，我走了许多弯路，最后选择了一下做法。

# **整体思路**
在本机使用hexo生成网站，使用git hook 推送到vps上，直接使用nginx来部署网站。
这个做法避免了在vps上安装nodejs和hexo(vps 性能堪忧)，至于缺点，暂时没找到...

# **本机配置（linux）**

想了解hexo的详情请访问[hexo](https://hexo.io/zh-cn/)

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
### 使用git来管理blog/public的版本

        $ cd ~/blog/public
        $ git init 
        $ git add .
        $ git commit -m "我的博客的雏形"
#### 为blog/public设置远程仓库(github.io&vps)
将在下面vps配置后介绍
### 使用git来管理blog版本

	$ cd ~/blog
	$ git init
#### 在该版本库中除去public目录
此处的目的是把用于博客展示的文件和生成博客的文件分开来管理.在用于博客展示的public目录中单独创建一个版本库，方便推送到vps和github.io上，而用于生成博客的文件使用独立的仓库进行管理。

        $ cd ~/blog
        $ touch .gitignore
        $ echo "public/" >> .gitignore
其实默认情况下，hexo 创建了.gitignore并且将public包含在里面的。但是如果没有，请手动操作上一步。  
接下来是创建初始提交：

	$ git add .
	$ git commit -m "Initial commit"
#### 为该blog仓库设置远程仓库(github)
```
        $ git remote add origin YourGithubReposAddress
```
以后博客有提交需要push到github上保持下来，就可以执行命令

        $ git push origin master
# **vps配置**
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
接下来是配置git hook
### git hook 设置
在本地创建一个目录，用于同步仓库。

    # cd ~
    # mkdir -p repos/Cinus.me.git && cd repos/Cinus.me.git //Cinus.me替换成你想要的名称
    # git init --bare
    # cd hooks
    # touch post-receive
    # vim post-receive
输入以下内容:
```
 #!/bin/bash -l
GIT_REPO=$HOME/repos/Cinus.me.git
PUBLIC_WWW=/var/www/html/public
 #push to github.io
git push github.io master

rm -rf $PUBLIC_WWW
git clone $GIT_REPO $PUBLIC_WWW
rm -rf $PUBLIC_WWW/.git
exit
```
保存退出，为`post-receive`添加执行权限

    # chmod u+x post-receive
# **github设置**
在你的github帐号中创建一个仓库，使用YourName.github.io命名，仓库设置为公开。
详细设置请访问[GithubPage](https://pages.github.com/)
# **本机配置**
接上面本机配置最后，为本地blog/public仓库设置远程仓库到vps

    $ cd ~/blog/public
    $ git remote add Cinus.me ssh://root@YourVpsIp:YourSSHPort/root/repos/Cinus.me.git
    $ git push Cinus.me master
此时使用域名或ip访问你的vps应该就能看到你的blog的雏形了。
设置远程仓库到github.io

    $ git remote add github.io YourGithubIoReposAddress
    $ git push github.io master
输入`https://YourGitHubUserName.github.io`就能看到你博客了。
## 更方便的方法
在vps的git hook端设置推送到github.io上去。在推送到vps以后，直接有脚本推送到github.io上去了，就不用手动进行了。
此处涉及到ssh无密登录等，我再慢慢更新吧。我现在就是采用这样一种做法。
# **后话** 
我采用的方式是在本地写好博客，使用`$ hexo g`生成站点文件，然后把public这个目录的版本库push到vps上，vps上的git hooks 在运行post-receive这个脚本将该git仓库push到/var/www/html/public这个仓库和github的github.io仓库中,这样就在vps和githubpage上完成了部署了。这里vps向github仓库推送需要设置该主机向github的公钥认证，也就是将vps的公钥提交到github上去。
有什么问题或本博客有错误的地方欢迎与我联系
<xyCinus@gmail.com>
