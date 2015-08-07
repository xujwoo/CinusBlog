title: Markdown语法
date: 2015-08-06 20:41:05
tags:
- Markdown
categoried:
- 文档

---
整理一下Markdown的语法，用这玩意儿写blog有点意思。
# **[Markdown介绍](https://zh.wikipedia.org/wiki/Markdown)**
**Markdown**是一种轻量级标记语言,它允许人们“使用易读易写的纯文本格式编写文档，然后转换成有效的XHTML(或者HTML)文档”。
它避免了我直接写html文档。这是我很喜欢的，而且hexo的markdown解释其生成的html其显示效果还是很不错的。
[github](https://github.com)的README支持markdown还有很多写作网站也支持markdown，例如[简书](http://www.jianshu.com/)等。
现在markdown用处非常多，光用来写博客就值得我学习它了。
# **标题**
## 使用**\#**为文章设置多级标题(类[Atx](http://www.aaronsw.com/2002/atx/))
{% codeblock Head_example1.md %}
# 一级标题  
## 二级标题  
### 三级标题
#### 四级标题  
{% endcodeblock %}
依次类推,最多6个#代表6级标题,其效果如下图所示：
{% asset_img 1.png 使用#为文章设置多级标题 %}
## 使用**=**和**-**为文章设置大小标题(类[Setext](http://docutils.sourceforge.net/mirror/setext.html))
利用**=**（最高阶标题）和**-**（第二阶标题）来标识标题：
{% codeblock Head_example2.md %}
This is an H1
=============
this is an H2
-------------
{% endcodeblock %}
任何数量的=和-效果都一样，其效果为：
{% asset_img 2.png 使用=和-为文章设置大小标题 %}
# **分割线**
使用三个以上的**星号**,**减号**,**下划线**来建立分割线，行内不要写其他东西，**星号**或**减号**间可以加入空格。
{% codeblock 分割线example.md %}
*****
_____
-----
* * * * * *
- - - -
{% endcodeblock %}
效果为：
{% asset_img 3.png 分割线示例 %}
# **引用**
## 文字引用
### 使用**>**引用文字
该引用方法是借鉴与email中的引用方式，在需要引用的行或段前加上>可以建立引用区块来引用该行的文字,引用可以嵌套。
```
>hello  
world
>>hello world
```
产生的效果为：
>hello  
world
>>hello world

### 使用hexo插件[Block Quote](https://hexo.io/zh-cn/docs/tag-plugins.html#Block_Quote)
该插件支持插入引言，可包含作者、来源和标题。通用格式为：
```
{% blockquote [author[, source]] [link] [source_link_title] %}
content
{% endblockquote %}
```
示例：
```
{% blockquote David Levithan, Wide Awake %}
Do not just seek happiness for yourself. Seek happiness for all. Through kindness. Through mercy.
{% endblockquote %}
```
效果为：
{% blockquote David Levithan, Wide Awake %}
Do not just seek happiness for yourself. Seek happiness for all. Through kindness. Through mercy.
{% endblockquote %}
### 醒目引文[Pullquote](https://hexo.io/zh-cn/docs/tag-plugins.html#Pull_Quote)
没整明白这是干嘛用的，翻译也好奇怪
```
{% pullquote [class] %}
I'm content in pullquote
Me too.
{% endpullquote %}
```
效果是：
{% pullquote [class] %}
I'm content in pullquote
Me too.
{% endpullquote %}
## 代码引用
作为程序员的博客，怎么能没有代码引用？
### `(反引号)引用一小段代码
在语句中应用一段代码或命令可以使用反引号
{% codeblock %}
code:`#include<iostream>`
{% endcodeblock %}
效果类似与：

code:`#include<iostream>`
### 利用缩进来引用代码段
使用4个空格或者一个tab的缩进能产生一个引用框来引用需要显示的代码
{% codeblock %}

    
    #include <iostream>
    #include <sys/type.h>
    using namespace std;
    int main(int argc , char* argv[]){
        int i;
        return 0;
    }
{% endcodeblock %}
产生效果如下：

    #include <iostream>
    #include <sys/type.h>
    using namespace std;
    int main(int argc , char* argv[]){
        int i;
        return 0;
    }
`注意`:代码的顶上一行要是空行，不然不是这种效果。
### 使用hexo支持的插件[codeblock](https://hexo.io/zh-cn/docs/tag-plugins.html#Code_Block)
通用语法为：
```
{% codeblock [title] [lang:language] [url] [link text] %}
code snippet
{% endcodeblock %}
```
示例:
```
{% codeblock example.sh lang:bash http://cinus.me/ "Cinus's link" %}
#!/bin/bash
echo "hello world"
exit 0;
{% endcodeblock %}
```
显示结果为：
{% codeblock example.sh lang:bash http://cinus.me/ "Cinus's link" %}
#!/bin/bash
echo "hello world"
exit 0;
{% endcodeblock %}
### 使用3个或以上的反引号来引用代码块
hexo 解析后的效果和使用缩进来引用代码块的效果一样
````
```
#include<stdio.h>

int main(){
	printf("hello");
	return 0;
}
```
````
显示为：
```
#include<stdio.h>

int main(){
	printf("hello");
	return 0;
}
```
### 引用[gist](https://gist.github.com)
通用语法为：
```
{% gist gist_id [filename] %}

```
示例:

```
{% gist ChenXiyu/51daf79a8de15adcfb19  testfile.cpp %}

```
效果：
{% gist ChenXiyu/51daf79a8de15adcfb19  testfile.cpp %}
### 引用source中的代码文件（[Include code](https://hexo.io/zh-cn/docs/tag-plugins.html#Include_Code))
hexo 提供的插件，用于插入`source`文件夹内的代码文件。
语法：
```
{% include_code [title] [lang:language] path/to/file %}
```
```
{% include_code server.cc lang:cpp server.cc %}
```
{% include_code server.cc lang:cpp server.cc %}
`测试未成功`。
## 引用网页
使用hexo插件[iframe](https://hexo.io/zh-cn/docs/tag-plugins.html#iframe)
通用语法：
```
{% iframe url [width] [height] %}

```
示例：
```
{% iframe http://cinus.me/ 920 400 %}
```
效果为：
{% iframe http://cinus.me/ 920 400 %}
## 图片引用
### 使用标准MD语法引用图片
#### 行内式
通用语法：
```
![Alt text](/path/to/img.jpg [Optional title])
```
示例：
```
![test Picture](https://upload.wikimedia.org/wikipedia/commons/5/57/SADF-44Parachute-Gecko-001.jpg)
```
![test Picture](https://upload.wikimedia.org/wikipedia/commons/5/57/SADF-44Parachute-Gecko-001.jpg)
#### 参考式
语法：
```
![Alt text][id]
**[id]是图片参考的名称**
[id]: url/to/image  "Optional title attribute"
```
示例：
```
![test Picture2][1]
[1]:https://c1.staticflickr.com/9/8199/8161648094_2b436fa1a0_b.jpg "测试图片"
```
![test Picture2][1]
### 使用[Image](https://hexo.io/zh-cn/docs/tag-plugins.html#Image)插件
通用语法：
```
{% img [class names] /path/to/image [width] [height] [title text [alt text]] %}

```
示例：
```
{% img https://grahamlesliemccallum.files.wordpress.com/2013/09/sadf-buffel-anti-mine-troop-carrier-sadf-military.jpg %}
```
{% img https://grahamlesliemccallum.files.wordpress.com/2013/09/sadf-buffel-anti-mine-troop-carrier-sadf-military.jpg %}
### 引用本地图片资源
以上的图片引用都是引用网络资源，按理说引用本地的资源也是可行的，但是我测试本地资源没有通过过，hexo提供了引用本地资源的方式。要使用这种方式引用本地资源，先要在你的hexo中设置打开`post_asset_folder`。
编辑顶层的`_config.yml`将
```
post_asset_folder: false
```
改为：
```
post_asset_folder: true
```
这样，使用`hexo new post postName`的时候就会在_post下生成一个与postName同名的目录，可以将你需要使用的资源文件放在这个目录下，在文章中调用。
调用语法：
```
{% asset_img imgName [title] %}
```
实例:
```
{% asset_img testImg.jpg testTitle %}
```
效果:
{% asset_img testImg.jpg testTitle %}
`注意`:要将图片资源放入文章对应的文件夹中。
## 链接
和图片引用类似，链接的引用也支持行内式，和参考式。对于电子邮件等还支持自动链接，hexo还支持link插件。
### 行内式
语法为：
```
[link's name](URL "title")
```
示例：
```
[Cinus's Blog](http://Cinus.me/ "hello Blog" )
```
产生如下效果：
[Cinus's Blog](http://Cinus.me/ "My Blog")
链接本机资源可以使用相对路径：
```
[About me](/about/)
```
[About me](/about/ "about me")
### 参考式
参考式的链接是在链接文字的括号后面再接上另一个方括号，而在第二个方括号里面要填入用以辨识链接的标记
```
[Link's name][id]
----some content-------
[id]:URL
```
示例
```
[Cinus's Blog][2]
----some content-------
[2]:http://cinus.me/
```
[Cinus's Blog][2]

```
[about me][3]
----some content-------
[3]:/about/
```
[about me][3]
### 自动链接
Markdown 支持以比较简短的自动链接形式来处理网址和电子邮件信箱，只要是用尖括号包起来， Markdown 就会自动把它转成链接。例如：
```

<xyCinus@gmail.com>
```
`注意前一行为空`,将会产生：

<xyCinus@gmail.com>
### [Link](https://hexo.io/zh-cn/docs/tag-plugins.html#Link)插件
在文章中插入链接，并自动给外部链接添加 target="_blank" 属性
```
{% link text url [external] [title] %}
```
示例
```
{% link test_link http://Cinus.me/ Cinus %}
```
{% link Cinus http://Cinus.me/ testLink %}
## 视频引用
### YouTube


[1]:https://c1.staticflickr.com/9/8199/8161648094_2b436fa1a0_b.jpg "测试图片"
[2]:http://cinus.me/
[3]:/about/
