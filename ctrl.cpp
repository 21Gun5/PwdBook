#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "ctrl.h"

//���������¼
void insertInfo(PASSWORD pwd[], int* pnCount)
{
	int i = *pnCount;		//��ʾ��ǰ�ǵڼ�����¼/�˼�¼�����뱾�е�λ��
	//if (i < 0 || i >= NUM)		//�����쳣����ֹ
	//{
	//	printf("����λ���쳣��\n");
	//	return;
	//}

	pwd = (PPASSWORD)malloc(sizeof(PASSWORD));
	//��ӡ��ʾ��Ϣ�������������¼
	printf("������< Ŀ��վ�� >: \n");
	scanf_s("%s", pwd[i].webSites, 100);
	printf("������< �û��� >: \n");
	scanf_s("%s", pwd[i].userName, 100);
	printf("������< ���� >: \n");
	scanf_s("%s", pwd[i].passWord, 100);
	printf("������< ��ע��Ϣ >: \n");
	scanf_s("%s", pwd[i].note, 100);

	//��ӳɹ���
	(*pnCount)++; //��¼��+1
	saveInfoB(pwd, *pnCount);		//���������ļ��������ƣ���������

	//�ƺ���
	printf("\n");
	system("cls");	//����

	return;
}

//���������ļ����������ļ����������ã�
void saveInfoB(PASSWORD pwd[], int nCount)
{
	//���ļ�
	FILE* pFile=NULL;
	errno_t err = fopen_s(&pFile, "./data.i", "wb");
	if (err != 0)		//����ʧ�ܣ���ֹ
	{
		return;
	}

	//д���ļ�
	fwrite(&nCount, sizeof(nCount), 1, pFile);		//д�뵱ǰ�����¼��
	fwrite(&g_nNum, sizeof(g_nNum), 1, pFile);		//д�����뱾����

	//int byteSize = sizeof(PASSWORD) * g_nNum;		//���������ڴ�ռ�
	int byteSize = sizeof(PASSWORD);		//���������ڴ�ռ�
	char* buf = (char*)malloc(byteSize);			//Ϊ���뱾��̬��������ռ�
	memcpy_s(buf, byteSize, pwd, byteSize);		//����ǰ��ָ�����¼���Ƶ���������

	//���м򵥼���
	//for (int i = 0; i > byteSize; i++)
	//{
	//	buf[i] -= 1;
	//}
	//int nlen = fwrite(buf, sizeof(PASSWORD), g_nNum, pFile);		//�����ܺ�������¼д���ļ�
	int nlen = fwrite(buf, sizeof(PASSWORD), 1, pFile);
	//if (nlen != g_nNum)		//�����ص�д��ɹ������ݿ����������Ԥ��ֵ
	//	printf("д��ʧ��!\n");
	//else
	//	printf("д��ɹ���\n");

	//�ر��ļ�
	fclose(pFile);
	free(buf);		//�ͷŶ�̬����Ŀռ�
	buf = NULL;		//��ʱ��ֵΪnull�������ΪҰָ��
	return;
}

