#define MAXSIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std; 

typedef struct
{
	int r[MAXSIZE + 1];  /* The List to be sorted, while r[0] as the guard or temporary variable */
	int length;          /* The length of list */ 
}SqList;

/* Exchange two varibales' value */
inline void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}
