#ifndef __LIST_TYPES_H
#define __LIST_TYPES_H

/* include files list */

#include "List_Cfg.h"
#include "Std_Types.h"

/* type definition list */

#if (LIST_STRUC_CFG == LIST_LINEAR)

typedef uint8_t ElemType; /* The value of ElemType based on specification£¬int as default */

typedef struct
{
    ElemType *list;     /* base address of list */
    uint8_t length;     /* real size */
    uint8_t maxSize;    /* max size to store list */
} List;

#elif (LIST_STRUC_CFG == LIST_LINKED)

typedef struct
{
    ElemType data;      /* data element */
    struct sNode* next; /* pointer to the next element */
} sNode;

#else
#error "Wrong structure congfigue!!"
#endif

#endif
