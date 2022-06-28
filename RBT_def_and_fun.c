#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Typos_key.h"
#include "RBT_def_and_fun.h"

struct node{
	void  *key;
	nd right;
	nd left;
	nd parent;
	int color; // 0 for black , 1 for red
};


void Transplant(nd *root,nd nil,nd u ,nd v);
nd Minimum(nd x,nd nil);
nd Maximum(nd x,nd nil);
void RightRotate(nd *root,nd nil,nd x);
void LeftRotate(nd *root,nd nil, nd x);
void InsertFixUp(nd *root,nd nil , nd z);
void DeleteFixUp(nd *root, nd nil , nd x);
int nodes_compare(const void *item1, const void *item2);
void SetValue(void *item1,void *item2);

/*int nodes_are_equal(const void *n1,const void *n2,int (*cmp)(const void *item1, const void *item2))
{
    if ((n1 != NULL) && (n2 != NULL)) {
        if ((*cmp)(n1, n2) != 0){
            return 0;
        }
        else {
            return 1;
        }
    }

}
*/


nd Dimiourgia_nil()
{
    nd nil = (nd) malloc(sizeof(struct node)); //desmeusi xorou gia ton nil
    nil->left=nil;                             // arxikopoisi tou nil
    nil->right=nil;
    nil->parent= nil;
    nil->color= 0;
    return nil;
}

void Insert(nd *root , nd nil,void  *key_ptr)
{
	nd z = (nd) malloc(sizeof(struct node));
	z->key=key_ptr;
    z->left=nil;
    z->right=nil;
    z->parent= nil;
    z->color= 0;
	nd y = nil;
	nd x = *root;
	while (x!=nil)
	{
        y = x;
        if (nodes_compare(z->key,x->key)==-1)
            x = x->left;
        else x = x->right;
	}
	z->parent = y;
	if (y == nil)
		*root = z;
	else if (nodes_compare(z->key,y->key)==-1)
		y->left = z;
	else {
    y->right = z;
	}
	z->left= nil;
	z->right=nil;
	z->color = 1;
	InsertFixUp(root,nil,z);

}

