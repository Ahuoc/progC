#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end) { 
  for (int i = start, j = end; i < j; i++, j--) {
    int temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}


int find_next_start(char str[], int len, int i) {
  // Assume we are starting after the last word
  while (i < len && (!isalpha(str[i]))) {
    i++;
  }
  if (i>=len) {
    return -1;
  }
  return i;
}

int find_next_end(char str[], int len, int i) {
  // Skip over whitespace, before skipping over the word to find the end.
  while (i < len && (!isalpha(str[i]))) {
    i++;
  }
  while (i < len && (isalpha(str[i]))) {
    i++;
  }
  if (i>=len+1) {
    return -1;
  }
  return i-1;
}

void reverse_words(char s[]) { 
  int i = 0;
  int len = strlen(s);
  int new_word = 1;
  int start = 0;
  int end = 0;
  while (i < len && new_word && start != -1 && end != -1) {
    new_word = 0;
    start = find_next_start(s, len, i);
    end = find_next_end(s, len, i);
    if (start != -1 && end != -1) {
      reverse_substring(s, start, end);
    }
    if (end != i) {
      new_word = 1;
    }
    i = end+1;
  }
}
