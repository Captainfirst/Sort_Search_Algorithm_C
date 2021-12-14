#ifndef __LIST_PRIV_H
#define __LIST_PRIV_H

/* include files list */
#include "List_Cfg.h"
#include "Std_Types.h"

/* function declaration */

#if (LIST_STRUC_CFG == LIST_LINEAR)

static void List_ReMalloc(List *L);

#else

#endif

#endif
