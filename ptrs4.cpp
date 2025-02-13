#include <stdio.h>
#include <string.h>

int main() {
    long num;
    printf("enter num: ");
    scanf("%ld", &num);

    char *s1[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *s2[] = {" ", " ", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char new_s[1000] = " ";

    if (num > 999999999 || num < 0) {
        printf("wrong input\num");
    }
    if (num >= 10000000) {
        int crores = num / 10000000;
        if (crores < 20) {
            strcat(new_s, s1[crores]);
        } else {
            if (crores % 10 == 0) {
                strcat(new_s, s2[crores / 10]);
            } else {
                strcat(new_s, s2[crores / 10]);
                strcat(new_s, " ");
                strcat(new_s, s1[crores % 10]);
            }
        }
        strcat(new_s, "  crores  ");
        num %= 10000000;
    }
    if (num >= 100000) {
        int lakhs = num / 100000;
        if (lakhs < 20) {
            strcat(new_s, s1[lakhs]);
        } else {
            if (lakhs % 10 == 0) {
                strcat(new_s, s2[lakhs / 10]);
            } else {
                strcat(new_s, s2[lakhs / 10]);
                strcat(new_s, " ");
                strcat(new_s, s1[lakhs % 10]);
            }
        }
        strcat(new_s, "  lakhs  ");
        num %= 100000;
    }
    if (num >= 1000) {
        int thousands = num / 1000;
        if (thousands < 20) {
            strcat(new_s, s1[thousands]);
        } else {
            strcat(new_s, s2[thousands / 10]);
            strcat(new_s, " ");
            if (thousands % 10 != 0) {
                strcat(new_s, s1[thousands % 10]);
            }
        }
        strcat(new_s, "  thousands  ");
        num %= 1000;
    }
    if (num >= 100) {
        int hundrads = num / 100;
        strcat(new_s, s1[hundrads]);
        strcat(new_s, "  hundrad  ");
        num %= 100;
    }
    if (num >= 0) {
        if (num < 20) {
            strcat(new_s, s1[num]);
        } else {
            strcat(new_s, s2[num / 10]);
            strcat(new_s, " ");
            if (num % 10 != 0) {
                strcat(new_s, s1[num % 10]);
            }
        }
    }

    printf("%s\num", new_s);
    return 0;
}