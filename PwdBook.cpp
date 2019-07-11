#include <stdio.h>
#include "data.h"
#include "ctrl.h"
#include "func.h"

int main()
{
	PRECORD pRcd = NULL;					//指向内存中密码本
	int nCount = 0;							//当前记录数
	g_nNum = CAPACITY;						//密码本容量（单位：记录）
	g_byteSize = sizeof(RECORD) * g_nNum;   //容量（单位：字节）
	int nRun = 1;							//是否运行标识

	initialFile();							//初始化密码文件
	readFile(&pRcd, &nCount);				//从文件读到内存

	while (nRun == 1)
	{
		showMenu();							//引导信息

		//接收用户操作
		int op;
		scanf_s("%d", &op);

		//调用相关模块
		switch (op)
		{
		case 查看所有:
			viewAllInfo(pRcd, nCount);
			break;
		case 增加记录:
			addInfo(pRcd, &nCount);
			break;
		case 删除记录:
			deleteInfo(pRcd, &nCount);
			break;
		case 修改记录:
			modifyInfo(pRcd, nCount);
			break;
		case 搜索记录:
			searchInfo(pRcd, nCount);
			break;
		case 导出文件:
			exportFile(pRcd, nCount);
			break;
		case 退出程序:
			nRun = 0;
			printf("再见！\n");
			break;
		default:
			break;
		}
	}
	return 0;
}