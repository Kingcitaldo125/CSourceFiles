#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_in(int mt, char **marray)
{
    for (int i = 0; i < mt; ++i)
    {
        int size;
        scanf("%d", &size);

        if (size == 0)
            continue;

        *(marray + i) = (char *)malloc(sizeof(char) * (size + 1));
        scanf("%s", *(marray + i));
        printf("string: %s string length: %d\n", *(marray + i), strlen(*(marray + i)));
    }
}

void printout(int mt, char **marray)
{
    printf("Printout:\n");

    for (int i = 0; i < mt; ++i)
    {
        printf("%s\n", *(marray + i));
    }
}

void cleanup(int mt, char **marray)
{
    printf("Freeing...\n");

    for (int i = 0; i < mt; ++i)
    {
        free(*(marray + i));
    }
}

void test()
{
    const int sizz = 4;
    char *mstring = malloc(sizeof(char) * sizz);

    strcpy(mstring, "asd");
    printf("mstring: %s mstring length: %d\n", mstring, strlen(mstring));
    free(mstring);
}

void app()
{
    int N;
    scanf("%d", &N);
    char *marray[N];

    read_in(N, marray);
    printout(N, marray);
    cleanup(N, marray);
}

int main(int argc, char **argv)
{
    app();

    printf("Hello World\n");

    return 0;
}
