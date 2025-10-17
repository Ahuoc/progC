#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *cons(int head, List *tail) { 
  /* malloc() will be explained in the next lecture! */
  List *cell = malloc(sizeof(List));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Functions for you to implement */

int sum(List *list) {
  int total = 0;
  int head = list->head;
  List *tail = list->tail;
  total += head;
  while (tail != NULL) {
    head = tail->head;
    tail = tail->tail;
    total += head;
  }
  return total;
}

void iterate(int (*f)(int), List *list) {
  list->head = f(list->head);
  List *tail = list->tail;
  while (tail != NULL) {
    tail->head = f(tail->head);
    tail = tail->tail;
  }
}

void print_list(List *list) { 
  int head = list->head;
  List *t = list->tail;
  printf("[");
  printf("%d", head);
  while (t != NULL) {
    head = t->head;
    printf(", %d", head);
    t = t->tail;
  }
  printf("]\n");
}

/**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2) {
  if (list1 == NULL) {
    return list2;
  }
  if (list2 == NULL) {
    return list1;
  }
  int h1, h2;
  List *t1, *t2;
  h1 = list1->head;
  h2 = list2->head;
  t1 = list1;
  t2 = list2;
  List *output;
  // Initialise output with the first value
  if (h1 <= h2) {
    output = cons(h1, NULL);
    t1 = t1->tail;
  }
  else {
    output = cons(h2, NULL);
    t2 = t2->tail;
  }
  List *output_ending_pointer = output;
  while (t1 != NULL && t2 != NULL) {
    h1 = t1->head;
    h2 = t2->head;
    if (h1 <= h2) {
      output_ending_pointer->tail = cons(h1, NULL);
      output_ending_pointer = output_ending_pointer->tail;
      t1 = t1->tail;
    }
    else {
      output_ending_pointer->tail = cons(h2, NULL);
      output_ending_pointer = output_ending_pointer->tail;
      t2 = t2->tail;
    }
  }
  
  if (t1 != NULL) {
    output_ending_pointer->tail = t1;
  }
  if (t2 != NULL) {
    output_ending_pointer->tail = t2;
  }

  return output;  
}

void split(List *list, List **list1, List **list2) { 
  *list1 = NULL;
  *list2 = NULL;
  int list_to_add_to = 0;

  // Pointers to the ends of the lists
  List **tail1 = list1;
  List **tail2 = list2;

  while (list) {
    List *tl = list->tail;
    list->tail = NULL; // Initialise for adding to output list.

    if (list_to_add_to) {
      *tail2 = list;
      tail2 = &((*tail2)->tail);
      list_to_add_to = 0;
    }
    else {
      *tail1 = list;
      tail1 = &((*tail1)->tail);
      list_to_add_to = 1;
    }
    list = tl;
  }
}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *mergesort(List *list) { 
  if (list == NULL || list->tail == NULL) { 
    return list;
  } else { 
    List *list1;
    List *list2;
    split(list, &list1, &list2);
    list1 = mergesort(list1);
    list2 = mergesort(list2);
    return merge(list1, list2);
  }
}
