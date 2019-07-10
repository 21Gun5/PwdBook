#include <stdio.h>
#include "data.h"
#include "ctrl.h"

int main()
{
	PPASSWORD pPwd = NULL;	//操控内存中密码本
	int nCount = 0;			//当前记录数
	g_nNum = NUM;			//容量
	int nRun = 1;

	readInfo(&pPwd, &nCount);	//初始化，导入密码文件

	while (nRun == 1)
	{
		//引导信息
		printf("你想干嘛？\n");
		printf("1 查看所有\n");
		printf("2 新增密码\n");
		printf("3 删除密码\n");
		printf("4 修改密码\n");
		printf("5 查询密码\n");
		printf("6 生成文件\n");
		printf("7 退出程序\n");

		//接收用户操作
		int op;
		scanf_s("%d", &op);

		//调用相关模块
		switch (op)
		{
		case 1://查看所有记录
			viewAllInfo(pPwd, nCount);
			break;
		case 2://增加纪录
			insertInfo(pPwd, &nCount);
			break;
		case 3://删除记录
			deleteInfo(pPwd, &nCount);
			break;
			//case 4://更改记录
			//	alertInfo(pPwd, nCount);
			//	break;
			//case 5://搜索记录
			//	searchInfo(pPwd, nCount);
			//	break;
			//case 6://导入密码文件（文本文件
			//	saveInfoA(pPwd, nCount);
			//	break;
		case 7://导入密码文件（文本文件
			nRun = 0;
			printf("再见！\n");
			break;
		default:
			break;
		}
	}
	return 0;
}