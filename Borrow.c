#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include"Borrow.h"
#include "common.h"

void borrowmenu()//显示管理员登录菜单
{
system("cls");



printf("\n\t欢迎使用北京化工大学图书管理系统\n");
       
printf("----------------------------------------------");
                  
printf("\n\t\t------------");
printf("\n\t\t|1.借书系统|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|2.还书系统|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|3.查询借阅|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|4.返回上级|\n");
printf("\t\t------------\n");

printf("\n\t    请按键选择，回车确定\n");
printf("----------------------------------------------\n");
return ;


}


void borrowmain(){
	void borrow(); //借书函数
	void bookreturn();//还书函数
	void inquire();//查询借阅
	void libmain();
	char c1 = 'a', ch = 'a';//初始化为‘a’
    int line= 4;//初始光标
    int choice = 1; // 因为光标在选项1上，所以就默认为1
    system("cls");
    borrowmenu();
	gotoxy(0, line);
    printf("\033[1;30;47m\t\t|1.借书系统|\033[0m");
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
				  printf("\t\t|2.还书系统|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|1.借书系统|\033[0m");
			  }
			  if (choice == 2)
			  {
				  gotoxy(0, line);
				  printf("\t\t|3.查询借阅|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|2.还书系统|\033[0m");
			  }
			  if (choice == 3)
			  {
				  gotoxy(0, line);
				  printf("\t\t|4.返回上级|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|3.查询借阅|\033[0m");
			  }
		  }

	  if (ch == DownKey && choice < 4)
	  {
		  choice += 1;
		  if (choice == 2)
		  {
			  gotoxy(0, line);
			  printf("\t\t|1.借书系统|");
			  line += 4;
			  gotoxy(0, line);
			  printf("\033[1;30;47m\t\t|2.还书系统|\033[0m");
		  }
		  if (choice == 3)
		  {
			  gotoxy(0, line);
			  printf("\t\t|2.还书系统|");
			  line += 4;
			  gotoxy(0, line);
			  printf("\033[1;30;47m\t\t|3.查询借阅|\033[0m");
		  }
		  if (choice == 4)
		  {
			  gotoxy(0, line);
			  printf("\t\t|3.查询借阅|");
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
	  borrow();
	  break;
		case 2:
      bookreturn();
      break;
	  	case 3:
	  inquire();
		case 4:
      libmain();
      break;
		default:
			printf("请不要乱输入选项！\n");
			getch();
			system("cls");
			break;
		}
    system("pause");

}




void borrow()//借书函数
{
	FILE *fp,*fp3;
	struct book *head=NULL;
    struct book *p,*p1,*p2;
    int i,loop,k,n=0,flag=0,s=0;
	int jnum=0;
	int many=0;
	float tprice=0;
	char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[30]={'\0'},tkind[20]={'\0'},tshuhao[20]={'\0'},
         ttname[20]={'\0'},mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'};
	char fileName[256] = {0};
	char hit=0;

	system("cls");
	if((fp=fopen(PATH_book,"r"))==NULL)
	{
		system("cls");
		printf("\n 图书馆无库存!按任意键退出!");
		getch();
		exit(0);
	}
	else
	{
        printf("\n请输入借阅书名:\n请输入:");
		scanf("%s",zname);
    k= tjzs();//统计图书馆文件个数

	for (i=0;i<k;i++)//先将图书信息建立链表，更改库存
    	{
    		fscanf(fp,"%s%s%s%s%s%d",tshuhao,tname,tauthor,tchuban,tkind,&many);
			n++;
			if(n==1)
			{
				p1=p2=(struct book*)malloc(LEN);
				head=p1;
			}
		    else
           	{
                p2->next=p1;
                p2=p1;
                p1=(struct book*)malloc(LEN);

            }
			strcpy(p1->num,tshuhao);//复制书号
			strcpy(p1->nam,tname);//复制书名
			strcpy(p1->aut,tauthor);//复制作者
			strcpy(p1->pub,tchuban);//复制出版社
			strcpy(p1->cat,tkind);//复制类别
			p1->many=many;//复制现存量
        }
        if(n==0)
 		head=NULL;
		else
		 {
		 	p2->next=p1;
		 	p1->next=NULL;
		 	fclose(fp);
		 }

	}
	p=head;
	
	for (;p!=NULL;)
	{
		if(!(strcmp(p->nam,zname)))//判断要借书的是否存在，标记等于1，存在库存减一
		{
			
            flag=1;
		 	loop=p->many;
		 	(p->many)--;
		 }
			p=p->next;
  }
	if(flag&&(loop>0))//存在被借的图书且现存量大于0，把库存量变化后的链表存入文件
    {

		fp=fopen(PATH_book,"w");
    	fclose(fp);
    	fp=fopen(PATH_book,"a");
    	p=head;

		for(;p !=NULL;)
    	{
    		fprintf(fp,"%-8s%-16s%-14s%-22s%-18s%-7d\n",p->num,p->nam,p->aut,p->pub,p->cat,p->many);
   		   	p=p->next;
		}
		free(p);
		fclose(fp);

		printf("\n请输入读者信息:\n ");//录入读者信息
		printf("账户名：");
		scanf("%d",&jnum);
		printf("借书日期：");
 		scanf("%s",riqi);
		sprintf(fileName,"%s%s%d%s",PATH_user,"\\",jnum,".txt");
		fp3=fopen(fileName,"a");
		fprintf(fp3,"%-8d%-18s%-16s\n",jnum,riqi,zname);
	    fclose(fp3);
        printf("借书成功!！按任意键返回\n");
		getch();//返回
		borrowmain();//调用借阅系统
   }
	else
    {
    	if(flag!=0){
        printf("此书已被借出!是否预约？\n输入1预约此书，输入2返回借阅\n");//否则输出此书已被借完
		int hi;
		scanf("%d",&hi);
		if(hi==1){
			jnum=atoi(uzhanghu);
			sprintf(fileName,"%s%s%d%s",PATH_user,"\\",jnum,".txt");
			fp3=fopen(fileName,"a");
			fprintf(fp3,"%-8d%-18s%-16s\n",jnum,"预约",zname);
	    	fclose(fp3);
			printf("预约成功！");
		}
		else
			borrowmain();
		}
		else
		printf("查找无此书!按任意键返回");
	}
	    getch();//返回
        borrowmain();//调用借阅系统

}


