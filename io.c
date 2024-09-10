#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include "io.h"

/* Reads next char from stdin. If no more characters, it returns EOF */
int read_char() {
    char c;// Jeg har en felj i ssize_t. Jeg vil gerne beholde den for robusthed i forhold til negative værdier
    ssize_t result = read(0, &c, 1);  // Læser en byte, ind i c addressen, fra "file descriptor". Gemmer derefter antal bytes læst i result.
    if (result < 0) {  // Alternativt i stedet for "0" kan der stå "stdin_fileno" som er en konstant der repræsenterer standard input.
        return EOF;
    } 
    return (int)c;
}


/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {
  ssize_t result = write(1, &c, 1);  // Skriver en byte, fra c addressen, til "file descriptor". Gemmer derefter antal bytes skrevet i result.
  if (result < 0) {
    return EOF;
  } 
  return 0;
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_string(char* s) {
  size_t len = strlen(s);
  ssize_t bytes_written = write(STDOUT_FILENO, s, len);
  if (bytes_written < 0) {
    return EOF;
  }
  return 0;
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
  if(n == 0) {
    intOut[0] = '0';
  }
  else {
    while (n > 0) {
      count--;
      intOut[count] = n % 10 + '0';
      n /= 10;
    }
    if(isNegative) {
      intOut[0] = '-';
    }
  }
  char* cPtr = intOut;c
  ssize_t bytes_written = write(STDOUT_FILENO, cPtr, strlen(intOut));
  if (bytes_written < 0) {
    return EOF;
  }
  return 0;
}
