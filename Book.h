#ifndef __BOOK_H__
#define __BOOK_H__            //��ֹͷ�ļ����ظ�����

#define MAX 1024
char sortlb[5][10] = {"��ѧ��", "��ʷ��", "��ѧ��", "������", "������"};
char buffer[MAX];
//ģ������
//ͼ���Ƽ�
void outsp();    //����չʾ
void libmenu(); //ͼ��˵�
void libmain(); //ͼ��ݹ���ϵͳ������
int tjzs(void);//ͳ��ͼ�鱾��
void searchbook();//��ѯͼ��
void scan(int choice);//���ͼ��
void sortmenu();//�������˵�
void sortmain();//����������
void rankmenu();//�������˵�
void sort(struct rank a[10000000],int k);//������
int cmpChStr(char * str,char * target);//����ģ������
int vagueSearch(char * source,char * target);//��ѯͼ��ģ������






#endif // __FUNC_H__
