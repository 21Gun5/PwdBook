#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "ctrl.h"
#include "func.h"

void addInfo(RECORD rcd[], int* pnCount)
{
	int i = *pnCount;			//记录标识
	chkPosErr(i);

	showInputMenu(rcd, i);		//据提示键入记录

	(*pnCount)++;				//记录+1
	saveFile(rcd, *pnCount);	//保存文件

	printf("添加成功！\n\n");
	system("pause");
	system("cls");
	return;
}

void viewAllInfo(RECORD rcd[], int nCount)
{
	//打印所有
	printf("===== 共计：%3d 条记录 =====\n", nCount);
	for (int i = 0; i < nCount; i++)
	{
		printRecord(rcd, i);
	}

	printf("查看成功！\n\n");

	system("pause");
	system("cls");
	return;
}

void deleteInfo(RECORD rcd[], int* pnCount)
{
	int i = 0;
	printf("请待删除记录ID：\n");
	scanf_s("%d", &i);
	chkPosErr(i);

	//删除记录，后者赋给前者
	for (int j = i; j < *pnCount - 1; j++)
	{
		rcd[j] = rcd[j + 1];
	}

	(*pnCount)--;
	saveFile(rcd, *pnCount);

	printf("删除成功！\n\n");
	system("pause");
	system("cls");
	return;
}

void modifyInfo(RECORD rcd[], int nCount)
{
	int i = 0;
	printf("请输入待修改记录ID：\n");
	scanf_s("%d", &i);
	chkPosErr(i);

	//据提示键入信息
	printf("开始修改：\n");
	showInputMenu(rcd, i);

	saveFile(rcd, nCount);
	printf("修改成功！\n\n");
	system("pause");
	system("cls");
	return;
}

void exportFile(RECORD rcd[], int nCount)
{
	//打开文件
	FILE* pFile;
	errno_t err = fopen_s(&pFile, "./output/data.txt", "w");
	chkFileOpenErr(err);

	//写入文件
	fprintf(pFile, "共：%3d条记录\n", nCount);
	for (int i = 0; i < nCount; i++)
	{
		fprintf(pFile, "ID:%3d || 站点:%s || 用户名:%s || 密码:%s || 备注:%s\n", i, rcd[i].site, rcd[i].usr, rcd[i].pwd, rcd[i].note);
	}

	//关闭文件
	fclose(pFile);

	printf("导出成功！\n\n");
	system("pause");
	system("cls");
	return;
}

void searchInfo(RECORD rcd[], int nCount)
{
	char key[100] = { 0 };		//关键字
	printf("请输入关键字：");
	scanf_s("%s", key, 100);

	//遍历寻找
	int findRcd[100] = { 0 };	//符合要求的记录的ID
	int nFindCount = 0;			//共有多少记录符合要求
	for (int i = 0; i < nCount; i++)
	{
		if (strstr(rcd[i].site, key))
		{
			findRcd[nFindCount] = i;
			nFindCount++;
			continue;			//结束本次循环，若在前面字段找到，后面字段就不用看了
		}
		if (strstr(rcd[i].usr, key))
		{
			findRcd[nFindCount] = i;
			nFindCount++;
			continue;
		}
		if (strstr(rcd[i].pwd, key))
		{
			findRcd[nFindCount] = i;
			nFindCount++;
			continue;
		}
		if (strstr(rcd[i].note, key))
		{
			findRcd[nFindCount] = i;
			nFindCount++;
			continue;
		}
	}

	//输出所有匹配项
	printf("===== 共计：%3d 条记录 =====\n", nFindCount);
	for (int i = 0; i < nFindCount; i++)
	{
		printRecord(rcd, findRcd[i]);
	}
	printf("\n");

	printf("查找成功！\n\n");
	system("pause");
	system("cls");
	return;
}
