
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
  return EOF;
}
