#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "Admin.h"
#include "common.h"
#include "Book.h"

void Adminmenu()//��ʾ����Ա��¼�˵�
{
system("cls");
printf("\n\t��ӭʹ�ñ���������ѧͼ�����ϵͳ\n");
       
printf("----------------------------------------------");
                  
printf("\n\t\t------------");
printf("\n\t\t|1.����ͼ��|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|2.ɾ��ͼ��|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|3.��������|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|4.�����ϼ�|\n");
printf("\t\t------------\n");

printf("\n\t    �밴��ѡ�񣬻س�ȷ��\n");
printf("----------------------------------------------\n");
return ;

}

void Adminmain()//����Ա��¼���ܺ���
{
	void usermain();
	void addbook();
	void deletebook();
	void condition();
	char c1 = 'a', ch = 'a'; // ��ʼ��Ϊ��a��
	int line = 4;			 // ��ʼ���
	int choice = 1;			 // ��Ϊ�����ѡ��1�ϣ����Ծ�Ĭ��Ϊ1
	system("cls");
	Adminmenu();
	gotoxy(0, line);
	printf("\033[1;30;47m\t\t|1.����ͼ��|\033[0m");
	while ((c1 = getch()) != '\r' || c1 != 13)
	{
		ch = getch();
		if (c1 == -32)
			if (ch == UpKey && choice > 1)
			{
				choice -= 1;
				if (choice == 1)
				{
					gotoxy(0, line);
					printf("\t\t|2.ɾ��ͼ��|");
					line -= 4;
					gotoxy(0, line);
					printf("\033[1;30;47m\t\t|1.����ͼ��|\033[0m");
				}
				if (choice == 2)
				{
					gotoxy(0, line);
					printf("\t\t|3.��������|");
					line -= 4;
					gotoxy(0, line);
					printf("\033[1;30;47m\t\t|2.ɾ��ͼ��|\033[0m");
				}
				if (choice == 3)
				{
					gotoxy(0, line);
					printf("\t\t|4.�����ϼ�|");
					line -= 4;
					gotoxy(0, line);
					printf("\033[1;30;47m\t\t|3.��������|\033[0m");
				}
			}

		if (ch == DownKey && choice < 4)
		{
			choice += 1;
			if (choice == 2)
			{
				gotoxy(0, line);
				printf("\t\t|1.����ͼ��|");
				line += 4;
				gotoxy(0, line);
				printf("\033[1;30;47m\t\t|2.ɾ��ͼ��|\033[0m");
			}
			if (choice == 3)
			{
				gotoxy(0, line);
				printf("\t\t|2.ɾ��ͼ��|");
				line += 4;
				gotoxy(0, line);
				printf("\033[1;30;47m\t\t|3.��������|\033[0m");
			}
			if (choice == 4)
			{
				gotoxy(0, line);
				printf("\t\t|3.��������|");
				line += 4;
				gotoxy(0, line);
				printf("\033[1;30;47m\t\t|4.�����ϼ�|\033[0m");
			}
		}
		}
		//���ع�굽��ȷλ��
		gotoxy(0, 8);
        //����ʵ��ѡ��Ĵ���
		switch (choice)
		{
		case 1:
      addbook();
      break;
		case 2:
      deletebook();
      break;
	  case 3:
	  condition();
	  break;
		case 4:
      usermain();
      break;
		default:
			printf("�벻Ҫ������ѡ�\n");
			getch();
			system("cls");
			break;
		}
    system("pause");
}



