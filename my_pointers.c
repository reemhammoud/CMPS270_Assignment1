#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//requies: two arrays and size of each
//effect: returns a merged sorted array
char** merge(int sizeOfa, int sizeOfb, char** a, char** b) {
    int i = 0, j = 0, x = 0;
    char** ans = malloc(20 * sizeof(char*));
    for (int i = 0; i < 10; ++i)
        ans[i] = malloc(20 * sizeof(char));
    while (j < sizeOfb && i < sizeOfa) {
        if (strcmp(a[i], b[j]) <= 0) {
            strcpy(ans[x++], a[i++]);
        }
        else {
            strcpy(ans[x++], b[j++]);
        };
    }
    while (i < sizeOfa) {
        strcpy(ans[x++], a[i++]);
    }
    while (j < sizeOfb) {
        strcpy(ans[x++], b[j++]);
    }
    return ans;
}
int main() {
    //Test cases
    char* a[3] = { "ab", "ac", "zd" };
    char* b[4] = { "za", "zb", "zzzzc" };
   
    char** ans = merge(3, 3, a, b);

    for (int i = 0; i < 6; i++) printf("%s\n", ans[i]);

    char* c[3] = { "aah", "reem", "ahamd" };
    char* d[4] = { "zahraa", "aaa", "barchalona" ,"tahir"};

    char** result = merge(3, 4, c, d);

    for (int i = 0; i < 6; i++) printf("%s\n", result[i]);
    return 0;
}