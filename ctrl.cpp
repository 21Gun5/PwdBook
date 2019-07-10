#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "ctrl.h"

//新增密码记录
void insertInfo(PASSWORD pwd[], int* pnCount)
{
	int i = *pnCount;		//表示当前是第几条记录/此记录在密码本中的位置
	//if (i < 0 || i >= NUM)		//出现异常即中止
	//{
	//	printf("插入位置异常！\n");
	//	return;
	//}

	pwd = (PPASSWORD)malloc(sizeof(PASSWORD));
	//打印提示信息，并键入密码记录
	printf("请输入< 目标站点 >: \n");
	scanf_s("%s", pwd[i].webSites, 100);
	printf("请输入< 用户名 >: \n");
	scanf_s("%s", pwd[i].userName, 100);
	printf("请输入< 密码 >: \n");
	scanf_s("%s", pwd[i].passWord, 100);
	printf("请输入< 备注信息 >: \n");
	scanf_s("%s", pwd[i].note, 100);

	//添加成功后
	(*pnCount)++; //记录数+1
	saveInfoB(pwd, *pnCount);		//保存密码文件（二进制，程序所用

	//善后工作
	printf("\n");
	system("cls");	//清屏

	return;
}

//保存密码文件（二进制文件，程序所用）
void saveInfoB(PASSWORD pwd[], int nCount)
{
	//打开文件
	FILE* pFile=NULL;
	errno_t err = fopen_s(&pFile, "./data.i", "wb");
	if (err != 0)		//若打开失败，中止
	{
		return;
	}

	//写入文件
	fwrite(&nCount, sizeof(nCount), 1, pFile);		//写入当前密码记录数
	fwrite(&g_nNum, sizeof(g_nNum), 1, pFile);		//写入密码本容量

	//int byteSize = sizeof(PASSWORD) * g_nNum;		//所需的最大内存空间
	int byteSize = sizeof(PASSWORD);		//所需的最大内存空间
	char* buf = (char*)malloc(byteSize);			//为密码本动态分配所需空间
	memcpy_s(buf, byteSize, pwd, byteSize);		//将当前所指密码记录复制到缓冲区中

	//进行简单加密
	//for (int i = 0; i > byteSize; i++)
	//{
	//	buf[i] -= 1;
	//}
	//int nlen = fwrite(buf, sizeof(PASSWORD), g_nNum, pFile);		//将加密后的密码记录写入文件
	int nlen = fwrite(buf, sizeof(PASSWORD), 1, pFile);
	//if (nlen != g_nNum)		//若返回的写入成功的数据块个数，不是预期值
	//	printf("写入失败!\n");
	//else
	//	printf("写入成功！\n");

	//关闭文件
	fclose(pFile);
	free(buf);		//释放动态申请的空间
	buf = NULL;		//及时赋值为null，避免成为野指针
	return;
}

