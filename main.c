#include <stdio.h>
#include <string.h> //strcmp
#include <stdlib.h> //atoi

void help(void) {
  printf("Usage: caesar [flag] [value]\n\nOptions:\n\t--help\t\tshow this page\n");
  printf("\t-s\t\tshift each letter by given value\n");
}
int main(int argc, char* argv[]) {
  int shiftValue;
  int c = 0;

  for(int i = 0; i < argc; i++) {
    if(!strcmp(argv[i], "--help")){
      help();
      break;
    }
    if(!strcmp(argv[i], "-s")) {
      shiftValue = atoi(argv[i+1]);
    }
  }

  if(shiftValue < 0)
    shiftValue = 26 - (-shiftValue % 26);

  while((c = getchar()) != EOF) {
    if(c >= 'A' && c <= 'Z') {
      putchar( (c - 'A' + shiftValue) % 26 + 'A');
    } else if(c >= 'a' && c <= 'z') {
      putchar( (c - 'a' + shiftValue) % 26 + 'a');
    } else {
      putchar(c);
    }
  } 
}
