#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "data.h"
#include "func.h"

void initialFile()
{
	FILE* pFile = NULL;
	errno_t err = fopen_s(&pFile, "./conf/data2.i", "rb");
	if (err == 0)
		return;
	else
	{
		fopen_s(&pFile, "./conf/data2.i", "wb");
		int n = 0;
		RECORD record;
		strcpy_s(record.site, 20, "1111111111111111111");
		strcpy_s(record.usr, 20, "2222222222222222222");
		strcpy_s(record.pwd, 20, "3333333333333333333");
		strcpy_s(record.note, 20, "4444444444444444444");

		fwrite(&n, sizeof(n), 1, pFile);
		fwrite(&g_nNum, sizeof(g_nNum), 1, pFile);

		char* buf = (char*)malloc(sizeof(RECORD));						
		memset(buf, 0, sizeof(RECORD));
		memcpy_s(buf, sizeof(RECORD), &record, sizeof(RECORD));

		//encode(buf, g_byteSize);

		fwrite(buf, sizeof(RECORD), g_nNum, pFile);

		//关闭文件
		fclose(pFile);
		return;
	}
}

void readFile(PRECORD* ppRcd, int* pnCount)
{
	//打开文件
	FILE* pFile;
	errno_t err = fopen_s(&pFile, "./conf/data2.i", "rb");
	chkFileOpenErr(err);

	//读取文件
	fread(pnCount, sizeof(int), 1, pFile);					//读记录数
	fread(&g_nNum, sizeof(g_nNum), 1, pFile);				//读容量

	char* buf = (char*)malloc(g_byteSize);					//buf作中介，加解密时用到
	memset(buf, 0, g_byteSize);
	*ppRcd = (PRECORD)malloc(g_byteSize);					//分配所需内存
	memset(*ppRcd, 0, g_byteSize);							//内存初始化

	int nLen = fread(buf, sizeof(RECORD), g_nNum, pFile);	//读文件到内存

	//decode(buf, g_byteSize);
	memcpy_s(*ppRcd, g_byteSize, buf, g_byteSize);			//拷贝rcd到buf

	char c = 'o';	//标识为向内输出
	chkFileIOErr(nLen, c);

	//关闭文件
	fclose(pFile);
	free(buf);

	return;
}

void saveFile(RECORD rcd[], int nCount)
{
	//打开文件
	FILE* pFile = NULL;
	errno_t err = fopen_s(&pFile, "./conf/data2.i", "wb");	//需要w覆盖旧，而非a追加
	chkFileOpenErr(err);

	//写入文件
	fwrite(&nCount, sizeof(nCount), 1, pFile);					//写入记录数
	fwrite(&g_nNum, sizeof(g_nNum), 1, pFile);					//写入容量

	char* buf = (char*)malloc(g_byteSize);						//buf作中介，加解密时用到
	memset(buf, 0, g_byteSize);
	memcpy_s(buf, g_byteSize, rcd, g_byteSize);					//拷贝rcd到buf

	//encode(buf, g_byteSize);

	int nLen = fwrite(buf, sizeof(RECORD), g_nNum, pFile);		//内存写到文件

	char c = 'o';	//标识为向外输出
	chkFileIOErr(nLen, c);

	//关闭文件
	fclose(pFile);
	free(buf);

	return;
}

//void time4File()
//{
//
//}

void showMenu()
{
	printf("密码本使用\n");
	printf("1 查看所有\n");
	printf("2 新增密码\n");
	printf("3 删除密码\n");
	printf("4 修改密码\n");
	printf("5 查询密码\n");
	printf("6 导出文件\n");
	printf("7 退出程序\n");
	printf("输入欲执行操作：");

	return;
}

void chkFileOpenErr(errno_t err) 
{
	if (err != 0)
	{
		printf("文件打开失败！\n");
		return;
	}
}

void chkPosErr(int i) 
{
	if (i < 0 || i >= CAPACITY)		//处理异常
	{
		printf("位置异常！\n");
		return;
	}
}

void chkFileIOErr(int nLen,char c) 
{
	if (nLen != g_nNum)
	{
		if (c == 'o')
		{
			printf("写入文件失败!\n");
		}
		if (c == 'i')
		{
			printf("读取文件失败!\n");
		}
	}

	return;
}

void showInputMenu(RECORD rcd[],int i) 
{
	printf("目标站点？");
	scanf_s("%s", rcd[i].site, COLUMNSIZE);
	printf("用户名？");
	scanf_s("%s", rcd[i].usr, COLUMNSIZE);
	printf("密码？"); 
	scanf_s("%s", rcd[i].pwd, COLUMNSIZE);
	printf("备注？"); 
	scanf_s("%s", rcd[i].note, COLUMNSIZE);

	return;
}

char * encode(char * buf,int n)
{
	for (int i = 0; i < n; i++)
	{
		buf[i] -= 1;
	}
	return buf;
}

char * decode(char* buf, int n)
{
	for (int i = 0; i < n; i++)
	{
		buf[i] += 1;
	}
	return buf;
}

void printRecord(RECORD rcd[],int i) 
{
	printf("记录ID：%3d\n", i);
	printf("站  点：%s\n", rcd[i].site);
	printf("用户名：%s\n", rcd[i].usr);
	printf("密  码：%s\n", rcd[i].pwd);
	printf("备  注：%s\n", rcd[i].note);
	printf("----------------------------\n");
}
