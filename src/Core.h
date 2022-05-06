#ifndef __CORE_H__
#define __CORE_H__

#include <stdlib.h>

typedef struct Object Object;
typedef struct ObjectDerived ObjectDerived; 

ObjectDerived* ObjectDerived__create( int buffer_size, const char* (*name)(Object*), 
                                        int (*sides)(Object*), void (*destroy)(Object*) );

Object* Object__create(ObjectDerived* derived);
ObjectDerived* Object__derived(Object* self);
void* Object__buffer(Object* self);

const char* Object__name(Object* self);
int Object__sides(Object* self);
void Object__destroy(Object* object);

#endif //__CORE_H__
