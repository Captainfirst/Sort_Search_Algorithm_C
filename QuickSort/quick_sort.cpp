#include "quick_sort.h"

void QuickSort(SqList *L)
{
	QSort(L, 1, L->length);
}

void QSort(SqList *L, int low, int high)
{
	int pivot;
	while(low < high)
	{
		pivot = Partition(L, low, high);
		
		QSort(L, low, pivot - 1);
		low = pivot + 1;	
	}
}

int Partition(SqList *L, int low, int high)
{
	int pivotkey;
	pivotkey = L->r[low];
	L->r[0] = pivotkey;
	while(low < high)
	{
		while(low < high && L->r[high] >= pivotkey)
  		    high--;
        L->r[low] = L->r[high];
		while(low < high && L->r[low] <= pivotkey)
		    low++;
		L->r[high] = L->r[low]; 
	}
	L->r[low] = L->r[0];
	return low; 
}

int main(void)
{
	SqList a = {{0, 50, 10, 90, 30, 70, 40, 80, 60, 20}, 9};
	SqList* L = &a;
	QuickSort(L);
	for(int i = 1; i < 10; i++)
	{
		printf("%d ", L->r[i]);
	}
	cout<<endl; 
	system("pause");
	return 0;
}
