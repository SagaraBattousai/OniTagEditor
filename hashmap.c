#include <stdlib.h>
#include <stdio.h>
#include "hashmap.h"

static const size_t default_size = 16;
static const size_t default_bits = 4;
static const double default_load_factor = 0.75;

static const size_t prime_multiplier = 37;
static const size_t prime_adder = 3733;

hashmap_t* new_hashmap(void)
{
  hashmap_t *map = (hashmap_t *)malloc(sizeof(hashmap_t));

  if(!map)
  {
    return NULL;
  }

  map->size = default_size;

  map->bits = default_bits;

  map->load_factor = default_load_factor;

  map->num_elems = 0;

  map->keys = (size_t *) calloc(map->size, sizeof(size_t));

  map->values = (void **) calloc(map->size, sizeof(void *));

  if(!(map->keys && map->values))
  {
    delete_hashmap(map);
    return NULL;
  }

  return map;

}

hashmap_t* new_hashmap_with_config(size_t size, double load_factor)
{
  hashmap_t *map = (hashmap_t *)malloc(sizeof(hashmap_t));

  if(!map)
  {
    return NULL;
  }

  size_t bits = size;

  bits--;
  bits |= bits >> 1;
  bits |= bits >> 2;
  bits |= bits >> 4;
  bits |= bits >> 8;
  bits |= bits >> 16;
  bits |= bits >> 32;
  bits++;

  map->size = (size_t) 1 << bits;

  map->bits = bits;

  map->load_factor = load_factor;

  map->num_elems = 0;

  map->keys = (size_t *) calloc(map->size, sizeof(size_t));

  map->values = (void **) calloc(map->size, sizeof(void *));

  if(!(map->keys && map->values))
  {
    delete_hashmap(map);
    return NULL;
  }

  return map;

}

static int add(hashmap_t *map, void *key, void *map_value)
{

  //Add Elem
  size_t value = (size_t)key;

  if(value == 0)
  {
    return -1;
  }

  size_t modulo = map->size - 1;

  size_t hash = modulo & (value * prime_multiplier);

  while(map->keys[hash] != 0)
  {

    if(map->keys[hash] == value)
    {
      map->values[hash] = map_value;
      return 2;
    }

    hash = modulo & (hash + prime_adder);

  }

  map->keys[hash] = value;
  map->values[hash] = map_value;

  map->num_elems++;

  return 1;

}

int remove_from_hashmap(hashmap_t *map, void *key)
{

  size_t modulo = map->size - 1;

  size_t value = (size_t)key;

  if(value == 0)
  {
    return -1;
  }

  size_t hash = modulo & (value * prime_multiplier);

  while(map->keys[hash] != 0)
  {

    if(map->keys[hash] == value)
    {
      map->keys[hash] = 0;

      map->values[hash] = 0;

      map->num_elems--;

      return 1;
    }

    hash = modulo & (hash + prime_adder);

  }

  return 0;
}

static void resize_hashmap(hashmap_t *map)
{

  if(map->num_elems >= (double)map->size * map->load_factor)
  {

    size_t *old_keys = map->keys;

    void **old_values = map->values;

    size_t old_size = map->size;

    map->bits++;
    map->size = (size_t) (1 << map->bits);
    map->keys = (size_t *)calloc(map->size, sizeof(size_t));
    map->values = (void **)calloc(map->size, sizeof(void *));

    if(!(map->keys && map->values))
    {
      delete_hashmap(map);

      fprintf(stderr, "Failure, could not resize hashmap from size %zu to %zu\
          \nCurrent size of map: %zu\n", old_size, map->size, map->num_elems);

      exit(EXIT_FAILURE);
    }

    map->num_elems = 0;

    for(size_t i = 0; i < old_size; i++)
    {
      add(map, (void *)old_keys[i], old_values[i]);
    }

    free(old_keys);
    free(old_values);

  }

}


int add_to_hashmap(hashmap_t *map, void *key, void *value)
{

  //Resize Hash Set Incase Full
  resize_hashmap(map);

  return add(map, key, value);

}

int get_from_hashmap(hashmap_t *map, void *key, void *map_value)
{
  size_t modulo = map->size - 1;

  size_t value = (size_t)key;

  if(value == 0)
  {
    return -1;
  }

  size_t hash = modulo & (value * prime_multiplier);

  while(map->keys[hash] != 0)
  {

    if(map->keys[hash] == value)
    {
      *((void **) map_value) = map->values[hash];

      return 1;
    }

    hash = modulo & (hash + prime_adder);

  }

  return 0;



}

int hashmap_contains_key(hashmap_t *map, void *key)
{

  size_t modulo = map->size - 1;

  size_t value = (size_t)key;

  if(value == 0)
  {
    return -1;
  }

  size_t hash = modulo & (value * prime_multiplier);

  while(map->keys[hash] != 0)
  {

    if(map->keys[hash] == value)
    {
      return 1;
    }

    hash = modulo & (hash + prime_adder);

  }

  return 0;

}

int hashmap_contains_value(hashmap_t *map, void *value)
{
  return is_member_of_hashset(get_value_set(map), value);
}

hashset_t* get_key_set(hashmap_t *map)
{
  hashset_t *key_set = (hashset_t *) malloc(sizeof(hashset_t));

  key_set->size = map->size;
  key_set->bits = map->bits;
  key_set->num_elems = map->num_elems;
  key_set->load_factor = map->load_factor;
  key_set->elems = map->keys;

  return key_set;

}

hashset_t* get_value_set(hashmap_t *map)
{
  hashset_t *value_set = new_hashset_with_config(map->size, map->load_factor);
  
  for(size_t i = 0; i < map->size; i++)
  {
    add_to_hashset(value_set, (void *) map->keys[i]);
  }

  return value_set;
}

size_t num_elems_hashmap(hashmap_t *map)
{
  return map->num_elems;
}

void clear_hashmap(hashmap_t *map)
{
  free(map->keys);
  free(map->values);
  map->keys = (size_t *)calloc(map->size, sizeof(size_t));
  map->values = (void **)malloc(map->size * sizeof(void *));
}

int is_hashmap_empty(hashmap_t *map)
{
  return map->num_elems != 0;
}

void delete_hashmap(hashmap_t *map)
{
  if(map)
  {
    free(map->keys);
    free(map->values);
  }

  free(map);
}
