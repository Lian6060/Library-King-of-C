#ifndef __BOOK_H__
#define __BOOK_H__            //防止头文件被重复包含

#define MAX 1024
char sortlb[5][10] = {"文学类", "历史类", "哲学类", "教育类", "军事类"};
char buffer[MAX];
//模糊搜索
//图书推荐
void outsp();    //书评展示
void libmenu(); //图书菜单
void libmain(); //图书馆管理系统主函数
int tjzs(void);//统计图书本书
void searchbook();//查询图书
void scan(int choice);//浏览图书
void sortmenu();//分类主菜单
void sortmain();//分类主函数
void rankmenu();//排行主菜单
void sort(struct rank a[10000000],int k);//排序函数
int cmpChStr(char * str,char * target);//中文模糊搜索
int vagueSearch(char * source,char * target);//查询图书模糊搜索






#endif // __FUNC_H__
