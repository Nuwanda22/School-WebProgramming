#include <stdio.h>
#include <string.h>

int main()
{
        int i = 0, j = 0;
        char string[256];
        char reverse[256];

        printf("input string : ");
        scanf("%s", string);
        
        for (i = strlen(string); i >= 0; i--, j++) {
                reverse[j] = string[i];   
                printf("%c", reverse[j]);
        }
        
        puts(reverse);
        
        return 0;
}