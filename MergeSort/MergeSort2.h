#ifndef _MERGESORT2_H_
#define _MERGESORT2_H_

#include "sort.h"

void MergeSort2(SqList *L);
void MergePass(int SR[], int TR[], int s, int n);
void Merge(int SR[], int TR[], int i, int m, int n);

#endif
