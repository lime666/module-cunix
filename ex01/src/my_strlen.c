#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "test.h"

unsigned int my_strlen (char *str) {
  unsigned int c = 0;
    while (*str!='\0') {
      c++;
      str++; }
    return c;
}
