#pragma once
#include "data.h"

/*
insert、delete、read需要更改记录数，故传指针间接修改之
read传PRECORD *，目的是修改PRECORD，将其指向刚进内存的文件
其他传RECORD[]即指针，目的是使用PRECORD，来操作内存中文件
*/
//函数声明：
void addInfo(RECORD rcd[], int* pnCount);		//新增记录
void deleteInfo(RECORD rcd[], int* pnCount);	//删除记录
void modifyInfo(RECORD rcd[], int nCount);		//修改记录
void viewAllInfo(RECORD rcd[], int nCount);		//查看所有
void searchInfo(RECORD rcd[], int nCount);		//搜索记录
void exportFile(RECORD rcd[], int nCount);		//导出文本文件



