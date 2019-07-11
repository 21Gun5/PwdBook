#pragma once

void initialFile();								//初始化密码文件
void readFile(PRECORD* ppRcd, int* pnCount);	//读取文件
void saveFile(RECORD rcd[], int nCount);		//保存二进制文件
void showMenu(void);							//显示菜单
void chkFileOpenErr(errno_t err);				//检测文件打开错误
void chkPosErr(int i);							//检测位置错误
void chkFileIOErr(int nLen, char c);			//检测文件读写错误
char* encode(char* buf, int n);					//加密
char* decode(char* buf, int n);					//解密
void showInputMenu(RECORD rcd[], int i);		//引导用户输入
void printRecord(RECORD rcd[], int i);			//打印某记录