

## 2021-2-3
[虚拟机启动后黑屏并无法关闭]()
[CentOS7安装VMware Tools](https://blog.csdn.net/zhujing16/article/details/88677253)
[CentOS使用Samba共享文件](https://www.cnblogs.com/lxx-coder/archive/2020/07/19/13339252.html)
Samba 语法：
```
// 添加 Samba 用户帐号

# smbpasswd -a sambauser

// 禁用 Samba 用户帐号

# smbpasswd -d sambauser

// 启用 Samba 用户帐号

# smbpasswd -e sambauser

// 删除 Samba 用户帐号

# smbpasswd -x sambauser
```
2019年2月28日

## gdb
[CppCon 2015: Greg Law " Give me 15 minutes & I'll change your view of GDB"](https://www.youtube.com/watch?v=PorfLSr3DDI)

[more](https://undo.io/resources/presentations/cppcon-2015-greg-law-give-me-15-minutes-ill-change/)


## shell
ubuntu修改默认的bash为zsh


## blog

[链队列的建立、判空、入队、出队、求长、访头、清空和销毁](https://blog.csdn.net/stpeace/article/month/2012/10)


---
2019年2月26日


## GeeksforGeeks  
[Explicitly Defaulted and Deleted Functions in C++ 11
](https://www.geeksforgeeks.org/explicitly-defaulted-deleted-functions-c-11/)

```c++
// C++ code to demonstrate that 
// non-special member functions 
// can't be defaulted 
class B { 
public: 

	// Error, func is not a special member function. 
	int func() = default; 
	
	// Error, constructor B(int, int) is not 
	// a special member function. 
	B(int, int) = default; 

	// Error, constructor B(int=0) 
	// has a default argument. 
	B(int = 0) = default; 
}; 

// driver program 
int main() 
{ 
	return 0; 
} 

```
---
### co_routine
[协程](https://github.com/Tencent/libco/blob/master/co_routine.h)

申请128 * 1024的栈空间 

> 有什么好处？
相比OS的preemptive进线程调度，用户态调度的优势有:
1) 综合切换开销很低（同普通函数调用），完全不涉及OS上下文切换、刷TLB和cache污染等系统调度问题.
2) 相比preemptive调度，应用主动让出的时机可以自己控制，更有利于资源利用率（但无法强制保证公平）.

也就是说:
a) 随着线程数量的增多，花在切换上的开销占比不会像OS线程那样增大；
b) 线程数量基本只受限于内存.

[用户态调度要保存些什么](http://woofy.cn/2017/07/07/user_level_schedule/)

---