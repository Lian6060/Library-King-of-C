#include <stdio.h>
#include <conio.h>
#include <string.h>//包含strlen函数
#include <stdlib.h>//其中包含system函数
#include "Login.h"
#include "Admin.c"
#include "Book.c"
#include "Borrow.c"
#include "common.h"


#ifdef _WIN32
#include <Windows.h>
#endif

void logpaint()
{
    
	printf("          _______        __          _____________             ____                     __             \n");
	printf("       /         \\      \\  \\        \\ ____________\\      _____\\ ___\\ ______            || |            _____________________ \n");
	printf("      /   ____    \\    _\\ _\\ ___     ___||______       \\ _________________\\           || |           \\ ________   _________\\  \n");
	printf("     /   /    \\ ____|  ||________||  |___  ______\\            ________           ______/  /______               | |            \n");
	printf("    ||  /                       |||     / /     //          \\ ________\\        \\ ______   _______\\              | |    \n");
	printf("   ||  ||                      |||   __/ /_____//__        _______________            ||  ||              ______| |______\n");
	printf("   ||  ||                     |||   |______________|      \\ ______________\\          //    \\\\            \\ ______   ______\\  \n");
	printf("    ||  \\     _____         ||      ______________        ________________          //      \\\\                  | |             \n");
	printf("      \\  \\____//     |     ||  //   ||    ____    ||      ||    _______    ||      //        \\\\                 | |            \n");
	printf("      \\            //      ||__//   ||   |____|   ||      ||   |_______|   ||     //           \\\\     __________| |___________   \n");
	printf("       \\  ______ //       |_____//  ||____________||      ||_______________||    //             \\\\  \\ ________________________\\  \n");

}
void logmenu()//显示登录菜单
{

printf("\n\n\t欢迎使用北京化工大学图书管理系统\n\n");
       
printf("----------------------------------------------");
                  
printf("\n\t\t------------");
printf("\n\t\t|1.登陆系统|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|2.创建账号|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|3.修改密码|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|4.退出系统|\n");
printf("\t\t------------\n");

printf("\n\t    请按键选择，回车确定\n");
printf("----------------------------------------------\n");
return ;
}


void gotoxy(short x,short y)//形参
{
	HANDLE hOut;
	COORD pos= {x,y};
	// 光标的起始位（第1列，第3行） 0是第1列 2是第3行
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
	//printf("定位光标位置搜索(%d,%d)\n",pos.X,pos.Y);
}
 
void paintWindow()       //绘制登录窗口
{
	int startX=8;
	int startY=6;
	int width=25;
	int height=20;
	int i=0;
	//打印顶部   
	//光标定位 找规律 ┗  ┛ ┏ ┓ ┃ ━
	//顶部 y不变 x 在变 (x-x+w)
	gotoxy(startX,startY);
	printf("┏");
	for(i=0;i<width-2;i++)  //控制循环次数width-2次
	{	
		printf("━ ");
	}
	printf("┓");
	//左边 x不变 y在变 (y到y+height)
	for(i=1;i<=height-2;i++)
	{
		gotoxy(startX,startY+i);
		printf("┃");
	}
	
	//右边 x不变 =startx+width-1  y在变 y 到 y+height
	for(i=1;i<=height-2;i++)
	{
		gotoxy(startX+width*2-3,startY+i);
		printf("┃");
	}
	//底部 x在变化    y不变 （x到x+width） ━ 
	gotoxy(startX,startY+height-1);
	printf("┗");
	for(i=0;i<width-2;i++)
	{
		printf("━ ");	
	}
	printf("┛");
 
	gotoxy(startX,startX+height);	
}
 
