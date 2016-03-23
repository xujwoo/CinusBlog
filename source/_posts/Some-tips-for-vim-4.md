title: Some Tips for Vim(4)
tags:
  - vim
categories:
  - Tech
  - «Practical Vim»
date: 2016-03-23 10:08:47

---
Vim 小技巧第四篇
<!--more-->
## 相对当前活动文件所在的目录打开文件
标题是不是有点绕？我们来看一个场景,我们有如下目录结构：
```
.
├── 404.html
├── About
│   └── index.md
├── categories
│   └── index.md
├── CNAME
├── _drafts
│   ├── Some-tips-for-vim-4
│   └── Some-tips-for-vim-4.md
├── _posts
│   ├── AddDaemonToSystemd
│   ├── AddDaemonToSystemd.md
│   ├── TheArtOfCommunicate.md
│   ├── TWClass.md
│   └── vim_register.md
├── search
│   └── index.md
└── tags
    └── index.md
```
我现在在当前目录下使用命令`vim _post/vim_register.md`打开了该文件，这个时候我们可以通过`:pwd`命令查看vim的工作目录在哪里，在当前shell目录下，也就是图中的`./`下，如果此时我希望编辑_post目录下的TWClass.md文件，那么我可以使用`:e _post/TWClass.md`来编辑它,但是我们只能通过相对路径来打开它吗？如果路径很长不是很累？虽然有`<TAB>`补全，但是那也得按很多次啊。。。
诶，这就是我们标题的意思了，相对当前活动文件所在的目录来打开文件。`:e %<TAB>`其中的*%*将会被替换成当前文件的完整路径，但这还不是我们想要的，我们想要的是去掉文件名的目录名称。`:e %:h<TAB>`将会去除文件名，其中*:h*修饰符的作用就是去除文件名。 现在如果我们想要打开`./_post/TWClass.md`时，我们只需要键入`:e %:h<TAB>T<TAB>`就可以啦，不必输入完整的路径
## 使用`:find`打开文件
find允许我们通过文件名打开一个文件，而不需要输入一个完整的路径，但是，find怎么知道这个文件在哪里呢？所以我们需要在使用find之前设置一下`path`选项。这里的path和shell中的PATH变量类似，在shell中输入一个命令，shell会在PATH所指定的路径中进行查找该可执行文件，而这里的path是vim所寻找文件名的路径。
设置path的方法`:set path+=[your path]`例如`:set path+=_post/**`表示把_post目录下的所有路径，还记得上节的`**`吗？在path中的双星和前面的双星不太一样，这里的双星代表的是递归目录中的所有目录，而不包括文件，而前面指的是该目录下的所有文件，包括递归目录下的文件，其实用法都差不多，细节上有点区别。 
好了，现在我们把path给设置好了，我们可以来使用find命令了，用法很简单`:find [filename]`就可以啦。只要在path所指定的路径中能找到该文件，那么，就能在vim中进行编辑了。
## 是用netrw来目录
在使用vim的时候，我们有没有给vim命令加参数的时候‘错误’的写了一个目录名称呢？然而vim并没有报错等动作，而是打开了该目录，出现类似这样的一个界面：
```
" ============================================================================                                                                                                                
" Netrw Directory Listing                                        (netrw v149)
"   /home/cxy/blog
"   Sorted by      name
"   Sort sequence: [\/]$,\<core\%(\.\d\+\)\=\>,\.h$,\.c$,\.cpp$,\~\=\*$,*,\.o$,\.obj$,\.info$,\.swp$,\.bak$,\~$
"   Quick Help: <F1>:help  -:go up dir  D:delete  R:rename  s:sort-by  x:exec
" ============================================================================
../
./
.deploy_git/
.git/
node_modules/
public/
scaffolds/
source/
themes/
.gitignore
README.md
_config.yml
db.json
npm-debug.log
package.json
```
这是我们进入了netrw的界面，这也是一个普通的缓冲区,如果你了解过linux下的文件系统（ext系列），你会知道其实目录也是一个文件，只不过它存储了一些特殊的内容，这里不做深究。这个功能由netrw插件提供的，该插件集成到了vim中，所以我们也不需要手动安装它。我们可以通过它来进行文件系统的管理.下面我们来看看，怎样进行文件系统的管理
在这个缓冲区中，和普通文件一样，使用hjkl来移动光标，同样可以使用`/`来搜索文件名，按下`<CR>`将会跳入另一个缓冲区，如果光标所在的位置是一个目录，那么，将跳到该目录下，同样是一个netrw界;如果光标下是一个文件名，那么，vim将在当前缓冲区中打开该文件。
使用`-`可以返回上一级目录，同样的动作可以通过将光标移动到../,然后敲`<CR>`实现
打开文件管理器的方式有几种：
* 直接用`vim [directory name]`来打开目录
* 在vim中使用`:edit [directory name]`打开目录，例如`:e .`或者`:e %:h`
* 使用`:Explore`打开当前目录

