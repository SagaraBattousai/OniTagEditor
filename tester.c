#include <stdio.h>
#include <stdlib.h>



int main(void)
{
  
  unsigned a = 'T' << 24 | 'I' << 16 | 'T' << 8 | '2';
  
  unsigned b = 'T' << 24 | 'I' << 16 | 'T' << 8 | '2';


  printf("Does a (%zu) == b (%zu)\n", (size_t)(void *)a, (size_t)(void *)b);

  return 0;
}
