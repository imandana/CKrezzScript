#include "MyClass.h"

typedef struct MyClassData {
   int x;
   int y;
   int width;
   int height;
} MyClassData;

const char* MyClass__name_override(Object* self) {
   return "MyClass";
}

int MyClass__sides_override(Object* self) {
   return 4;
}

void* MyClass__destroy_override(Object* myClass) {
   free(myClass);
}

ObjectDerived* myClass_type;

Object* MyClass__to_object(MyClass* myClass) {
   return ((Object*) myClass);
}

MyClass* MyClass__from_object(Object* object) {
  if (!object)  {
    return ((MyClass*) 0);
  }

  ObjectDerived* type = Object__type(object);
  if (type != myClass_type) {
    return ((MyClass*) 0);
  }

  return ((MyClass*) object);
}

MyClassData* MyClass__myClass_data(MyClass* self) {
   Object* object = (Object*) self;
   return (MyClassData*) Object__buffer(object);
}

MyClass* MyClass__create(int x, int y, int width, int height) {
    myClass_type = ObjectDerived__create(
           sizeof(MyClassData),
           &MyClass__name_override,
           &MyClass__sides_override,
           &MyClass__destroy_override);       
   MyClass* result = (MyClass*) Object__create(myClass_type);
   MyClassData* myClass_data = MyClass__myClass_data(result);
   myClass_data->x = x;
   myClass_data->y = y;
   myClass_data->width = width;
   myClass_data->height = height;
   return result;
}

void MyClass__destroy(MyClass* myClass) {
   Object__destroy(MyClass__to_object(myClass));
}

int MyClass__x(MyClass* self) {
   return MyClass__myClass_data(self)->x;
}

int MyClass__y(MyClass* self) {
   return MyClass__myClass_data(self)->y;
}   

int MyClass__width(MyClass* self) {
   return MyClass__myClass_data(self)->width;
}

int MyClass__height(MyClass* self) {
   return MyClass__myClass_data(self)->height;
}