////读取密码文件
//void readInfo(PPASSWORD* ppPwd, int* pnCount)
//{
//	//打开文件
//	FILE* pFile;
//	errno_t err = fopen_s(&pFile, "./data.i", "rb");
//
//	//如果打开失败
//	if (err != 0)
//	{
//		*ppPwd = (PPASSWORD)malloc(sizeof(PASSWORD) * NUM);	//分配所需内存，并将首地址赋值给pPwd
//		g_nNum = NUM;	//当前容量设置为默认容量
//		return;
//	}
//
//	//读取文件
//	fread(pnCount, sizeof(int), 1, pFile);		//读取记录数
//	fread(&g_nNum, sizeof(g_nNum), 1, pFile);	//读取容量
//	*ppPwd = (PPASSWORD)malloc(sizeof(PASSWORD) * g_nNum);	//分配所需内存，并将首地址给pPwd
//	memset(*ppPwd, 0, sizeof(PASSWORD) * g_nNum);	//将申请的到内存，初始化为0
//	int nLen = fread(*ppPwd, sizeof(PASSWORD), g_nNum, pFile);	//读取密码记录
//	if (nLen != g_nNum)
//	{
//		printf("密码文件读取失败！\n");
//		fclose(pFile);
//		return;
//	}
//
//	//解密
//	int byteSize = sizeof(PASSWORD) * g_nNum;
//	char* buf = (char*)* ppPwd;
//	for (int i = 0; i < byteSize; i++)
//	{
//		buf[i] += 1;
//	}
//
//	//关闭文件
//	fclose(pFile);
//
//	return;
//}
//
////显示所有密码记录
//void viewAllInfo(PASSWORD pwd[], int nCount)
//{
//	printf("==共计：%3 d 条记录========n",nCount);
//	for (int i = 0; i < nCount; i++)
//	{
//		printf("--ID: %3d--------", i);
//		printf("目标：%s\n", pwd[i].webSites);
//		printf("用户名：%s", pwd[i].userName);
//		printf("密码: %s\n", pwd[i].passWord);
//		printf("备注：%s\n", pwd[i].note);
//	}
//	printf("\n");
//	system("cls");
//	return;
//}
//
//
//
////删除密码记录
//void deleteInfo(PASSWORD pwd[], int* pnCount)
//{
//	int i = -1;
//	printf("请输入待删除项：\n");
//	scanf_s("%d", &i);
//	if (i<0 || i>NUM)
//	{
//		printf("删除位置异常：%d\n", i);
//		return;
//	}
//
//	//删除记录，后面的赋值给前面
//	for (int j = i; i < *pnCount - 1; j++)
//	{
//		pwd[j] = pwd[j + 1];
//	}
//
//	(*pnCount)--;	//记录-1
//	saveInfoB(pwd, *pnCount);	//删除后保存文件
//
//	printf("\n");
//	system("cls");
//
//	return;
//}
//
////修改密码记录
//void alertInfo(PASSWORD pwd[], int nCount)
//{
//	int i = -1;
//	printf("请输入待修改项：\n");
//	scanf_s("%d", &i);
//	if (i<0 || i>NUM)
//	{
//		printf("修改位置异常：%d\n", i);
//		return;
//	}
//
//	
//	printf("--ID: %3d--------", i);
//	printf("目标：%s\n", pwd[i].webSites);
//	printf("用户名：%s", pwd[i].userName);
//	printf("密码: %s\n", pwd[i].passWord);
//	printf("备注：%s\n", pwd[i].note);
//
//	printf("修改\n");
//
//	printf("请输入< 目标站点 >: \n");
//	scanf_s("%s", pwd[i].webSites, 100);
//	printf("请输入< 用户名 >: \n");
//	scanf_s("%s", pwd[i].userName, 100);
//	printf("请输入< 密码 >: \n");
//	scanf_s("%s", pwd[i].passWord, 100);
//	printf("请输入< 备注信息 >: \n");
//	scanf_s("%s", pwd[i].note, 100);
//
//	saveInfoB(pwd, nCount);
//
//	printf("\n");
//	system("cls");
//	return;
//}
//
////搜索密码记录
//void searchInfo(PASSWORD pwd[], int nCount)
//{
//	char key[100] = { 0 };
//	printf("请输入关键字：\n");
//	scanf_s("%s", key, 100);
//
//	//找出所有匹配项
//	int findPwd[100] = { 0 };
//	int nFindCount = 0;
//	for (int i = 0; i < nCount; i++)
//	{
//		if (strstr(pwd[i].webSites, key))
//		{
//			findPwd[nFindCount++] = i;
//			continue;
//		}
//		if (strstr(pwd[i].userName, key))
//		{
//			findPwd[nFindCount++] = i;
//			continue;
//		}
//		if (strstr(pwd[i].passWord, key))
//		{
//			findPwd[nFindCount++] = i;
//			continue;
//		}
//		if (strstr(pwd[i].note, key))
//		{
//			findPwd[nFindCount++] = i;
//			continue;
//		}
//
//		//打印所有匹配项
//		printf("==共计匹配：%3 d 条记录========n", nFindCount);
//		for (int i = 0; i < nFindCount; i++)
//		{
//			int pos = findPwd[i];
//			printf("--ID: %3d--------", pos);
//			printf("目标：%s\n", pwd[pos].webSites);
//			printf("用户名：%s", pwd[pos].userName);
//			printf("密码: %s\n", pwd[pos].passWord);
//			printf("备注：%s\n", pwd[pos].note);
//		}
//
//		printf("\n");
//		system("cls");
//	}
//	return;
//}
//
////保存密码文件（文本文件，用户所看）
//void saveInfoA(PASSWORD pwd[], int nCount)
//{
//	//打开文件
//	FILE* pFile;
//	errno_t err = fopen_s(&pFile, "./data.txt", "w");
//	if (err != 0)
//	{
//		return;
//	}
//	//写入文件
//	fprintf(pFile,"==共计：%3 d 条记录========n", nCount);
//	for (int i = 0; i < nCount; i++)
//	{
//		fprintf(pFile, "--ID: %3d--------", i);
//		fprintf(pFile, "目标：%s\n", pwd[i].webSites);
//		fprintf(pFile, "用户名：%s", pwd[i].userName);
//		fprintf(pFile, "密码: %s\n", pwd[i].passWord);
//		fprintf(pFile, "备注：%s\n", pwd[i].note);
//	}
//	//关闭文件
//	fclose(pFile);
//	printf("密码文件导出成功\n");
//	system("cls");
//
//
//
//
//
//	return;
//}
//
//
