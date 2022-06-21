//#include <iostream>

#include <stdio.h>
#include <err.h>

typedef struct {
    char name[256];
    char description[512];
} game_t;

int main()
{
    printf("Hello, World!\n");

    FILE *file = fopen("hello.txt", "r");

    if (file == NULL)
        err(1, "Could not open `hello.txt`.");

    game_t game;

    fscanf(file, "%256[^:]:%512[^\n]", game.name, game.description);

    fclose(file);

    printf("Loaded game `%s`.\n"
           "It can be described as `%s`.\n",
           game.name, game.description);

    return 0;
}