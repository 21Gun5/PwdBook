#pragma once
#include "data.h"

/*
insert��delete��read��Ҫ���ļ�¼�����ʴ�ָ�����޸�֮
read��PRECORD *��Ŀ�����޸�PRECORD������ָ��ս��ڴ���ļ�
������RECORD[]��ָ�룬Ŀ����ʹ��PRECORD���������ڴ����ļ�
*/
//����������
void addInfo(RECORD rcd[], int* pnCount);		//������¼
void deleteInfo(RECORD rcd[], int* pnCount);	//ɾ����¼
void modifyInfo(RECORD rcd[], int nCount);		//�޸ļ�¼
void viewAllInfo(RECORD rcd[], int nCount);		//�鿴����
void searchInfo(RECORD rcd[], int nCount);		//������¼
void exportFile(RECORD rcd[], int nCount);		//�����ı��ļ�



