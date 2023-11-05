#ifndef __COMMON_H__
#define __COMMON_H__   

//此文件将所有用到的宏定义和结构体封装起来便于引用

//存储用户账号密码信息的文件路??
#define PATH "D:\\Code for C\\Library-King of C 1.0\\accpass.txt"

//存储用户借阅情况文件的文件夹????
#define PATH_user "D:\\Code for C\\Library-King of C 1.0\\user-book"

//存储库存书籍的文件路??
#define PATH_book "D:\\Code for C\\Library-King of C 1.0\\tushu.txt"

//存储书评文件路径
#define PATH_review "D:\\Code for C\\Library-King of C 1.0\\review.txt"

//按键asc
#define UpKey 72
#define DownKey 80
#define LeftKey 75
#define RightKey 77

void gotoxy(short x,short y);

#define LEN2 sizeof(struct login)	//有关登录系统的结构体
struct login//登录信息
{
	int account;
	char password[20];
	struct login*next;
};

#define LEN sizeof(struct book)//有关图书信息的结构体
struct book//图书信息
{
	char num[20],nam[20],aut[20],pub[30],cat[20];
	int  many;
	float price;
	struct book*next;
};

#define LEN3 sizeof(struct rank)	//有关排???的结构??
struct rank
{
	int accountt ;
	int nn;
};

char uzhanghu[9]={0};

#define LEN1 sizeof(struct reader)//有关读者信??的结构体
struct reader//读者借阅信息
{
	int jnum;
	char time[20],tsnam[20];
	struct reader *next;
};

#endif// __FUNC_H__