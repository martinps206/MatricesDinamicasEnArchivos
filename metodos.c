#include <stdio.h>
#include <stdlib.h>
#include "metodos.h"
#define FREE(p)   do { free(p); (p) = NULL; } while(0)

void matrix_free(matrix_t *M){
    int i;
    for(i = 0; i < M->n; i++)
        FREE(M->M[i]);
    FREE(M->M);
    FREE(M);
} 

void write_matrix(matrix_t *M){
    int n,m;
    printf("\n");
    for(n=0; n < M->n; n++){
        for(m=0; m < M->m; m++){
            printf("\t%.2f", M->M[n][m]);
        }
        printf("\n");
    }
}

matrix_t *matrix_create(int a, int b){
    int i;
    matrix_t *M;
    
    M = malloc(sizeof(matrix_t));
    if(M == NULL){
        return NULL;
    }

    M->n = a;
    M->m = b;

    M->M = malloc(a * sizeof(double *));
    if(M->M == NULL){
        return NULL;
    }
    for(i = 0; i < a; i++){
        M->M[i] = malloc(b * sizeof(double));
        if(M->M[i] == NULL){
            return NULL;
        }
    }
    return M;
}

// Creamos la matriz con valores al azar
matrix_t *read_matrix(int a, int b){
    matrix_t *M;
    int i, j;
	M = matrix_create(a, b);
    
    if(M == NULL){
        return NULL;
    }
	
	for(i=0; i < M->m; i++){
        for(j=0; j < M->n; j++){
            M->M[j][i]=rand () % 99 + 10;
        }
    }
    return M;
}
//Cargamos la matriz en un archivo de lectura y escritura
void cargar_matrixFile(matrix_t *M, char *arch){
	FILE *f;
	f = fopen(arch,"w+");
	if(arch == NULL) exit(1);
	for(int i = 0; i < M->n; i++){
		for(int j = 0; j < M->m; j++){
				fprintf(f, "\t%.2f ", M->M[i][j]);
		}
			fprintf(f, "\n");
	}
	fclose(f);
}	
//metodos del 'leerMatriz.c'
matrix_t *matrixCreate(int n, int m){
    int i;
    matrix_t *M;
    
    M = malloc(sizeof(matrix_t));
    if(M == NULL){
        return NULL;
    }

    M->m = m;
    M->n = n;

    M->M = malloc(n * sizeof(double *));
    if(M->M == NULL){
        return NULL;
    }
    for(i = 0; i < n; i++){
        M->M[i] = malloc(m * sizeof(double));
        if(M->M[i] == NULL){
            return NULL;
        }
    }
    return M;
}

matrix_t *readMatrix(char *filename, int n, int m){
    FILE *fp;
    matrix_t *M;
    int ni, mj, i, j;
    char line[100000];
    char num[1000];

    M = matrix_create(n, m);
    if(M == NULL){
        return NULL;
    }
    fp = fopen(filename,"r");
    if(fp == NULL){
        printf("Error al abrir archivo");
        return NULL;
    }

    for(ni = 0; ni < n; ni++){
        fgets(line, 100000, fp); 
        i = 0;
        mj = 0;
        while(mj < m){
            j = 0;

            while(line[i] != ' ' && line[i] != '\n'){
                num[j] = line[i];
                j++;
                i++;
            }

            i++;
            num[j] = '\0';
            M->M[ni][mj] = atof(num);
            mj++;
            j = 0;
        }
    }
                
    fclose(fp);
    return M;
}

void writeMatrix(matrix_t *M){
    int n,m;
    printf("\n");
    for(n=0; n < M->n; n++){
        for(m=0; m < M->m; m++){
            printf("\t%.2f", M->M[n][m]);
        }
        printf("\n");
    }
}
