
typedef struct ASTINTBase
{
    struct ASTINTBase* parent;
	
	int (*Operator)(int, int);

	struct ASTINTBase* left;
	struct ASTINTBase* right;
	
	int visited;
	int* value;
	
} ASTINTBase;

ASTBase* ExecuteAST_INT(ASTINTBase* lookUp)
{
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
}
