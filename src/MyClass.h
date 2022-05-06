#ifndef __MYCLASS_H__
#define __MYCLASS_H__

#include "Core.h"

typedef struct MyClass MyClass;

Object* MyClass__to_object(MyClass* myClass);
MyClass* MyClass__from_object(Object* object);
MyClass* MyClass__create(int x, int y, int width, int height);
void MyClass__destroy(MyClass* square);

// Similar to the accessors in the prior case
int MyClass__x(MyClass* self);    
int MyClass__y(MyClass* self);    
int MyClass__width(MyClass* self);    
int MyClass__height(MyClass* self);  

#endif //__MYCLASS_H__