////��ȡ�����ļ�
//void readInfo(PPASSWORD* ppPwd, int* pnCount)
//{
//	//���ļ�
//	FILE* pFile;
//	errno_t err = fopen_s(&pFile, "./data.i", "rb");
//
//	//�����ʧ��
//	if (err != 0)
//	{
//		*ppPwd = (PPASSWORD)malloc(sizeof(PASSWORD) * NUM);	//���������ڴ棬�����׵�ַ��ֵ��pPwd
//		g_nNum = NUM;	//��ǰ��������ΪĬ������
//		return;
//	}
//
//	//��ȡ�ļ�
//	fread(pnCount, sizeof(int), 1, pFile);		//��ȡ��¼��
//	fread(&g_nNum, sizeof(g_nNum), 1, pFile);	//��ȡ����
//	*ppPwd = (PPASSWORD)malloc(sizeof(PASSWORD) * g_nNum);	//���������ڴ棬�����׵�ַ��pPwd
//	memset(*ppPwd, 0, sizeof(PASSWORD) * g_nNum);	//������ĵ��ڴ棬��ʼ��Ϊ0
//	int nLen = fread(*ppPwd, sizeof(PASSWORD), g_nNum, pFile);	//��ȡ�����¼
//	if (nLen != g_nNum)
//	{
//		printf("�����ļ���ȡʧ�ܣ�\n");
//		fclose(pFile);
//		return;
//	}
//
//	//����
//	int byteSize = sizeof(PASSWORD) * g_nNum;
//	char* buf = (char*)* ppPwd;
//	for (int i = 0; i < byteSize; i++)
//	{
//		buf[i] += 1;
//	}
//
//	//�ر��ļ�
//	fclose(pFile);
//
//	return;
//}
//
////��ʾ���������¼
//void viewAllInfo(PASSWORD pwd[], int nCount)
//{
//	printf("==���ƣ�%3 d ����¼========n",nCount);
//	for (int i = 0; i < nCount; i++)
//	{
//		printf("--ID: %3d--------", i);
//		printf("Ŀ�꣺%s\n", pwd[i].webSites);
//		printf("�û�����%s", pwd[i].userName);
//		printf("����: %s\n", pwd[i].passWord);
//		printf("��ע��%s\n", pwd[i].note);
//	}
//	printf("\n");
//	system("cls");
//	return;
//}
//
//
//
////ɾ�������¼
//void deleteInfo(PASSWORD pwd[], int* pnCount)
//{
//	int i = -1;
//	printf("�������ɾ���\n");
//	scanf_s("%d", &i);
//	if (i<0 || i>NUM)
//	{
//		printf("ɾ��λ���쳣��%d\n", i);
//		return;
//	}
//
//	//ɾ����¼������ĸ�ֵ��ǰ��
//	for (int j = i; i < *pnCount - 1; j++)
//	{
//		pwd[j] = pwd[j + 1];
//	}
//
//	(*pnCount)--;	//��¼-1
//	saveInfoB(pwd, *pnCount);	//ɾ���󱣴��ļ�
//
//	printf("\n");
//	system("cls");
//
//	return;
//}
//
////�޸������¼
//void alertInfo(PASSWORD pwd[], int nCount)
//{
//	int i = -1;
//	printf("��������޸��\n");
//	scanf_s("%d", &i);
//	if (i<0 || i>NUM)
//	{
//		printf("�޸�λ���쳣��%d\n", i);
//		return;
//	}
//
//	
//	printf("--ID: %3d--------", i);
//	printf("Ŀ�꣺%s\n", pwd[i].webSites);
//	printf("�û�����%s", pwd[i].userName);
//	printf("����: %s\n", pwd[i].passWord);
//	printf("��ע��%s\n", pwd[i].note);
//
//	printf("�޸�\n");
//
//	printf("������< Ŀ��վ�� >: \n");
//	scanf_s("%s", pwd[i].webSites, 100);
//	printf("������< �û��� >: \n");
//	scanf_s("%s", pwd[i].userName, 100);
//	printf("������< ���� >: \n");
//	scanf_s("%s", pwd[i].passWord, 100);
//	printf("������< ��ע��Ϣ >: \n");
//	scanf_s("%s", pwd[i].note, 100);
//
//	saveInfoB(pwd, nCount);
//
//	printf("\n");
//	system("cls");
//	return;
//}
//
////���������¼
//void searchInfo(PASSWORD pwd[], int nCount)
//{
//	char key[100] = { 0 };
//	printf("������ؼ��֣�\n");
//	scanf_s("%s", key, 100);
//
//	//�ҳ�����ƥ����
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
//		//��ӡ����ƥ����
//		printf("==����ƥ�䣺%3 d ����¼========n", nFindCount);
//		for (int i = 0; i < nFindCount; i++)
//		{
//			int pos = findPwd[i];
//			printf("--ID: %3d--------", pos);
//			printf("Ŀ�꣺%s\n", pwd[pos].webSites);
//			printf("�û�����%s", pwd[pos].userName);
//			printf("����: %s\n", pwd[pos].passWord);
//			printf("��ע��%s\n", pwd[pos].note);
//		}
//
//		printf("\n");
//		system("cls");
//	}
//	return;
//}
//
////���������ļ����ı��ļ����û�������
//void saveInfoA(PASSWORD pwd[], int nCount)
//{
//	//���ļ�
//	FILE* pFile;
//	errno_t err = fopen_s(&pFile, "./data.txt", "w");
//	if (err != 0)
//	{
//		return;
//	}
//	//д���ļ�
//	fprintf(pFile,"==���ƣ�%3 d ����¼========n", nCount);
//	for (int i = 0; i < nCount; i++)
//	{
//		fprintf(pFile, "--ID: %3d--------", i);
//		fprintf(pFile, "Ŀ�꣺%s\n", pwd[i].webSites);
//		fprintf(pFile, "�û�����%s", pwd[i].userName);
//		fprintf(pFile, "����: %s\n", pwd[i].passWord);
//		fprintf(pFile, "��ע��%s\n", pwd[i].note);
//	}
//	//�ر��ļ�
//	fclose(pFile);
//	printf("�����ļ������ɹ�\n");
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