void addbook()//����ͼ��
{
	FILE*fp;
	char i;
	int many=0;
    char  nam[20]={'\0'},aut[20]={'\0'},cat[20]={'\0'},pub[20]={'\0'},num[20]={'\0'};
    system ("cls");

    if ((fp=fopen(PATH_book,"r"))==NULL)//if��䣺��ͼ����ļ��������ڴ��ļ����½�
	{
      fp=fopen(PATH_book,"w");
      fclose(fp);
    }
	fp=fopen(PATH_book,"a");
	
	printf("\n�밴���¸�ʽ����ͼ����Ϣ:\n��� ���� ���� ������ ��� ������");
	
	for(;i!=27;)//Ϊ��ʵ������һ�κ�esc�˳�
	{
		printf("\n������:\n");
		scanf("%s%s%s%s%s%d",num,nam,aut,pub,cat,&many);
		fprintf(fp,"%-8s%-16s%-14s%-16s%-18s%-7d\n",num,nam,aut,pub,cat,many);
	    printf("���������밴�س������������밴Esc\n");
        i=getch();//��ͣ����i���պ������һ��ָ��
        for (;i!=13&&i!=27;)//��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
        i=getch();
     }

	fclose(fp);
    printf("\n����ɹ�,�������������һ��!");
    getch();
    
	Adminmain();//������һ��
}
void deletebook()//ɾ��ͼ��
{
	   struct book *head=NULL;
       struct book *p,*p1,*p2;
       int tmany=0,n=0,j,k;
       float tprice=0;
       char  tnam[20]={'\0'},taut[20]={'\0'},tcat[20]={'\0'},tpub[20]={'\0'},tnum[20]={'\0'};
	   char jjnam[20]={'\0'};
	   char i;
       FILE *fp;
       if ((fp=fopen(PATH_book,"r"))==NULL)//���ļ�
       {
	       system ("cls");
           printf("\n��¼�ļ�������!�����������");
           getch();
           Adminmain();
       }

	   else//ʵ��ɾ���Ĺ���
	   {
	      system ("cls");
	      printf("\n��������Ҫɾ��������:");//����ɾ��ͼ������
          scanf("%s",jjnam);
          printf("\nȷ��ɾ����س���ȡ���밴Esc\n");
          i=getch();
          for(;i!=13&&i!=27;)
          i=getch();
          if (i==27)
          Adminmain();
	      fp=fopen(PATH_book,"r");
		 j=tjzs();

	   for (k=0;k<j;k++)
       {
	       fscanf(fp,"%s%s%s%s%s%d",tnum,tnam,taut,tpub,tcat,&tmany);
           if (strcmp(jjnam,tnam))//�Ƚ����֣�����ͬ���ֵ���Ϣ���Ƶ�����
          {
	          n++;//��ͬ����ֵΪ0��ִ��if������ѭ������ͬ��ִ��ֱ�������в�ͬ����������������
	            if (n==1)//��������
                {
		          p1=p2=(struct book*)malloc(LEN);
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct book*)malloc(LEN);//�½�����
                }

                strcpy(p1->num,tnum);//�������
                strcpy(p1->nam,tnam);//��������
                strcpy(p1->aut,taut);//������������
                strcpy(p1->pub,tpub);//���Ƴ�����
                strcpy(p1->cat,tcat);//�������
                p1->many=tmany;//���Ƹ���
           }
       }
             if (n==0)//���ͼ��ֻ��һ������һ��պú�Ҫɾ������ͬ
			 {
			 head=NULL;
			 }
			 else//������������ʣ��һ������ռ䣬���Է��
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 }
    }

   fp=fopen(PATH_book,"w");//����ļ���ֻд�򿪣�Ȼ��ر�
   fclose(fp);
   fp=fopen(PATH_book,"a");//׷���ļ�
   p=head;

   for (;p!=NULL;)//���������ݸ��ǵ��ļ�
   {
   	   fprintf(fp,"%-8s%-16s%-14s%-16s%-18s%-7d\n",p->num,p->nam,p->aut,p->pub,p->cat,p->many);
   	   p=p->next;
   }
   fclose(fp);
   system ("cls");
   printf("\nɾ���ɹ� \n�������������һ��\n");
   getch();//������һ��
   Adminmain();
}

void condition(){
	FILE *fp,*fp1;
	int account=0;
	int accnum=0,outbooknum=0;
	char riqi[10],bookname[20],lastbookname[20];
    int month, date,umonth,udate,flag=0;
	char password[20] = {'\0'}, fileName[256]={'\0'};
	fp=fopen(PATH,"r");	//���ļ�
	for (accnum=0;!feof(fp);accnum++)			//������ļ�
		fscanf(fp,"%d %s",&account,password);
	fclose(fp);//�ر��ļ�
	system("cls");
	printf("������������ڣ�\n");
	scanf("%s", riqi);
	sscanf(riqi, "%d.%d", &month, &date);
	system("cls");
	printf("C���Դ���ͼ�����ϵͳ�������\n");
	printf("------------------------------------------------\n");
	printf("��ǰע���û��� %d ��\n", accnum);
	printf("------------------------------------------------\n");
	printf("�ѽ��ͼ�����飺\n");
	printf("�û�:\t\t��������:\t\t�ڽ���Ŀ:\n");
	fp=fopen(PATH,"r");	//���ļ�
	for (;!feof(fp);){			//������ļ�
		fscanf(fp,"%d %s",&account,password);
		flag = 0;
		sprintf(fileName,"%s%s%d%s",PATH_user,"\\",account,".txt");
			fp1=fopen(fileName,"r");
			for (;!feof(fp1);){
			 fscanf(fp1, "%*d%s%s", riqi, bookname);
			 if(strcmp(riqi,"ԤԼ") && strcmp(lastbookname,bookname)){
				printf("%-5d\t\t%-9s\t\t%-9s\n", account, riqi, bookname);
				outbooknum++;
			 }
			 strcpy(lastbookname, bookname);
			 sscanf(riqi, "%d.%d", &umonth, &udate);
			 if (((month - umonth) * 30 + date - udate) >= 20)
				flag = 1;
			}
			fclose(fp1);
	}
	printf("�ڽ�ͼ�鹲%d��\n", outbooknum);
	fclose(fp);
	fclose(fp);//�ر��ļ�
	getch();
	Adminmenu();
}