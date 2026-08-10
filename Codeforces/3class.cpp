#include <stdio.h>
char str[100];
int pos;
int S() {
    if (str[pos] == 'a') {
        pos++;         
        return S(); 
    }
    if (str[pos] == 'b') {
        pos++;     
        return 1;
    }
    return 0;          
}

int main() {
    printf("Enter the string: ");
    scanf("%s", str);

    pos = 0;
    if (S() && str[pos] == '\0')
        printf("String ACCEPTED\n");
    else
        printf("String REJECTED\n");

    return 0;
}