#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "ctrl.h"

//������¼
void insertInfo(RECORD rcd[], int* pnCount)
{
	int i = *pnCount;		//��¼��ʶ

	//if (i < 0 || i >= NUM)		//�����쳣
	//{
	//	printf("����λ���쳣��\n");
	//	return;
	//}

	//����ʾ�����¼
	printf("Ŀ��վ��?");
	scanf_s("%s", rcd[i].site, 100);
	printf("�û���?");
	scanf_s("%s", rcd[i].usr, 100);
	printf("����?");
	scanf_s("%s", rcd[i].pwd, 100);
	printf("��ע?");
	scanf_s("%s", rcd[i].note, 100);

	//��ӳɹ���
	(*pnCount)++; //��¼+1
	saveFile(rcd, *pnCount);		//�����ļ�

	printf("\n");
	//system("cls");	//����
	return;
}

//�����ļ���������
void saveFile(RECORD rcd[], int nCount)
{
	//���ļ�
	FILE* pFile = NULL;
	errno_t err = fopen_s(&pFile, "./data.i", "wb");	//��Ҫwģʽ�����Ǿ��ļ�������a׷��
	if (err != 0)
	{
		return;
	}

	//д���ļ�
	fwrite(&nCount, sizeof(nCount), 1, pFile);		//д���¼��
	fwrite(&g_nNum, sizeof(g_nNum), 1, pFile);		//д������

	int byteSize = sizeof(RECORD) * g_nNum;		//�����ڴ�
	char* buf = (char*)malloc(byteSize);			//����ռ�
	memcpy_s(buf, byteSize, rcd, byteSize);		//rcd->buf��rcdΪ��,bufΪ�н�)

	//����
	//for (int i = 0; i > byteSize; i++)
	//{
	//	buf[i] -= 1;
	//}

	int nlen = fwrite(buf, sizeof(RECORD), g_nNum, pFile);		//д�������¼��buf->pfile

	//if (nlen != g_nNum)
	//	printf("д��ʧ��!\n");
	//else
	//	printf("д��ɹ���\n");

	//�ر��ļ�
	fclose(pFile);
	free(buf);		//�ͷſռ�
	buf = NULL;		//��������ָ��
	return;
}

//��ȡ�ļ�
void readFile(PRECORD* ppRcd, int* pnCount)
{
	//���ļ�
	FILE* pFile;
	errno_t err = fopen_s(&pFile, "./data.i", "rb");

	//�����ʧ��
	if (err != 0)
	{
		printf("�ļ���ʧ�ܣ�\n");
		//*ppRcd = (PRECORD)malloc(sizeof(RECORD) * NUM);	//���������ڴ棬�����׵�ַ��ֵ��pRcd
		//g_nNum = NUM;	//��ǰ��������ΪĬ������
		return;
	}

	//��ȡ�ļ�
	fread(pnCount, sizeof(int), 1, pFile);		//����¼��
	fread(&g_nNum, sizeof(g_nNum), 1, pFile);	//������

	*ppRcd = (PRECORD)malloc(sizeof(RECORD) * g_nNum);	//���������ڴ�
	memset(*ppRcd, 0, sizeof(RECORD) * g_nNum);	//�ڴ��ʼ��
	int nLen = fread(*ppRcd, sizeof(RECORD), g_nNum, pFile);	//���ļ����ڴ�
	if (nLen != g_nNum)
	{
		printf("�����ļ���ȡʧ�ܣ�\n");
		fclose(pFile);
		return;
	}

	//����
	//int byteSize = sizeof(RECORD) * g_nNum;
	//char* buf = (char*)* ppRcd;
	//for (int i = 0; i < byteSize; i++)
	//{
	//	buf[i] += 1;
	//}

	//�ر��ļ�
	fclose(pFile);
	return;
}

//��ʾ����
void viewAllInfo(RECORD rcd[], int nCount)
{
	printf("===== ���ƣ�%3d ����¼ =====\n", nCount);
	for (int i = 0; i < nCount; i++)
	{
		printf("��¼ID��%3d\n", i);
		printf("վ  �㣺%s\n", rcd[i].site);
		printf("�û�����%s\n", rcd[i].usr);
		printf("��  �룺%s\n", rcd[i].pwd);
		printf("��  ע��%s\n", rcd[i].note);
		printf("----------------------------\n");
	}
	printf("\n");
	//system("cls");
	return;
}

//ɾ����¼
void deleteInfo(RECORD rcd[], int* pnCount)
{
	int i = 0;
	printf("���ɾ����¼ID��\n");
	scanf_s("%d", &i);

	//if (i < 0 || i >= NUM)
	//{
	//	printf("ID�쳣�����ʵ��%d\n", i);
	//	return;
	//}

	//ɾ����¼�����߸���ǰ��
	for (int j = i; j < *pnCount - 1; j++)
	{
		rcd[j] = rcd[j + 1];
	}

	(*pnCount)--;
	saveFile(rcd, *pnCount);	//�����ļ�

	//printf("\n");
	//system("cls");

	return;
}

//�޸ļ�¼
void modifyInfo(RECORD rcd[], int nCount)
{
	int i = 0;
	printf("��������޸ļ�¼ID��\n");
	scanf_s("%d", &i);

	//if (i < 0 || i >= NUM)
	//{
	//	printf("�޸�λ���쳣��%d\n", i);
	//	return;
	//}

	printf("��ʼ�޸ģ�\n");

	printf("Ŀ��վ�㣿");
	scanf_s("%s", rcd[i].site, 100);
	printf("�û�����");
	scanf_s("%s", rcd[i].usr, 100);
	printf("���룿");
	scanf_s("%s", rcd[i].pwd, 100);
	printf("��ע��");
	scanf_s("%s", rcd[i].note, 100);

	saveFile(rcd, nCount);

	//printf("\n");
	//system("cls");
	return;
}

//��ѯ��¼
void searchInfo(RECORD rcd[], int nCount)
{
	char key[100] = { 0 };
	printf("������ؼ��֣�");
	scanf_s("%s", key, 100);

	//����Ѱ��
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
	//����ƥ����
	printf("===== ���ƣ�%3d ����¼ =====\n", nFindCount);
	for (int i = 0; i < nFindCount; i++)
	{
		int pos = findRcd[i];
		printf("��¼ID��%3d\n", pos);
		printf("վ  �㣺%s\n", rcd[pos].site);
		printf("�û�����%s\n", rcd[pos].usr);
		printf("��  �룺%s\n", rcd[pos].pwd);
		printf("��  ע��%s\n", rcd[pos].note);
	}
	printf("\n");
	return;
}

//�����ļ����ı�
void exportFile(RECORD rcd[], int nCount)
{
	//���ļ�
	FILE* pFile;
	errno_t err = fopen_s(&pFile, "./data.txt", "w");

	//if (err != 0)
	//{
	//	return;
	//}

	//д���ļ�
	fprintf(pFile, "����%3d����¼\n", nCount);
	for (int i = 0; i < nCount; i++)
	{
		fprintf(pFile, "ID:%3d || վ��:%s || �û���:%s || ����:%s || ��ע:%s\n", i, rcd[i].site, rcd[i].usr, rcd[i].pwd, rcd[i].note);
	}

	//�ر��ļ�
	fclose(pFile);

	//printf("�����ļ������ɹ�\n");
	//system("cls");
	return;
}


