#include <ctype.h>
#include <stdio.h>

int main(void) {
    unsigned long int charcount = 0;
    unsigned long int wordcount = 0;
    unsigned long int linecount = 0;
    int c, last, separator = 1;

    for (last = '\n'; (c = getchar()) != EOF; last = c) {
        charcount++;
        if (c == '\n') {
            linecount++;
            separator = 1;
        } else
        if (isspace(c)) {
            separator = 1;
        } else {
            wordcount += separator;
            separator = 0;
        }
    }
    if (last != '\n') {
        linecount++;
    }
    printf("%lu %lu %lu\n", charcount, wordcount, linecount);
    return 0;
}

