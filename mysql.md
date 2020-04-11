# MySQL

- SEQUEL

  Structured

  English

  Query

  Language

- SQL

  Structured

  Query

  Language









## 连接Docker的MySQL	

`use mysql;`

`select host,user,plugin,authentication_string from mysql.user;`

![image-20200310204211291](/Users/henry/Library/Application Support/typora-user-images/image-20200310204211291.png)



`ALTER user 'root'@'%' IDENTIFIED WITH mysql_native_password BY '123456';`

`FLUSH PRIVILEGES;`



