#include <stdio.h>
#include "data.h"
#include "ctrl.h"
#include "func.h"

int main()
{
	PRECORD pRcd = NULL;					//ָ���ڴ������뱾
	int nCount = 0;							//��ǰ��¼��
	g_nNum = CAPACITY;						//���뱾��������λ����¼��
	g_byteSize = sizeof(RECORD) * g_nNum;   //��������λ���ֽڣ�
	int nRun = 1;							//�Ƿ����б�ʶ

	initialFile();							//��ʼ�������ļ�
	readFile(&pRcd, &nCount);				//���ļ������ڴ�

	while (nRun == 1)
	{
		showMenu();							//������Ϣ

		//�����û�����
		int op;
		scanf_s("%d", &op);

		//�������ģ��
		switch (op)
		{
		case �鿴����:
			viewAllInfo(pRcd, nCount);
			break;
		case ���Ӽ�¼:
			addInfo(pRcd, &nCount);
			break;
		case ɾ����¼:
			deleteInfo(pRcd, &nCount);
			break;
		case �޸ļ�¼:
			modifyInfo(pRcd, nCount);
			break;
		case ������¼:
			searchInfo(pRcd, nCount);
			break;
		case �����ļ�:
			exportFile(pRcd, nCount);
			break;
		case �˳�����:
			nRun = 0;
			printf("�ټ���\n");
			break;
		default:
			break;
		}
	}
	return 0;
}