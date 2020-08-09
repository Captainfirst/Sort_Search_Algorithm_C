#include "HillSort.h"

void ShellSort(SqList *L)
{
    int i, j;
    int increment = L->length;
    do
    {
        increment = increment / 3 + 1;
        for (i = increment + 1; i <= L->length; i++)
        {
            if(L->r[i] < L->r[i-increment])
            {
                L->r[0] = L->r[i];
                for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j-=increment)
                    L->r[j + increment] = L->r[j];
                L->r[j + increment] = L->r[0];
            }
        }
    } while (increment > 1);
}

int main(void)
{
	SqList a = {{0, 50, 10, 90, 30, 70, 40, 80, 60, 20}, 9};
	SqList* L = &a;
	ShellSort(L);
	for(int i = 1; i < 10; i++)
	{
		printf("%d ", L->r[i]);
	}
	cout<<endl; 
	system("pause");
	return 0;
}
