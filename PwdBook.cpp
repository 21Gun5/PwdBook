#include <stdio.h>
#include "data.h"
#include "ctrl.h"

int main()
{
	PRECORD pRcd = NULL;	//ָ�����뱾���ڴ�
	int nCount = 0;			//��ǰ��¼��
	g_nNum = CAPACITY;		//����
	int nRun = 1;

	readFile(&pRcd, &nCount);	//���뱾���ļ�->�ڴ�

	while (nRun == 1)
	{
		//������Ϣ
		printf("���뱾ʹ��\n");
		printf("1 �鿴����\n");
		printf("2 ��������\n");
		printf("3 ɾ������\n");
		printf("4 �޸�����\n");
		printf("5 ��ѯ����\n");
		printf("6 �����ļ�\n");
		printf("7 �˳�����\n");
		printf("������ִ�в�����");

		//�����û�����
		int op;
		scanf_s("%d", &op);

		//�������ģ��
		switch (op)
		{
		case 1://�鿴���м�¼
			viewAllInfo(pRcd, nCount);
			break;
		case 2://���Ӽ�¼
			insertInfo(pRcd, &nCount);
			break;
		case 3://ɾ����¼
			deleteInfo(pRcd, &nCount);
			break;
		case 4://�޸ļ�¼
			modifyInfo(pRcd, nCount);
			break;
		case 5://������¼
			searchInfo(pRcd, nCount);
			break;
		case 6://�����ļ�
			exportFile(pRcd, nCount);
			break;
		case 7://�˳�
			nRun = 0;
			printf("�ټ���\n");
			break;
		default:
			break;
		}
	}
	return 0;
}