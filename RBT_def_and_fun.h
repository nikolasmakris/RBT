#ifndef RBT_DEF_AND_FUN_H_INCLUDED
#define RBT_DEF_AND_FUN_H_INCLUDED

#include "Typos_key.h"

typedef struct node *nd;

nd Dimiourgia_nil();
void PrintInOrder(nd root,nd nil);
void Insert(nd *root , nd nil ,void *key);
void Delete(nd *root , nd nil , nd z);
nd find_node(nd root , nd nil ,void *Tk_ptr ,int *flag);
int is_rbt_empty(nd root,nd nil);
int nodes_are_equal(const void *n1,const void *n2,int (*cmp)(const void *item1, const void *item2));

#endif // RBT_DEF_AND_FUN_H_INCLUDED
