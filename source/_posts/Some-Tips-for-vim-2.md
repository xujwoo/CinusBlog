title: Some Tips for vim(2)
date: 2015-10-11 00:05:03
tags:
- vim
- note
categories:
- Tech
- «Practical Vim»

---
## 1. 跳转到当前行的某个字符上
* `f{char}`,向右跳转到特定的字符{char}上.
* `F{char}`,向左跳转到特定的字符{char}上.
* `;`,正向跳转.
* `,`,反向跳转.

## 2. 可视模式的几个小技巧
* `gv`,重选上次的高亮区域.(如果上次被选中的行被删除了,那执行`gv`以后可能就不是你想要的结果了)
* 在可视模式下切换选区的活动端可以使用`o`.光标会从选中区域的一端跳到另一端.

## 3. 命令行模式
{% blockquote The Old Testament of Unix %}
在洪荒时期,先出现了ed,ed是ex之父,ex为vi之父,而vi是vim之父
{% endblockquote %}
<!--more-->
未完待续
