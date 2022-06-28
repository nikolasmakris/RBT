#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "RBT_def_and_fun.h"
#include "Typos_key.h"

int main() {


    Typos_key *n;

	int option,find;
	nd node_found,root,nil;

	nil=Dimiourgia_nil();
	root=nil;


	printf("Select option\n");                  //menou
	printf( "1.Insert\n") ;
	printf( "2.Delete\n") ;
	printf( "3.Search\n") ;
	printf( "4.PrintInOrder\n") ;
	printf( "0.Exit\n" ) ;
	fflush(stdin);
	scanf("%d",&option);
	getchar();

	while (option != 0){
	if (option == 1)
	{
			n = Dimiourgia();

			printf("Give number to insert:\n");
			scanf("%d",&(n->x));
			getchar();
			Insert(&root,nil,(void *)n);
	}
	if (option == 2)
	{
		n = Dimiourgia();
		printf("Give number to delete:\n");
        scanf("%d",&(n->x));
        getchar();
        if (!is_rbt_empty(root,nil)){                      // elegxos gia keno dentro
            node_found = find_node(root, nil, (void *) n, &find); // anazitisi komvou kai epistrofi timis
            if (find != 0 ){
                Delete(&root,nil,node_found);
            }
            else {
                printf("Error : Node not found\n");
            }
        }
        else {
            printf("The Tree is empty\n");
        }
	}
	else if (option == 3)
	{
		n = Dimiourgia();
		printf("Give number to search:");
		scanf("%d",&(n->x)) ;
		getchar();
        if (!is_rbt_empty(root,nil)){                          // elegxos gia keno dentro
            find_node(root , nil , (void *)n , &find);  // anazitisi komvou
            if (find != 0 ){
                printf("Node found %d" , n->x);
            }
            else {
                printf("Node doesn't exist in RBT\n");
            }
        }
        else{
            printf("The Tree is empty\n");
        }
	}
	else if (option == 4)
		{
            if (!is_rbt_empty(root,nil)){                      // elegxos gia keno dentro
                printf("\nNow printing values in order\n");

                PrintInOrder(root,nil);                            //ektipwsi kleidion
                }
            else{
                printf("The Tree is empty\n");
            }
		}
    else
    {


    }
		printf( "\nSelect option\n" );
		printf( "1.Insert\n") ;
		printf( "2.Delete\n") ;
		printf( "3.Search\n") ;
		printf( "4.PrintInOrder\n") ;
		printf( "0.Exit\n") ;
		fflush(stdin);
        scanf("%d",&option);
        getchar();
	}
	printf("EXIT");
	return 0;
}


