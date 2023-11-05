#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "Admin.h"
#include "common.h"
#include "Book.h"

void Adminmenu()//显示管理员登录菜单
{
system("cls");
printf("\n\t欢迎使用北京化工大学图书管理系统\n");
       
printf("----------------------------------------------");
                  
printf("\n\t\t------------");
printf("\n\t\t|1.增加图书|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|2.删减图书|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|3.借阅总览|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|4.返回上级|\n");
printf("\t\t------------\n");

printf("\n\t    请按键选择，回车确定\n");
printf("----------------------------------------------\n");
return ;

}

void Adminmain()//管理员登录功能函数
{
	void usermain();
	void addbook();
	void deletebook();
	void condition();
	char c1 = 'a', ch = 'a'; // 初始化为‘a’
	int line = 4;			 // 初始光标
	int choice = 1;			 // 因为光标在选项1上，所以就默认为1
	system("cls");
	Adminmenu();
	gotoxy(0, line);
	printf("\033[1;30;47m\t\t|1.增加图书|\033[0m");
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
					printf("\t\t|2.删减图书|");
					line -= 4;
					gotoxy(0, line);
					printf("\033[1;30;47m\t\t|1.增加图书|\033[0m");
				}
				if (choice == 2)
				{
					gotoxy(0, line);
					printf("\t\t|3.借阅总览|");
					line -= 4;
					gotoxy(0, line);
					printf("\033[1;30;47m\t\t|2.删减图书|\033[0m");
				}
				if (choice == 3)
				{
					gotoxy(0, line);
					printf("\t\t|4.返回上级|");
					line -= 4;
					gotoxy(0, line);
					printf("\033[1;30;47m\t\t|3.借阅总览|\033[0m");
				}
			}

		if (ch == DownKey && choice < 4)
		{
			choice += 1;
			if (choice == 2)
			{
				gotoxy(0, line);
				printf("\t\t|1.增加图书|");
				line += 4;
				gotoxy(0, line);
				printf("\033[1;30;47m\t\t|2.删减图书|\033[0m");
			}
			if (choice == 3)
			{
				gotoxy(0, line);
				printf("\t\t|2.删减图书|");
				line += 4;
				gotoxy(0, line);
				printf("\033[1;30;47m\t\t|3.借阅总览|\033[0m");
			}
			if (choice == 4)
			{
				gotoxy(0, line);
				printf("\t\t|3.借阅总览|");
				line += 4;
				gotoxy(0, line);
				printf("\033[1;30;47m\t\t|4.返回上级|\033[0m");
			}
		}
		}
		//重载光标到正确位置
		gotoxy(0, 8);
        //具体实现选择的代码
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
			printf("请不要乱输入选项！\n");
			getch();
			system("cls");
			break;
		}
    system("pause");
}



