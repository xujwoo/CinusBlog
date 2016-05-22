title: jsNote
tags:
- JavaScript

---
* 查看一个对象本身的所有属性，可以使用Object.keys方法  
```
var o = {
  key1: 1,
  key2: 2
};

Object.keys(o);
// ['key1', 'key2']
```
* 删除一个属性，需要使用delete命令,delete命令只能删除对象本身的属性，不能删除继承的属性.
```
var o = {p: 1};
Object.keys(o) // ["p"]

delete o.p // true
o.p // undefined
Object.keys(o) // []
```