void InsertFixUp(nd *root, nd nil , nd z)
{
	nd y;
	while (z->parent->color == 1)
	{
		if (z->parent == z->parent->parent->left)
		{
			y=z->parent->parent->right;
			if (y->color == 1)
			{
				z->parent->color=0;
				y->color=0;
				z->parent->parent->color=1;
				z=z->parent->parent;
			}
			else {
                if (z == z->parent->right)
                {
				z=z->parent;
				LeftRotate(root,nil,z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                RightRotate(root,nil,z->parent->parent);
                }

		}
		else
		{
			{
						y=z->parent->parent->left;
						if (y->color == 1)
						{
							z->parent->color=0;
							y->color=0;
							z->parent->parent->color=1;
							z=z->parent->parent;
						}
						else {
                            if (z == z->parent->left)
                            {
							z=z->parent;
							RightRotate(root,nil,z);
                            }
                            z->parent->color = 0;
                            z->parent->parent->color = 1;
                            LeftRotate(root,nil,z->parent->parent);
                            }


			}
		}
	}
	(*root)->color=0;
}


void Delete(nd *root,nd nil,nd z)
{
	nd y,x;
	int y_original_color;
	y=z;
	y_original_color = y->color;
	if (z->left == nil)
	{
		x=z->right;
		Transplant(root,nil,z,z->right);
	}
	else if(z->right == nil){
        x=z->left;
		Transplant(root,nil,z,z->left);
	}
	else{
		y = Minimum(z->right,nil);
		y_original_color = y->color;
		x = y->right;
		if (y->parent == z)
			x->parent=y;
		else
			{
			Transplant(root,nil,y,y->right);
			y->right=z->right;
			y->right->parent=y;
			}
		Transplant(root,nil,z,y);
		y->left=z->left;
		y->left->parent=y;
		y->color=z->color;
        }
	if (y_original_color == 0){
		DeleteFixUp(root,nil,x);
	}
	free(z);
}



void Transplant(nd *root , nd nil ,nd u ,nd v)
{
	if (u->parent==nil){
		(*root)=v;}
	else if (u==u->parent->left){
		u->parent->left=v;
		}
	else {
        u->parent->right=v;
        }
	v->parent=u->parent;
}

nd Minimum(nd x,nd nil)
{
	while (x!=nil){
		Minimum(x->left,nil);
        return x;
	}
}
nd Maximum(nd x,nd nil)
{
	while (x!=nil){
			Maximum(x->right,nil);
            return x;
	}
}



void PrintInOrder(nd x,nd nil)
{
	 if (x!=nil){
        {

                PrintInOrder(x->left,nil);
                Typos_key *n1=x->key;
                printf("\n%d",n1->x);
                PrintInOrder(x->right,nil);
        }
        }

}
void RightRotate(nd *root, nd nil ,nd x)
{
		 nd y;
		 y= x->left; // set y
		 x->left = y->right; // turn y’s left subtree into x’s right subtree
		 if (y->right != nil)
			 y->right->parent = x;

		 y->parent = x->parent; // link x’s parent to y

		 if (x->parent == nil)
			 *root = y;
		 else if (x == x->parent->right)
			 x->parent->right = y;
		 else
			 x->parent->left = y;

		 y->right = x; // put x on y’s left
		 x->parent = y;
}
void LeftRotate(nd *root, nd nil, nd x)
{
	 nd y;
	 y= x->right; // set y
	 x->right = y->left; // turn y’s left subtree into x’s right subtree
	 if (y->left !=nil)
		 y->left->parent = x;

	 y->parent = x->parent; // link x’s parent to y

	 if (x->parent == nil)
		*root = y;
	 else if (x == x->parent->left)
		 x->parent->left = y;
	 else x->parent->right = y;

	 y->left = x; // put x on y’s left
	 x->parent = y;
}


void DeleteFixUp(nd *root ,nd nil , nd x)
{
    nd w;
    while ((x!=(*root)) && (x->color == 0)){
        if (x==x->parent->left){
            w=x->parent->right;
            if (w->color == 1){
                w->color = 0;
                x->parent->color=1;
                LeftRotate(root, nil , x->parent);
                w = x->parent->right;
            }
            if ((w->left->color==0) && (w->right->color==0)){
                w->color=1;
                x=x->parent;
            }
            else{
                if (w->right->color==0){
                    w->left->color=0;
                    w->color=1;
                    RightRotate(root,nil,w);
                    w=x->parent->right;
                }
                w->color=x->parent->color;
                x->parent->color=0;
                w->right->color=0;
                LeftRotate(root,nil,x->parent);
                x=(*root);
            }
        }
    else {
            w=x->parent->left;
            if (w->color == 1){
                w->color = 0;
                x->parent->color=1;
                LeftRotate(root,nil,x->parent);
                w=x->parent->left;
            }
            if ((w->right->color==0) && (w->left->color==0)){
                w->color=1;
                x=x->parent;
            }
            else{
                if (w->left->color==0){
                    w->right->color=0;
                    w->color=1;
                    RightRotate(root,nil,w);
                    w=x->parent->left;
                }
                w->color=x->parent->color;
                x->parent->color=0;
                w->left->color=0;
                LeftRotate(root,nil,x->parent);
                x=(*root);
            }
        }
    }
    x->color=0;
}

nd find_node(nd root , nd nil , void * key_ptr , int *find_ptr)
{
   nd temp,aux;
   temp=root;
   aux=nil;
   (*find_ptr) = 0;
   while ((temp!=nil) && ((*find_ptr)== 0) ){
        if (nodes_compare(key_ptr,temp->key)==0){
            aux = temp;
            (*find_ptr) = 1;
        }
        else if (nodes_compare(key_ptr,temp->key)==-1){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return aux;
}

int is_rbt_empty(nd root,nd nil)
{
    return (root==nil);
}
