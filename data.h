#pragma once

#define �鿴���� 1
#define ���Ӽ�¼ 2
#define ɾ����¼ 3
#define �޸ļ�¼ 4
#define ������¼ 5
#define �����ļ� 6
#define �˳����� 7
#define CAPACITY 50			//��ʼ����
#define COLUMNSIZE 20		//ÿ���ֶδ�С

extern int g_nNum;			//��ǰ��������λ����¼
extern int g_byteSize;		//��ǰ��������λ���ֽ�

//�����¼�ṹ��
typedef struct _RECORD
{
	char site[COLUMNSIZE];	//վ��
	char usr[COLUMNSIZE];	//�û���
	char pwd[COLUMNSIZE];	//����
	char note[COLUMNSIZE];	//��ע
}RECORD, * PRECORD;