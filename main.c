
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
int count = 0;


int
main()
{
  char command;
  struct int_llist *collection = NULL;
  struct int_llist *latest = collection;

  // Read through commands
  while ((command = read_char()) == ('a' | 'b' | 'c')) {
    if (command == 'a') {
        add_int(&collection, count);
    } else if (command == 'c') {
        remove_int(&collection);
    }
      count++;
  }


  write_string(count_str);
  write_int(count);
  write_char('\n');
  write_string(collection_str);
  print_list(collection);


  return 0;
}

int add_int(struct int_llist **collection, int count) {
    // Allocate memory for new int_llist and set values
    struct int_llist *new_int = (struct int_llist *)malloc(sizeof(struct int_llist));
    new_int->value = count;
    new_int->next = NULL;

    // Add new int_llist to collection tail
    if(*collection == NULL) {
        *collection = new_int;
    } else {
        struct int_llist *latest = *collection;
        while(latest->next != NULL) {
            latest = latest->next;
        }
        latest->next = new_int;
    }
    return 0;
}

int remove_int(struct int_llist **collection) {
    // Remove latest int_llist from collection
    if(*collection == NULL) {
        return -1;
    }

    struct int_llist *temp = *collection;
    struct int_llist *previous = NULL;

    if(temp->next != NULL) {
        while(temp->next != NULL) {
            previous = temp;
            temp = temp->next;
        }
        if(previous != NULL) {
            previous->next = NULL;
            free(temp);
        } else {
            free(temp);
            *collection = NULL;
        }
    }
    return 0;
}

int print_list(struct int_llist *collection) {
    // Print all values in collection
    struct int_llist *temp = collection;
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