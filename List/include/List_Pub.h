#ifndef __LIST_PUB_H
#define __LIST_PUB_H

/* include files list */

#include "List_Cfg.h"
#include "Std_Types.h"

/* function declaration */

#if (LIST_STRUC_CFG == LIST_LINEAR)

void List_Init(List *L, int ms);

void List_Deinit(List *L);

uint8_t List_Size(List *L);

uint8_t List_IsEmpty(List *L);

ElemType List_GetElem(List *L, uint8_t pos);

void List_Traverse(List *L);

int8_t List_Find(List *L, ElemType x);

int8_t List_UpdatePos(List *L, uint8_t pos, ElemType x);

void List_InserFirst(List *L, ElemType x);

void List_InsertLast(List *L, ElemType x);

int8_t List_InsertPos(List *L, int pos, ElemType x);

void List_InsertOrderList(List *L, ElemType x);

ElemType List_DeleteFirstList(List *L);

ElemType List_DeleteLastList(List *L);

ElemType List_DeletePosList(List *L, int pos);

Boolean List_DeleteValueList(List *L, ElemType x);

#elif (LIST_STRUC_CFG == LIST_LINKED)

void List_InitList(sNode **HL);

void List_ClearList(sNode **HL);

uint8_t List_SizeList(sNode *HL);

Boolean List_EmptyList(sNode *HL);

ElemType List_GetElem(sNode *HL, uint8_t pos);

ElemType *List_FindList(sNode *HL, ElemType x);

void List_TraverseList(sNode *HL);

Boolean List_UpdatePosList(sNode *HL, uint8_t pos, ElemType x);

void List_InsertFirstlist(sNode **HL, ElemType x);

void List_InsetLastlist(sNode **HL, ElemType x);

Boolean List_InsertPosList(sNode **HL, uint8_t pos, ElemType x);

void List_InsertOrderList(sNode **HL, ElemType x);

ElemType List_DeleteFirstList(sNode **HL);

ElemType List_DeleteLastList(sNode **HL);

ElemType List_DeletePosList(sNode **HL, uint8_t pos);

#else
#error "Wrong structure congfigue!!"
#endif

#endif
