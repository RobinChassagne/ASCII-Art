//
// Created by robinchassagne on 29/05/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static
int error_handling(int ac, char **av)
{
    if (ac == 1) {
        printf("Not enough argument.\n");
        return 84;
    }
    if (ac > 2) {
        printf("Too many arguments.\n");
        return 84;
    }
    if (atoi(av[1]) < 0) {
        printf("Only positives numbers.\n");
        return 84;
    }
    if (!av || !av[1])
        return 84;
    return 0;
}

static
void print_char_part(int space, int space_mid)
{
    for (int a = 0; a != space; a++)
        printf(" ");
    printf("*");
    for (int b = 0; b != space_mid; b ++)
        printf(" ");
    printf("*\n");
}

static
void first_part(char **av)
{
    int loop = 0;
    int space = atoi(av[1]) * 3 - 1;
    int space_mid = 0;

    if (atoi(av[1]) == 1) {
        for (int n = 0; n != (atoi(av[1]) * 3); n ++)
            printf(" ");
        printf("*\n");
        return;
    }
    for (int i = 0; i != (atoi(av[1]) * 3) - 1; i ++)
        printf(" ");
    printf("*\n");
    while (loop != atoi(av[1]) - 1) {
        space -= 1;
        space_mid += 1;
        print_char_part(space, space_mid);
        space_mid += 1;
        loop ++;
    }
}

static
void the_big_line(char **av)
{
    int stars = 0;
    int space_mid = 0;
    int loop = 0;

    if (atoi(av[1]) == 1) {
        for (int b = 0; b != atoi(av[1]) * 3; b ++)
            printf("*");
        printf(" ");
        for (int w = 0; w != atoi(av[1]) * 3; w ++)
            printf("*");
        printf("\n");
        return;
    }
    stars = (atoi(av[1]) * 2) + 1;
    for (int i = 0; i != stars; i ++)
        printf("*");
    while (loop != atoi(av[1]) - 1) {
        space_mid += 2;
        loop ++;
    }
    space_mid -= 1;
    for (int k = 0; k != space_mid; k ++)
        printf(" ");
    for (int i = 0; i != stars; i ++)
        printf("*");
    printf("\n");
}

static
int count_space_mid(int number)
{
    int loop_2 = 0;
    int space_mid = 0;

    while (loop_2 != number - 1) {
        space_mid += 2;
        loop_2 ++;
    }
    return space_mid;
}

static
void the_middle_1(char **av)
{
    int space = 0;
    int loop = 0;
    int space_mid = count_space_mid(atoi(av[1])) + (atoi(av[1]) * 2) * 2 - 2;

    if (atoi(av[1]) == 1) {
        printf(" ");
        printf("*");
        for (int g = 0; g != atoi(av[1]) * 3; g++)
            printf(" ");
        printf("*\n");
        return;
    }
    while (loop != atoi(av[1])) {
        space += 1;
        for (int m = 0; m != space; m ++) {
            printf(" ");
        }
        printf("*");
        space_mid -= 1;
        for (int h = 0; h != space_mid; h ++)
            printf(" ");
        space_mid -= 1;
        printf("*\n");
        loop += 1;
    }
}

static
void the_middle_2(char **av)
{
    int space = atoi(av[1]);
    int loop = 0;
    int space_mid = count_space_mid(atoi(av[1])) + (atoi(av[1]) * 2);

    while (loop != atoi(av[1]) - 1) {
        space -= 1;
        for (int m = 0; m != space; m ++) {
            printf(" ");
        }
        printf("*");
        space_mid += 1;
        for (int d = 0; d != space_mid; d ++)
            printf(" ");
        space_mid += 1;
        printf("*\n");
        loop += 1;
    }
}

static
void last_part(char **av)
{
    int loop = 0;
    int loop_2 = 0;
    int space = (atoi(av[1]) * 2) - 1;
    int space_mid = count_space_mid(atoi(av[1]));

    if (atoi(av[1]) == 1) {
        for (int p = 0; p != atoi(av[1]) * 3; p ++)
            printf(" ");
        printf("*\n");
        return;
    }
    while (loop != atoi(av[1]) - 1) {
        space += 1;
        space_mid -= 1;
        print_char_part(space, space_mid);
        space_mid -= 1;
        loop ++;
    }
    for (int i = 0; i != (atoi(av[1]) * 3) - 1; i ++)
        printf(" ");
    printf("*\n");
}

static
void main_loop(char **av)
{
    if (!av)
        return;
    first_part(av);
    the_big_line(av);
    the_middle_1(av);
    the_middle_2(av);
    the_big_line(av);
    last_part(av);
}

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 84)
        return 84;
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        printf("[USAGE] -->  ./a.out [number]\n");
        return 0;
    }
    if (atoi(av[1]) == 0) {
        printf("Sorry, it's impossible with 0.\n");
        return 0;
    }
    main_loop(av);
    return 0;
}
