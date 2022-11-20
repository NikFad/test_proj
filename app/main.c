#include <stdio.h>

int my_max(int a, int b) {
    return (a>b) ? a : b;
}

int main() {
    int a =4, b =-1;
    int c = my_max(a,b);
}