#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "ctrl.h"

//新增记录
void insertInfo(RECORD rcd[], int* pnCount)
{
	int i = *pnCount;		//记录标识

	//if (i < 0 || i >= NUM)		//处理异常
	//{
	//	printf("插入位置异常！\n");
	//	return;
	//}

	//据提示键入记录
	printf("目标站点?");
	scanf_s("%s", rcd[i].site, 100);
	printf("用户名?");
	scanf_s("%s", rcd[i].usr, 100);
	printf("密码?");
	scanf_s("%s", rcd[i].pwd, 100);
	printf("备注?");
	scanf_s("%s", rcd[i].note, 100);

	//添加成功后
	(*pnCount)++; //记录+1
	saveFile(rcd, *pnCount);		//保存文件

	printf("\n");
	//system("cls");	//清屏
	return;
}

//保存文件（二进制
void saveFile(RECORD rcd[], int nCount)
{
	//打开文件
	FILE* pFile = NULL;
	errno_t err = fopen_s(&pFile, "./data.i", "wb");	//需要w模式，覆盖旧文件，而非a追加
	if (err != 0)
	{
		return;
	}

	//写入文件
	fwrite(&nCount, sizeof(nCount), 1, pFile);		//写入记录数
	fwrite(&g_nNum, sizeof(g_nNum), 1, pFile);		//写入容量

	int byteSize = sizeof(RECORD) * g_nNum;		//所需内存
	char* buf = (char*)malloc(byteSize);			//分配空间
	memcpy_s(buf, byteSize, rcd, byteSize);		//rcd->buf（rcd为主,buf为中介)

	//加密
	//for (int i = 0; i > byteSize; i++)
	//{
	//	buf[i] -= 1;
	//}

	int nlen = fwrite(buf, sizeof(RECORD), g_nNum, pFile);		//写入密码记录，buf->pfile

	//if (nlen != g_nNum)
	//	printf("写入失败!\n");
	//else
	//	printf("写入成功！\n");

	//关闭文件
	fclose(pFile);
	free(buf);		//释放空间
	buf = NULL;		//避免悬空指针
	return;
}

//读取文件
void readFile(PRECORD* ppRcd, int* pnCount)
{
	//打开文件
	FILE* pFile;
	errno_t err = fopen_s(&pFile, "./data.i", "rb");

	//如果打开失败
	if (err != 0)
	{
		printf("文件打开失败！\n");
		//*ppRcd = (PRECORD)malloc(sizeof(RECORD) * NUM);	//分配所需内存，并将首地址赋值给pRcd
		//g_nNum = NUM;	//当前容量设置为默认容量
		return;
	}

	//读取文件
	fread(pnCount, sizeof(int), 1, pFile);		//读记录数
	fread(&g_nNum, sizeof(g_nNum), 1, pFile);	//读容量

	*ppRcd = (PRECORD)malloc(sizeof(RECORD) * g_nNum);	//分配所需内存
	memset(*ppRcd, 0, sizeof(RECORD) * g_nNum);	//内存初始化
	int nLen = fread(*ppRcd, sizeof(RECORD), g_nNum, pFile);	//读文件到内存
	if (nLen != g_nNum)
	{
		printf("密码文件读取失败！\n");
		fclose(pFile);
		return;
	}

	//解密
	//int byteSize = sizeof(RECORD) * g_nNum;
	//char* buf = (char*)* ppRcd;
	//for (int i = 0; i < byteSize; i++)
	//{
	//	buf[i] += 1;
	//}

	//关闭文件
	fclose(pFile);
	return;
}

//显示所有
void viewAllInfo(RECORD rcd[], int nCount)
{
	printf("===== 共计：%3d 条记录 =====\n", nCount);
	for (int i = 0; i < nCount; i++)
	{
		printf("记录ID：%3d\n", i);
		printf("站  点：%s\n", rcd[i].site);
		printf("用户名：%s\n", rcd[i].usr);
		printf("密  码：%s\n", rcd[i].pwd);
		printf("备  注：%s\n", rcd[i].note);
		printf("----------------------------\n");
	}
	printf("\n");
	//system("cls");
	return;
}

//删除记录
void deleteInfo(RECORD rcd[], int* pnCount)
{
	int i = 0;
	printf("请待删除记录ID：\n");
	scanf_s("%d", &i);

	//if (i < 0 || i >= NUM)
	//{
	//	printf("ID异常，请核实：%d\n", i);
	//	return;
	//}

	//删除记录，后者赋给前者
	for (int j = i; j < *pnCount - 1; j++)
	{
		rcd[j] = rcd[j + 1];
	}

	(*pnCount)--;
	saveFile(rcd, *pnCount);	//保存文件

	//printf("\n");
	//system("cls");

	return;
}

//修改记录
void modifyInfo(RECORD rcd[], int nCount)
{
	int i = 0;
	printf("请输入待修改记录ID：\n");
	scanf_s("%d", &i);

	//if (i < 0 || i >= NUM)
	//{
	//	printf("修改位置异常：%d\n", i);
	//	return;
	//}

	printf("开始修改：\n");

	printf("目标站点？");
	scanf_s("%s", rcd[i].site, 100);
	printf("用户名？");
	scanf_s("%s", rcd[i].usr, 100);
	printf("密码？");
	scanf_s("%s", rcd[i].pwd, 100);
	printf("备注？");
	scanf_s("%s", rcd[i].note, 100);

	saveFile(rcd, nCount);

	//printf("\n");
	//system("cls");
	return;
}

//查询记录
void searchInfo(RECORD rcd[], int nCount)
{
	char key[100] = { 0 };
	printf("请输入关键字：");
	scanf_s("%s", key, 100);

	//遍历寻找
	int findRcd[100] = { 0 };
	int nFindCount = 0;
	for (int i = 0; i < nCount; i++)
	{
		if (strstr(rcd[i].site, key))
		{
			findRcd[nFindCount++] = i;
			continue;
		}
		if (strstr(rcd[i].usr, key))
		{
			findRcd[nFindCount++] = i;
			continue;
		}
		if (strstr(rcd[i].pwd, key))
		{
			findRcd[nFindCount++] = i;
			continue;
		}
		if (strstr(rcd[i].note, key))
		{
			findRcd[nFindCount++] = i;
			continue;
		}
	}
	//所有匹配项
	printf("===== 共计：%3d 条记录 =====\n", nFindCount);
	for (int i = 0; i < nFindCount; i++)
	{
		int pos = findRcd[i];
		printf("记录ID：%3d\n", pos);
		printf("站  点：%s\n", rcd[pos].site);
		printf("用户名：%s\n", rcd[pos].usr);
		printf("密  码：%s\n", rcd[pos].pwd);
		printf("备  注：%s\n", rcd[pos].note);
	}
	printf("\n");
	return;
}

//导出文件（文本
void exportFile(RECORD rcd[], int nCount)
{
	//打开文件
	FILE* pFile;
	errno_t err = fopen_s(&pFile, "./data.txt", "w");

	//if (err != 0)
	//{
	//	return;
	//}

	//写入文件
	fprintf(pFile, "共：%3d条记录\n", nCount);
	for (int i = 0; i < nCount; i++)
	{
		fprintf(pFile, "ID:%3d || 站点:%s || 用户名:%s || 密码:%s || 备注:%s\n", i, rcd[i].site, rcd[i].usr, rcd[i].pwd, rcd[i].note);
	}

	//关闭文件
	fclose(pFile);

	//printf("密码文件导出成功\n");
	//system("cls");
	return;
}