void usermain()     //用户登录界面
{
	void libmain();
	void logmain();
	int match(int m,char a[9]);
    char ch=0;
	int i=0;
	char password[9]={0};
	int account;
	system("cls");
	//字符数组部分初始化
	//绘制一个窗口
	paintWindow();
	//绘制标题 标签
	gotoxy(28,9);
	printf("登录窗口");
	
    gotoxy(9+5,12);
	printf("账号：");
	
    gotoxy(9+5,16);
	printf("密码：");
	
	gotoxy(22,12);//光标定位在用户名输入的位置
	//用户名的输入 存储
	strcpy(uzhanghu, "");
	while(1)
	{
		ch=getch();
		if(ch=='\r'&&i==0)  //任何内容都没输
		{	
			continue;
		}
		if(ch=='\r'&&i>0||i==8)  //长度最多八位
		{
			break;
		}
		if(ch>='0'&&ch<='9' || ch>='a'&&ch<='z'|| ch>='A'&&ch<='Z')
		{
			putch(ch);
			uzhanghu[i]=ch;
			++i;
		}	
		if( ch==8 )
		{		//此 if 语句用于当用户输入退格时，删掉一个字符 输错可以退格修改
		if( i==0 )
		continue;
		putchar('\b');
		putchar(' ');
		putchar('\b');
		i = i-2;
		continue;
		}

	}
 
	gotoxy(22,16); //光标定位在密码输入的位置
	i=0;//使用同一个计数器 需要重置
	//密码输入 存储
	while(1)
	{
		ch=getch();
		if(ch=='\r'&&i==0)  //任何内容都没输
		{
			continue;
		}
		if(ch=='\r'&&i>0||i==8)  //长度最多八位
		{
			break;
		}
		if(ch>='0'&&ch<='9' || ch>='a'&&ch<='z'|| ch>='A'&&ch<='Z')
		{
			putch('*');
			password[i]=ch;
			++i;
		}	
		if( ch==8 )
		{		//此 if 语句用于当用户输入退格时，删掉一个字符 输错可以退格修改
		if( i==0 )
		continue;
		putchar('\b');
		putchar(' ');
		putchar('\b');
		i = i-2;
		continue;
		}
	}
	if(!strcmp(uzhanghu,"admin") && !strcmp(password,"admin"))
	{
		gotoxy(22,18); 
		printf("管理员登陆成功!按任意键继续");
		getch();
		Adminmain();   //管理员登录后界面
	}
	else
	{
		account=atoi(uzhanghu);   //字符串转数字
		int zz=2,j,k,n;
		char hit=0;
		zz=match(account,password);
    	gotoxy(22,18); 
	 {
	 if(zz==1)
	 {
       printf("登陆成功!按任意键继续");
	   getch();
	   libmain();     //zhuandao登陆后界面
	 }
	else if(zz==-1)
		 {
		 printf("密码错误!");
		 getch();
		 system("cls");
		 logmain();
		 }
	else if(zz==0)
		 {
		 printf("不存在此用户,请新建账户");
		 getch();
		 system("cls");
		 logmain();
		 }
	}
	gotoxy(0,27);
}
	//显示登录成功 登录失败
    
  //登录验证  admin 123456
}

void logmain()//登录功能函数
{
	void usermain();
	void create();
	void xgmm();
	char choose;
	logpaint();
	logmenu();
	scanf(" %c",&choose);
	switch(choose)//功能函数
  {
	case'1':{
	    system("cls");
		usermain();
	    break;}
	case'2':{
		system("cls");
		create();
	  	break;}
	case'3':{
	  	system("cls");
		xgmm();//修改密码
	  	break;}
	case'4':{
	  	system("cls");
    getch();
  	exit(0);
  	system ("cls");
	break;}
  }
}


int match(int m,char a[9])//匹配数据库中的账号密码
{
	//判断用户账号密码
	FILE*fp;
	int n=0,i=0;
	int account;
	char password[9];

	if ((fp=fopen(PATH,"r"))==NULL)//这是账号密码txt文件路径
	  {
         system ("cls");
		 printf("\n 还未存在用户!请新建账户");
		 getch();
	 	system("cls");
		logmain();     //转回登录功能函数
	
      }

        for(;!feof(fp);)
      {
        fscanf(fp,"%d %s",&account,password);
        if(m==account)
        {
        	if(!strcmp(a,password))
				return 1;
			else
			{
				return -1;
		   }
	    }
	  }
	  return 0;
 }


