#include <stdio.h>

void rmchar(char* str, char c){
    
    char *pr = str, *pw = str;
    while(*pr) {
        *pw = *pr++;
        pw += (*pw != c);
    }
    
    *pw = '\0';
}

int main()
{
    
    char *s;
    char c;
    
    printf("\nEnter a string: ");
    scanf("%s", &s);

    printf("%s", s);

    printf("\nEnter character to be removed:" );
    scanf("%c", &c);
    
    printf("\nThe string input is %s\nThe removed char is %c", s, c);
    
    rmchar(s,c);
    
    printf("\nThe new string is: %s", s);
    

    return 0;
}