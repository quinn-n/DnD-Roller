/*
roll-stats.cpp
Rolls character stats for dnd
Written by Quinn Neufeld
Jan. 3rd 2020
Jan. 8th 2020
Made top 3 rolls count instead of all rolls to match new understanding of ruleset
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_ROLLS 4
#define N_STATS 6

//Rolls dice a given number of times and stores the result in buff
void rollDice(int* buff, size_t n) {
    for (size_t i = 0; i < n; i++) {
        buff[i] = rand() % 6 + 1;
    }
}

//Returns the lowest non-zero element
size_t getLowest(int* buff, size_t n) {
    size_t lowest = 0;
    for (size_t i = 1; i < n; i++) {
        if (buff[i] != 0 && buff[i] < buff[lowest])
            lowest = i;
    }
    return lowest;
}

//Removes all but the three highest dice rolls
void filterDice(int* buff, size_t n) {
    //Allocate space to store the removed elements
    size_t removed[n - 3];
    for (size_t i = 0; i < n - 3; i++) {
        size_t lowest = getLowest(buff, n);
        removed[i] = lowest;
        buff[lowest] = 0;
    }
}

int main() {
    //Seed
    srand(time(NULL));
    //Allocate memory for dice rolls
    int* nbuff = (int*) malloc(sizeof(int) * N_ROLLS);
    for (size_t i = 0; i < N_STATS; i++) {
        //Roll 1d6 6 times
        rollDice(nbuff, N_ROLLS);
        //Print out each 1d6 roll
        for (size_t n = 0; n < N_ROLLS; n++) {
            printf("%i ", nbuff[n]);
        }
        //Get the 3 highest dice rolls
        filterDice(nbuff, N_ROLLS);
        //Get the sum of the 3 highest dice rolls
        int sum = 0;
        for (size_t i = 0; i < N_ROLLS; i++) {
            sum += nbuff[i];
        }
        printf("%i\n", sum);
    }
}