#pragma once

#define CAPACITY 5			//��ʼ����
extern int g_nNum;			//��ǰ����

//�����¼�ṹ��
typedef struct _RECORD
{
	char site[4];	//վ��
	char usr[4];	//�û���
	char pwd[4];	//����
	char note[4];	//��ע
}RECORD, * PRECORD;