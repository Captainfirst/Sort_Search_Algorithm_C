/**
 * @file List.c
 * @brief List API
 * @author ZYXKK9 (FirstpioneerZYX@outlook.com)
 * @version 1.0
 * @date 2021-06-18
 *
 * @copyright Copyright (c) 2021  ZYXKK9
 *
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2021-06-18 <td>1.0     <td>ZYXkk9  <td>initial version
 * </table>
 */

/* include files list */
#include "List.h"

#if (LIST_STRUC_CFG == LIST_LINEAR)
/**
 * @brief  Initiate the list.
 * @param  L                list
 * @param  ms               maxsize of the list
 */
void List_Init(List *L, int ms)
{
    if (ms < 0u)
    {
        printf("illegal value for ms!\n");
        exit(1);
    }
    {
        /* Dummy for QAC check */
    }

    L->maxSize = ms;
    L->list = (ElemType *)malloc(ms * sizeof(ElemType));

    if (!L->list)
    {
        printf("Dynamically allocating memory failed!\n");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }

    L->length = 0u;
}

/**
 * @brief  Clear the value and memory space of list.
 * @param  L                list
 */
void List_Deinit(List *L)
{
    if (L->list != NULL)
    {
        free(L->list);
        L->list = NULL;
        L->maxSize = 0;
        L->length = 0;
    }
    else
    {
        /* Dummy for QAC check */
    }
}

/**
 * @brief Get the size of list.
 * @param  L                list
 * @return uint8_t
 */
uint8_t List_Size(List *L)
{
    return L->length;
}

/**
 * @brief Judge whether the list is empty.
 * @param  L                list
 * @return uint8_t
 */
uint8_t List_IsEmpty(List *L)
{
    if (L->length == 0u)
    {
        return 1u;
    }
    else
    {
        return 0u;
    }
}

/**
 * @brief  Get the element based on the input parameter pos.
 * @param  L                list
 * @param  pos              list index, start from 1
 * @return ElemType
 */
ElemType List_GetElem(List *L, uint8_t pos)
{
    if (pos < 1 || pos > L->length)
    {
        printf("Wrong index due to out of bounds!\n");
        exit(1);
    }
    return L->list[pos - 1u];
}

/**
 * @brief  Traverse every member of list.
 * @param  L                list
 */
void List_Traverse(List *L)
{
    uint8_t index_u8;
    for (index_u8 = 0; index_u8 < L->length; index_u8++)
    {
        printf("%u ", L->list[index_u8]);
    }
    printf("\n");
}

/**
 * @brief Find whether element x is included in list.
 * @param  L                list
 * @param  x                element to be found
 * @return int8_t          index if found, or -1 if not
 */
int8_t List_Find(List *L, ElemType x)
{
    uint8_t index_u8;
    for (index_u8 = 0; index_u8 < L->length; index_u8++)
    {
        if (L->list[index_u8] == x)
        {
            return index_u8;
        }
        else
        {
            /* Dummy for QAC check */
        }
    }
    return -1;
}

/**
 * @brief  Modify one element in list based on position.
 * @param  L                list
 * @param  pos              index specified to be modified
 * @param  x                element to be modified
 * @return int8_t           modification result: 1->success  0->failed
 */
int8_t List_UpdatePos(List *L, uint8_t pos, ElemType x)
{
    if (pos < 1 || pos > L->length)
    {
        return 0;
    }
    else
    {
        /* Dummy for QAC check */
    }
    L->list[pos - 1u] = x;
    return 1;
}

/**
 * @brief  Insert an element in the head of the list.
 * @param  L                list
 * @param  x                element to be inserted
 */
void List_InserFirst(List *L, ElemType x)
{
    int index_u8;
    if (L->length == L->maxSize)
    {
        List_ReMalloc(L);
    }
    else
    {
        /* Dummy for QAC check */
    }
    for (index_u8 = L->length - 1u; index_u8 > 0; index_u8--)
    {
        L->list[index_u8 + 1u] = L->list[index_u8];
    }
    L->list[0] = x;
    L->length++;
}

/**
 * @brief  Reallocated the memory capacity twice.
 * @param  L                list
 */
