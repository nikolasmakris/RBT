#include <malloc.h>
#include "Typos_key.h"

Typos_key * Dimiourgia()  // ylopoiisi tis sinartisis dimiourgia
{
    Typos_key * New = malloc(sizeof(Typos_key)); // to Typos_key einai to onoma tou typou tou struct kai to new einai i metavliti typoy Typos_key . To new to epistrefoume sto .h
   /* printf("%p\n", New); */
    return New;
}



void SetValue(void *item1 ,void  *item2)
{
    Typos_key *n1 = item1;
    Typos_key *n2 = item2;
    //n1->x = n2->x;   // for int
    //strcpy(n1->x,n2->x); // for strings
}

int nodes_compare(const void *item1, const void *item2)
 {
 Typos_key *n1 = item1;
 Typos_key *n2 = item2;
    //return strcmp(n1->x,n2->x);
    if (n1->x==n2->x){
        return 0;
    }
    else if (n1->x<n2->x){
            return -1;
    }
    else {
            return 1;
    }
}
