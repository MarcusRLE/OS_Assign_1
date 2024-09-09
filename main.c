
/* You are not allowed to use <stdio.h> */
#include "io.h"


/**
 * @name  main
 * @brief This function is the entry point to your program
 * @return 0 for success, anything else for failure
 *
 *
 * Then it has a place for you to implementation the command 
 * interpreter as  specified in the handout.
 */
typedef struct Node{
  int value;
  struct Node* next;
  struct Node* prev;  
} Node;

typedef struct Collection{
  Node* head;
  Node* tail;
} Collection;

int main()
{
  /*-----------------------------------------------------------------
   *TODO:  You need to implement the command line driver here as
   *       specified in the assignment handout.
   *
   * The following pseudo code describes what you need to do
   *  
   *  Declare the counter and the collection structure variables
   *
   *
   *  In a loop
   *    1) Read a command from standard in using read_char function
   *    2) If the command is not 'a', 'b', 'c': then break the loop
   *    3) Process the command as specified in the handout
   *  End loop
   *
   *  Print your collection of elements as specified in the handout
   *    as a comma delimited series of integers
   *-----------------------------------------------------------------*/
   int counter = 0;
   Collection collection ={0, NULL};
    char command;

while(1){
  command  = read_char();
  if(command == EOF || (command != 'a' && command != 'b' && command != 'c')){
    break;
  }
  switch(command){
    case 'a':
      add_element(&collection);
      counter++;
      break;
    case 'b':
      counter++
      break;
    case 'c':
      remove_element(&collection);
      counter++;
      break;
  }
}
  return 0;
}
