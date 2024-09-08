
#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "io.h"

/* Reads next char from stdin. If no more characters, it returns EOF */
int
read_char() {
  return EOF;
}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {
  return EOF;
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_string(char* s) {
  return EOF;
}

/* Writes n to stdout (without any formatting).   
 * If no errors occur, it returns 0, otherwise EOF
 */
int
write_int(int n) {
  int nCopy = n;
  int count = 0;
  int isNegative = 0;
  /*Use a copy of n so original input remains intact. If n is negative, we increment
  *count to make room for '-'. We also flip the sign of both n and nCopy to simplify
  *the code further down.
  */
  if(nCopy < 0) {
    nCopy = -nCopy;
    n = -n;
    isNegative = 1;
    count++;
  }
  //Count number of digits - used to determine size of char[]
  while(nCopy > 0) {
    count++;
    nCopy /= 10;
  }
  char intOut[count+1];
  intOut[count] = '\0';
  //Handle n == 0;
  if(n == 0) {
    intOut[0] = '0';
  }
  else {
    //Use modulus to find the least significant digit, and convert it to a char by adding it with '0'.
    while (n > 0) {
      count--;
      intOut[count] = n % 10 + '0';
      n /= 10;
    }
    if(isNegative) {
      intOut[0] = '-';
    }
  }
  
  size_t bytes = strlen(intOut); 
  ssize_t bytes_written = write(STDOUT_FILENO, cPtr, bytes);
  if (bytes_written < 0) {
    return EOF;
  }
  return 0;
}
