
#include "Mp3TagEditor/mp3TagEditor.h"

#include <iostream>
#include <fstream>
#include <string>

std::string test()
{

  std::fstream fs;
  fs.open("resources/Legend of Zelda Majora's Mask OST [Disk 1] - Koji Kondo and Toru Minegeshi - Catch Small Item.mp3", std::fstream::in | std::fstream::binary);

  char arr[4];
  /* char * arr = new char[4]; */

  fs.read(arr, 3);
  arr[3] = '\0';

  return std::string(arr);
}
