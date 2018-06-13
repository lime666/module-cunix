#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "test.h"

char *my_strcpy (char *dest, const char *src)
{
  char *save = dest;
    while ( *dest++ = *src++ );
    return save;
}