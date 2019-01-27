#pragma once

#ifdef EXPORT_DLL
  #define HASHSET_API __declspec(dllexport)
#else
  #define HASHSET_API __declspec(dllimport)
#endif

typedef struct
{
  size_t size;
  size_t bits;
  size_t num_elems;
  size_t *elems;
  double load_factor;
} hashset_t;

HASHSET_API hashset_t* new_hashset(void);

HASHSET_API hashset_t* new_hashset_with_config(size_t size, double load_factor);

HASHSET_API int add_to_hashset(hashset_t *set, void *new_elem);

HASHSET_API int remove_from_hashset(hashset_t *set, void *old_elem);

HASHSET_API int is_member_of_hashset(hashset_t *set, void *elem);

HASHSET_API size_t num_elems_hashset(hashset_t *set);

HASHSET_API void delete_hashset(hashset_t *set);
