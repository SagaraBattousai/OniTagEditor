#include <stdlib.h>
#include <stdio.h>
#include "hashset.h"

static const size_t default_size = 16;
static const size_t default_bits = 4;
static const double load_factor = 0.75;

static const size_t prime_multiplier = 37;
static const size_t prime_adder = 3733;


hashset_t* new_hashset(void)
{
  hashset_t *set = (hashset_t *)malloc(sizeof(hashset_t));

  if(!set)
  {
    return NULL;
  }

  set->size = default_size;

  set->bits = default_bits;

  set->load_factor = load_factor;

  set->num_elems = 0;

  set->elems = (size_t *)calloc(set->size, sizeof(size_t));

  if(!set->elems)
  {
    delete_hashset(set);
    return NULL;
  }

  return set;

}

hashset_t* new_hashset_with_config(size_t size, double load_factor)
{
  hashset_t *set = (hashset_t *)malloc(sizeof(hashset_t));

  if(!set)
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

  set->size = (size_t) 1 << bits;

  set->bits = bits;

  set->load_factor = load_factor;

  set->num_elems = 0;

  set->elems = (size_t *) calloc(set->size, sizeof(size_t));

  if(!set->elems)
  {
    delete_hashset(set);
    return NULL;
  }

  return set;

}

static int add(hashset_t *set, void *elem)
{

  //Add Elem

  size_t value = (size_t)elem;

  if(value == 0)
  {
    return -1;
  }

  size_t modulo = set->size - 1;

  size_t hash = modulo & (value * prime_multiplier);

  while(set->elems[hash] != 0)
  {

    if(set->elems[hash] == value)
    {
      return 0;
    }

    hash = modulo & (hash + prime_adder);

  }

  set->elems[hash] = value;

  set->num_elems++;

  return 1;

}

int remove_from_hashset(hashset_t *set, void *old_elem)
{

  size_t modulo = set->size - 1;

  size_t value = (size_t)old_elem;

  if(value == 0)
  {
    return -1;
  }

  size_t hash = modulo & (value * prime_multiplier);

  while(set->elems[hash] != 0)
  {

    if(set->elems[hash] == value)
    {
      set->elems[hash] = 0;

      set->num_elems--;

      return 1;
    }

    hash = modulo & (hash + prime_adder);

  }

  return 0;
}

static void resize_hashset(hashset_t *set)
{

  if(set->num_elems >= (double)set->size * set->load_factor)
  {

    size_t *old_elems = set->elems;

    size_t old_size = set->size;

    set->bits++;
    set->size = (size_t) (1 << set->bits);
    set->elems = (size_t *)calloc(set->size, sizeof(size_t));

    if(!set->elems)
    {
      delete_hashset(set);

      fprintf(stderr, "Failure, could not resize hashmap from size %zu to %zu\
          \nCurrent size of set: %zu\n", old_size, set->size, set->num_elems);

      exit(EXIT_FAILURE);
    }

    set->num_elems = 0;

    for(size_t i = 0; i < old_size; i++)
    {
      add(set, (void *)old_elems[i]);
    }

    free(old_elems);

  }

}


int add_to_hashset(hashset_t *set, void *new_elem)
{

  //Resize Hash Set Incase Full
  resize_hashset(set);

  return add(set, new_elem);

}

int is_member_of_hashset(hashset_t *set, void *elem)
{

  size_t modulo = set->size - 1;

  size_t value = (size_t)elem;

  if(value == 0)
  {
    return -1;
  }

  size_t hash = modulo & (value * prime_multiplier);

  while(set->elems[hash] != 0)
  {

    if(set->elems[hash] == value)
    {
      return 1;
    }

    hash = modulo & (hash + prime_adder);

  }

  return 0;

}

size_t num_elems_hashset(hashset_t *set)
{
  return set->num_elems;
}

void delete_hashset(hashset_t *set)
{
  if(set)
  {
    free(set->elems);
  }

  free(set);
}
