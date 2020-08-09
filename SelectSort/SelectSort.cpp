#include "SelectSort.h"

void SelectSort(SqList *L)
{
    int i, j, min;
    for (i = 1; i < L->length; i++)
    {
        min = i;
        for (j = i + 1; j <= L->length; j++)
        {
            if(L->r[min] > L->r[j])
                min = j;
        }
        if( i != min )
            swap(L, i, min);
    }
}

int main(void)
{
	SqList a = {{0, 50, 10, 90, 30, 70, 40, 80, 60, 20}, 9};
	SqList* L = &a;
	SelectSort(L);
	for(int i = 1; i < 10; i++)
	{
		printf("%d ", L->r[i]);
	}
	cout<<endl; 
	system("pause");
	return 0;
}
