#include <stdio.h>
#include "Book.h"
#include "common.h"




void libmenu()//��ʾ��¼�˵�
{

printf("\n\t��ӭʹ�ñ���������ѧͼ�����ϵͳ\n");
       
printf("----------------------------------------------");
                  
printf("\n\t\t------------");
printf("\n\t\t|1.��ѯͼ��|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|2.�軹ͼ��|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|3.���ͼ��|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|4.�����ϼ�|\n");
printf("\t\t------------\n");

printf("\n\t    �밴��ѡ�񣬻س�ȷ��\n");
printf("----------------------------------------------\n");
return ;

}

int tjzs()//ͳ��ͼ���ı�����
{
		FILE *fp;
		int txcl=0,n;
		float tprice=0;
		char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[20]={'\0'},tkind[20]={'\0'},tshuhao[20]={'\0'};
		fp=fopen(PATH_book,"r");//���ļ�
		for (n=0;!feof(fp);n++)//������ļ�
		fscanf(fp,"%s%s%s%s%s%d",tshuhao,tname,tauthor,tchuban,tkind,&txcl);
		n--;
		fclose(fp);//�ر��ļ�
		return (n);//���ظ���
}


void libmain(){
	int tjzs(void);
	void usermain();
	void borrowmain();
	void searchbook();
	void yuyue();
	void outsp();
	//void rankmenu();
	char c1 = 'a', ch = 'a';//��ʼ��Ϊ��a��
    int line= 4;//��ʼ���
    int choice = 1; // ��Ϊ�����ѡ��1�ϣ����Ծ�Ĭ��Ϊ1
    system("cls");
    libmenu();
	yuyue();
	outsp();
	//rankmenu();
	gotoxy(0, line);
    printf("\033[1;30;47m\t\t|1.��ѯͼ��|\033[0m");
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
				  printf("\t\t|2.�軹ͼ��|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|1.��ѯͼ��|\033[0m");
			  }
			  if (choice == 2)
			  {
				  gotoxy(0, line);
				  printf("\t\t|3.���ͼ��|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|2.�軹ͼ��|\033[0m");
			  }
			  if (choice == 3)
			  {
				  gotoxy(0, line);
				  printf("\t\t|4.�����ϼ�|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|3.���ͼ��|\033[0m");
			  }
		  }

	  if (ch == DownKey && choice < 4)
	  {
		  choice += 1;
		  if (choice == 2)
		  {
			  gotoxy(0, line);
			  printf("\t\t|1.��ѯͼ��|");
			  line += 4;
			  gotoxy(0, line);
			  printf("\033[1;30;47m\t\t|2.����ͼ��|\033[0m");
		  }
		  if (choice == 3)
		  {
			  gotoxy(0, line);
			  printf("\t\t|2.����ͼ��|");
			  line += 4;
			  gotoxy(0, line);
			  printf("\033[1;30;47m\t\t|3.���ͼ��|\033[0m");
		  }
		  if (choice == 4)
		  {
			  gotoxy(0, line);
			  printf("\t\t|3.���ͼ��|");
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
			printf("�벻Ҫ������ѡ�\n");
			getch();
			system("cls");
			break;
		}
    system("pause");

}




int cmpChStr(char * str,char * target){
    //����ռ��λ
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

void searchbook()//��ѯͼ��
{
	   FILE *fp;
       int k=0,many=0,m=0,n=0;
	   float price=0;
       char  nam[20]={'\0'},aut[20]={'\0'},cat[20]={'\0'},pub[20]={'\0'},num[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen(PATH_book,"r"))==NULL)//���ļ�
       {
	       system ("cls");
           printf("\n��¼�ļ�������!�����������");
  		   getch();
		   libmain();
       }
	   system("cls");
       printf("���������,����,���߻�����ѯ��\n");
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
			  printf("��ѯ���:\n\n");
			  printf("���\t����\t\t����\t\t������\t\t    ���\t\t�ִ���\n");
            }
			printf("%-8s%-16s%-16s%-20s%-20s%-16d\n",num,nam,aut,pub,cat,many);
            k++;
        }
       }
        if (k==0)//�ļ���Ϊ��������޼�¼��������һ��
        { system ("cls");
        printf("\n�޷��ϼ�¼!\n");
        getch();
        libmain();
		}
		fclose(fp);//��ѯ����
		getch();
		libmain();
}



