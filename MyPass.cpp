#include <stdio.h>
#include "data.h"
#include "ctrl.h"

int main()
{
	PPASSWORD pPwd = NULL;	//ָ�����뱾��ָ�루Ҳָ������¼����¼��ɱ���
	int nCount = 0;		//��ǰ�����¼��
	g_nNum = 0;			//���뱾��������������¼��

	//readInfo(&pPwd, &nCount);	//��ʼ�����뱾

	while (1)
	{
		//��ӡ������Ϣ
		printf("������\n");
		printf("1 �鿴�������룺\n");
		printf("2 �������룺\n");
		printf("3 ɾ�����룺\n");
		printf("4 �޸����룺\n");
		printf("5 ��ѯ���룺\n");
		printf("6 �����ļ���\n");

		//�����û�����
		int op;
		scanf_s("%d", &op);

		//���ݲ�����������Ӧģ��
		switch (op)
		{
		//case 1://�鿴���м�¼
		//	viewAllInfo(pPwd, nCount);
		//	break;
		case 2://�����¼�¼
			insertInfo(pPwd, &nCount);
			break;
		//case 3://ɾ����¼
		//	deleteInfo(pPwd, &nCount);
		//	break;
		//case 4://���ļ�¼
		//	alertInfo(pPwd, nCount);
		//	break;
		//case 5://������¼
		//	searchInfo(pPwd, nCount);
		//	break;
		//case 6://���������ļ����ı��ļ�
		//	saveInfoA(pPwd, nCount);
		//	break;
		default:
			break;
		}
	}
	return 0;
}