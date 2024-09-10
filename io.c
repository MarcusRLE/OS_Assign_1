
#include <errno.h>
#include <unistd.h>

#include "io.h"


int read_char() {
  
}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {
  ssize_t result = write(1, &c, 1);  // Skriver en byte, fra c addressen, til "file descriptor". Gemmer derefter antal bytes skrevet i result.
  if (result == 1) {
    return 0;
  } else if(result == -1) {
    return EOF;
  }
  return EOF;
}//https://pubs.opengroup.org/onlinepubs/007908799/xsh/write.html

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
  return EOF;
}
