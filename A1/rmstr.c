//Part 4: rmstr
#include <stdio.h>
#include <string.h>

//Function to remove a string from within another string
void rmstr(char* str, char* c){
    
    //Using the string library to modify the input.
    while( str=strstr(str,c) ){
         memmove(str,str+strlen(c),1+strlen(str+strlen(c)));
    }
       
}

int main()
{
    
    char s[] = "This is a cool string";
    char *c = "cool ";
    
    printf("\nThe string input is %s\nThe string to be removed is %s", s, c);
    
    rmstr(s,c);

    printf("\nThe new string is: %s", s);
    
    return 0;
}