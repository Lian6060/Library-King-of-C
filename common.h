#ifndef __COMMON_H__
#define __COMMON_H__   

//���ļ��������õ��ĺ궨��ͽṹ���װ������������

//�洢�û��˺�������Ϣ���ļ�·??
#define PATH "D:\\Code for C\\Library-King of C 1.0\\accpass.txt"

//�洢�û���������ļ����ļ���????
#define PATH_user "D:\\Code for C\\Library-King of C 1.0\\user-book"

//�洢����鼮���ļ�·??
#define PATH_book "D:\\Code for C\\Library-King of C 1.0\\tushu.txt"

//�洢�����ļ�·��
#define PATH_review "D:\\Code for C\\Library-King of C 1.0\\review.txt"

//����asc
#define UpKey 72
#define DownKey 80
#define LeftKey 75
#define RightKey 77

void gotoxy(short x,short y);

#define LEN2 sizeof(struct login)	//�йص�¼ϵͳ�Ľṹ��
struct login//��¼��Ϣ
{
	int account;
	char password[20];
	struct login*next;
};

#define LEN sizeof(struct book)//�й�ͼ����Ϣ�Ľṹ��
struct book//ͼ����Ϣ
{
	char num[20],nam[20],aut[20],pub[30],cat[20];
	int  many;
	float price;
	struct book*next;
};

#define LEN3 sizeof(struct rank)	//�й���???�Ľṹ??
struct rank
{
	int accountt ;
	int nn;
};

char uzhanghu[9]={0};

#define LEN1 sizeof(struct reader)//�йض�����??�Ľṹ��
struct reader//���߽�����Ϣ
{
	int jnum;
	char time[20],tsnam[20];
	struct reader *next;
};

#endif// __FUNC_H__