void sortmenu(){
printf("\n\t\t\t       ���ͼ��\n");
       
printf("------------------------------------------------------------------------");

printf("\n ��ѧ��          ��ʷ��          ��ѧ��          ������          ������\n");

printf("------------------------------------------------------------------------\n");

}

void sortmain(){
void scan(int choice);
char c1 = 'a', ch = 'a';//��ʼ��Ϊ��a��
  int column= 1;//��ʼ���
  int choice = 0; // ��Ϊ�����ѡ��1�ϣ����Ծ�Ĭ��Ϊ1
  system("cls");
  sortmenu();
  gotoxy(column, 3);
    printf("\033[1;30;47m��ѧ��\033[0m");
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
				  printf("��ʷ��");
				  column -= 16;
				  gotoxy(column, 3);
				  printf("\033[1;30;47m��ѧ��\033[0m");
			  }
			  if (choice == 1)
			  {
				  gotoxy(column, 3);
				  printf("��ѧ��");
				  column -= 16;
				  gotoxy(column, 3);
				  printf("\033[1;30;47m��ʷ��\033[0m");
			  }
			  if (choice == 2)
			  {
				  gotoxy(column, 3);
				  printf("������");
				  column -= 16;
				  gotoxy(column, 3);
				  printf("\033[1;30;47m��ѧ��\033[0m");
			  }
			  if (choice == 3)
			  {
				  gotoxy(column, 3);
				  printf("������");
				  column -= 16;
				  gotoxy(column, 3);
				  printf("\033[1;30;47m������\033[0m");
			  }
		  }

	  if (ch == RightKey && choice < 4)
	  {
		  choice += 1;
		  if (choice == 1)
		  {
			  gotoxy(column, 3);
			  printf("��ѧ��");
			  column += 16;
			  gotoxy(column, 3);
			  printf("\033[1;30;47m��ʷ��\033[0m");
		  }
		  if (choice == 2)
		  {
			  gotoxy(column, 3);
			  printf("��ʷ��");
			  column += 16;
			  gotoxy(column, 3);
			  printf("\033[1;30;47m��ѧ��\033[0m");
		  }
		  if (choice == 3)
		  {
			  gotoxy(column, 3);
			  printf("��ѧ��");
			  column += 16;
			  gotoxy(column, 3);
			  printf("\033[1;30;47m������\033[0m");
		  }
		  if (choice == 4)
		  {
			  gotoxy(column, 3);
			  printf("������");
			  column += 16;
			  gotoxy(column, 3);
			  printf("\033[1;30;47m������\033[0m");
		  }
	  }
	  	gotoxy(0, 6);
        //����ʵ��ѡ��Ĵ���
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
			  printf("���\t����\t\t����\t\t������\t\t���\t�ִ���\n");
            }
			printf("%-8s%-16s%-12s%-20s%-12s%-16d\n",num,nam,aut,pub,cat,many);
            k++;
        }
    }
	int o = 10;
	while(o--)
		printf("                                                                  ");
	if (k == 0) // �ļ���Ϊ��������޼�¼��������һ��
	{
        printf("\n�޷��ϼ�¼!\n");
		}
		fclose(fp);//��ѯ����
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
			fscanf(fcount,"%s",c);//������ļ�
			n--;
    	//����ļ��е����� 
        s[k].accountt=account;
        s[k].nn=n/3;
		//����ṹ�� �ṹ������ 
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