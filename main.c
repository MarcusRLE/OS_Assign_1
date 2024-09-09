
/* You are not allowed to use <stdio.h> */
#include <stdlib.h>

#include "io.h"
#include "main.h"

/**
 * @name  main
 * @brief This function is the entry point to your program
 * @return 0 for success, anything else for failure
 *
 *
 * Then it has a place for you to implementation the command 
 * interpreter as  specified in the handout.
 */

char count_str[] = "Count = ";
char collection_str[] = "Collection = ";


int
main()
{
  int count = 0;
  char command;
  intNode *collection = NULL;

  // Read through commands
  while ((command = read_char()) == ('a' | 'b' | 'c')) {
    if (command == 'a') {
        add_int(&collection, count);
    } else if (command == 'c') {
        remove_last(&collection);
    }
      count++;
  }


  write_string(count_str);
  write_int(count);
  write_char('\n');
  write_string(collection_str);
  print_list(collection);

  free_list(&collection);


  return 0;
}

int add_int(intNode **collection, int count) {
    // Allocate memory for new intNode and set values
    intNode *new_int = (intNode *)malloc(sizeof(intNode));
    new_int->value = count;
    new_int->next = NULL;

    // Add new intNode to collection tail
    if(*collection == NULL) {
        *collection = new_int;
    } else {
        intNode *latest = *collection;
        while(latest->next != NULL) {
            latest = latest->next;
        }
        latest->next = new_int;
    }
    return 0;
}

int remove_last(intNode **collection) {
    // Remove latest intNode from collection
    if(*collection == NULL) {
        return -1;
    }

    intNode *temp = *collection;
    intNode *previous = NULL;

    if(temp->next != NULL) {
        while(temp->next != NULL) {
            previous = temp;
            temp = temp->next;
        }
        if(previous != NULL) {
            previous->next = NULL;
        } else {
            *collection = NULL;
        }

        free(temp);
    }
    return 0;
}

int print_list(intNode *collection) {
    // Print all values in collection
    intNode *temp = collection;
    while(temp != NULL) {
        write_int(temp->value);
        temp = temp->next;
        if(temp->next != NULL) {
            write_char(',');
            write_char(' ');
        }
    }
    return 0;
}

int free_list(intNode **collection) {
    if(*collection == NULL) {
        return -1;
    }
    // Free all memory allocated for collection
    intNode *temp = *collection;
    intNode *next = NULL;
    while(temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    return 0;
}