void creat_user_book(int str0){

FILE *fcount;

char fileName[256] = {0};

strcpy(fileName, PATH_user);


sprintf(fileName,"%s%s%d%s",fileName,"\\",str0,".txt");

fcount=fopen(fileName,"w+");

fclose(fcount);

}



//新写的
void create ()
{
	
	FILE *fp;
	int account,accounta;
	char password[20] ,passworda[20],confirm[20];
	char hit=0;
	int len;
	system("cls");
	paintWindow();
	//绘制标题 标签
	gotoxy(28,9);
	printf("创建账户");
	
    gotoxy(9+5,12);
	printf("新账号：");
	
    gotoxy(9+5,14);
	printf("新密码：");
	
	gotoxy(9+5,16);
	printf("确认密码：");
	
	gotoxy(22,12);
	fp=fopen(PATH,"r");
	for(;;)//输入两次密码确认，两次相同才能确认,和while(1)一样
	{
	   
	   scanf("%d",&account);
	   for(;!feof(fp);)
      {
        
		fscanf(fp,"%d%s",&accounta,passworda);

        if(account==accounta)
        {
        	gotoxy(22,18);
			printf("用户已存在！");
        	getch();
			system("cls");
        	logmain();
		}}
		fclose(fp);
		fp=fopen(PATH,"a");
    	gotoxy(22,14);
	   scanf("%s",password);
	   len=strlen(password);
	   system("cls");
	    paintWindow();
	    gotoxy(28,9);
		printf("创建账户");
	
        gotoxy(9+5,12);
	    printf("新账号：");
	    gotoxy(22,12);
	    printf("%d\n",account);
	    
    	gotoxy(9+5,14);
		printf("新密码：");
		gotoxy(22,14);
		while(len--)printf("%c",'*');
		
		gotoxy(9+5,16);
		printf("确认密码：");
	   gotoxy(24,16);
	   int i = 0; //记录密码长度
		char c; //用于实现密码隐式输入
		while (1) {
    		c = _getch(); 
			if (c == '\r') { //遇到回车，表明密码输入结束
				break; 
			}
			else if (c == '\b') { //遇到退格，需要删除前一个星号
				printf("\b \b");  //退格，打一个空格，再退格，实质上是用空格覆盖掉星号
				--i;
			}
			else {
				confirm[i++] = c;//将字符放入数组
				printf("*");     
			}
		}
	   if(strcmp(password,confirm)==0)
	   {
	       fprintf(fp,"\n%d %s",account,password);
		   creat_user_book(account);
		   break;
       }
       else
	   {
	       gotoxy(11,18);
		   printf("两次输入密码不一致,继续创建按回车,退出按ESC");
	       hit=getch();
		   if(hit=27){
				system("cls");
		   		logmain();
			}
			else if(hit=13){
				system("cls");
				create();
			}

		         }
   }
   gotoxy(22,18);
   fclose(fp);
   printf("创建成功,按任意键返回");
   getch();
   system("cls");
   logmain();
}


int count()//统计文本accpass中账号密码个数
{
FILE *fp;
int account=0;
int n;
char password[20]={'\0'};
fp=fopen(PATH,"r");	//打开文件
for (n=0;!feof(fp);n++)			//逐个读文件
	fscanf(fp,"%d %s",&account,password);
fclose(fp);//关闭文件
n--;
return (n);//返回个数
}

void xg(int z,char m[20])			//修改函数,用于修改密码借还图书的txt文件修改
{
	FILE *fp;
	int zhanghao1,n,j,k;
	char mima1[20];
	struct login *head,*p,*p1,*p2;

	 fp=fopen(PATH,"r");
	   j =count();

	   for (k=0;k<=j;k++)
       {
	       fscanf(fp,"%d %s",&zhanghao1,mima1);
           if (z!=zhanghao1)//比较名字，将不同名字的信息复制到链表
          {
	            n++;//相同返回值为0不执行if语句继续循环，不同则执行直到将所有不同的书名建立成链表
	            if (n==1)//建立链表
                {
		          p1=p2=(struct login*)malloc(LEN2);
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct login*)malloc(LEN2);//新建链表
                }
 				p1->account=zhanghao1;
                strcpy(p1->password,mima1);//复制账号密码
          }
       }
        if (n==0)
			 {
			 head=NULL;
			 }
			 else//建立链表的最后剩余一个储存空间，所以封底
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 }
			  fp=fopen(PATH,"w");//清空文件，只写打开，然后关闭
              fclose(fp);
              fp=fopen(PATH,"a");//追加文件
              p=head;
            for (;p!=NULL;)//把链表内容覆盖到文件
   			{
   	   		 	fprintf(fp,"%d %s\n",p->account,p->password);
   	   			p=p->next;
	        }
	        fprintf(fp,"%d %s",z,m);
            fclose(fp);

}

