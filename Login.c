#include <stdio.h>
#include <conio.h>
#include <string.h>//����strlen����
#include <stdlib.h>//���а���system����
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
void logmenu()//��ʾ��¼�˵�
{

printf("\n\n\t��ӭʹ�ñ���������ѧͼ�����ϵͳ\n\n");
       
printf("----------------------------------------------");
                  
printf("\n\t\t------------");
printf("\n\t\t|1.��½ϵͳ|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|2.�����˺�|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|3.�޸�����|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|4.�˳�ϵͳ|\n");
printf("\t\t------------\n");

printf("\n\t    �밴��ѡ�񣬻س�ȷ��\n");
printf("----------------------------------------------\n");
return ;
}


void gotoxy(short x,short y)//�β�
{
	HANDLE hOut;
	COORD pos= {x,y};
	// ������ʼλ����1�У���3�У� 0�ǵ�1�� 2�ǵ�3��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
	//printf("��λ���λ������(%d,%d)\n",pos.X,pos.Y);
}
 
void paintWindow()       //���Ƶ�¼����
{
	int startX=8;
	int startY=6;
	int width=25;
	int height=20;
	int i=0;
	//��ӡ����   
	//��궨λ �ҹ��� ��  �� �� �� �� ��
	//���� y���� x �ڱ� (x-x+w)
	gotoxy(startX,startY);
	printf("��");
	for(i=0;i<width-2;i++)  //����ѭ������width-2��
	{	
		printf("�� ");
	}
	printf("��");
	//��� x���� y�ڱ� (y��y+height)
	for(i=1;i<=height-2;i++)
	{
		gotoxy(startX,startY+i);
		printf("��");
	}
	
	//�ұ� x���� =startx+width-1  y�ڱ� y �� y+height
	for(i=1;i<=height-2;i++)
	{
		gotoxy(startX+width*2-3,startY+i);
		printf("��");
	}
	//�ײ� x�ڱ仯    y���� ��x��x+width�� �� 
	gotoxy(startX,startY+height-1);
	printf("��");
	for(i=0;i<width-2;i++)
	{
		printf("�� ");	
	}
	printf("��");
 
	gotoxy(startX,startX+height);	
}
 
void usermain()     //�û���¼����
{
	void libmain();
	void logmain();
	int match(int m,char a[9]);
    char ch=0;
	int i=0;
	char password[9]={0};
	int account;
	system("cls");
	//�ַ����鲿�ֳ�ʼ��
	//����һ������
	paintWindow();
	//���Ʊ��� ��ǩ
	gotoxy(28,9);
	printf("��¼����");
	
    gotoxy(9+5,12);
	printf("�˺ţ�");
	
    gotoxy(9+5,16);
	printf("���룺");
	
	gotoxy(22,12);//��궨λ���û��������λ��
	//�û��������� �洢
	strcpy(uzhanghu, "");
	while(1)
	{
		ch=getch();
		if(ch=='\r'&&i==0)  //�κ����ݶ�û��
		{	
			continue;
		}
		if(ch=='\r'&&i>0||i==8)  //��������λ
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
		{		//�� if ������ڵ��û������˸�ʱ��ɾ��һ���ַ� �������˸��޸�
		if( i==0 )
		continue;
		putchar('\b');
		putchar(' ');
		putchar('\b');
		i = i-2;
		continue;
		}

	}
 
	gotoxy(22,16); //��궨λ�����������λ��
	i=0;//ʹ��ͬһ�������� ��Ҫ����
	//�������� �洢
	while(1)
	{
		ch=getch();
		if(ch=='\r'&&i==0)  //�κ����ݶ�û��
		{
			continue;
		}
		if(ch=='\r'&&i>0||i==8)  //��������λ
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
		{		//�� if ������ڵ��û������˸�ʱ��ɾ��һ���ַ� �������˸��޸�
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
		printf("����Ա��½�ɹ�!�����������");
		getch();
		Adminmain();   //����Ա��¼�����
	}
	else
	{
		account=atoi(uzhanghu);   //�ַ���ת����
		int zz=2,j,k,n;
		char hit=0;
		zz=match(account,password);
    	gotoxy(22,18); 
	 {
	 if(zz==1)
	 {
       printf("��½�ɹ�!�����������");
	   getch();
	   libmain();     //zhuandao��½�����
	 }
	else if(zz==-1)
		 {
		 printf("�������!");
		 getch();
		 system("cls");
		 logmain();
		 }
	else if(zz==0)
		 {
		 printf("�����ڴ��û�,���½��˻�");
		 getch();
		 system("cls");
		 logmain();
		 }
	}
	gotoxy(0,27);
}
	//��ʾ��¼�ɹ� ��¼ʧ��
    
  //��¼��֤  admin 123456
}

void logmain()//��¼���ܺ���
{
	void usermain();
	void create();
	void xgmm();
	char choose;
	logpaint();
	logmenu();
	scanf(" %c",&choose);
	switch(choose)//���ܺ���
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
		xgmm();//�޸�����
	  	break;}
	case'4':{
	  	system("cls");
    getch();
  	exit(0);
  	system ("cls");
	break;}
  }
}


