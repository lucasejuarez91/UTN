#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

struct producto prod[1000];
struct producto min[10];
struct producto max[10];
struct producto prodAux;
int j;
struct proveedor prov[3];

int menu(int i){
	int option;
	int auxId;
	
	do{
	printf("1.Alta\n2.Modificar\n3.Baja\n4.Informar\n5.Listar\n6.Salir\n>");
	scanf("%d",&option);
	
	switch(option) {
		case 1: // alta
				printf("--Alta de Producto\n");
					printf( "Codigo de Producto: 00%d\n",i );
				
					if (controlCodigo(i) == -1){
						return -1;
					}
					prod[i].codProv = Proveedores(); // funcion que muestra los proveedores activos
					
					printf( "Descripcion: " );
					scanf("%s",&prod[i].descrProd);
					
					do{
						printf( "Ingrese importe: " );
						scanf("%d",&prod[i].impProd );
					} while (!validaInt(prod[i].impProd));
					
					do{
						printf( "Ingrese cantidad: " );
						scanf("%d",&prod[i].cantProd );
					} while (!validaInt(prod[i].cantProd));
					
					i++;
					
				break;
		case 2: //modificar
				if(productosExistentes(i) == 0){
					break;
				} else {
				printf("--Modificacion de Producto\n");
				printf("Ingrese el numero de producto a modificar");
				scanf("%d",&auxId);
					for(j=0;j<i;j++) {
						if(prod[j].codProd==auxId) {
								printf( "Codigo de Producto:%d\n",j);
								
								prod[i].codProv = Proveedores();
								
								printf( "Descripcion: " );
								scanf("%s",&prod[j].descrProd);
								
								do{
									printf( "Ingrese importe: " );
									scanf("%d",&prod[i].impProd );
								} while (!validaInt(prod[i].impProd));
								
								do{
									printf( "Ingrese cantidad: " );
									scanf("%d",&prod[i].cantProd );
								} while (!validaInt(prod[i].cantProd));
								
								break;
						}else{
							printf("No existe el codigo a modificar.\n");
							break;
						}
				}
			}
		case 3: //baja
				if(productosExistentes(i) == 0){
					break;
				} else {
				printf("--Baja de Producto\n");
				printf("Ingrese el numero de producto a eliminar");
				scanf("%d",&auxId);
					for(j=0;j<i;j++) {
						if(prod[j].codProd==auxId) {
								prod[j].codProd = -1;
								prod[j].codProv = -1;
								strcpy(prod[j].descrProd,"\0");
								prod[j].impProd = -1;
								prod[j].cantProd = -1;
//								Imprimimos los nuevos valores.
								printf("CodProd\tCodProv\tDescr\tImpor\tCant\n");
									printf("%d\t%d\t%s\t%d\t%d\n",prod[j].codProd,prod[j].codProv,prod[j].descrProd,prod[j].impProd,prod[j].cantProd);
								break;
						}else{
							printf("No existe el codigo a eliminar.\n");
							break;
						}
				}
				break;
			}
		case 4: //informar
				if(productosExistentes(i) == 0){
					break;
				} else {
				printf("--Informacion\n");
					for(j=0;j<5;j++) {
						if(j==0){
							min[j]=prod[j];
							max[j]=prod[j];
						}
						if(prod[j].cantProd>max[j].cantProd){
							max[j]=prod[j];
						}
						if(prod[j].cantProd<min[j].cantProd){
							max[j]=prod[j];
						}
					}
				printf("Datos minimos\n");
					for( j=0; j<i; j++ ) {
						printf("CodProd\tCodProv\tDescr\tImpor\tCant\n");
						printf("%d\t%d\t%s\t%d\t%d\n",min[j].codProd,min[j].codProv,min[j].descrProd,min[j].impProd,min[j].cantProd);
					}				
				printf("Datos maximos\n");
					for( j=0; j<i; j++ ) {
						printf("CodProd\tCodProv\tDescr\tImpor\tCant\n");
						printf("%d\t%d\t%s\t%d\t%d\n",max[j].codProd,max[j].codProv,max[j].descrProd,max[j].impProd,max[j].cantProd);
					}				
				break;
			}
		case 5: //listar
				if(productosExistentes(i) == 0){
					break;
				} else {
				printf("--Listado de Productos\n");
				for(i=0;i<5-1;i++) {
					for(j=i+1;j<5;j++) {
						if(prod[i].codProv<prod[j].codProv){ 
							prodAux=prod[i];
							prod[i]=prod[j];
							prod[j]=prodAux;
						}
						if(prod[i].codProv==prod[j].codProv){
							if(strcmp(prod[i].descrProd,prod[j].descrProd)>0){ 
								prodAux=prod[i];
								prod[i]=prod[j];
								prod[j]=prodAux;
							}
						}
					}
				}
					for( j=0; j<i; j++ ) {
						printf("CodProd\tCodProv\tDescr\tImpor\tCant\n");
						printf("%d\t%d\t%s\t%d\t%d\n",prod[j].codProd,prod[j].codProv,prod[j].descrProd,prod[j].impProd,prod[j].cantProd);
					}
				break;
			}
		case 6: // salir
				printf("Gracias, vuelva pronto.");
				break;
		default:
				printf("Opcion incorrecta, reintente");
				break;
			}
	}while(option!=6);
}

int validaInt(int v){
	if(v<0){
		printf("El valor debe ser mayor a cero!");
		return 0;
	}
	
	return 1;
}

int controlCodigo(int i){
	for(j=0;j<i;j++) {
		if(prod[j].codProd==i){
			printf("Codigo ya utilizado.");
			return -1;
		} 
	}
	
	prod[i].codProd = i;
	return i;
}

int Proveedores(){
	prov[0].descrProv = "Manaos";
	prov[1].descrProv = "Pepsi";
	prov[2].descrProv = "Kodak";
		printf("Elija una opcion.\n");
		printf( "Proveedor 1: %s\nProveedor 2: %s\n Proveedor 3: %s",prov[0].descrProv,prov[1].descrProv,prov[2].descrProv);
	
	int codProv=0;
	scanf("%i",&codProv );
	
	return codProv;
}

int productosExistentes(int i){
	if(i==0){
		printf("Para realizar otras operaciones primero debe ingresar un producto.");
		return 0;
	}
	return 1;
}
