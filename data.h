#pragma once

//全局变量、常量的声明
#define NUM 5			//初始密码本容量（最大密码记录数）
extern int g_nNum;		//当前的密码本容量

//存储密码记录的结构体（一条记录有4个字段
typedef struct _PASSWORD
{
	char webSites[4];	//站点
	char userName[4]; //用户名
	char passWord[4]; //密码
	char note[4];		//备注
}PASSWORD, * PPASSWORD;