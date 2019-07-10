#include <stdio.h>
#include "data.h"
#include "ctrl.h"

int main()
{
	PPASSWORD pPwd = NULL;	//指向密码本的指针（也指向单条记录，记录组成本）
	int nCount = 0;		//当前密码记录数
	g_nNum = 0;			//密码本容量（最大密码记录数

	//readInfo(&pPwd, &nCount);	//初始化密码本

	while (1)
	{
		//打印引导信息
		printf("你想干嘛？\n");
		printf("1 查看所有密码：\n");
		printf("2 新增密码：\n");
		printf("3 删除密码：\n");
		printf("4 修改密码：\n");
		printf("5 查询密码：\n");
		printf("6 生成文件：\n");

		//接收用户操作
		int op;
		scanf_s("%d", &op);

		//根据操作，调用相应模块
		switch (op)
		{
		//case 1://查看所有记录
		//	viewAllInfo(pPwd, nCount);
		//	break;
		case 2://插入新纪录
			insertInfo(pPwd, &nCount);
			break;
		//case 3://删除记录
		//	deleteInfo(pPwd, &nCount);
		//	break;
		//case 4://更改记录
		//	alertInfo(pPwd, nCount);
		//	break;
		//case 5://搜索记录
		//	searchInfo(pPwd, nCount);
		//	break;
		//case 6://导入密码文件（文本文件
		//	saveInfoA(pPwd, nCount);
		//	break;
		default:
			break;
		}
	}
	return 0;
}