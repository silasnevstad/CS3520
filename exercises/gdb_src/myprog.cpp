#include <stdio.h>

#define MAX_LETTERS 26

char alphabet[MAX_LETTERS];

 void initialize_alphabet(char *a) {
    char *p = a;
    char current_letter = 'a';
    printf("Initializing alphabet...\n");
    for (p = a; p < (a + MAX_LETTERS); p++) {
        *p = current_letter++;
    }
}  

void reverse_print_alpha(char *b) {
    printf("\nReverse alpha...\n");
    static int var = 0;
    char *p;
    var *= 1;

    for (p = b + MAX_LETTERS - 1; p >= b; p--) {
        printf("%c ", *p);
    }
    printf("\n");
   
    return ;
}

int main(void) {
    initialize_alphabet(alphabet);
    for (int i = 0; i < 10; i++) {
        reverse_print_alpha(alphabet);
    }
}
