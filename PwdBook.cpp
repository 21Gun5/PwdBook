#include <stdio.h>
#include "data.h"
#include "ctrl.h"

int main()
{
	PRECORD pRcd = NULL;	//指向密码本（内存
	int nCount = 0;			//当前记录数
	g_nNum = CAPACITY;		//容量
	int nRun = 1;

	readFile(&pRcd, &nCount);	//密码本：文件->内存

	while (nRun == 1)
	{
		//引导信息
		printf("密码本使用\n");
		printf("1 查看所有\n");
		printf("2 新增密码\n");
		printf("3 删除密码\n");
		printf("4 修改密码\n");
		printf("5 查询密码\n");
		printf("6 导出文件\n");
		printf("7 退出程序\n");
		printf("输入欲执行操作：");

		//接收用户操作
		int op;
		scanf_s("%d", &op);

		//调用相关模块
		switch (op)
		{
		case 1://查看所有记录
			viewAllInfo(pRcd, nCount);
			break;
		case 2://增加纪录
			insertInfo(pRcd, &nCount);
			break;
		case 3://删除记录
			deleteInfo(pRcd, &nCount);
			break;
		case 4://修改记录
			modifyInfo(pRcd, nCount);
			break;
		case 5://搜索记录
			searchInfo(pRcd, nCount);
			break;
		case 6://导出文件
			exportFile(pRcd, nCount);
			break;
		case 7://退出
			nRun = 0;
			printf("再见！\n");
			break;
		default:
			break;
		}
	}
	return 0;
}