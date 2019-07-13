#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "ctrl.h"
#include "func.h"

void addInfo(RECORD rcd[], int* pnCount)
{
	int i = *pnCount;			//��¼��ʶ
	chkPosErr(i);

	showInputMenu(rcd, i);		//����ʾ�����¼

	(*pnCount)++;				//��¼+1
	saveFile(rcd, *pnCount);	//�����ļ�

	printf("��ӳɹ���\n\n");
	system("pause");
	system("cls");
	return;
}

void viewAllInfo(RECORD rcd[], int nCount)
{
	//��ӡ����
	printf("===== ���ƣ�%3d ����¼ =====\n", nCount);
	for (int i = 0; i < nCount; i++)
	{
		printRecord(rcd, i);
	}

	printf("�鿴�ɹ���\n\n");

	system("pause");
	system("cls");
	return;
}

void deleteInfo(RECORD rcd[], int* pnCount)
{
	int i = 0;
	printf("���ɾ����¼ID��\n");
	scanf_s("%d", &i);
	chkPosErr(i);

	//ɾ����¼�����߸���ǰ��
	for (int j = i; j < *pnCount - 1; j++)
	{
		rcd[j] = rcd[j + 1];
	}

	(*pnCount)--;
	saveFile(rcd, *pnCount);

	printf("ɾ���ɹ���\n\n");
	system("pause");
	system("cls");
	return;
}

void modifyInfo(RECORD rcd[], int nCount)
{
	int i = 0;
	printf("��������޸ļ�¼ID��\n");
	scanf_s("%d", &i);
	chkPosErr(i);

	//����ʾ������Ϣ
	printf("��ʼ�޸ģ�\n");
	showInputMenu(rcd, i);

	saveFile(rcd, nCount);
	printf("�޸ĳɹ���\n\n");
	system("pause");
	system("cls");
	return;
}

void exportFile(RECORD rcd[], int nCount)
{
	//���ļ�
	FILE* pFile;
	errno_t err = fopen_s(&pFile, "./output/data.txt", "w");
	chkFileOpenErr(err);

	//д���ļ�
	fprintf(pFile, "����%3d����¼\n", nCount);
	for (int i = 0; i < nCount; i++)
	{
		fprintf(pFile, "ID:%3d || վ��:%s || �û���:%s || ����:%s || ��ע:%s\n", i, rcd[i].site, rcd[i].usr, rcd[i].pwd, rcd[i].note);
	}

	//�ر��ļ�
	fclose(pFile);

	printf("�����ɹ���\n\n");
	system("pause");
	system("cls");
	return;
}

void searchInfo(RECORD rcd[], int nCount)
{
	char key[100] = { 0 };		//�ؼ���
	printf("������ؼ��֣�");
	scanf_s("%s", key, 100);

	//����Ѱ��
	int findRcd[100] = { 0 };	//����Ҫ��ļ�¼��ID
	int nFindCount = 0;			//���ж��ټ�¼����Ҫ��
	for (int i = 0; i < nCount; i++)
	{
		if (strstr(rcd[i].site, key))
		{
			findRcd[nFindCount] = i;
			nFindCount++;
			continue;			//��������ѭ��������ǰ���ֶ��ҵ��������ֶξͲ��ÿ���
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

	//�������ƥ����
	printf("===== ���ƣ�%3d ����¼ =====\n", nFindCount);
	for (int i = 0; i < nFindCount; i++)
	{
		printRecord(rcd, findRcd[i]);
	}
	printf("\n");

	printf("���ҳɹ���\n\n");
	system("pause");
	system("cls");
	return;
}
