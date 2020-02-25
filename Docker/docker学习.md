
![](./images/docker.png)


![](./images/linux_vs_docker.png)

使用docker的目的

![](./images/docker_target.png)

使用场景
![](./images/usage.png)

![](./images/docker_parts.png)


**什么是镜像**？  
Docker 包括三个基本概念
* 镜像（Image）
* 容器（Container）
* 仓库（Repository）

**Docker 容器**
![](./images/docker_work.png)
docker 使用容器来运行
- docker 不用root命令
![](./images/noroot.png)


## 镜像
- docker 启动CentOS  
`docker run -t -i centos  /bin/bash`

## Docker 命令
- 查看版本  
`docker --version`

- Docker inspect 命令  
`docker inspect centos`


## Docker 实例
### docker 安装 Redis  
`docker pull redis:latest`

#### 运行
`docker run -itd --name redis-test -p 6379:6379 redis`

#### 安装成功
![](./images/docker_redis.png)