除了`:Explore`vim还提供了`:Vexplore`和`:Sexplore`分别对应于垂直分割窗口和水平分割窗口然后显示一个Explore，但是在我的配置上`:Explore`和`Sexplore`效果是一样的。
### vim下工程目录‘最佳’实践
在其他编辑器中是不是在左边有一列被称为工程目录的东西，里面列出了该工程下的目录和文件，然后你需要编辑哪个文件，你就点击进去在右边的窗口中进行编辑。我们也可以使用netrw构造工程目录，但是，这并不是vim下的最佳实践，«Practical vim»中给出了一个比喻，来介绍在vim中怎么样使用netrw是最佳实践：
我们可以将vim的一个缓冲区看成一张扑克牌，它有两面，一面是netrw，一面是文件缓冲区，当我们输入`:Explore`时，扑克牌切换到netrw这一面，然后，我们选择我们需要编辑的文件，键入`<CR>`，这时，扑克牌被翻到了文件这一面，我们可以在这一面进行文件的编辑。最佳实践就是循环往复的翻转这张扑克牌来实现在不同的文件中进行切换.
by the way,可以使用`<C-^>`来在当前缓冲区和轮换缓冲区中进行切换噢，还记得轮换缓冲区的概念吗？去看看上一篇的开头把～

当然，既然把它称为文件管理器，它当然具有一些文件管理器的操作啦，比如`D`删除，`R`重命名等，还可以按照你指定的规则重新排序，欲知更多细节，在netrw中键入`<F1>`查看详细帮助吧。

## 将文件保存到不存在的目录中
有时候我们在使用vim打开文件的时候，在一个不存在的目录下打开了文件，此时，vim是不会出现任何问题的，它会打开一个空白的缓冲区给我们编辑，但是在保存的时候，vim试图去访问那个不存在的目录时就会报错，这个时候就有点麻烦了，我文件的编辑好了，但是不能正确的保存，这不很蛋疼?
此时我们可以分情况使用两种方法来保存我们的文件。
1. 我们的目录写错了。使用`:w [correct path/filename]`保存到正确的文件中，然后安心的退出当前的缓冲区
2. 我的确要写入该目录，但是该目录我忘记创建了。使用外部命令`:!mkdir -P %:h`创建目录，然后写入`:w`

## 使用root权限写入文件(**非常有用！！！**)
很多时候，我们以普通用户的身份打开了一个只读文件（忘记加sudo了)，然后在该缓冲区上进行了修改，当我们需要保存时，vim却告诉我们这是一个read only的文件，缓冲区中修改的内容我没有权限写入文件中，我以前不知道这个方法的时候就只剩下一脸懵逼了。。。采用最傻逼的方法，使用wrte命令写入一个能够读写的文件，然后退出vim，用sudo来执行文件替换。
现在有一个好方法，可以不用那么麻烦。既然当前的vim不让我写入文件，那我就交给一个shell来写好了，而这个shell刚好是用sudo来打开的：
```
:w !sudo tee % > /dev/null
```
其中`:w !{cmd}`会将当前缓冲区的内容当作一个标准输入交给{cmd}而我们在后面使用sudo 运行了一个tee命令，这个tee就相当于在你电话线上搭线监听的一个间谍，从它这里过去的内容，它会往标准输出输出一份，它还会往文件中输入一份，在上条命令中往标准输出的那份被输出到了/dev/null中，这是一个‘黑洞’,输出给它的东西都没了。。。所以你想忽略什么输出，你就把它输出到/dev/null中就好了;而输出到文件中的那一份就被输出到了%文件中，还记得这个%在vim中代表什么吗？就是当前缓冲区所对应的文件的完整路径。
在执行该命令后，vim会和你有两次交互：
1. 提示输入我的sudo密码（请把你的脸转过去），当然，如果你在之前输入过一次sudo密码，那么可能这一步不会出现(看sudo设置）
2. 提示你缓冲区对应的文件有改动，重新载入文件与否，其实此时缓冲区和文件内容是一致的，就选择载入吧