#include <stdio.h>

char* undecl(char *val)
{
  return (val << 8) | 0x122;
}
