#pragma once

void initialFile();								//��ʼ�������ļ�
void readFile(PRECORD* ppRcd, int* pnCount);	//��ȡ�ļ�
void saveFile(RECORD rcd[], int nCount);		//����������ļ�
void showMenu(void);							//��ʾ�˵�
void chkFileOpenErr(errno_t err);				//����ļ��򿪴���
void chkPosErr(int i);							//���λ�ô���
void chkFileIOErr(int nLen, char c);			//����ļ���д����
char* encode(char* buf, int n);					//����
char* decode(char* buf, int n);					//����
void showInputMenu(RECORD rcd[], int i);		//�����û�����
void printRecord(RECORD rcd[], int i);			//��ӡĳ��¼