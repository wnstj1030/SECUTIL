#include <stdio.h>


int my_strlen(char* name) {
    int count = 0;
    int i = 0;
    while (*(name + i) != NULL) {
        i++;
    }
    printf("'%s' length is %d\n", name, i);
    return i;
}

void my_strcpy(char* name, char* src) {
    char* new_arr;
    int i = 0;
    int len = my_strlen(src);
    for (int i = 0; i < len; i++) {
        *(name + i) = *(src + i);
    }
}

void my_strcat(char* name, char* src) {
    int s_len = my_strlen(src);
    int n_len = my_strlen(name);
    for (int i = 0; i < s_len; i++) {
        *(name + n_len + i) = *(src + i);
    }
}


int main(void) {
    char name[32] = "Hello~~";
    char name1[32] = "World!";
    printf("name : % s\n", name);
    my_strcat(name, name1);
    printf("name : % s\n", name);
        return 0;
}