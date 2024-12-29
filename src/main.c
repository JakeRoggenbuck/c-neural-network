#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double sigmoid(double x) { return 1.0 / (1 + exp(-x)); }

double dsigmoid(double x) { return x * (1.0 - x); }

double random_double() { return (rand() / (RAND_MAX / 1.0)); }

void fill_matrix_random(double **matrix, int x, int y) {
    printf("Fill matrix randomly:\n");
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            matrix[i][j] = random_double();
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_matrix(double **matrix, int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

double **create_empty_matrix(int x, int y) {
    double **matrix = calloc(x, sizeof(double *));

    if (matrix == NULL) {
        fprintf(stderr, "Malloc failed.\n");
        exit(1);
    }

    for (int i = 0; i < x; ++i) {
        matrix[i] = calloc(y, sizeof(double *));

        if (matrix[i] == NULL) {
            fprintf(stderr, "Malloc failed.\n");
            exit(1);
        }
    }

    return matrix;
}

struct NeuralNetwork {
    double **input;
    double **weights1;
    double **weights2;
    double **y;
    double **output;
};

struct NeuralNetwork *create_neural_network(double **x, double **y, int xw,
                                            int xh, int yw, int yh) {
    struct NeuralNetwork *nn = malloc(sizeof(struct NeuralNetwork));

    if (nn == NULL) {
        fprintf(stderr, "Malloc failed.\n");
        exit(1);
    }

    nn->input = x;

    nn->weights1 = create_empty_matrix(xw, 4);
    fill_matrix_random(nn->weights1, xw, 4);

    nn->weights2 = create_empty_matrix(4, 1);
    fill_matrix_random(nn->weights2, 4, 1);

    nn->y = y;
    nn->output = create_empty_matrix(yw, yh);

    return nn;
}

void feedforward(struct NeuralNetwork nn) {}

void backprop(struct NeuralNetwork nn) {}

int main() {
    double **matrix = calloc(5, sizeof(double *));

    if (matrix == NULL) {
        fprintf(stderr, "Malloc failed.\n");
        exit(1);
    }

    for (int i = 0; i < 5; ++i) {
        matrix[i] = calloc(4, sizeof(double *));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Malloc failed.\n");
            exit(1);
        }
    }

    fill_matrix_random(matrix, 5, 4);

    double Xsource[4][3] = {{0, 0, 1}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    double *X[3];

    for (int i = 0; i < 4; ++i) {
        X[i] = Xsource[i];
    }

    printf("X matrix:\n");
    print_matrix(X, 4, 3);
    printf("\n");

    double ysource[4][1] = {{0}, {1}, {1}, {0}};
    double *y[1];

    for (int i = 0; i < 4; ++i) {
        y[i] = ysource[i];
    }

    printf("y matrix:\n");
    print_matrix(y, 4, 1);
    printf("\n");

    struct NeuralNetwork *nn = create_neural_network(X, y, 4, 3, 4, 1);

    return 0;
}
