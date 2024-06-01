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
void print_the_char(int count_space, int stars, int s_2)
{
    for (int k = 0; k != count_space; k ++)
        printf(" ");
    for (int l = 0; l != stars; l ++)
        printf("*");
    printf(" ");
    for (int m = 0; m != s_2; m ++)
        printf("*");
    printf("\n");
}

static
void main_loop(char **av)
{
    int loop = 0;
    int count_space = atoi(av[1]);
    int stars = 0;
    int stars_2 = 0;

    for (int i = 0; i != atoi(av[1]); i++)
        printf(" ");
    printf("*\n");
    while (loop < atoi(av[1])) {
        count_space -= 1;
        stars += 1;
        stars_2 += 1;
        print_the_char(count_space, stars, stars_2);
        loop++;
    }
    if (atoi(av[1]) != 0) {
        for (int i = 0; i != atoi(av[1]) - 1; i++)
            printf(" ");
        printf("| |\n");
    }
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        printf("[USAGE] -->  ./a.out [number]\n");
        return 0;
    }
    if (error_handling(ac, av) == 84)
        return 84;
    main_loop(av);
    return 0;
}
