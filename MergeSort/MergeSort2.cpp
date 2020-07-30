#include "MergeSort2.h"

void MergeSort2(SqList *L)
{
    int *TR = (int*)malloc(L->length * sizeof(int));
    int k = 1;
    while(k < L->length)
    {
        MergePass(L->r, TR, k, L->length);
        k = 2 * k;
        MergePass(TR, L->r, k, L->length);
        k = 2 * k;
    } 
}

void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for(j = m+1, k = i; i <= m && j <= n; k++)
	{
		if(SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if(i <= m)
	{
		for(l = 0; l <= m - i; l++)
			TR[k+l] = SR[i+l];
	}
	if(j <= n)
	{
		for(l = 0; l <= n - j; l++)
			TR[k+l] = SR[j+l];
	}
}

void MergePass(int SR[], int TR[], int s, int n)
{
    int i = 1;
    int j;
    while(i <= n-2*s+1)
    {
        Merge(SR, TR, i, i+s-1, i+2*s-1);
        i = i + 2 * s;
    }
    if(i < n-s+1)
        Merge(SR, TR, i, i+s-1, n);
    else
        for (j = i; j <= n; j++)
            TR[j] = SR[j];
}

int main(void)
{
	SqList a = {{0, 50, 10, 90, 30, 70, 40, 80, 60, 20}, 9};
	SqList* L = &a;
	MergeSort2(L);
	for(int i = 1; i < 10; i++)
	{
		printf("%d ", L->r[i]);
	}
	cout<<endl; 
	system("pause");
	return 0;
}