/* tree.h -- binary search tree */
/* 			 no duplicate items are allowed in the tree */
#ifndef _TREE_H_
#define _TREE_H_
#include<stdbool.h>
/* readine Item as appropriate */
typedef struct item
{
	char petname[20];
	char petkind[20];
} Item;

#define MAXITEMS 10
typedef struct node
{
	Item item;
	struct node * right;		/* pointer to right branch */
	struct node * left;		/* pointer to left branch  */
}Node;

typedef struct tree
{
	Node * root;			/* pointer to root of tree */
	int size;				/* number of items in tree */
}Tree;

/* function prototypes */

/* operation: 		initialize a tree to empty 			*/
/* preconditons:	ptree points to a tree	   			*/
/* postconditions:  the tree is initialized to empty    */
void InitializeTree(Tree *ptree);

/* operation:		determine if tree is empty			*/
/* preconditions:   ptree points to a tree				*/
/* postconditions:	function returns true if tree is 	*/
/*					empty and returns false otherwise   */
bool TreeIsEmpty(const Tree * ptree);

/* operation:		determine if tree is full			*/
/* preconditions:   ptree points to a tree				*/
/* postconditions:	function returns true if tree is 	*/
bool TreeIsFull(const Tree *ptree);

/* operation:		determine number of items in tree	*/
/* preconditions:   ptree points to a tree				*/
/* postconditions:	function returns numbers of items in*/
/*					tree								*/
int TreeItemCount(const Tree * ptree);

/* operation:  		find an item in a tree 				*/
/* preconditions:   pi points to an item				*/
/*					ptree points to an initialized tree */
/* postconditions:	function returns if item is in tree */
/*					and return false otherwise			*/
bool InTree(const Item *pi, const Tree *ptree);

/* operation:       applay a function to each itme in   */
/* preconditons:	ptree points to a tree				*/
/*					pfun points to a function that takes*/
/*					an Item argument and has no return  */
/*					value								*/
/* postconditions:	the function pointed to by pfun is 	*/
/*					executed once for each item in tree */
void Traverse(const Tree *ptree, void(*pfun)(Item item));

/* operation:    	delete everything from the tree		*/
/* preconditons:	ptree points to an initialized tree */
/* postconditions:	tree is empty						*/
void DeleteAll(Tree * ptree);
#endif
