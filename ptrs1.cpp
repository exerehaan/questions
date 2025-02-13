#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *replaceSubstring(const char *str, const char *str1, const char *str2) {
    int lenStr = strlen(str);
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);

    
    int count = 0;
    const char *temp = str;
    while ((temp = strstr(temp, str1)) != NULL) {
        count++;
        temp += lenStr1;
    }

  
    if (count == 0) {
        char *copy = (char *)malloc(lenStr + 1);
        if (!copy) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        strcpy(copy, str);
        return copy;
    }

    int newLen = lenStr + count * (lenStr2 - lenStr1) + 1;
    char *newStr = (char *)malloc(newLen);
    if (!newStr) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    char *currentPos = newStr;
    while (*str) {
        
        if (strstr(str, str1) == str) {
            strcpy(currentPos, str2);
            currentPos += lenStr2;
            str += lenStr1;
        } else {
            *currentPos++ = *str++;
        }
    }
    *currentPos = '\0';

    return newStr;
}

int main() {
    char str[][100] = {
        "We will teach you how to...",
        "Move a mountain",
        "Level a building",
        "Erase the past",
        "Make a million",
        "...all through C!"
    };
    
    int size = sizeof(str) / sizeof(str[0]);
    char str1[50], str2[50];

    printf("Enter the string to replace (str1): ");
    scanf("%s", str1);
    printf("Enter the replacement string (str2): ");
    scanf("%s", str2);

    
    char *modifiedStr[size];
    for (int i = 0; i < size; i++) {
        modifiedStr[i] = replaceSubstring(str[i], str1, str2);
    }

  
    printf("\nModified Strings:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", modifiedStr[i]);
        free(modifiedStr[i]); 
    }

    return 0;
}