int match(int m,char a[9])//ƥ�����ݿ��е��˺�����
{
	//�ж��û��˺�����
	FILE*fp;
	int n=0,i=0;
	int account;
	char password[9];

	if ((fp=fopen(PATH,"r"))==NULL)//�����˺�����txt�ļ�·��
	  {
         system ("cls");
		 printf("\n ��δ�����û�!���½��˻�");
		 getch();
	 	system("cls");
		logmain();     //ת�ص�¼���ܺ���
	
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



//��д��
void create ()
{
	
	FILE *fp;
	int account,accounta;
	char password[20] ,passworda[20],confirm[20];
	char hit=0;
	int len;
	system("cls");
	paintWindow();
	//���Ʊ��� ��ǩ
	gotoxy(28,9);
	printf("�����˻�");
	
    gotoxy(9+5,12);
	printf("���˺ţ�");
	
    gotoxy(9+5,14);
	printf("�����룺");
	
	gotoxy(9+5,16);
	printf("ȷ�����룺");
	
	gotoxy(22,12);
	fp=fopen(PATH,"r");
	for(;;)//������������ȷ�ϣ�������ͬ����ȷ��,��while(1)һ��
	{
	   
	   scanf("%d",&account);
	   for(;!feof(fp);)
      {
        
		fscanf(fp,"%d%s",&accounta,passworda);

        if(account==accounta)
        {
        	gotoxy(22,18);
			printf("�û��Ѵ��ڣ�");
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
		printf("�����˻�");
	
        gotoxy(9+5,12);
	    printf("���˺ţ�");
	    gotoxy(22,12);
	    printf("%d\n",account);
	    
    	gotoxy(9+5,14);
		printf("�����룺");
		gotoxy(22,14);
		while(len--)printf("%c",'*');
		
		gotoxy(9+5,16);
		printf("ȷ�����룺");
	   gotoxy(24,16);
	   int i = 0; //��¼���볤��
		char c; //����ʵ��������ʽ����
		while (1) {
    		c = _getch(); 
			if (c == '\r') { //�����س������������������
				break; 
			}
			else if (c == '\b') { //�����˸���Ҫɾ��ǰһ���Ǻ�
				printf("\b \b");  //�˸񣬴�һ���ո����˸�ʵ�������ÿո񸲸ǵ��Ǻ�
				--i;
			}
			else {
				confirm[i++] = c;//���ַ���������
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
		   printf("�����������벻һ��,�����������س�,�˳���ESC");
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
   printf("�����ɹ�,�����������");
   getch();
   system("cls");
   logmain();
}


int count()//ͳ���ı�accpass���˺��������
{
FILE *fp;
int account=0;
int n;
char password[20]={'\0'};
fp=fopen(PATH,"r");	//���ļ�
for (n=0;!feof(fp);n++)			//������ļ�
	fscanf(fp,"%d %s",&account,password);
fclose(fp);//�ر��ļ�
n--;
return (n);//���ظ���
}

void xg(int z,char m[20])			//�޸ĺ���,�����޸�����軹ͼ���txt�ļ��޸�
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
           if (z!=zhanghao1)//�Ƚ����֣�����ͬ���ֵ���Ϣ���Ƶ�����
          {
	            n++;//��ͬ����ֵΪ0��ִ��if������ѭ������ͬ��ִ��ֱ�������в�ͬ����������������
	            if (n==1)//��������
                {
		          p1=p2=(struct login*)malloc(LEN2);
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct login*)malloc(LEN2);//�½�����
                }
 				p1->account=zhanghao1;
                strcpy(p1->password,mima1);//�����˺�����
          }
       }
        if (n==0)
			 {
			 head=NULL;
			 }
			 else//������������ʣ��һ������ռ䣬���Է��
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 }
			  fp=fopen(PATH,"w");//����ļ���ֻд�򿪣�Ȼ��ر�
              fclose(fp);
              fp=fopen(PATH,"a");//׷���ļ�
              p=head;
            for (;p!=NULL;)//���������ݸ��ǵ��ļ�
   			{
   	   		 	fprintf(fp,"%d %s\n",p->account,p->password);
   	   			p=p->next;
	        }
	        fprintf(fp,"%d %s",z,m);
            fclose(fp);

}

void xgmm()//�޸�����
{

	   FILE *fp;
       int zh=0,k=0,many=0,m=0,n=0;
       int chazhao,hit;
       char mima[20]={'\0'},password1[20]={'\0'},oldmima[20]={'\0'};
       char  mm[20]={'\0'};
       char i;
       if ((fp=fopen(PATH,"r"))==NULL)//���ļ�
       {
	       system ("cls");
           printf("\n��¼�ļ�������!�����������");
  		   getch();
  		   system("cls");
		   logmain();
       }
	   system("cls");
	   paintWindow();
       gotoxy(28,9);
		printf("�޸�����");
	
        gotoxy(9+5,12);
	    printf("�˺ţ�");

	    
    	gotoxy(9+5,14);
		printf("ԭ���룺");
		
		gotoxy(9+5,16);
		printf("�����룺");
		
		gotoxy(9+5,18);
		printf("ȷ�����룺");
	    
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
				printf("�޸�����");
	
        		gotoxy(9+5,12);
	    		printf("�˺ţ�");
                gotoxy(22,12);
                printf("%d\n",chazhao);
	    
    			gotoxy(9+5,14);
				printf("ԭ���룺");
				gotoxy(22,14);
				printf("%s\n",oldmima);
		
				gotoxy(9+5,16);
				printf("�����룺");
				while(len--)printf("%c",'*');
				
		
		        gotoxy(9+5,18);
		        printf("ȷ�����룺");
		        int i = 0; //��¼���볤��
					char c; //����ʵ��������ʽ����
					while (1) 
					{
						c = _getch(); //�� _getch() �������룬�ַ�������ʾ����Ļ��
						if (c == '\r') { //�����س������������������
							break; //while ѭ���ĳ���
						}
						else if (c == '\b') { //�����˸���Ҫɾ��ǰһ���Ǻ�
							printf("\b \b");  //�˸񣬴�һ���ո����˸�ʵ�������ÿո񸲸ǵ��Ǻ�
							--i;
						}
						else {
							password1[i++] = c;//���ַ���������
							printf("*");     
						}
					}
				
	   			
	             if(strcmp(mima,password1)==0)
	   			 {
		            xg(chazhao,mima);
					gotoxy(22,20);
					printf("�޸�����ɹ�����������˳�");
		            getch();
				    system("cls");
					logmain();
	                
   			     }
       			  else
	   			  {
	       		   	  gotoxy(22,20);
					  printf("�����������벻һ��,��������˳�");
	       			  hit=getch();
		   			  system("cls");
				      logmain();

   				  }
			}
			else
			{
				gotoxy(22,20);
				printf("��������󣬰���������أ�");
				getch();
				system("cls");
				logmain();
	            
			}

        }
      }
	   gotoxy(22,20);
	   printf("�����ڴ��˺ţ������������");
		fclose(fp);//�޸Ľ���
		getch();
		system("cls");
		logmain();
}

