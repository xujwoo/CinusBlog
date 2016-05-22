title: amix-vimrc
tags:

---
写了好几遍vim使用技巧了，那些都是vim默认的配置，vim也可以通过自定义配置，完成一些更加强大的功能。个人小大小闹的话可以修改`~/.vimrc`文件来增强vim的功能，然而，我们也可以站在巨人的肩膀上，使用大牛们成熟的配置文件，github上就有很多优秀的成体系的配置文件啊，我就找到一个，然后用上了。就是[这个](https://github.com/amix/vimrc)
这篇博客就是介绍这个配置文件的用法的，其实也就是我自己使用的时候看看他文档的一个笔记，应该说只是把它的readme文件做了一个简单的翻译。
这个项目拥有者心也很大哈，readme上写的是***The Ultimate vimrc***，好吧，来看看吧。
## 介绍
这个配置有两个版本：
* awesome
* basic

看名字就知道，awesome包含的东西比较多，大量的插件啊等等，适合开发环境，basic呢，就是基本的一些配置，适用于生产环境嘛，
## install & update
### awesome
```
git clone https://github.com/amix/vimrc.git ~/.vim_runtime
sh ~/.vim_runtime/install_awesome_vimrc.sh
```
### basic
```
git clone git://github.com/amix/vimrc.git ~/.vim_runtime
sh ~/.vim_runtime/install_basic_vimrc.sh
```

就是把项目拷贝下来，然后运行不同的脚本啦，有兴趣的去看两个脚本的源代码吧，easy

### update
```
cd ~/.vim_runtime
git pull --rebase
```
## include plugins
* [pathogen.vim](https://github.com/tpope/vim-pathogen): Manages the runtime path of the plugins
* [snipMate.vim](https://github.com/garbas/vim-snipmate): snipMate.vim aims to be a concise vim script that implements some of TextMate's snippets features in Vim
* [bufexplorer.zip](https://github.com/vim-scripts/bufexplorer.zip): Buffer Explorer / Browser. This plugin can be opened with `<leader+o>`
* [NERD Tree](https://github.com/scrooloose/nerdtree): A tree explorer plugin for vim
* [ack.vim](https://github.com/mileszs/ack.vim): Vim plugin for the Perl module / CLI script 'ack'
* [ag.vim](https://github.com/rking/ag.vim): A much faster Ack
* [ctrlp.vim](https://github.com/ctrlpvim/ctrlp.vim): Fuzzy file, buffer, mru and tag finder. In my config it's mapped to `<Ctrl+F>`, because `<Ctrl+P>` is used by YankRing
* [mru.vim](https://github.com/vim-scripts/mru.vim): Plugin to manage Most Recently Used (MRU) files. Includes my own fork which adds syntax highlighting to MRU. This plugin can be opened with `<leader+f>`
* [open_file_under_cursor.vim](https://github.com/amix/open_file_under_cursor.vim): Open file under cursor when pressing `gf`
* [vim-indent-object](https://github.com/michaeljsmith/vim-indent-object): Defines a new text object representing lines of code at the same indent level. Useful for python/vim scripts
* [vim-multiple-cursors](https://github.com/terryma/vim-multiple-cursors): Sublime Text style multiple selections for Vim, CTRL+N is remapped to CTRL+S (due to YankRing)
* [vim-expand-region](https://github.com/terryma/vim-expand-region): Allows you to visually select increasingly larger regions of text using the same key combination.
* [vim-fugitive](https://github.com/tpope/vim-fugitive): A Git wrapper so awesome, it should be illegal
* [goyo.vim](https://github.com/junegunn/goyo.vim) and [vim-zenroom2](https://github.com/amix/vim-zenroom2): 
Remove all clutter and focus only on the essential. Similar to iA Writer or Write Room [Read more here](http://amix.dk/blog/post/19744)
* [vim-commentary](https://github.com/tpope/vim-commentary): Comment stuff out.  Use `gcc` to comment out a line (takes a count), `gc` to comment out the target of a motion. `gcu` uncomments a set of adjacent commented lines.
* [syntastic](https://github.com/scrooloose/syntastic): Syntax checking hacks for vim
* [vim-yankstack](https://github.com/maxbrunsfeld/vim-yankstack): Maintains a history of previous yanks, changes and deletes
* [lightline.vim](https://github.com/itchyny/lightline.vim): A light and configurable statusline/tabline for Vim

我会一个个搞清楚这些插件的作用，我相信这些东西都是精品

## Include modes
* [vim-coffee-script](https://github.com/kchmck/vim-coffee-script)
* [vim-less](https://github.com/groenewege/vim-less)
* [vim-bundle-mako](https://github.com/sophacles/vim-bundle-mako)
* [vim-markdown](https://github.com/tpope/vim-markdown)
* [nginx.vim](https://github.com/vim-scripts/nginx.vim): Highlights configuration files for nginx
* [vim-go](https://github.com/fatih/vim-go)

同上，我也会一个一个琢磨这些东西的用处

## 我怎么写我自己的配置？
当然，你可以在`~/.vimrc`里面增加你自己的内容，但是使用了这套配置，还是建议在`~/.vim_runtime/my_configs.vim`里面添加你自己的配置

## key mappings


