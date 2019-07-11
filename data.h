#pragma once

#define 查看所有 1
#define 增加记录 2
#define 删除记录 3
#define 修改记录 4
#define 搜索记录 5
#define 导出文件 6
#define 退出程序 7
#define CAPACITY 50			//初始容量
#define COLUMNSIZE 20		//每个字段大小

extern int g_nNum;			//当前容量（单位：记录
extern int g_byteSize;		//当前容量（单位：字节

//密码记录结构体
typedef struct _RECORD
{
	char site[COLUMNSIZE];	//站点
	char usr[COLUMNSIZE];	//用户名
	char pwd[COLUMNSIZE];	//密码
	char note[COLUMNSIZE];	//备注
}RECORD, * PRECORD;