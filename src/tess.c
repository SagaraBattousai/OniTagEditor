#include <stdio.h>
#include <stdlib.h>

typedef struct{
  unsigned char buf[3];
  unsigned char ver;
  unsigned char min;
  unsigned char flags;
  unsigned char remainingTagSize[4];
}tagHeader;

int main(void)
{

  FILE *file = fopen("Legend of Zelda Majora's Mask OST [Disk 1] - Koji Kondo and Toru Minegeshi - Catch Small Item.mp3", "rb");

  tagHeader *tag = (tagHeader *)malloc(sizeof(tagHeader));

  void *a = (void *) tag;

  fread(a, 10, 1, file);

  printf("uncasted tag title = %s cast tag title = %s\n", tag->buf,
      ((tagHeader *)a)->buf);

  return 0;
}
