# boost 库安装
1. 到官网下载最新版的boost，http://www.boost.org/users/history/version_1_67_0.html

2. 可能需要预先安装相关项：

`yum -y install gcc-c++ python-devel bzip2-devel zlib-devel`
 
3. 解压：

`tar zxvf boost_1_67_0.tar.gz`
4. 进入解压后的目录boost_1_67_0，执行：

`sudo ./bootstrap.sh --prefix=/usr/local/boost`
5. 安装：

`sudo ./b2 install`
6. 安装Boost.Build

(1) 进入boost_1_67_0目录下的tools/build目录，执行：

`sudo ./bootstrap.sh`
(2) 安装

`sudo ./b2 install --prefix=/usr/local/boost`
7. 修改环境变量
`vim /etc/environment`
向文件中增加如下路径：

```
    CPLUS_INCLUDE_PATH=/usr/local/boost/include
    LIBRARY_PATH=/usr/local/boost/lib
```
添加完成后，进行保存操作。

8. 测试
```C++
#include <boost/date_time/gregorian/gregorian.hpp> 
#include <iostream> 
using namespace std;
int main() 
{ 
    boost::gregorian::date d(boost::gregorian::day_clock::local_day());
    cout << d.year()<<"." << d.month()<<"." <<d.day() <<endl; 
    getchar();
    return 0;
}
```

编译：`g++ -I /usr/local/boost/include -L /usr/local/boost/lib testBoost.cpp -o testBoost`