#ifndef __LOGIN_H__
#define __LOGIN_H__            //��ֹͷ�ļ����ظ�����
#include "Login.c"              //�������.c����Ӳ�֪��Ϊʲô

void logpaint();
void logmenu();                 //��ʾ��¼�˵�
void logmain();                 //��¼���ܺ���
int match(int m,char a[9]);    //ƥ�����ݿ��е��˺�����
void usermain();                //�����˻�����ĵ�¼����
void create();                  //�������˻�
int count();                    //ͳ���ı�accpass���˺��������
void xg(int z,char m[20]);//�޸��ļ����ݺ���
void xgmm();//�޸����뺯��
void creat_user_book(int str0);//Ϊÿ���û������Լ��Ľ軹���ļ�
void paintWindow();

#endif // __FUNC_H__


/*
9.30������
�û���¼ͷ�ļ�����������
1.��¼�˵�logmenu
2.�˺�����ƥ�亯��match
2.��¼����login
3.ע�ᣨûд��Ҫд���ļ���
4.xgmm----ɾ �� д
5.admin------����Աϵͳ   -adminmain--
6.ͼ�λ�----������д
7����
8.
*/


/**
1.��.h��������
2.��.c���涨��
3.�������͵���h
*/
