#pragma once

//ȫ�ֱ���������������
#define NUM 5			//��ʼ���뱾��������������¼����
extern int g_nNum;		//��ǰ�����뱾����

//�洢�����¼�Ľṹ�壨һ����¼��4���ֶ�
typedef struct _PASSWORD
{
	char webSites[4];	//վ��
	char userName[4]; //�û���
	char passWord[4]; //����
	char note[4];		//��ע
}PASSWORD, * PPASSWORD;