void bookreturn(){
 	 FILE *fp,*fp3,*fp4;
	 struct reader *head=NULL;
	 struct reader *p,*p1,*p2;
	 struct book *lhead1=NULL;
	 struct book *zp1,*lp1,*lp2;
	 int txcl=0,i;
	 char shuping[256];
	 float tprice=0;
	 char tname[20]={'\0'},tauthor[20]={'\0'},tkind[20]={'\0'},
	 tchuban[30]={'\0'},ttname[20]={'\0'},tshuhao[20]={'\0'};
	 int tzhenghao=0,n=0,k=0,t=0,flag=0;
	 char tmingzi[20]={'\0'},triqi[20]={'\0'},tzname[20]={'\0'},ttzname[20]={'\0'};
	int username;
	char day[20],bookname[20],lastbookname[20];
	 system ("cls");
	int account=atoi(uzhanghu);
	char fileName[256] = {0};
	sprintf(fileName, "%s%s%d%s", PATH_user, "\\", account, ".txt");
	if ((fp = fopen(fileName, "r")) == NULL) // 不存在读者文件，则输出不能还书
	{
		system("cls");
		printf("\n 不存在借书者!按任意键退出!");
		getch();
		system("cls");
		borrowmain();
      }

	  else
	  {
		printf("你的在借图书：\n借阅日期:\t\t在借书目:\n");
		while(!feof(fp)){
			fscanf(fp,"%d %s %s",&username,day,bookname);
			if(strcmp(day,"预约"))
			if(strcmp(lastbookname,bookname))
				printf("%5s\t\t\t%5s\n",day,bookname);
			strcpy(lastbookname,bookname);
		}
		printf("*******************************\n");
	    printf("\n请输入要归还的图书书名:\n");
		 scanf("%s",ttzname);//输入还书书名
		fclose(fp);
		fp=fopen(fileName,"r");
		 while(!feof(fp))//读取读者借书信息
           {
			fscanf(fp,"%d%s%s\n ",&tzhenghao,triqi,tzname);
			if((account==tzhenghao)&&!strcmp(tzname,ttzname))//如果证号书名存在，则标记为1
			flag=1;
			}
      fclose(fp);
	  fp=fopen(fileName,"r");//打开读者文件，删除借书信息
	  if(flag)
	  {
	  for (i=0;i<k;i++)//将读者文件复制到链表
	  {
	  fscanf(fp,"%d%s%s\n ",&tzhenghao,triqi,tzname);//读取文件信息
	  if(!((account==tzhenghao)&&!strcmp(ttzname,tzname)))
	  {
          n++;
		  if (n==1)
		  {
		      p1=p2=(struct reader*)malloc(LEN1);//新建链表
			  head=p1;
		  }
		  else
		  {
		        p2->next=p1;
				p2=p1;
				p1=(struct reader*)malloc(LEN1);//新建链表
          }
		  p1->jnum=tzhenghao;//复制证号
		  strcpy(p1->time,triqi);//复制日
		  strcpy(p1->tsnam,tzname);//复制书名
		  }}
		  if (n==0)
		  head=NULL;
		  else
		  {
		       p2->next=p1;
			   p1->next=NULL;
			   fclose(fp);
	      }
		  fp=fopen(fileName,"w");//清空读者文件
		  fclose(fp);
		  fp=fopen(fileName,"a");//追加信息
		  p=head;
		  for (;p!=NULL;)//把链表内容覆盖读者文件
		  {
		      fprintf(fp,"\n%-8d%-18s%-10s\n",p->jnum,p->time,p->tsnam);
			  p=p->next;
	      }
		  free(p);
		  fclose(fp);
		  }}

		  if(flag)//标记为1，即还书时更改库存
		  {
			  printf("还书成功!\n");
			  printf("请输入你对这本书的书评:\n");
			  scanf("%s", shuping);
			  fp4 = fopen(PATH_review, "a");
			  fprintf(fp4,"\n%s %s", ttzname, shuping);
			  fclose(fp4);
			  printf("按任意键退出");
			  n = 0;
			  flag = 0;
			  fp3=fopen(PATH_book,"r");//打开图书馆文件
			  k=tjzs();//获取图书馆文件个数
			  for (i=0;i<k;i++)//将图书馆文件复制到链表
			  {
			       fscanf(fp3,"%s%s%s%s%s%d",tshuhao,tname,tauthor,tchuban,tkind,&txcl);//读取信息
				   n++;
				   if (n==1)
				   {
				       lp1=lp2=(struct book*)malloc(LEN);//新建链表
					   lhead1=lp1;
				   }
				   else
				   {
				       lp2->next=lp1;
					   lp2=lp1;
					   lp1=(struct book*)malloc(LEN);//新建链表
				   }
				   strcpy(lp1->num,tshuhao);//复制书号
				   strcpy(lp1->nam,tname);//复制书名
				   strcpy(lp1->aut,tauthor);//复制作者
				   strcpy(lp1->pub,tchuban);//复制出版社
				   strcpy(lp1->cat,tkind);//复制类别
				   lp1->many=txcl; //复制现存量
				   }
				   if (n==0)
				   {
 	  		          lhead1=NULL;
				   }
				   else
				   {
				   	   lp2->next=lp1;
				   	   lp1->next=NULL;
				   	   fclose(fp3);
				   }
				   zp1=lhead1;
				   for (;zp1!=NULL;)
				   {
				        if(!(strcmp(zp1->nam,ttzname)))//寻找书名相同
						++(zp1->many);//现存量加1
						zp1=zp1->next;
					}
					fp3=fopen(PATH_book,"w");//清空图书馆文件
					fclose(fp);
					fp3=fopen(PATH_book,"a");//追加信息
					zp1=lhead1;
					for (;zp1!=NULL;)//把链表内容覆盖图书馆文件
					{
                         fprintf(fp3,"%-8s%-16s%-14s%-22s%-18s%-7d\n",
        				 zp1->num,zp1->nam,zp1->aut,zp1->pub,zp1->cat,zp1->many);
						 zp1=zp1->next;
				    }
					fclose(fp3);
					getch();//返回
					borrowmain();//调用借阅系统
					}
					else
					printf("不存在此信息!按任意键返回!");
					getch();//返回
					borrowmain();//调用借阅系统
}