void addbook()//增加图书
{
	FILE*fp;
	char i;
	int many=0;
    char  nam[20]={'\0'},aut[20]={'\0'},cat[20]={'\0'},pub[20]={'\0'},num[20]={'\0'};
    system ("cls");

    if ((fp=fopen(PATH_book,"r"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen(PATH_book,"w");
      fclose(fp);
    }
	fp=fopen(PATH_book,"a");
	
	printf("\n请按以下格式输入图书信息:\n书号 书名 作者 出版社 类别 进库量");
	
	for(;i!=27;)//为了实现输入一次后按esc退出
	{
		printf("\n请输入:\n");
		scanf("%s%s%s%s%s%d",num,nam,aut,pub,cat,&many);
		fprintf(fp,"%-8s%-16s%-14s%-16s%-18s%-7d\n",num,nam,aut,pub,cat,many);
	    printf("继续输入请按回车，结束输入请按Esc\n");
        i=getch();//暂停程序当i接收后继续下一条指令
        for (;i!=13&&i!=27;)//保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
        i=getch();
     }

	fclose(fp);
    printf("\n保存成功,按任意键返回上一层!");
    getch();
    
	Adminmain();//返回上一层
}
void deletebook()//删除图书
{
	   struct book *head=NULL;
       struct book *p,*p1,*p2;
       int tmany=0,n=0,j,k;
       float tprice=0;
       char  tnam[20]={'\0'},taut[20]={'\0'},tcat[20]={'\0'},tpub[20]={'\0'},tnum[20]={'\0'};
	   char jjnam[20]={'\0'};
	   char i;
       FILE *fp;
       if ((fp=fopen(PATH_book,"r"))==NULL)//打开文件
       {
	       system ("cls");
           printf("\n记录文件不存在!按任意键返回");
           getch();
           Adminmain();
       }

	   else//实现删除的功能
	   {
	      system ("cls");
	      printf("\n请输入你要删除的书名:");//输入删除图书书名
          scanf("%s",jjnam);
          printf("\n确认删除请回车，取消请按Esc\n");
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
           if (strcmp(jjnam,tnam))//比较名字，将不同名字的信息复制到链表
          {
	          n++;//相同返回值为0不执行if语句继续循环，不同则执行直到将所有不同的书名建立成链表
	            if (n==1)//建立链表
                {
		          p1=p2=(struct book*)malloc(LEN);
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct book*)malloc(LEN);//新建链表
                }

                strcpy(p1->num,tnum);//复制书号
                strcpy(p1->nam,tnam);//复制书名
                strcpy(p1->aut,taut);//复制作者名字
                strcpy(p1->pub,tpub);//复制出版社
                strcpy(p1->cat,tcat);//复制类别
                p1->many=tmany;//复制个数
           }
       }
             if (n==0)//如果图书只有一项且这一项刚好和要删除的相同
			 {
			 head=NULL;
			 }
			 else//建立链表的最后剩余一个储存空间，所以封底
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 }
    }

   fp=fopen(PATH_book,"w");//清空文件，只写打开，然后关闭
   fclose(fp);
   fp=fopen(PATH_book,"a");//追加文件
   p=head;

   for (;p!=NULL;)//把链表内容覆盖到文件
   {
   	   fprintf(fp,"%-8s%-16s%-14s%-16s%-18s%-7d\n",p->num,p->nam,p->aut,p->pub,p->cat,p->many);
   	   p=p->next;
   }
   fclose(fp);
   system ("cls");
   printf("\n删除成功 \n按任意键返回上一层\n");
   getch();//返回上一层
   Adminmain();
}

void condition(){
	FILE *fp,*fp1;
	int account=0;
	int accnum=0,outbooknum=0;
	char riqi[10],bookname[20],lastbookname[20];
    int month, date,umonth,udate,flag=0;
	char password[20] = {'\0'}, fileName[256]={'\0'};
	fp=fopen(PATH,"r");	//打开文件
	for (accnum=0;!feof(fp);accnum++)			//逐个读文件
		fscanf(fp,"%d %s",&account,password);
	fclose(fp);//关闭文件
	system("cls");
	printf("请输入今日日期：\n");
	scanf("%s", riqi);
	sscanf(riqi, "%d.%d", &month, &date);
	system("cls");
	printf("C语言大王图书管理系统情况概览\n");
	printf("------------------------------------------------\n");
	printf("当前注册用户共 %d 人\n", accnum);
	printf("------------------------------------------------\n");
	printf("已借出图书详情：\n");
	printf("用户:\t\t借阅日期:\t\t在借书目:\n");
	fp=fopen(PATH,"r");	//打开文件
	for (;!feof(fp);){			//逐个读文件
		fscanf(fp,"%d %s",&account,password);
		flag = 0;
		sprintf(fileName,"%s%s%d%s",PATH_user,"\\",account,".txt");
			fp1=fopen(fileName,"r");
			for (;!feof(fp1);){
			 fscanf(fp1, "%*d%s%s", riqi, bookname);
			 if(strcmp(riqi,"预约") && strcmp(lastbookname,bookname)){
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
	printf("在借图书共%d本\n", outbooknum);
	fclose(fp);
	fclose(fp);//关闭文件
	getch();
	Adminmenu();
}