void xgmm()//修改密码
{

	   FILE *fp;
       int zh=0,k=0,many=0,m=0,n=0;
       int chazhao,hit;
       char mima[20]={'\0'},password1[20]={'\0'},oldmima[20]={'\0'};
       char  mm[20]={'\0'};
       char i;
       if ((fp=fopen(PATH,"r"))==NULL)//打开文件
       {
	       system ("cls");
           printf("\n记录文件不存在!按任意键返回");
  		   getch();
  		   system("cls");
		   logmain();
       }
	   system("cls");
	   paintWindow();
       gotoxy(28,9);
		printf("修改密码");
	
        gotoxy(9+5,12);
	    printf("账号：");

	    
    	gotoxy(9+5,14);
		printf("原密码：");
		
		gotoxy(9+5,16);
		printf("新密码：");
		
		gotoxy(9+5,18);
		printf("确认密码：");
	    
		gotoxy(22,12);
       scanf("%d",&chazhao);
       
	   gotoxy(22,14);
	   scanf("%s",&oldmima);
	   
	   m =count();
	   for (n=0;n<=m;n++)
	   {
	    fscanf(fp,"%d %s",&zh,mm);
        if(zh==chazhao)
        {
        	if(!strcmp(mm,oldmima))
        	{
        		gotoxy(22,16);
        		scanf("%s",mima);
				int len=strlen(mima);
				system("cls");
				paintWindow();
				gotoxy(28,9);
				printf("修改密码");
	
        		gotoxy(9+5,12);
	    		printf("账号：");
                gotoxy(22,12);
                printf("%d\n",chazhao);
	    
    			gotoxy(9+5,14);
				printf("原密码：");
				gotoxy(22,14);
				printf("%s\n",oldmima);
		
				gotoxy(9+5,16);
				printf("新密码：");
				while(len--)printf("%c",'*');
				
		
		        gotoxy(9+5,18);
		        printf("确认密码：");
		        int i = 0; //记录密码长度
					char c; //用于实现密码隐式输入
					while (1) 
					{
						c = _getch(); //用 _getch() 函数输入，字符不会显示在屏幕上
						if (c == '\r') { //遇到回车，表明密码输入结束
							break; //while 循环的出口
						}
						else if (c == '\b') { //遇到退格，需要删除前一个星号
							printf("\b \b");  //退格，打一个空格，再退格，实质上是用空格覆盖掉星号
							--i;
						}
						else {
							password1[i++] = c;//将字符放入数组
							printf("*");     
						}
					}
				
	   			
	             if(strcmp(mima,password1)==0)
	   			 {
		            xg(chazhao,mima);
					gotoxy(22,20);
					printf("修改密码成功，按任意键退出");
		            getch();
				    system("cls");
					logmain();
	                
   			     }
       			  else
	   			  {
	       		   	  gotoxy(22,20);
					  printf("两次输入密码不一致,按任意键退出");
	       			  hit=getch();
		   			  system("cls");
				      logmain();

   				  }
			}
			else
			{
				gotoxy(22,20);
				printf("旧密码错误，按任意键返回！");
				getch();
				system("cls");
				logmain();
	            
			}

        }
      }
	   gotoxy(22,20);
	   printf("不存在此账号，按任意键返回");
		fclose(fp);//修改结束
		getch();
		system("cls");
		logmain();
}

