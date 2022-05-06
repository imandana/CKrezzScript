#include "Core.h"

#include <stdio.h>
#include <stdlib.h>

#include "kvec.h"

struct DerivedObject
{
    int a;
};

DerivedObject* create()
{
    return 0;
}

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

typedef struct FunPointerStruct
{
    int (*Operator)(int, int);
} FunPointerStruct;

typedef struct IntVariableName
{
    char* name;
    int value;
}

int main()
{
    FILE* ptr;
    char ch;
  
    kvec_t(int) array;
	kv_init(array);
    kv_resize( int, array, 20);

    kvec_t( FunPointerStruct* ) op;
    kv_init(op);
    kv_resize( FunPointerStruct* , op, 20);
    
    FunPointerStruct* p = (FunPointerStruct*)malloc( 20* sizeof(FunPointerStruct) );
 
    // Opening file in reading mode
    ptr = fopen("main.krz", "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    
    int  i =0;
    
    // Dummy Add
    p->Operator = &Add;
    kv_push( FunPointerStruct*, op, p); // append
    p++;
    while( !feof(ptr) )
    {
        ch = fgetc(ptr);
        
        if( ch >= 48 && ch <= 57)
        {
            printf("%c is number \n", ch);
            kv_push(int, array, ch - 48);
            printf("%d the value \n", array.a[i] );
            i++;
        }
        else if( ch == '+')
        {
            p->Operator = &Add;
            kv_push( FunPointerStruct*, op, p); // append
            p++;
            
        }
        else if( ch == '*')
        {
            p->Operator = &Mul;
            kv_push( FunPointerStruct*, op, p); // append
            p++;
            
        }
        //printf("%c", ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop eading.
    }
    
    int hasil = 0;
    for( int k = 0; k < kv_size( array); k++)
    {
        hasil = op.a[ k ]->Operator( hasil, array.a[ k ] );
    }
    printf("%d", hasil);
    
/*     
    kvec_t(int) array;
	kv_init(array);
    kv_resize( int, array, 20);
    
	kv_push(int, array, 10); // append

    kvec_t( FunPointerStruct* ) op;
    kv_init(op);
    kv_resize( FunPointerStruct* , op, 20);
    
    FunPointerStruct* p = (FunPointerStruct*)malloc( sizeof(FunPointerStruct) );
    p->Operator = &Mul;
    
	kv_push( FunPointerStruct*, op, p); // append
    
   
    int hasil = op.a[0]->Operator(3 , 3);
    
    printf("%d", hasil);  */
    
    fclose(ptr);
    
    return 0;
}