static void List_ReMalloc(List *L)
{
    ElemType *p = realloc(L->list, 2u * L->maxSize * sizeof(ElemType));
    if (!p)
    {
        printf("No enough memory to be allocated!\n");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }
    L->list = p;
    L->maxSize = 2u * L->maxSize;
    printf("Memory capacity has been doubled.\n");
}

/**
 * @brief  Insert element at the end of list
 * @param  L                list
 * @param  x                element to be inserted
 */
void List_InsertLast(List *L, ElemType x)
{
    if(L->length >= L->maxSize)
    {
        List_ReMalloc(L);
    }
    else
    {
        /* Dummy for QAC check */
    }

    L->list[L->length] = x;
    L->length++;
}

/**
 * @brief  Insert element x at certain position
 * @param  L                list
 * @param  pos              position
 * @param  x                element to be inserted
 * @return int              insert result: 1->success  0->failed
 */
int8_t List_InsertPos(List *L, int pos, ElemType x)
{
    uint8_t index_u8;

    if(pos < 1 || pos > L->maxSize + 1)
    {
        return 0;
    }
    else
    {
       /* Dummy for QAC check */
    }

    if(L->length >= L->maxSize)
    {
        List_ReMalloc(L);
    }
    else
    {
       /* Dummy for QAC check */
    }

    for (index_u8 = L->length - 1u; index_u8 >= pos - 1u; index_u8--)
    {
        L->list[index_u8 + 1u] = L->list[index_u8];
    }

    L->list[pos - 1u] = x;
    L->length++;

    return 1;
}

/**
 * @brief  Insert element x in an increasing ordered list
 * @param  L                list
 * @param  x                element to be inserted
 */
void List_InsertOrderList(List *L, ElemType x)
{
    uint8_t indexi_u8, indexj_u8;

    if(L->length >= L->maxSize)
    {
        List_ReMalloc(L);
    }
    else
    {
        /* Dummy for QAC check */
    }

    for (indexi_u8 = 0; indexi_u8 < L->length;indexi_u8++)
    {
        if(x < L->list[indexi_u8])
            break;
    }
    for (indexj_u8 = L->length - 1u; indexj_u8 >= indexi_u8; indexj_u8--)
    {
        L->list[indexj_u8 + 1u] = L->list[indexj_u8];
    }
    L->list[indexi_u8] = x;
    L->length++;
}

/**
 * @brief  Delete the head list element and return it.
 * @param  L                List
 * @return ElemType         head element to be deleted
 */
ElemType List_DeleteFirstList(List *L)
{
    uint8_t index_u8;
    ElemType temp;

    if (L->length == 0)
    {
        printf("Null list, denied to be deleted\n");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }
    temp = L->list[0];
    for (index_u8 = 1; index_u8 < L->length; index_u8++)
        L->list[index_u8 - 1U] = L->list[index_u8];
    L->length--;
    return temp;
}

/**
 * @brief  Delete the tail element
 * @param  L            List
 * @return ElemType     The element to be deleted
 */
ElemType List_DeleteLastList(List *L)
{
    if(L->length == 0)
    {
        printf("Null list, no element!\n");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }

    L->length--;
    return L->list[L->length];
}

/**
 * @brief  Delete the element in the list located in certain pos
 * @param  L                List
 * @param  pos              Element to be deleted at this position
 * @return ElemType         Element to be deleted
 */
ElemType List_DeletePosList(List *L, int pos)
{
    ElemType temp;
    uint8_t index_u8;
    if (pos < 1 || pos > L->length)
    {
        printf("Invalid pos！\n");
        exit(1);
    }
    temp = L->list[pos - 1];
    for (index_u8 = pos; index_u8 < L->length; index_u8++)
        L->list[index_u8 - 1] = L->list[index_u8];
    L->length--;
    return temp;
}

/**
 * @brief  Delete the first element in list matching with x
 * @param  L                List
 * @param  x                element to be deleted
 * @return Boolean          TRUE  match x in list
 *                          FALSE No match
 */
