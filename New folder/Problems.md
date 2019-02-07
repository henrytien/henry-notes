[从一个线上服务器警告谈谈backlog](http://www.cnblogs.com/heat-man/p/backlog.html)  


[浅谈tcp socket的backlog参数](https://www.jianshu.com/p/e6f2036621f4)  

[调查SocketServer拒绝客户端连接的问题](http://lpbobo.com/2016/02/05/%E8%B0%83%E6%9F%A5socketserver%20connection%20refused/)


Linux CentOS 7, how to set Python3.5.2 as default Python version?


use get_pip.py

-bash: yum: command not found

Yum crashed with Keyboard Interrupt error

CentOS7更换yum软件镜像源.md

使用翻墙代理
首先你要有代理工具，前提是已经打开了SS代理，获取 socks5 的代理地址，通过git的内置工具设置代理地址，127.0.0.1:9742 这个是我的工具给我分配的端口号码。

git config --global http.proxy socks5://127.0.0.1:9742
git config --global https.proxy socks5://127.0.0.1:9742
也可以直接修改配置文件 sudo vi ~/.gitconfig ，摁i进入编辑模式，在最下面添加一段配置代码，按Esc退出编辑模式，输入:wq保存并退出。

[http]
    proxy = socks5://127.0.0.1:9742 
[https]
    proxy = socks5://127.0.0.1:9742 


通过代理工具提高Github Clone速度.md