void inquire(){
	FILE *fp;
	char fileName[256]={0};
	int username;
	char day[20],bookname[20],lastbookname[20];
	int account =atoi(uzhanghu);
	system("cls");
	sprintf(fileName,"%s%s%d%s",PATH_user,"\\",account,".txt");
	fp=fopen(fileName,"r");
	printf("用户%d已借书籍信息\n",account);
	if (fp==NULL)//这是账号密码txt文件路径
	{
		printf("亲，目前没有在借阅籍呢。\n");
		getch();
	 	system("cls");
		borrowmain();     //转回登录功能函数
	
    }
	printf("借阅日期：\t\t在借书目:\n");
	for(;!feof(fp);){
		fscanf(fp,"%d %s %s",&username,day,bookname);
		if(strcmp(lastbookname,bookname) && strcmp("预约",day))
			printf("%5s\t\t\t%5s\n",day,bookname);
		strcpy(lastbookname,bookname);
	}
	printf("*******************************\n");
	printf("按回车键前去还书，按ESC退回上一级\n");
	int i=getch();//暂停程序当i接收后继续下一条指令
    if(i==13){
		system("cls");
        bookreturn();}
	else if(i==27){
		system("cls");
		borrowmain();
	}
	fclose(fp);
}


void yuyue(){  //预约到馆提醒
	int tjzs(void);
	FILE *fp3;
	int username;
	int yuyue_flag=0;
	int account=atoi(uzhanghu);
	char day[20],bookname[20];
	char fileName[256] = {0};

	FILE *fp;
       int k=0,many=0,m=0,n=0;
       char  nam[20]={'\0'},aut[20]={'\0'},cat[20]={'\0'},pub[30]={'\0'},num[20]={'\0'};
       char i;

	sprintf(fileName,"%s%s%d%s",PATH_user,"\\",account,".txt");
	fp3 = fopen(fileName, "r");
	while(!feof(fp3)){
		   fscanf(fp3, "%d %s %s", &username, day, bookname);
		   if (!strcmp(day, "预约"))
		   {
			yuyue_flag=1;
			break;
		}
	}
	fclose(fp3);
	if(yuyue_flag){
	m=tjzs();
	fp=fopen(PATH_book,"r");
	   for (n=0;n<m;n++)
	   {
	    fscanf(fp,"%s%s%s%s%s%d",num,nam,aut,pub,cat,&many);
        if(!strcmp(bookname,nam))
        {
			if(many >0){
		  		gotoxy(52, 2);
				printf("------------------------");
				gotoxy(52, 3);
				printf("您预约的%s已到馆\n",nam);
				gotoxy(52, 4);
				printf("------------------------");
			}
        }
       }
	fclose(fp);
	}
}


