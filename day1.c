#include <stdio.h>
#include <stdlib.h>

#define LEN 1000

// Comparison function, from Wikipedia :D
int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;
    else if (x > y)
        return 1;

    return 0;
}

void part1(FILE* input, int left[LEN], int right[LEN]) {
    int difference[LEN];
    int total = 0;

    // Sort left and right arrays
    qsort(left, LEN, sizeof(int), compare);
    qsort(right, LEN, sizeof(int), compare);

    for (int i = 0; i < LEN; i++) {
        // The difference must be positive
        if (left[i] > right[i]) {
            difference[i] = left[i] - right[i];
        } else {
            difference[i] = right[i] - left[i];
        }
        total += difference[i];
    }

    printf("The solution to part 1 is: %d\n", total);
}

void part2(FILE* input, int left[LEN], int right[LEN]) {
    int temp = 0;
    int score = 0;

    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if (left[i] == right[j])
                temp++;
        }
        score += left[i] * temp;
        temp = 0;
    }

    printf("The solution to part 2 is: %d\n", score);
}

int main() {
    FILE *input = fopen("inputs/day1.txt", "r");
    int left[LEN], right[LEN];

    // Checking if input file exists
    if (input == NULL) {
        printf("no input :(\n");
        return 1;
    } else {
        printf("gaming!\n");
    }

    // Parsing the input into arrays for each column
    for (int i = 0; i < LEN; i++) {
        fscanf(input, "%d %d", &left[i], &right[i]);
    }

    part1(input, left, right);
    part2(input, left, right);

    return 0;
}
