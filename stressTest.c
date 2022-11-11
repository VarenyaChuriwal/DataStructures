// Source: https://github.com/mraoaakash/CS1203/blob/main/Code%20Files/loopStressTest.c

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){

    float i;
    // Breakpoint achieved
    float increment = 0.00000000000000000000000000000000000000000001;
    float n = 0.0000000000000000000000000000000000000000001; 
    int count = 1;

    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        count++;
    }

    return 0;
}

