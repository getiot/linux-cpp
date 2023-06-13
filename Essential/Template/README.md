# Template 示例说明

## template_class

template_class.cpp 是一个简单的 C++ 模板类的示例程序，该程序用于实现一个栈（stack）数据结构。

在该示例程序中，模板类 MyStack 支持任意类型的元素，可以创建一个 T 类型的数组，其中 T 是在模板声明时指定的类型参数。

- 在构造函数中，MyStack 类使用 new 运算符创建一个大小为 n 的 T 类型数组；
- 在 push() 方法中，新元素将被插入到数组的顶部；
- 在 pop() 方法中，栈顶元素将被弹出并返回；
- 在 peek() 方法中，返回栈顶元素的值，但不删除它。

通过使用模板类，能够将这段代码具有更广泛的可重用性和灵活性，可以将 `MyStack<int>` 类型的栈用于 int 类型的对象，这种形式也可以用于 `MyStack<double>` 类型的栈，或在需要使用其他类型的程序中，可以使用 `MyStackstd::string` 类型的栈。这种类型参数化方式可以大大简化代码，从而提高了可读性和可维护性。

## template_function

template_function.cpp 是一个简单的 C++ 模板函数的示例程序。
