#include <stdio.h>
#include <stdlib.h>

#include "kvec.h"
#include "MyClass.h"

#include <MyDefine.h>

/* sdasd */
int main()
{
    printf("ASCII\n");
/*     MyClass* myObj = MyClass__create(0, 0, 10, 20);

    printf("MyClass value = %d, \n", MyClass__height( myObj ) );
    
    Object* obj = MyClass__to_object( myObj );
    
    printf("Object value = %d, \n", Object__sides( obj ) );
    
    printf("Object name = %s, \n", Object__name( obj ) ); */
    
    
   	kvec_t(int) array;
	kv_init(array);
    kv_resize( int, array, 20);
    
	kv_push(int, array, 10); // append
	/* kv_a(int, array, 20) = 5; // dynamic */
	/* kv_A(array, 20) = 4; // static */
    printf("%d\n", array.n );
    
    printf("%d\n", array.m );
    
    printf("%d\n", array.a[0] );
    
    printf("%d\n", kv_a( int, array, 0 ) );
    
    kvec_t( Object* ) arrayObj;
    kv_init( arrayObj );
    kv_resize( Object*, arrayObj, 3);
    
    kv_push( Object* , arrayObj,  MyClass__to_object( MyClass__create(0, 0, 10, 20) ) );
    kv_push( Object* , arrayObj,  MyClass__to_object( MyClass__create(0, 0, 55, 66) ) );
    kv_push( Object* , arrayObj,  MyClass__to_object( MyClass__create(0, 0, 12, 32) ) );
    
    for( int i =0 ; i < 3 ; i++)
    {
        printf("Object value = %d, \n", Object__sides( arrayObj.a[i] ) );
    }
    
	kv_destroy(array);
    kv_destroy(arrayObj);
	return 0;
    
}
