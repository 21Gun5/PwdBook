#include <stdio.h>
#include "data.h"
#include "ctrl.h"

int main()
{
	PPASSWORD pPwd = NULL;	//�ٿ��ڴ������뱾
	int nCount = 0;			//��ǰ��¼��
	g_nNum = NUM;			//����
	int nRun = 1;

	readInfo(&pPwd, &nCount);	//��ʼ�������������ļ�

	while (nRun == 1)
	{
		//������Ϣ
		printf("������\n");
		printf("1 �鿴����\n");
		printf("2 ��������\n");
		printf("3 ɾ������\n");
		printf("4 �޸�����\n");
		printf("5 ��ѯ����\n");
		printf("6 �����ļ�\n");
		printf("7 �˳�����\n");

		//�����û�����
		int op;
		scanf_s("%d", &op);

		//�������ģ��
		switch (op)
		{
		case 1://�鿴���м�¼
			viewAllInfo(pPwd, nCount);
			break;
		case 2://���Ӽ�¼
			insertInfo(pPwd, &nCount);
			break;
		case 3://ɾ����¼
			deleteInfo(pPwd, &nCount);
			break;
			//case 4://���ļ�¼
			//	alertInfo(pPwd, nCount);
			//	break;
			//case 5://������¼
			//	searchInfo(pPwd, nCount);
			//	break;
			//case 6://���������ļ����ı��ļ�
			//	saveInfoA(pPwd, nCount);
			//	break;
		case 7://���������ļ����ı��ļ�
			nRun = 0;
			printf("�ټ���\n");
			break;
		default:
			break;
		}
	}
	return 0;
}