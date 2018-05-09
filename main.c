#include <stdio.h>
#include <stdlib.h>
#include "Mp3TagEditor.h"
#include "hashmap.h"

int main(void)
{

  char *filename = "Legend of Zelda Majora's Mask OST [Disk 1] - Koji Kondo and Toru Minegeshi - Catch Small Item.mp3";

  FILE *file;

  file = fopen(filename, "rb");

  mp3Info *info = new_mp3Info(filename);

  hashmap_t *frames = info->tag->frames;

  printf("%zu\n", frames->num_elems);

  /* frame *f = (frame *) malloc(sizeof(frame)); */
  frame *f;// = (frame *) malloc(sizeof(frame));
  
  
  size_t key = 'T' << 24 | 'I' << 16 | 'T' << 8 | '2';


  printf("%zu\n", num_elems_hashmap(frames));

  int x = get_from_hashmap(frames, (void *) key, (void *) &f);

  printf("so its %i\n", x);

  /* if(!f) */
  /* { */
  /*   printf("Error\n"); */
  /* } */

  textBodyFrame *tbf = (textBodyFrame *) f->frameBody;

  if(!tbf)
  {
    printf("okaydddddd\n"); 
  }
  printf("%s\n", tbf->info);
  

  return 0;
}