Boolean List_DeleteValueList(List *L, ElemType x)
{
    int indexi_u8, indexj_u8;
    for (indexi_u8 = 0; indexi_u8 < L->length; indexi_u8++)
    {
        if(L->list[indexi_u8] == x)
        {
            break;
        }
        else
        {
            /* Dummy for QAC check */
        }
    }

    if(indexi_u8 >= L->maxSize)
        return FALSE;

    for (indexj_u8 = indexi_u8 + 1U; indexj_u8 < L->length; indexj_u8++)
    {
        L->list[indexj_u8 - 1U] = L->list[indexj_u8];
    }

    L->length--;

    return TRUE;
}

#elif (LIST_STRUC_CFG == LIST_LINKED)

/**
 * @brief  Init list
 * @param  HL       list
 */
void List_InitList(sNode** HL)
{
    *HL = NULL;
}

/**
 * @brief  Clear the entile list
 * @param  HL       List
 */
void List_ClearList(sNode** HL)
{
    sNode *cp, *np;
    cp = *HL;
    while (cp != NULL)
    {
        np = cp->next;
        free(cp);
        cp = np;
    }
    *HL = NULL;
}

/**
 * @brief  Get the size of single link list
 * @param  HL          List
 * @return             Size of single link list
 */
uint8_t List_SizeList(sNode* HL)
{
    uint8_t size_u8 = 0;

    while (HL != NULL)
    {
        size_u8++;
        HL = HL->next;
    }

    return size_u8;
}

/**
 * @brief  Check if the sigle link list is empty
 * @return Boolean          TRUE  list is empty
 *                          FALSE list is not empty
 */
