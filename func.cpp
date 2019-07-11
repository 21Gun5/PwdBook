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

		//�ر��ļ�
		fclose(pFile);
		return;
	}
}

void readFile(PRECORD* ppRcd, int* pnCount)
{
	//���ļ�
	FILE* pFile;
	errno_t err = fopen_s(&pFile, "./conf/data2.i", "rb");
	chkFileOpenErr(err);

	//��ȡ�ļ�
	fread(pnCount, sizeof(int), 1, pFile);					//����¼��
	fread(&g_nNum, sizeof(g_nNum), 1, pFile);				//������

	char* buf = (char*)malloc(g_byteSize);					//buf���н飬�ӽ���ʱ�õ�
	memset(buf, 0, g_byteSize);
	*ppRcd = (PRECORD)malloc(g_byteSize);					//���������ڴ�
	memset(*ppRcd, 0, g_byteSize);							//�ڴ��ʼ��

	int nLen = fread(buf, sizeof(RECORD), g_nNum, pFile);	//���ļ����ڴ�

	//decode(buf, g_byteSize);
	memcpy_s(*ppRcd, g_byteSize, buf, g_byteSize);			//����rcd��buf

	char c = 'o';	//��ʶΪ�������
	chkFileIOErr(nLen, c);

	//�ر��ļ�
	fclose(pFile);
	free(buf);

	return;
}

void saveFile(RECORD rcd[], int nCount)
{
	//���ļ�
	FILE* pFile = NULL;
	errno_t err = fopen_s(&pFile, "./conf/data2.i", "wb");	//��Ҫw���Ǿɣ�����a׷��
	chkFileOpenErr(err);

	//д���ļ�
	fwrite(&nCount, sizeof(nCount), 1, pFile);					//д���¼��
	fwrite(&g_nNum, sizeof(g_nNum), 1, pFile);					//д������

	char* buf = (char*)malloc(g_byteSize);						//buf���н飬�ӽ���ʱ�õ�
	memset(buf, 0, g_byteSize);
	memcpy_s(buf, g_byteSize, rcd, g_byteSize);					//����rcd��buf

	//encode(buf, g_byteSize);

	int nLen = fwrite(buf, sizeof(RECORD), g_nNum, pFile);		//�ڴ�д���ļ�

	char c = 'o';	//��ʶΪ�������
	chkFileIOErr(nLen, c);

	//�ر��ļ�
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
	printf("���뱾ʹ��\n");
	printf("1 �鿴����\n");
	printf("2 ��������\n");
	printf("3 ɾ������\n");
	printf("4 �޸�����\n");
	printf("5 ��ѯ����\n");
	printf("6 �����ļ�\n");
	printf("7 �˳�����\n");
	printf("������ִ�в�����");

	return;
}

void chkFileOpenErr(errno_t err) 
{
	if (err != 0)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return;
	}
}

void chkPosErr(int i) 
{
	if (i < 0 || i >= CAPACITY)		//�����쳣
	{
		printf("λ���쳣��\n");
		return;
	}
}

void chkFileIOErr(int nLen,char c) 
{
	if (nLen != g_nNum)
	{
		if (c == 'o')
		{
			printf("д���ļ�ʧ��!\n");
		}
		if (c == 'i')
		{
			printf("��ȡ�ļ�ʧ��!\n");
		}
	}

	return;
}

void showInputMenu(RECORD rcd[],int i) 
{
	printf("Ŀ��վ�㣿");
	scanf_s("%s", rcd[i].site, COLUMNSIZE);
	printf("�û�����");
	scanf_s("%s", rcd[i].usr, COLUMNSIZE);
	printf("���룿"); 
	scanf_s("%s", rcd[i].pwd, COLUMNSIZE);
	printf("��ע��"); 
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
	printf("��¼ID��%3d\n", i);
	printf("վ  �㣺%s\n", rcd[i].site);
	printf("�û�����%s\n", rcd[i].usr);
	printf("��  �룺%s\n", rcd[i].pwd);
	printf("��  ע��%s\n", rcd[i].note);
	printf("----------------------------\n");
}
