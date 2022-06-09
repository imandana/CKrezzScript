
typedef struct IntImmutableDataStorage
{
	int* pValue;
	int size;
	
} IntImmutableDataStorage;

typedef struct IntMutableDataStorage
{
	int* pValue;
	int size;
} IntMutableDataStorage;

typedef struct ParameterType
{
	int* pValue;
	int size;
	
} ParameterType;

typedef struct ArrayASTINT
{
	ASTINTBase* pValue;
	int size;
} ArrayASTINT;

typedef struct VoidFunction
{
	ArrayASTINT* astInt;
	
} VoidFunction;

typedef struct ArrayOfVoidFunction
{
	ParameterType* param;
    VoidFunction* pVoidFunc;
	int size;
	
} ArrayOfVoidFunction;



////////////////////////////////////////////////////////
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
	
///////////////////////////////////////////////////////////////////

ArrayOfVoidFunction testVoidFunc;

int getSize = 0;
int getParamSize = 0;
void InitVoidFunc()
{
	getSize = 1;
	getParamSize = 3;
	
	testVoidFunc.param = (ParameterType*) malloc(getSize* sizeof(ParameterType));
	
	testVoidFunc.param->pValue = (int*)malloc( getParamSize * sizeof(int));
	testVoidFunc.param->size = getParamSize;
	*(testVoidFunc.param->pValue ) = 5;
	*(testVoidFunc.param->pValue + 1) = 8;
	*(testVoidFunc.param->pValue + 2) = 2;
	
	testVoidFunc.pVoidFunc = (VoidFunction*) malloc( sizeof(VoidFunction) );
	
	testVoidFunc.pVoidFunc->astInt = root;
}

void ExecuteVoidFunc()
{
	ExecuteAST_INT(ASTINTBase* testVoidFunc.pVoidFunc->astInt);
	
/* 	ExecuteAST_FLOAT(ASTINTBase* testVoidFunc.pVoidFunc->astFloat);
	ExecuteAST_DOUBLE(ASTINTBase* testVoidFunc.pVoidFunc->astDouble);
	
	ExecuteAST_ARRAYOFCHAR(ASTINTBase* testVoidFunc.pVoidFunc->astArrayOfChar); */
	
}
