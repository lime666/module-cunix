#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

int my_puts(const char *str) {
  write(1, str, strlen(str));
  write(1, "\n", 1);
  return 0;
}
