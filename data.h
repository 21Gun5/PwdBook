#pragma once

#define CAPACITY 5			//初始容量
extern int g_nNum;			//当前容量

//密码记录结构体
typedef struct _RECORD
{
	char site[4];	//站点
	char usr[4];	//用户名
	char pwd[4];	//密码
	char note[4];	//备注
}RECORD, * PRECORD;