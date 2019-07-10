#pragma once
#include "data.h"

void insertInfo(RECORD rcd[], int* nCount);
void saveFile(RECORD rcd[], int nCount);
void readFile(PRECORD* ppRcd, int *nCount);
void viewAllInfo(RECORD rcd[], int nCount);
void deleteInfo(RECORD rcd[], int *nCount);
void modifyInfo(RECORD rcd[], int nCount);
void searchInfo(RECORD rcd[], int nCount);
void exportFile(RECORD rcd[], int nCount);



