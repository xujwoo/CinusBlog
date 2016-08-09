title: react
tags:
---
getInitialState方法，将在组件被挂载的时候被调用，并且只会调用一次，用于设置组件的初始状态。
## 组件生命周期
componentWillMount方法在组件将要被挂载的时候被调用，该方法也只会调用一次，组件的render方法将在生命周期内多次被调用来渲染组件，所以此处一般放一些只执行一次的代码。
componentDidMount 方法将在组件已经运行了render方法，并且将dom实际渲染出来后调用。此处应该是一些需要实际操作dom的代码。
componentWillUnmount 方法在你准备移除这个component的时候将被调用，比如移除监听器等的操作。
## 组件方法
getDefaultProps 在创建组件时可以设置默认值
PropTypes 用于定义变量的类型，对避免非期望赋值很有帮助
mixins 如果多个组件使用相同的方法，可以将共同点抽象出一个组件，然后使用mixins方法将这个父组件包含到各个组件中，这样，这些组件就可以共用一些方法了，但是，mixins的组件中，不可以覆盖minxin进来的方法。

