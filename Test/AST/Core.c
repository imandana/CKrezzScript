#include <stdio.h>
#include <stdlib.h>

#include "kvec.h"


int Mul(int val1, int val2)
{
    return val1 * val2;
}
int Div(int val1, int val2)
{
    return val1 / val2;
}
int Add(int val1, int val2)
{
     return val1 + val2;
}
int Sub(int val1, int val2)
{
     return val1 - val2;
}


typedef struct ASTBase
{
    struct ASTBase* parent;
	
	int (*Operator)(int, int);

	struct ASTBase* left;
	struct ASTBase* right;
	
	int visited;
	int value;
	
} ASTBase;


typedef struct FunPointerStruct
{
    int (*Operator)(int, int);
} FunPointerStruct;


int main()
{
	ASTBase* root = (ASTBase*)calloc(1, sizeof(ASTBase) );
	root->Operator = Mul;
	
	ASTBase* ch1 = (ASTBase*)calloc(1, sizeof(ASTBase) );
	ch1->parent = root;
	ch1->Operator = Add;
	root->right = ch1;
	
	ASTBase* ch2 = (ASTBase*)calloc(1, sizeof(ASTBase) );
	ch2->parent = root;
	ch2->value = 3;
	root->left = ch2;
	
	//////////////////
	ASTBase* ch21 = (ASTBase*)calloc(1, sizeof(ASTBase) );
	ch21->parent = ch1;
	ch21->Operator = Mul;
	ch1->right = ch21;
	
	ASTBase* ch22 = (ASTBase*)calloc(1, sizeof(ASTBase) );
	ch22->parent = ch1;
	ch22->value = 3;
	ch1->left = ch22;
	
	//////////////////
	ASTBase* ch31 = (ASTBase*)calloc(1, sizeof(ASTBase) );
	ch31->parent = ch21;
	ch31->value = 3;
	ch21->right = ch31;
	
	ASTBase* ch32 = (ASTBase*)calloc(1, sizeof(ASTBase) );
	ch32->parent = ch21;
	ch32->value = 2;
	ch21->left = ch32;
	
	ASTBase* lookUp = root;
	//ASTBase* lookUp = ch21;
	if( lookUp->right )
		lookUp = lookUp->right;
	
	//Right side of Parent child
	while( lookUp->parent != 0 )
	{
		if( lookUp->right && !lookUp->right->visited )
		{
			lookUp = lookUp->right;
			continue;
		}
		
		if( lookUp->left && !lookUp->left->visited )
		{
			lookUp = lookUp->left;
			continue;
		}
		
		lookUp->parent->value = lookUp->parent->Operator( lookUp->parent->left->value, lookUp->parent->right->value );
		
		printf("%d %d %d\n", lookUp->parent->value, lookUp->parent->left->value, lookUp->parent->right->value);
		
		lookUp->parent->right->visited = 1;
		lookUp->parent->left->visited = 1;
		
		lookUp = lookUp->parent;
	}
	
	if( lookUp->left )
		lookUp = lookUp->left;
	
	//Left side of Parent child
	while( lookUp->parent != 0 )
	{
		if( lookUp->right && !lookUp->right->visited )
		{
			lookUp = lookUp->right;
			continue;
		}
		
		if( lookUp->left && !lookUp->left->visited )
		{
			lookUp = lookUp->left;
			continue;
		}
		
		lookUp->parent->value = lookUp->parent->Operator( lookUp->parent->left->value, lookUp->parent->right->value );
		
		lookUp->parent->right->visited = 1;
		lookUp->parent->left->visited = 1;
		
		lookUp = lookUp->parent;
	}
	
	printf("%d ", lookUp->value);
	
	free(ch1);
	free(ch2);
	free(root);
	
    return 0;
}

