
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

///////////////////
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

typedef struct IntFunction
{
	ArrayASTINT* astInt;
	
} IntFunction;

typedef struct ArrayOfIntFunction
{
	ParameterType* param;
    IntFunction* pIntFunc;
	int size;
	
} ArrayOfIntFunction;




////////////////////////////////////////////////////////
	ASTINTBase* root = (ASTINTBase*)calloc(1, sizeof(ASTINTBase) );
	root->Operator = Mul;
	
	ASTINTBase* ch1 = (ASTINTBase*)calloc(1, sizeof(ASTINTBase) );
	ch1->parent = root;
	ch1->Operator = Add;
	root->right = ch1;
	
	ASTINTBase* ch2 = (ASTINTBase*)calloc(1, sizeof(ASTINTBase) );
	ch2->parent = root;
	ch2->value = 3;
	root->left = ch2;
	
	//////////////////
	ASTINTBase* ch21 = (ASTINTBase*)calloc(1, sizeof(ASTINTBase) );
	ch21->parent = ch1;
	ch21->Operator = Mul;
	ch1->right = ch21;
	
	ASTINTBase* ch22 = (ASTINTBase*)calloc(1, sizeof(ASTINTBase) );
	ch22->parent = ch1;
	ch22->value = 3;
	ch1->left = ch22;
	
	//////////////////
	ASTINTBase* ch31 = (ASTINTBase*)calloc(1, sizeof(ASTINTBase) );
	ch31->parent = ch21;
	ch31->value = 3;
	ch21->right = ch31;
	
	ASTINTBase* ch32 = (ASTINTBase*)calloc(1, sizeof(ASTINTBase) );
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
	ExecuteAST_INT(testVoidFunc.pVoidFunc->astInt);
	
/* 	ExecuteAST_FLOAT(ASTINTBase* testVoidFunc.pVoidFunc->astFloat);
	ExecuteAST_DOUBLE(ASTINTBase* testVoidFunc.pVoidFunc->astDouble);
	
	ExecuteAST_ARRAYOFCHAR(ASTINTBase* testVoidFunc.pVoidFunc->astArrayOfChar); */
	
}


/////////////////////////////////////////////////////////////////
ArrayOfIntFunction testIntFunc;

int getSize = 0;
int getParamSize = 0;

void InitIntFunc()
{
	getSize = 1;
	getParamSize = 3;
	
	// +1 for return value
	testIntFunc.param = (ParameterType*) malloc( (getSize + 1 )* sizeof(ParameterType));
	
	testIntFunc.param->pValue = (int*)malloc( getParamSize * sizeof(int));
	testIntFunc.param->size = getParamSize;
	*(testIntFunc.param->pValue + 1 ) = 9;
	*(testIntFunc.param->pValue + 2) = 3;
	*(testIntFunc.param->pValue + 3) = 7;
	
	testIntFunc.pIntFunc = (VoidFunction*) malloc( sizeof(VoidFunction) );
	
	testIntFunc.pIntFunc->astInt = root;
}

ASTBase* returnVal;

void ExecuteIntFunc()
{
	ExecuteAST_INT(testIntFunc.pIntFunc->astInt);
	
/* 	ExecuteAST_FLOAT(ASTINTBase* testIntFunc.pIntFunc->astFloat);
	ExecuteAST_DOUBLE(ASTINTBase* testIntFunc.pIntFunc->astDouble);
	
	ExecuteAST_ARRAYOFCHAR(ASTINTBase* testIntFunc.pIntFunc->astArrayOfChar); */
	
}