title: ThoughtWorks Lecture Room
date: 2015-10-17 13:18:24
tags:
- linux
- ThoughtWorks
- note
categories:
- Tech
toc: true

---
## 第一课Linux基础
讲师:颜王
推荐一个网站[<鸟哥的linux私房菜>](http://vbird.dic.ksu.edu.tw/linux_basic/linux_basic.php),也可以买这本书.
再推荐一个网站[linux command line](http://billie66.github.io/TLCL/book/)
### What is Linux
参考这个:[linux是什么](http://vbird.dic.ksu.edu.tw/linux_basic/0110whatislinux.php),需要说明的几点是:
* linux只是一个操作系统内核,与其他[GNU](http://www.gnu.org/)组织开发的工具组合在一起组成GNU/Linux操作系统.
* 自从使用git来管理linux内核的代码以后,不再使用奇偶数来标识内核的稳定版和开发板.
* linux 是宏内核,linux大部分设备驱动是写在内核里面的,linux提供了以内核模块的方式插入驱动程序.

<!--more-->
### Basic Shell command
1. pwd: print working directory, 打印出当前工作目录.
2. ls : list 列出内容 
 + -a --all 包含隐藏文件/目录(.开头)
 + -l --long 以长格式列出文件/目录信息.就是列出文件类型,权限,所属用户所属组等这些东西
 + -F --classify 使用(\*/=\>@|)来标识文件或目录类型.\*表示可执行文件,/表示目录,@表示链接文件,|表示管道文件,=表示套接字文件,\>代表什么我还真不知道,木有见过额......
3. cd : change directory 切换目录.
 + 绝对路径:从根出发到达某一目录/文件的路径.
 + 相对路径:从当前路径出发到达某一目录/文件的路径
 + . : 当前目录
 + ..:上一层目录
4. mkdir: make directory 创建目录
 + -p --parent: 创建目录时创建丢失的父目录,也就是可以创建多层目录
5. rmdir: remove **empty** directories 删除**空**目录
6. cp: copy 复制
 + -r --recursive : 递归复制,复制目录必须加上-r选项.
 + -a : 复制所有属性,包括所有者,所属组及其权限.在使用cp备份文件时用的多.
7. rm: remove 删除文件/目录
 + -r :递归删除,删除目录时必须使用该选项. 
 + -f :忽略不存在的文件或者参数,即使你的参数错误也不给出错误提示.常常用于强制删除,不给出提示.
8. mv: move and rename file or directories 
 + -u --update:只有当源文件比目标文件更新或者目标文件本来就不存在时在执行mv,常用与备份.
9. touch : use to create a file or change the timestamp of file ,实际上该命令是用来更改文件的时间戳的.但是默认情况下如果文件不存在则会新建一个文件.
 + 一个文件有三个时间戳,这里不深究先.
10. cat : 连接文件,并将文件内容打印出来.
 + 常用于将文本文件内容输出在标准输出.例如:`cat /etc/passwd`
 + 不带参数时会从标准输入读取,然后输出到标准输出.
 + 可以使用`here-document(<<)`,不深究先
11. tac : 逆向输出文件.可以看到,这个命令是cat的逆转
12. head/tail: 查看文件头/末尾几行
 + -{NUM} 输出头/末尾NUM行
 + tail -F :如果有进程在写入该文件,那么将实时的显示进程写入的内容.一般用于日志查看. 
13. less/more: 用于滚动查看文件内容.
 + less可上下滚动,且支持vim的上下滚动方式(hjkl)而且支持vim的模式匹配(/),所以使用less就够了.
14. wc: word count 计算文本的行数,单词数,字符数.
 + -l --line 计算行数.
 + -w --word 计算单词数.关于颜王哥在课堂上说的为什么/etc/passwd文件的单词数只有六十几个的答案是:默认判断单词的分割符是空格,而该文件用:作为字段分割符.验证方法是,将空格换成回车,然后计算行数.
 + -c/-m 计算字符数.
15. find: 查找文件.这个命令非常强大,但是我并不怎么常用...缺点:遍历硬盘查找,慢.
 + -name {filename} 按名称查找文件.
 + -type {bcdpflsD} 按文件类型查找.
16. locate 在数据库中查找文件或目录.这个我常用.缺点:当有新文件加入时,数据库更新不及时可能需要手动更新数据库:`sudo updatedb`
 + 有些发行版默认情况下没有安装该包,如果该命令不存在请安装mlocate包.
17. file 查看文件类型:ASCII文本?可执行程序?
18. type 查看命令类型:shell内建命令?命令别名?
19. **man** 查看命令详细文档

### 管道及重定向
文件描述符中0,1,2已经被定义,分别为:标准输入,标准输出,标准错误输出.
1. (未命名)管道`|`,用于把上一个命令的输出作为下一个命令的输入.
例如:`cat /etc/passwd | awk -F':' '{print $1" "$2}'`,这个例子中把cat命令的输出作为后一条命令awk的输入.最后是打印了/etc/passwd文件中第一个和第二个字段的内容.
2. `>` 标准输出重定向(覆盖模式)
例如:`ls > file`将ls命令的输出输出到文件file中,如果再次执行`free > file` 那么将覆盖前面的内容.
3. `>>` 标准输出重定向(追加模式)
例如:`free >> file2`会把free命令的内容输出到文件file2中,如果继续执行`cat /proc/meminfo >> file2`那么将在文件的后面追加cat命令输出的内容.
4. `2>` 标准错误输出重定向(覆盖模式)
例如:`find / -name gnome 2> /dev/null`将把find命令输出的错误信息重定向到/dev/null(输出黑洞)中.
5. `2>>` 标准错误输出重定向(追加模式)
例如:`find / -name awesome 2>> fileerr`将把find命令输出的错误信息重定向到fileerr后面.
6. `<` 输入重定向
7. `<<` here-document,上面有提及.
记忆方法: 两个括号的是追加模式,加上2(2是标准错误输出的文件描述符)的是标准错误输出的重定向.here-document 可以先不了解.

### network manager:
1. ping : 向目标主机发送icmp包.测试网络状况.参数可以是ip地址,也可以是域名
例如:`ping www.baidu.com`
2. telnet: 一个远古时期用来访问远程机器的工具.不够安全.参数是ip地址加端口号.
例如:`telnet www.baidu.com 80`也可以用该命令登录ftp服务器等.
3. wget: 命令行下载工具.支持断电续传.
例如:`wget cinus.me`就能下载我博客的首页文件.该命令能下载整个站点文件并转换成本地链接,详细使用请参考我另一篇博客.
4. curl: 命令行下的上传和下载工具.支持很多种协议.
例如:`curl -X GET 10.129.100.142:8080/hobbies/`这是上课时的用例,现在没法用.
5. ssh: 远程登录程序.较telnet安全不少,登录远程机器推荐使用ssh
例如:`ssh cxy@10.112.222.12`来用cxy用户登录主机xxx.xxx.xxx.xxx.前面的ip是没有意义的.
6. scp: 基于ssh的文件传输工具.用来远程文件传输
例如:`scp -P 22 cxy@10.11.23.123:/home/cxy/hello ./`会把远程主机xxx.xxx.xxx.xxx下的/home/cxy/hello 文件发送到本机当前目录.
`scp -P 22 ./hello cxy@10.11.23.123:/home/cxy/`将把本机文件复制到远程主机.当然,源和目标都可以是远程主机.就不写实例了.. 
7. netstat:查看网络状态工具.现在使用`ss`更多.
8. lsof:列出打开的文件.可以用来看套接字文件是否打开.

### 文本处理
1. grep :用于查找匹配正则表达式的文件内容.
 + -i --ignore: 忽略大小写的区别.
 + -n :打印出行号
 + -r :在目录中递归查找
2. awk: awk可以执行一段awk程序来处理文本,这段程序可以直接用''包含写在命令后面,也可以写入文件,然后指定该程序文件.所以可以将其理解为一个脚本语言解释器,该命令相当强大,这里不会深挖.
 + 命令格式:`awk '条件类型1{动作1} 条件类型2{动作2} ...' filename`
 + `awk -F':' '{print $1" "$2}' /etc/passwd` 该命令执行了''中的程序:打印出第一和第二个字段.前面的-F是指定分割符为":",因为/etc/passwd文件中的字段分割符为":".
3. sed: stream editor(流编辑器).一般为一行一行处理文本,也可以读入多行一起处理.sed实际也是执行一段脚本.
```
     [cxy@ThinkPad ~]# sed [-nefr] [动作]
     选项与参数：
     -n  ：使用安静(silent)模式。在一般 sed 的用法中，所有来自 STDIN 
     的数据一般都会被列出到萤幕上。但如果加上 -n 参数后，则只有经过
     sed 特殊处理的那一行(或者动作)才会被列出来。
     -e  ：直接在命令列模式上进行 sed 的动作编辑；
     -f  ：直接将 sed 的动作写在一个文件内， -f filename 则可以运行 filename 内的 
     sed 动作；
     -r  ：sed 的动作支持的是延伸型正规表示法的语法。(默认是基础正规表示法语法)
     -i  ：直接修改读取的文件内容，而不是由萤幕输出。

     动作说明：  [n1[,n2]]function
     n1, n2 ：不见得会存在，一般代表『选择进行动作的行数』，举例来说，如果我的动作
     是需要在 10 到 20 行之间进行的，则『 10,20[动作行为] 』

     function 有底下这些咚咚：
     a   ：新增， a 的后面可以接字串，而这些字串会在新的一行出现(目前的下一行)～
     c   ：取代， c 的后面可以接字串，这些字串可以取代 n1,n2 之间的行！
     d   ：删除，因为是删除啊，所以 d 后面通常不接任何咚咚；
     i   ：插入， i 的后面可以接字串，而这些字串会在新的一行出现(目前的上一行)；
     p   ：列印，亦即将某个选择的数据印出。通常 p 会与参数 sed -n 一起运行～
     s   ：取代，可以直接进行取代的工作哩！通常这个 s 的动作可以搭配
     正规表示法！例如 1,20s/old/new/g 就是啦！
```
例如:`sed 's/root/cxy/g' /etc/passwd` 将/etc/passwd文件中的root替换为cxy,注意:这里不是改变文件内容,只是将处理后的文本内容输出在标准输出上,如果想直接修改文本需要加上参数-i,此时得注意你有写该文件的权限.

### 系统管理
1. sudo: 临时切换用户(组)来执行命令.有些同学的账户不能使用sudo命令,因为没有被授权.最简单的一个方法是:
执行`visudo`找到`root    ALL=(ALL:ALL) ALL`在下一行加上`{your UserName}     ALL=(ALL:ALL) ALL`,保存退出.如果输入有错误那么将会报错,如果成功退出,表示修改成功
用法:`sudo command`接下来你需要输入当前用户名的密码,成功后将使用root用户来运行command,在未来5分钟以内执行sudo你将不需要输入密码.该时间可以在配置文件中修改.
3. dpkg: Debian系列的包管理器,一般用于自己下载.deb包的安装,和查看本地安装了哪些包
 + -i --install: 安装一个安装包.
 + -r --remove: 移除一个安装包.
2. apt: Debian系列的包管理器,包装可dpkg相对较高级,可以自动解决依赖问题.
 + update: 更新源信息`sudo apt update`
 + upgrade: 更新本地包`sudo apt upgrade`
 + search: 查找某包: `apt search mlocate`
 + install: 安装一个包`sudo apt install mlocate`
 + remove: 删除一个包 `sudo apt remove mlocate`
4. aptitude: Debian系列更高级的包管理器.命令参数参考apt
5. pacman: ArchLinux包管理器
6. yum: 红帽系列包管理器
7. DNF: 红帽公司打算用来替换yum的包管理器.

### Basic vim usage
vim 需要讲的东西太多,这么短的篇幅来讲vim感觉很无力.也许你看着这些操作没有什么规律,但是如果你继续往深入学习下去你会发现,一切都是那么合情合理,设计优美
+ 光标移动:`hjkl`
+ 光标跳到文件头:`gg`
+ 光标跳到文件末尾:`G`
+ 光标跳到行首:`0`,光标跳到行尾:`$`
+ 在光标上一行插入文本:`O`,下一行插入文本`o` 普通模式 -/> 插入模式
+ 在当前位置进行插入:`i`,在行首进行插入:`I` 普通模式 -/> 插入模式
+ 在当前闻之进行追加:`a`,在行尾进行追加:`A` 普通模式 -/> 插入模式
+ 删除一行:`dd`
+ 撤销上一个修改:`u`
+ 重复上一次修改:`.`
+ 撤销上一个撤销:`<Ctrl-r>`
+ 复制一行:`yy`
+ 以单词为基本单位移动光标:`w`/`e`/`b` -/> 向后跳一个单词(光标在单纯首字母)/向后跳一个单词(光标在单词尾字母)/向前跳一个单词
+ 在一行上进行查找:`f`/`F`. `f`:从当前位置向行尾查找某字符 , `F`:从当前位置向行首查找某字符
+ 重复f/F操作:`;`正向重复,`,`反向重复
+ 在文本中查找光标下的单词:`#`,使用`n`和`N`来正反向查找. 
+ 匹配括号:`%`
+ 缩进:
    - 自动缩进:`=`
    - 增加一个缩进等级:`>`
    - 减小一个缩进等级:`<`
+ `v`:普通模式和可视模式的开关. 	 普通模式 <-> 可视模式
+ `V`:普通模式和行可视模式的开关.	 普通模式 <-> 行可视模式
+ `<C-v>`:普通模式和块可是模式的开关.	 普通模式 <-> 行可视模式
+ `:wq`保存退出,怕大家不不知道...T_T
+ `:q!`强制退出,不保存
+ `:h [keyword]`调出帮助文档

### 建议
+ vim 入门:[鸟哥](http://vbird.dic.ksu.edu.tw/linux_basic/0310vi.php)
+ 不会的命令问`man command`
+ 多用

有什么遗漏再来补充吧.

## 第二课GIT
讲师:赵梦茹,邢砚敏
### git简介
git,一种分布式版本控制系统,linus对该名字的定义是'The stupid content tracker',但是我更加喜欢这个解释:'Global Information Tracker'. 关于git项目的发起也有一段故事在里面,感兴趣的同学自己去google
### 分布式与集中式比较
* 集中式
    :集中式版本控制系统有一个主服务器,所有历史版本都存放在主服务器上,本机不存放历史提交,所以在本机工作时对网络依赖严重,每次commit或者请求最新/历史版本都得访问服务器.如果主服务器宕机或者与主服务器的网络不通,那么开发工作将无法继续下去.如果主服务器数据丢失那么历史版本将也就此消失.
* 分布式
    :分布式版本控制系统可以不存在主服务器,每一个节点都是一个完整的版本库,包含所有的历史版本,可以在本地版本库内做任何操作,分布式也可以有类似于主服务器的Hub,像github和gitcafe,也可以自己搭建私有的Hub.采用分布式版本控制,即使Hub宕机,你依然可以在本地进行开发提交更新,即使Hub的数据丢失,也可以通过某一个节点的本地仓库来恢复数据.

### git 基本使用
* **git init [Dir]** : 在Dir目录下初始化一个仓库(会在[Dir]中生成一个.git目录,用来存放版本控制数据)
* **git config** : 用来配置版本库的命令,可以直接输入git config 来查看简单的帮助
    + `git config [--global|--system] user.email <YourEmail>`
    + `git config [--global|--system] user.name <YourName>`
    + `git config [--global|--system] core.editor <nano|vim|emacs>`
    + --global,--system的区别:主要的区别是作用范围,--global是对一个用户来说的全局,配置加上该参数将把配置写入用户的配置文件:`~/.gitconfig`中.而--system是针对整个系统的全局设置,加上该参数以后将会把配置写入系统的配置文件:`/etc/gitconfig`中,而两个都不加的话则是针对一个repo的,该配置只在该repo中有效,配置将写入:`<Path/to/Repo>/.git/gitconfig`中.其实手动将配置写入以上文件的效果是一样的.关于linux中配置文件的优先级是:个人配置>系统配置,小范围配置>大范围配置,这是怎么来的呢?首先很多人以为系统会做一个判断,如果小范围配置文件存在,那么只执行小范围的配置文件,其实不是这样的,实际是从大范围的配置文件开始执行,执行完毕后执行小范围的配置文件,比如先执行系统配置,再执行个人配置.这样如果小范围(个人)配置与系统配置的值有差异,那么后执行的配置的值将会覆盖先执行的配置的值.比如系统配置执行完毕后email的值是该系统管理员的email,但是我现在是以cxy的身份登录,进入shell后执行了我自己的配置文件,我的配置文件里面有一条就是将email设置为我自己email,那么我的配置文件执行完毕以后,系统管理员的email的配置也将被我覆盖.
* **git add** 将未追踪/修改/删除的文件状态加入索引区
    + git有三个区域:工作目录,暂存区,git仓库.工作目录是你当前工作的地方,你可以检出任何一个历史版本到你的工作目录进行开发.暂存区是你执行git add 以后,文件'所在'的地方/状态,下次提交将把暂存区的内容提交到版本库中.git仓库是该项目所有历史版本存放的地方.
    + 文件在三个'区域'/状态的转换:
        - 将工作目录文件添加到暂存区域:git add [filename] 
        - 将暂存区域/git仓库的文件恢复到工作目录:git checkout [提交指纹] [filename]
        - 将暂存区域的文件提交到git仓库:git commit 
        - 使用git仓库中的某个提交来替代暂存区文件:git reset 
* **git status** 查看当前版本库文件的状态/整个版本库的状态
* **git checkout** 1.用于检出文件. 2.用于检出分支
    + git checkout [-b] [branch] 检出到branch分支,加上-b参数:如果不存在branch分支,将新建一个分支命名为branch并检出之.
    + git checkout -- [file] 从暂存区检出文件(丢弃工作区的改动)
    + git checkout [提交指纹] [file] 中某个提交中检出文件到工作目录中(丢弃工作目录的改动)
* **git branch** 查看/新建分支
    + git branch 查看有那些分支.当前分支用`*`标识.
    + git branch [name] 新建一个分支,命名为name
    + git show-branch 将包含更多提交与分支的关系信息.
* **git merge** 合并分支
    + git merge [branch] 将branch和当前分支进行合并,可能需要手动解决冲突.有3种合并策略.
* **git rebase** 用来改变一串提交的基础.
    + git rebase [branch] 将当前分支与branch的共同父节点变到branch的头上(将branch上从共同父节点开始的提交的补丁一个一个打到当前分支的每一个提交上),可能需要手动解决冲突.在多人协作开发时,从远端仓库上pull别人的提交时用的很多.
* **git pull** 从远端仓库拉取最新提交,并且在本地仓库中进行合并/变基
    + `git pull [--rebase] origin master`从origin远端仓库中拉取master分支上的新提交,并且与本地仓库中master分支进行合并/变基(取决与是否家--rebase).
* **git push** 推送本地提交到远端仓库
    + `git push origin master` push本地的master分支上的新提交到origin上去.注意:本地仓库的需要推送的分支必须包含origin上所有的历史,不然推送将失败,你需要先pull下你没有的历史提交,合并/变基以后在进行push.
* **git commit** 体检暂存区域的内容到git仓库中
* **git diff** 比较文件差异
    + 工作目录中的文件和暂存区文件的差异比较:git diff 
    + 暂存区文件与git仓库中最新提交中文件差异比较:git diff --cached
    + 比较任意两个文件:git diff [版本指纹1]:[filename1] [版本指纹2]:[filename2]
* **git clone** 拷贝一个'远程'版本库
    + git clone [URL]
* **git log** 查看历史提交
    + `git log --oneline --graph` --oneline:一个提交显示为一行, --graph :图形方式显示出分支关系等
* **git reset** 重置工作目录/暂存区,详情请参考我的另一篇[博客](/Git-Change_your_commit/)
* **git rm** 删除工作目录下的文件/目录
    + 实际相当于命令`rm`和`git add`的组合
    + 这个remove并不是删除版本库里面的东西,git仓库里面的东西理论上是不能被改变的(ReadOnly).这个命令只是删除工作目录下的文件/目录.

### 使用git进行协作
当你需要推送你的更新到远程的版本库的时候你必须保证,远程版本库的历史提交是你本地历史提交的子集,也就是说远程版本库有的历史,你本地必须全部有,不然你需要先把远程的提交拉下来然后rebase/merge后再进行push.就像课上老师说的实例,小G同学推送了自己的更新到远程版本库中,而现在ellmi同学也要把自己的更新push到远程版本库中,但是ta执行了`git push `以后,git告诉ta你有一些提交需要先pull下来后才能push,于是ellmi同学就把小G的推送pull下来,在本地做了一个merge,现在远程版本库里面有的提交在ellmi的本地仓库中也有了,那么ellmi可以做一次push了.于是ellmi将本地的修改push到远程版本库中了.那么如果现在小G又做了一次修改并提交了,小G想把新的提交push到远端服务器呢?那么ta也得先把ellmi推送上去的提交先pull下来,做一次rebase/merge,然后在push上去.
### 推荐书籍/网站
[Pro git 2](http://7xl4y6.com1.z0.glb.clouddn.com/Pro%20Git中文版.pdf)
[猴子都能懂的GIT入门](http://backlogtool.com/git-guide/cn/)
[Git 版本控制管理](http://www.amazon.cn/gp/product/B00U42VM7Y?keywords=git%E7%89%88%E6%9C%AC%E6%8E%A7%E5%88%B6%E7%AE%A1%E7%90%86)
