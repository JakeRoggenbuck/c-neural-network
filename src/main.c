#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double sigmoid(double x) { return 1.0 / (1 + exp(-x)); }

double dsigmoid(double x) { return x * (1.0 - x); }

double random_double() { return (rand() / (RAND_MAX / 1.0)); }

struct NeuralNetwork {
    double **input;
    double **weights1;
    double **weights2;
    double **y;
    double **output;
};

void fill_matrix_random(double **matrix, int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            matrix[i][j] = random_double();
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void feedforward(struct NeuralNetwork nn) {}

void backprop(struct NeuralNetwork nn) {}

int main() {
    double **matrix = calloc(5, sizeof(double *));
    for (int i = 0; i < 5; ++i) {
        matrix[i] = calloc(4, sizeof(double *));
    }
    fill_matrix_random(matrix, 5, 4);

    return 0;
}
