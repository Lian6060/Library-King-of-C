#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include"Borrow.h"
#include "common.h"

void borrowmenu()//��ʾ����Ա��¼�˵�
{
system("cls");



printf("\n\t��ӭʹ�ñ���������ѧͼ�����ϵͳ\n");
       
printf("----------------------------------------------");
                  
printf("\n\t\t------------");
printf("\n\t\t|1.����ϵͳ|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|2.����ϵͳ|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|3.��ѯ����|\n");
printf("\t\t------------\n");

printf("\n\t\t------------");
printf("\n\t\t|4.�����ϼ�|\n");
printf("\t\t------------\n");

printf("\n\t    �밴��ѡ�񣬻س�ȷ��\n");
printf("----------------------------------------------\n");
return ;


}


void borrowmain(){
	void borrow(); //���麯��
	void bookreturn();//���麯��
	void inquire();//��ѯ����
	void libmain();
	char c1 = 'a', ch = 'a';//��ʼ��Ϊ��a��
    int line= 4;//��ʼ���
    int choice = 1; // ��Ϊ�����ѡ��1�ϣ����Ծ�Ĭ��Ϊ1
    system("cls");
    borrowmenu();
	gotoxy(0, line);
    printf("\033[1;30;47m\t\t|1.����ϵͳ|\033[0m");
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
				  printf("\t\t|2.����ϵͳ|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|1.����ϵͳ|\033[0m");
			  }
			  if (choice == 2)
			  {
				  gotoxy(0, line);
				  printf("\t\t|3.��ѯ����|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|2.����ϵͳ|\033[0m");
			  }
			  if (choice == 3)
			  {
				  gotoxy(0, line);
				  printf("\t\t|4.�����ϼ�|");
				  line -= 4;
				  gotoxy(0, line);
				  printf("\033[1;30;47m\t\t|3.��ѯ����|\033[0m");
			  }
		  }

	  if (ch == DownKey && choice < 4)
	  {
		  choice += 1;
		  if (choice == 2)
		  {
			  gotoxy(0, line);
			  printf("\t\t|1.����ϵͳ|");
			  line += 4;
			  gotoxy(0, line);
			  printf("\033[1;30;47m\t\t|2.����ϵͳ|\033[0m");
		  }
		  if (choice == 3)
		  {
			  gotoxy(0, line);
			  printf("\t\t|2.����ϵͳ|");
			  line += 4;
			  gotoxy(0, line);
			  printf("\033[1;30;47m\t\t|3.��ѯ����|\033[0m");
		  }
		  if (choice == 4)
		  {
			  gotoxy(0, line);
			  printf("\t\t|3.��ѯ����|");
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
			printf("�벻Ҫ������ѡ�\n");
			getch();
			system("cls");
			break;
		}
    system("pause");

}




