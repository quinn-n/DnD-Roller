/*
 * expected-die.c
 * printes out the expected values of n-sided die
 * written by Quinn Neufeld
 * Augest 19th 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double get_expected(int);

void print_help();

int main(int argc, char** argv) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
            print_help();
            return 1;
        }
        int d = atoi(argv[i]);
        printf("d%i: %f\n", d, get_expected(d));
    }
}

//Returns the expected value for an n-sided die
double get_expected(int n) {
    double e = 0;
    for (double i = 1; i <= n; i++) {
        e += i / n;
    }
    return e;
}

//Prints help message
void print_help() {
    printf("Usage: expected-die <sides>\n");
    printf("Calculates the expected value for an n-sided die\n");
}
