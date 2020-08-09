#include "HeapSort.h"

void HeapSort(SqList *L)
{
    int i;
    for (i = L->length / 2; i > 0; i--)
        HeapAjust(L, i, L->length);

    for (i = L->length; i > 1; i--)
    {
        swap(L, 1, i);
        HeapAjust(L, 1, i-1);
    }

}

void HeapAjust(SqList *L, int s, int m)
{
    int temp, j;
    temp = L->r[s];
    for (j = 2 * s; j <= m; j *= 2)
    {
        if(j < m && L->r[j] < L->r[j+1])
            ++j;
        if(temp >= L->r[j])
            break;
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = temp;
}

int main(void)
{
	SqList a = {{0, 50, 10, 90, 30, 70, 40, 80, 60, 20}, 9};
	SqList* L = &a;
	HeapSort(L);
	for(int i = 1; i < 10; i++)
	{
		printf("%d ", L->r[i]);
	}
	cout<<endl; 
	system("pause");
	return 0;
}