Boolean List_EmptyList(sNode* HL)
{
    if(HL == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * @brief  Get the element at pos position
 * @param  HL               List head
 * @param  pos              Position
 * @return ElemType         The element at pos position
 */
ElemType List_GetElem(sNode* HL, uint8_t pos)
{
    uint8_t index_u8 = 0U;

    if(pos < 1)
    {
        printf("Invalid pos, function would be terminated!\n");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }

    while(HL != NULL)
    {
        index_u8++;
        if(index_u8 == pos)
        {
            break;
        }
        HL = HL->next;
    }

    if(HL != NULL)
    {
        return HL->data;
    }
    else
    {
        printf("Invalid pos, function would be terminated!\n");
        exit(1);
    }
}

/**
 * @brief      Traverse the single link list
 * @param  HL               List head
 */
void List_TraverseList(sNode* HL)
{
    while(HL != NULL)
    {
        printf("%d, ", HL->data);
        HL = HL->next;
    }
    printf("\n");
}

/**
 * @brief Find x in single link list
 * @param  HL               List head
 * @param  x                element to be found
 * @return ElemType         If found , This is element address
 *                          If not, return Nullptr
 */
ElemType* List_FindList(sNode* HL, ElemType x)
{
    while(HL != NULL)
    {
        if(HL->data == x)
        {
            return &HL->data;
        }
        else
        {
            HL = HL->next;
        }
    }
    return NULL;
}

/**
 * @brief  Modify the value at pos as x
 * @param  HL               List
 * @param  pos              the position in the list
 * @param  x                value to be changed
 * @return Boolean          If modified successfully, return TRUE
 *                          If not, return FALSE
 */
Boolean List_UpdatePosList(sNode* HL, uint8_t pos, ElemType x)
{
    uint8_t index_u8 = 0;
    sNode *p = HL;
    while(p != NULL)
    {
        index_u8++;
        if(pos == index_u8)
        {
            break;
        }
        else
        {
            p = p->next;
        }
    }

    if(pos == i)
    {
        p->data = x;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * @brief  Insert an element in the head position
 * @param  HL               Single link list
 * @param  x                element to be inserted
 */
void List_InsertFirstlist(sNode** HL, ElemType x)
{
    sNode *newp;
    newp = malloc(sizeof(sNode));
    if(newp == NULL)
    {
        printf("No adequate dynamic allocation!");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }

    newp->data = x;
    newp->next = *HL;
    *HL = newp;
}

/**
 * @brief  Insert an element in the end position
 * @param  HL               Single link list
 * @param  x                element to be inserted
 */
void List_InsetLastlist(sNode** HL, ElemType x)
{
    sNode *newp;
    newp = malloc(sizeof(sNode));
    if(newp == NULL)
    {
        printf("No adequate dynamic allocation!");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }

    newp->data = x;
    newp->next = NULL;
    if(*HL == NULL)
    {
        *HL = newp;
    }
    else
    {
        sNode* p = *HL;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = newp;
    }
}

/**
 * @brief  Insert the element x at No. x position in the single link list
 * @param  HL               List
 * @param  pos              position
 * @param  x                element to be inserted
 * @return Boolean          TRUE: insert successfully
 *                          FLASE: insert failed
 */
Boolean List_InsertPosList(sNode** HL, uint8_t pos, ElemType x)
{
    uint8_t index_u8 = 0U;
    sNode *newp;
    sNode *cp = *HL, *ap = NULL;
    if(pos <= 0U)
    {
        printf("Invalid pos value!\n");
        return FALSE;
    }
    else
    {
        /* Dummy for QAC check */
    }

    while(cp != NULL)
    {
        index_u8++;
        if(pos == index_u8)
        {
            break;
        }
        else
        {
            ap = cp;
            cp = cp->next;
        }
    }
    newp = malloc(sizeof(sNode));
    if(newp == NULL)
    {
        printf("No adequate dynamic allocation!");
        return FALSE;
    }
    else
    {
        /* Dummy for QAC check */
    }
    newp->data = x;
    if(ap == NULL)
    {
        newp->next = cp;
        *HL = newp;
    }
    else
    {
        newp->next = cp;
        ap->next = newp;
    }
    return TRUE;
}

/**
 * @brief  Insert element x in the ordered sigle link list and keep its original sequence
 * @param  HL               List
 * @param  x                element to be inserted
 */
void List_InsertOrderList(sNode** HL, ElemType x)
{
    sNode *cp = *HL, ap = NULL;
    sNode *newp;
    newp = malloc(sizeof(sNode));
    if(newp == NULL)
    {
        printf("No adequate dynamic allocation!");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }
    newp->data = x;
    if((cp == NULL) || (x < cp->data))
    {
        newp->next = cp;
        *HL = newp;
        return;
    }
    else
    {
        /* Dummy for QAC check */
    }
    while(cp != NULL)
    {
        if(x < cp->data)
        {
            break;
        }
        else
        {
            ap = cp;
            cp = cp->next;
        }
    }
    newp->next = cp;
    ap->next = newp;
}

/**
 * @brief  Delete the head node and return value of this node
 * @param  HL               List
 * @return ElemType         The element to be deleted
 */
ElemType List_DeleteFirstList(sNode** HL)
{
    ElemType temp;
    sNode *p = *HL;
    if(*HL == NULL)
    {
        printf("Invalid head node!");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }
    *HL = *HL->next;
    temp = p->data;
    free(p);
    return temp;
}

/**
 * @brief  Delete the trail node and return value of this node
 * @param  HL               List
 * @return ElemType         The element to be deleted
 */
ElemType List_DeleteLastList(sNode** HL)
{
    ElemType temp;
    sNode *cp = *HL;
    sNode *ap = NULL;
    if(cp == NULL)
    {
        printf("Invalid head node!");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }
    while(cp->next != NULL)
    {
        ap = cp;
        cp = cp->next;
    }
    if(ap == NULL)
    {
        *HL = *HL->next;
    }
    else
    {
        ap->next = NULL;
    }
    temp = cp->data;
    free(cp);
    return temp;
}

/**
 * @brief  Delete the element at certain position and return its value
 * @param  HL               List
 * @param  pos              the position to be deleted
 * @return ElemType         element to be deleted
 */
ElemType List_DeletePosList(sNode **HL, uint8_t pos)
{
    uint8_t index_u8 = 0U;
    ElemType temp;
    sNode *cp = *HL;
    sNode *ap = NULL;
    if(cp == NULL || pos <= 0)
    {
        printf("Invalid pos!\n");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }

    while(cp != NULL)
    {
        index_u8++;
        if(pos == index_u8)
        {
            break;
        }
        ap = cp;
        cp = cp->next;
    }

    if(cp == NULL)
    {
        printf("Invalid pos!\n");
        exit(1);
    }
    else
    {
        /* Dummy for QAC check */
    }

    if(pos == 1U)
    {
        *HL = *HL->next;
    }
    else
    {
        ap->next = cp->next;
    }
    temp = ap->data;
    free(cp);
    return temp;
}


#else
#error "Wrong structure congfigue!!"
#endif
