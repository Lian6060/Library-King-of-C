#ifndef __LOGIN_H__
#define __LOGIN_H__            //防止头文件被重复包含
#include "Login.c"              //这句引用.c必须加不知道为什么

void logpaint();
void logmenu();                 //显示登录菜单
void logmain();                 //登录功能函数
int match(int m,char a[9]);    //匹配数据库中的账号密码
void usermain();                //输入账户密码的登录函数
void create();                  //创建新账户
int count();                    //统计文本accpass中账号密码个数
void xg(int z,char m[20]);//修改文件内容函数
void xgmm();//修改密码函数
void creat_user_book(int str0);//为每个用户创建自己的借还书文件
void paintWindow();

#endif // __FUNC_H__


/*
9.30。。。
用户登录头文件包含函数有
1.登录菜单logmenu
2.账号密码匹配函数match
2.登录函数login
3.注册（没写，要写入文件）
4.xgmm----删 查 写
5.admin------管理员系统   -adminmain--
6.图形化----后期再写
7完善
8.
*/


/**
1.在.h里面声明
2.在.c里面定义
3.主函数就调用h
*/
