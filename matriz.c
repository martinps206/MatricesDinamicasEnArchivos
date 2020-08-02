#include <stdio.h>
#include <stdlib.h>
#include "metodos.h"

void formato(void){
    printf("Formato de entrada:\n");
    printf(".\(nombre de archivo) [n] [m] archivo1.txt\n");
    printf("Donde n y m son las dimenciones de cada matriz\n");
    printf("y archivo1.txt contiene los valores\n");
    printf("de la matriz.\n");
}

int main(int argc, char **argv){
	int a, b;
	matrix_t *M;
	char *f;
	
	// Anlizamos las entradas de la interface
	if (argc != 4){
		formato();
		return 0;
	}
	
	// Asiganamos los valores de entrada
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	f = argv[3];
	
	printf("%s",f);
	
	// Creamos la matriz con valores al azar
	M = read_matrix(a, b);
	cargar_matrixFile(M,f);
	write_matrix(M);

	matrix_free(M);
	printf("\n");
	return 0;
}