void borrow()//���麯��
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
		printf("\n ͼ����޿��!��������˳�!");
		getch();
		exit(0);
	}
	else
	{
        printf("\n�������������:\n������:");
		scanf("%s",zname);
    k= tjzs();//ͳ��ͼ����ļ�����

	for (i=0;i<k;i++)//�Ƚ�ͼ����Ϣ�����������Ŀ��
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
			strcpy(p1->num,tshuhao);//�������
			strcpy(p1->nam,tname);//��������
			strcpy(p1->aut,tauthor);//��������
			strcpy(p1->pub,tchuban);//���Ƴ�����
			strcpy(p1->cat,tkind);//�������
			p1->many=many;//�����ִ���
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
		if(!(strcmp(p->nam,zname)))//�ж�Ҫ������Ƿ���ڣ���ǵ���1�����ڿ���һ
		{
			
            flag=1;
		 	loop=p->many;
		 	(p->many)--;
		 }
			p=p->next;
  }
	if(flag&&(loop>0))//���ڱ����ͼ�����ִ�������0���ѿ�����仯�����������ļ�
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

		printf("\n�����������Ϣ:\n ");//¼�������Ϣ
		printf("�˻�����");
		scanf("%d",&jnum);
		printf("�������ڣ�");
 		scanf("%s",riqi);
		sprintf(fileName,"%s%s%d%s",PATH_user,"\\",jnum,".txt");
		fp3=fopen(fileName,"a");
		fprintf(fp3,"%-8d%-18s%-16s\n",jnum,riqi,zname);
	    fclose(fp3);
        printf("����ɹ�!�������������\n");
		getch();//����
		borrowmain();//���ý���ϵͳ
   }
	else
    {
    	if(flag!=0){
        printf("�����ѱ����!�Ƿ�ԤԼ��\n����1ԤԼ���飬����2���ؽ���\n");//������������ѱ�����
		int hi;
		scanf("%d",&hi);
		if(hi==1){
			jnum=atoi(uzhanghu);
			sprintf(fileName,"%s%s%d%s",PATH_user,"\\",jnum,".txt");
			fp3=fopen(fileName,"a");
			fprintf(fp3,"%-8d%-18s%-16s\n",jnum,"ԤԼ",zname);
	    	fclose(fp3);
			printf("ԤԼ�ɹ���");
		}
		else
			borrowmain();
		}
		else
		printf("�����޴���!�����������");
	}
	    getch();//����
        borrowmain();//���ý���ϵͳ

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
	if ((fp = fopen(fileName, "r")) == NULL) // �����ڶ����ļ�����������ܻ���
	{
		system("cls");
		printf("\n �����ڽ�����!��������˳�!");
		getch();
		system("cls");
		borrowmain();
      }

	  else
	  {
		printf("����ڽ�ͼ�飺\n��������:\t\t�ڽ���Ŀ:\n");
		while(!feof(fp)){
			fscanf(fp,"%d %s %s",&username,day,bookname);
			if(strcmp(day,"ԤԼ"))
			if(strcmp(lastbookname,bookname))
				printf("%5s\t\t\t%5s\n",day,bookname);
			strcpy(lastbookname,bookname);
		}
		printf("*******************************\n");
	    printf("\n������Ҫ�黹��ͼ������:\n");
		 scanf("%s",ttzname);//���뻹������
		fclose(fp);
		fp=fopen(fileName,"r");
		 while(!feof(fp))//��ȡ���߽�����Ϣ
           {
			fscanf(fp,"%d%s%s\n ",&tzhenghao,triqi,tzname);
			if((account==tzhenghao)&&!strcmp(tzname,ttzname))//���֤���������ڣ�����Ϊ1
			flag=1;
			}
      fclose(fp);
	  fp=fopen(fileName,"r");//�򿪶����ļ���ɾ��������Ϣ
	  if(flag)
	  {
	  for (i=0;i<k;i++)//�������ļ����Ƶ�����
	  {
	  fscanf(fp,"%d%s%s\n ",&tzhenghao,triqi,tzname);//��ȡ�ļ���Ϣ
	  if(!((account==tzhenghao)&&!strcmp(ttzname,tzname)))
	  {
          n++;
		  if (n==1)
		  {
		      p1=p2=(struct reader*)malloc(LEN1);//�½�����
			  head=p1;
		  }
		  else
		  {
		        p2->next=p1;
				p2=p1;
				p1=(struct reader*)malloc(LEN1);//�½�����
          }
		  p1->jnum=tzhenghao;//����֤��
		  strcpy(p1->time,triqi);//������
		  strcpy(p1->tsnam,tzname);//��������
		  }}
		  if (n==0)
		  head=NULL;
		  else
		  {
		       p2->next=p1;
			   p1->next=NULL;
			   fclose(fp);
	      }
		  fp=fopen(fileName,"w");//��ն����ļ�
		  fclose(fp);
		  fp=fopen(fileName,"a");//׷����Ϣ
		  p=head;
		  for (;p!=NULL;)//���������ݸ��Ƕ����ļ�
		  {
		      fprintf(fp,"\n%-8d%-18s%-10s\n",p->jnum,p->time,p->tsnam);
			  p=p->next;
	      }
		  free(p);
		  fclose(fp);
		  }}

		  if(flag)//���Ϊ1��������ʱ���Ŀ��
		  {
			  printf("����ɹ�!\n");
			  printf("����������Ȿ�������:\n");
			  scanf("%s", shuping);
			  fp4 = fopen(PATH_review, "a");
			  fprintf(fp4,"\n%s %s", ttzname, shuping);
			  fclose(fp4);
			  printf("��������˳�");
			  n = 0;
			  flag = 0;
			  fp3=fopen(PATH_book,"r");//��ͼ����ļ�
			  k=tjzs();//��ȡͼ����ļ�����
			  for (i=0;i<k;i++)//��ͼ����ļ����Ƶ�����
			  {
			       fscanf(fp3,"%s%s%s%s%s%d",tshuhao,tname,tauthor,tchuban,tkind,&txcl);//��ȡ��Ϣ
				   n++;
				   if (n==1)
				   {
				       lp1=lp2=(struct book*)malloc(LEN);//�½�����
					   lhead1=lp1;
				   }
				   else
				   {
				       lp2->next=lp1;
					   lp2=lp1;
					   lp1=(struct book*)malloc(LEN);//�½�����
				   }
				   strcpy(lp1->num,tshuhao);//�������
				   strcpy(lp1->nam,tname);//��������
				   strcpy(lp1->aut,tauthor);//��������
				   strcpy(lp1->pub,tchuban);//���Ƴ�����
				   strcpy(lp1->cat,tkind);//�������
				   lp1->many=txcl; //�����ִ���
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
				        if(!(strcmp(zp1->nam,ttzname)))//Ѱ��������ͬ
						++(zp1->many);//�ִ�����1
						zp1=zp1->next;
					}
					fp3=fopen(PATH_book,"w");//���ͼ����ļ�
					fclose(fp);
					fp3=fopen(PATH_book,"a");//׷����Ϣ
					zp1=lhead1;
					for (;zp1!=NULL;)//���������ݸ���ͼ����ļ�
					{
                         fprintf(fp3,"%-8s%-16s%-14s%-22s%-18s%-7d\n",
        				 zp1->num,zp1->nam,zp1->aut,zp1->pub,zp1->cat,zp1->many);
						 zp1=zp1->next;
				    }
					fclose(fp3);
					getch();//����
					borrowmain();//���ý���ϵͳ
					}
					else
					printf("�����ڴ���Ϣ!�����������!");
					getch();//����
					borrowmain();//���ý���ϵͳ
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
	printf("�û�%d�ѽ��鼮��Ϣ\n",account);
	if (fp==NULL)//�����˺�����txt�ļ�·��
	{
		printf("�ף�Ŀǰû���ڽ��ļ��ء�\n");
		getch();
	 	system("cls");
		borrowmain();     //ת�ص�¼���ܺ���
	
    }
	printf("�������ڣ�\t\t�ڽ���Ŀ:\n");
	for(;!feof(fp);){
		fscanf(fp,"%d %s %s",&username,day,bookname);
		if(strcmp(lastbookname,bookname) && strcmp("ԤԼ",day))
			printf("%5s\t\t\t%5s\n",day,bookname);
		strcpy(lastbookname,bookname);
	}
	printf("*******************************\n");
	printf("���س���ǰȥ���飬��ESC�˻���һ��\n");
	int i=getch();//��ͣ����i���պ������һ��ָ��
    if(i==13){
		system("cls");
        bookreturn();}
	else if(i==27){
		system("cls");
		borrowmain();
	}
	fclose(fp);
}


void yuyue(){  //ԤԼ��������
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
		   if (!strcmp(day, "ԤԼ"))
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
				printf("��ԤԼ��%s�ѵ���\n",nam);
				gotoxy(52, 4);
				printf("------------------------");
			}
        }
       }
	fclose(fp);
	}
}


