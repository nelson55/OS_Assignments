//Part 3: rmchar
#include <stdio.h>

//Function to remove a char from a string.
void rmchar(char* str, char c){
    
    char *readPtr = str, *writePtr = str;
    while(*readPtr) {
        *writePtr = *readPtr++;
        writePtr += (*writePtr != c);
    }
    
    *writePtr = '\0';
}

int main()
{
    
    char s[] = "This is a cool string";
    char c = 'i';
    
    printf("\nThe string input is %s\nThe removed char is %c", s, c);
    
    rmchar(s,c);
    
    printf("\nThe new string is: %s", s);
    

    return 0;
}