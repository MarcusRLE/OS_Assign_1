
/* You are not allowed to use <stdio.h> */
#include <stdlib.h>

#include "io.h"
#include "main.h"

char count_str[] = "Count = ";
char collection_str[] = "Collection = ";

/**
 * @name  main
 * @brief This function is the entry point to your program
 * @return 0 for success, anything else for failure
 *
 *
 * Then it has a place for you to implementation the command 
 * interpreter as  specified in the handout.
 */
int
main() {
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

  // Print current count and collection
  print_all(collection, count);

  // Free memory allocated for collection
  free_list(&collection);

  return 0;
}

/**
 * @name  add_int
 * @brief This function adds a new intNode to the collection
 * @param collection - pointer to the head of the collection
 * @param count - the value to be added to the collection
 * @return 0 for success, anything else for failure
 */
int
add_int(intNode **collection, int count) {
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

/**
 * @name  remove_last
 * @brief This function removes the last intNode from the collection
 * @param collection - pointer to the head of the collection
 * @return 0 for success, anything else for failure
 */
int
remove_last(intNode **collection) {
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

/**
 * @name  print_all
 * @brief This function prints the count and all values in the collection
 * @param collection - pointer to the head of the collection
 * @param count - the number of values in the collection
 * @return 0 for success, anything else for failure
 */
int
print_all(intNode *collection, int count){
    write_string(count_str);
    write_int(count);
    write_char('\n');
    write_string(collection_str);
    print_list(collection);
    return 0;
}

/**
 * @name  print_list
 * @brief This function prints all values in the collection
 * @param collection - pointer to the head of the collection
 * @return 0 for success, anything else for failure
 */
int
print_list(intNode *collection) {
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

/**
 * @name  free_list
 * @brief This function frees all memory allocated for the collection
 * @param collection - pointer to the head of the collection
 * @return 0 for success, anything else for failure
 */
int
free_list(intNode **collection) {
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