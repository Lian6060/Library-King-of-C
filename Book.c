#include <stdio.h>
#include "Book.h"
#include "common.h"




void libmenu()//显示登录菜单
{

printf("\n\t欢迎使用北京化工大学图书管理系统\n");
       
printf("----------------------------------------------");
                  
printf("\n\t\t------------");
printf("\n\t\t|1.查询图书|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|2.借还图书|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|3.浏览图书|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|4.返回上级|\n");
printf("\t\t------------\n");

printf("\n\t    请按键选择，回车确定\n");
printf("----------------------------------------------\n");
return ;

}

int tjzs()//统计图书文本个数
{
		FILE *fp;
		int txcl=0,n;
		float tprice=0;
		char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[20]={'\0'},tkind[20]={'\0'},tshuhao[20]={'\0'};
		fp=fopen(PATH_book,"r");//打开文件
		for (n=0;!feof(fp);n++)//逐个读文件
		fscanf(fp,"%s%s%s%s%s%d",tshuhao,tname,tauthor,tchuban,tkind,&txcl);
		n--;
		fclose(fp);//关闭文件
		return (n);//返回个数
}


void libmain(){
	int tjzs(void);
	void usermain();
	void borrowmain();
	void searchbook();
	void yuyue();
	void outsp();
	//void rankmenu();
	char c1 = 'a', ch = 'a';//初始化为‘a’
    int line= 4;//初始光标
    int choice = 1; // 因为光标在选项1上，所以就默认为1
    system("cls");
    libmenu();
	yuyue();
	outsp();
	//rankmenu();
	gotoxy(0, line);
    printf("\033[1;30;47m\t\t|1.查询图书|\033[0m");
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
				  printf("\t\t|2.借还图书|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|1.查询图书|\033[0m");
			  }
			  if (choice == 2)
			  {
				  gotoxy(0, line);
				  printf("\t\t|3.浏览图书|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|2.借还图书|\033[0m");
			  }
			  if (choice == 3)
			  {
				  gotoxy(0, line);
				  printf("\t\t|4.返回上级|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|3.浏览图书|\033[0m");
			  }
		  }

	  if (ch == DownKey && choice < 4)
	  {
		  choice += 1;
		  if (choice == 2)
		  {
			  gotoxy(0, line);
			  printf("\t\t|1.查询图书|");
			  line += 4;
			  gotoxy(0, line);
			  printf("\033[1;30;47m\t\t|2.借阅图书|\033[0m");
		  }
		  if (choice == 3)
		  {
			  gotoxy(0, line);
			  printf("\t\t|2.借阅图书|");
			  line += 4;
			  gotoxy(0, line);
			  printf("\033[1;30;47m\t\t|3.浏览图书|\033[0m");
		  }
		  if (choice == 4)
		  {
			  gotoxy(0, line);
			  printf("\t\t|3.浏览图书|");
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
	  searchbook();
	  break;
		case 2:
      borrowmain();
      break;
	  	case 3:
	  sortmain();
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




int cmpChStr(char * str,char * target){
    //中文占两位
    int i,j,tag = 0;
    for(i = 0;i < strlen(str);i+=2){
        for(j = 0;j < strlen(target);j+=2){
            if(str[i] == target[j] && str[i+1] == target[j+1])
                tag++;
        }
    }
    return tag == strlen(str) / 2 ? 1 : 0;
}

 
int vagueSearch(char * source,char * target){
    if (strstr(target, source) != NULL || cmpChStr(target, source)) {
        return 1;
    }
    return 0;
}

void searchbook()//查询图书
{
	   FILE *fp;
       int k=0,many=0,m=0,n=0;
	   float price=0;
       char  nam[20]={'\0'},aut[20]={'\0'},cat[20]={'\0'},pub[20]={'\0'},num[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen(PATH_book,"r"))==NULL)//打开文件
       {
	       system ("cls");
           printf("\n记录文件不存在!按任意键返回");
  		   getch();
		   libmain();
       }
	   system("cls");
       printf("请输入书号,书名,作者或类别查询：\n");
       scanf("%s",chazhao);
       system ("cls");
       m=tjzs();
	   
	   for (n=0;n<m;n++)
	   {
	    fscanf(fp,"%s%s%s%s%s%d",num,nam,aut,pub,cat,&many);
        if(!strcmp(chazhao,num)||vagueSearch(chazhao,nam)||vagueSearch(chazhao,aut)||!strcmp(chazhao,cat))
        {
        	if(k==0)
            {
			  printf("查询结果:\n\n");
			  printf("书号\t书名\t\t作者\t\t出版社\t\t    类别\t\t现存量\n");
            }
			printf("%-8s%-16s%-16s%-20s%-20s%-16d\n",num,nam,aut,pub,cat,many);
            k++;
        }
       }
        if (k==0)//文件夹为空则输出无记录并返回上一层
        { system ("cls");
        printf("\n无符合记录!\n");
        getch();
        libmain();
		}
		fclose(fp);//查询结束
		getch();
		libmain();
}



void sortmenu(){
printf("\n\t\t\t       浏览图书\n");
       
printf("------------------------------------------------------------------------");

printf("\n 文学类          历史类          哲学类          教育类          军事类\n");

printf("------------------------------------------------------------------------\n");

}

void sortmain(){
void scan(int choice);
char c1 = 'a', ch = 'a';//初始化为‘a’
  int column= 1;//初始光标
  int choice = 0; // 因为光标在选项1上，所以就默认为1
  system("cls");
  sortmenu();
  gotoxy(column, 3);
    printf("\033[1;30;47m文学类\033[0m");
    while ((c1 = getch()) != '\r' || c1 != 13)
    {
	  ch = getch();
	  if (c1 == -32)
		  if (ch == LeftKey && choice > 0)
		  {
			  choice -= 1;
			  if (choice == 0)
			  {
				  gotoxy(column, 3);
				  printf("历史类");
				  column -= 16;
				  gotoxy(column, 3);
				  printf("\033[1;30;47m文学类\033[0m");
			  }
			  if (choice == 1)
			  {
				  gotoxy(column, 3);
				  printf("哲学类");
				  column -= 16;
				  gotoxy(column, 3);
				  printf("\033[1;30;47m历史类\033[0m");
			  }
			  if (choice == 2)
			  {
				  gotoxy(column, 3);
				  printf("教育类");
				  column -= 16;
				  gotoxy(column, 3);
				  printf("\033[1;30;47m哲学类\033[0m");
			  }
			  if (choice == 3)
			  {
				  gotoxy(column, 3);
				  printf("军事类");
				  column -= 16;
				  gotoxy(column, 3);
				  printf("\033[1;30;47m教育类\033[0m");
			  }
		  }

	  if (ch == RightKey && choice < 4)
	  {
		  choice += 1;
		  if (choice == 1)
		  {
			  gotoxy(column, 3);
			  printf("文学类");
			  column += 16;
			  gotoxy(column, 3);
			  printf("\033[1;30;47m历史类\033[0m");
		  }
		  if (choice == 2)
		  {
			  gotoxy(column, 3);
			  printf("历史类");
			  column += 16;
			  gotoxy(column, 3);
			  printf("\033[1;30;47m哲学类\033[0m");
		  }
		  if (choice == 3)
		  {
			  gotoxy(column, 3);
			  printf("哲学类");
			  column += 16;
			  gotoxy(column, 3);
			  printf("\033[1;30;47m教育类\033[0m");
		  }
		  if (choice == 4)
		  {
			  gotoxy(column, 3);
			  printf("教育类");
			  column += 16;
			  gotoxy(column, 3);
			  printf("\033[1;30;47m军事类\033[0m");
		  }
	  }
	  	gotoxy(0, 6);
        //具体实现选择的代码
		scan(choice);
		}
		getch();
		libmain();
		system("pause");

}


void scan(int choice){
	char leibie[10];
	strcpy(leibie, sortlb[choice]);
	FILE *fp;
    int k=0,many=0,m=0,n=0;
    char  nam[20]={'\0'},aut[20]={'\0'},cat[20]={'\0'},pub[20]={'\0'},num[20]={'\0'};
    fp=fopen(PATH_book,"r");
	m=tjzs();
	for (n=0;n<m;n++)
	{
	fgets(buffer , MAX , fp);
	sscanf(buffer,"%s %s %s %s %s %d",num,nam,aut,pub,cat,&many);
    if(!strcmp(leibie,cat))
        {
        	if(k==0)
            {
			  printf("书号\t书名\t\t作者\t\t出版社\t\t类别\t现存量\n");
            }
			printf("%-8s%-16s%-12s%-20s%-12s%-16d\n",num,nam,aut,pub,cat,many);
            k++;
        }
    }
	int o = 10;
	while(o--)
		printf("                                                                  ");
	if (k == 0) // 文件夹为空则输出无记录并返回上一层
	{
        printf("\n无符合记录!\n");
		}
		fclose(fp);//查询结束
}


/*

void sort(struct rank a[10000000],int k)
{
	int i,j;
	struct rank temp;
	for(i=0;i<=k-1;i++)
	{
		for(j=0;j<k-1-i;j++)
		{
			if(a[j].nn<a[j+1].nn)
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
*/
/*
void rankmenu()
{
	
	FILE *fp,*fcount;
	int i,lenght=0;
	int account,n,k=0;
	char password[20],fileName[100],c[100];
	struct rank s[k];
	fp=fopen(PATH,"r");
	for(;!feof(fp);)
      {
      	fscanf(fp,"%d %s",&account,password);
	    sprintf(fileName,"%s%s%d%s",PATH_user,"\\",account,".txt");
	    fcount=fopen(fileName,"r");
    	for (n=0;!feof(fcount);n++)
			fscanf(fcount,"%s",c);//逐个读文件
			n--;
    	//输出文件中的行数 
        s[k].accountt=account;
        s[k].nn=n/3;
		//加入结构体 结构体排序 
        k++;
		printf("%ld %d\n", s[0].accountt, s[0].nn);
		fclose(fcount);
        }
	  //sort(s,k);
	  //for(i=0;i<k;i++)
	  //{
	  	
	  //}
	  fclose(fp);
 }
*/


 void outsp(){
	FILE *fp2;
	char bookname[20], shuping[512];
	int num = 0;
	int account = atoi(uzhanghu);
	srand(account);
	int randnum=rand()%3;
	fp2 = fopen(PATH_review, "r");
	for (num=0;!feof(fp2); num++){
		fscanf(fp2, "%s %s", bookname, shuping);
		if(num==randnum)
			break;
	}
	fclose(fp2);
	gotoxy(52, 7);
	printf("--------------%s--------------", bookname);
	int line = 8;
	gotoxy(52, line);
	for (int i = 0; i < strlen(shuping); i++){
		printf("%c", shuping[i]);
		if(i%34==0){
			line++;
			gotoxy(52, line);
		}
	}
	line+=2;
	gotoxy(52, line);
	printf("--------------%s--------------", bookname);
 }