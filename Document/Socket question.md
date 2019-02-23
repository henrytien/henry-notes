
2019-2-23  
[TCP option SO_LINGER (zero) - when it's required](https://stackoverflow.com/questions/3757289/tcp-option-so-linger-zero-when-its-required)

setsockopt so-linger

[What is SOL_SOCKET used for?](https://stackoverflow.com/questions/21515946/what-is-sol-socket-used-for)

```c
int getsockopt(int socket, int level, int option_name, 
     void *option_value, socklen_t *option_len);
```

The option_name argument specifics a single option to be retrieved. It can be one of the following values defined in <sys/socket.h>  
[read here](http://pubs.opengroup.org/onlinepubs/7908799/xns/getsockopt.html) 
