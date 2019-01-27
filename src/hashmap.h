#pragma once

#ifdef EXPORT_DLL
  #define HASHMAP_API __declspec(dllexport)
#else
  #define HASHMAP_API __declspec(dllimport)
#endif

#include "hashset.h"

typedef struct hashmap_t
{
  size_t size;
  size_t bits;
  double load_factor;
  size_t num_elems;
  size_t *keys;
  void **values;
} hashmap_t;

HASHMAP_API hashmap_t* new_hashmap(void);

HASHMAP_API hashmap_t* new_hashmap_with_config(size_t size, double load_factor);

HASHMAP_API int add_to_hashmap(hashmap_t *map, void *key, void *value);

//map_value must have the actual type of a pointer to a variable of the type of
//whatever you saved.
//For example if we're saving int's map_value will be int*, if were saving Object*
//then map_value will be Object ** i.e. &(Object *).
HASHMAP_API int get_from_hashmap(hashmap_t *map, void *key, void *map_value);

HASHMAP_API int remove_from_hashmap(hashmap_t *map, void *key);

HASHMAP_API int hashmap_contains_key(hashmap_t *map, void *key);

HASHMAP_API int hashmap_contains_value(hashmap_t *map, void *value);

HASHMAP_API hashset_t* get_key_set(hashmap_t *map);

HASHMAP_API hashset_t* get_value_set(hashmap_t *map);

HASHMAP_API size_t num_elems_hashmap(hashmap_t *map);

HASHMAP_API void clear_hashmap(hashmap_t *map);

HASHMAP_API int is_hashmap_empty(hashmap_t *map);

HASHMAP_API void delete_hashmap(hashmap_t *map);
