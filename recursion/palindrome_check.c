#include <stdio.h>
#include <string.h>

int isPalindrome(char* str, int start, int end) {
    if (start >= end)
        return 1;
    if (str[start] != str[end])
        return 0;
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[] = "madam";
    int len = strlen(str);
    printf("%s is %s\n", str, isPalindrome(str, 0, len - 1) ? "palindrome" : "not palindrome");
    return 0;
}
// Updated on 2026-04-22
