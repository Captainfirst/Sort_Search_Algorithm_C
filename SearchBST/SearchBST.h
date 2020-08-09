typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

bool SearchBST(BiTree T, int key, BiTree f, BiTree *p);
bool InsertBST(BiTree *T, int key);
bool Delete(BiTree *p);
bool DeleteBST(BiTree *T, int key);