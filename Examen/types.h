#include <stdio.h>
#include <stdlib.h>

struct producto {
	int codProd;
	int codProv;
	char descrProd[50];
	int impProd;
	int cantProd;
};

struct proveedor {
	int codProv[3];
	char descrProv[50];
};

