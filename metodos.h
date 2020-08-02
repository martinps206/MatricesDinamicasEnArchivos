#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix{
    int m, n;
    double **M;
} matrix_t;

matrix_t *matrixCreate(int, int);
matrix_t *readMatrix(char *, int, int);
void writeMatrix(matrix_t *);

matrix_t *read_matrix(int, int);
void write_matrix(matrix_t *);
void cargar_matrixFile(matrix_t *, char *);
void matrix_free(matrix_t *);

#endif
