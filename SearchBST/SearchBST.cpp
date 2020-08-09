#include "SearchBST.h"
#include <stdlib.h>

bool SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if(!T)
    {
        *p = f;
        return false;
    }
    else if(key == T->data)
    {
        *p = T;
        return true;
    }
    else if(key < T->data)
    {
        return SearchBST(T->lchild, key, T, p);
    }
    else
    {
        return SearchBST(T->rchild, key, T, p);
    }
}

bool InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if(!SearchBST(*T, key, nullptr, &p))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = nullptr;
        if(!p)
        {
            *T = s;
        }
        else if(key < p->data)
        {
            p->lchild = s;
        }
        else
        {
            p->rchild = s;
        }
    }
    else
        return false;
}

bool DeleteBST(BiTree *T, int key)
{
    if(!*T)
    {
        return false;
    }
    else
    {
        if(key == (*T)->data)
            return Delete(T);
        else if(key < (*T)->data)
            return DeleteBST(&(*T)->lchild, key);
        else
            return DeleteBST(&(*T)->rchild, key);
    }
}

bool Delete(BiTree *p)
{
    BiTree q, s;
    if((*p)->rchild == nullptr)
    {
        q = (*p);
        *p = (*p)->lchild;
        free(q);
    }
    else if((*p)->lchild == nullptr)
    {
        q = (*p);
        *p = (*p)->rchild;
        free(q);
    }
    else
    {
        q = *p;
        s = (*p)->lchild;
        while(s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        if(q!=*p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild;
        free(s);
    }
    return true;
}

int main(void)
{
    int i;
    int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    BiTree T = nullptr;
    for (i = 0; i < 10; i++)
    {
        InsertBST(&T, a[i]);
    }
    system("pause");
    return 0;
}