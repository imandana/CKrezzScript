#include "Core.h"

struct Object 
{
   ObjectDerived* derived;
   char buffer_start;
};

struct ObjectDerived 
{
   int buffer_size;
   const char* (*name)(Object*);
   int (*sides)(Object*);
   void (*destroy)(Object*);      
};

ObjectDerived* ObjectDerived__create(
     int buffer_size,
     const char* (*name)(Object*),
     int (*sides)(Object*),
     void (*destroy)(Object*)) 
{
   ObjectDerived* result = (ObjectDerived*) malloc(sizeof(ObjectDerived));
   result->buffer_size = buffer_size;
   result->name = name;
   result->sides = sides;
   result->destroy = destroy;
   return result;
}

Object* Object__create(ObjectDerived* type)
{
  int size = sizeof(Object) + type->buffer_size;
  Object* result = (Object*) malloc(size);
  result->derived = type;
  return result;
}

ObjectDerived* Object__type(Object* self) 
{
  return self->derived;
}

void* Object__buffer(Object* self) {
   return (void*) &(self->buffer_start);
}

const char* Object__name(Object* self)
{
     return self->derived->name(self);
}

int Object__sides(Object* self) 
{
  return self->derived->sides(self);
}

void Object__destroy(Object* object) 
{
   if (object) {
      object->derived->destroy(object);
   }
}

