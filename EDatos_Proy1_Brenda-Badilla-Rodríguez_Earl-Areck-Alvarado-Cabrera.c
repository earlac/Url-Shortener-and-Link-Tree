/*
Creado por Earl Alvarado y Brenda Badilla
Creado el 2 de Noviembre, 7:50 pm
Última modificación: 7 de Nov, 23:46

Programa que utiliza estructuras de datos y analiza una tabla hash para introducir datos del tipo bit.ly que son URLs recortados y linktr.ee s que son bibliotecas de urls y los simulan con información guardada.

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define tamannoTabla 20

typedef struct url {
	char longUrl[MAX_NAME];
	char shortUrl[MAX_NAME];
	int contVisitas;
	char nombre[MAX_NAME];
	char descripcion[MAX_NAME];
	
	struct url *siguiente;
} url;
struct url *primero, *ultimo;

url * tablaHash[tamannoTabla];

typedef struct linkTree{
	char nombreLinkTree[MAX_NAME];
	url *primerLk;
	url *segundoLk;
	url *tercerLk;
	
	struct linkTree *siguienteLk;
} linkTree;
struct linkTree *primeroLk, *ultimoLk;

typedef struct ABC{
	char letra;
	
	struct ABC *siguienteabc;
} ABC;
struct ABC *primeroabc, *ultimoabc;

/*----FUNCIONALIDAD 1--------------------------------------------*/
/*----Añadir URLs, mostrar lista Hash----------------------------*/
unsigned int hash(char *longUrl){
	/*
	F: Función hash para asignar un lugar al elemento a insertar
	E: El elemento a insertar
	S: Valor modificado por la función
	*/
	int length = strnlen(longUrl, MAX_NAME);
	unsigned int valorHash=0;
	for (int i =0; i< length; i++){
		valorHash += longUrl[i];
		valorHash %= tamannoTabla;
		
	}
	return valorHash;

}

bool inicializarTablaHash(){
	/*
	F: crea una tabla hash 
	E: NA
	S: NA
	*/
	for (int i =0; i<tamannoTabla; i++){
		tablaHash[i]=NULL;
	}
}

void imprimirTabla(){
	/*
	F: Muestra en pantalla la tabla hash.
	E: NA
	S: Tabla hash con colisiones.
	*/
	printf("Tabla Hash----------------\n--------------------------\n");
	for (int i =0; i<tamannoTabla; i++){
		if (tablaHash[i]==NULL){
			printf("\t%d\t---\n", i);
		}else{
			printf("\t%d\t ", i);
			url *tmp = tablaHash[i];
			while (tmp!= NULL){
				printf("%s - ", tmp->longUrl);
				tmp = tmp->siguiente;
			}
			printf("\n");
		}
	}
	printf("--------------------------\n");
}

bool insertarTabla(url *p){
	/*
	F: Inserta el elemento del tipo url en la tabla hash
	E: Elemento tipo url
	S: tabla hash modificada
	*/
	if (p == NULL) return false;
	int index = hash(p->longUrl);
	p->siguiente= tablaHash[index];
	tablaHash[index]=p;
	if (tablaHash[index]==NULL)
	return true;
}
void annadirUrl(){
	/*
	F: Crea un elemento del tipo url y solicita la información para añadirlo a la lista enlazada de este tipo.
	E: Información necesaria para la URL
	S: Se crea el nodo de este tipo
	*/
	url *nuevo;
	nuevo=(url *) malloc (sizeof(url));
	if (nuevo== NULL) printf("No hay memoria disponible!\n");
	
	printf("Ingrese la URL:\n");
    fflush(stdout);
    fgets(nuevo-> longUrl, MAX_NAME, stdin);
    fgets(nuevo-> longUrl, MAX_NAME, stdin);
  
  	printf("Ahora analizare los valores para crear una nueva url.(AUN EN PROCESO.)\n");
  	
	printf("Ingrese un nombre para describir esta URL.\n");
    fflush(stdout);
    fgets(nuevo-> nombre, MAX_NAME, stdin);
    /*--------------*/
    char temporal[500];
        
    for(int f=0; f<strlen(nuevo->longUrl);f++){
    	char temp = nuevo->longUrl[f];

    	ABC *nuevoabc;
		nuevoabc=(ABC *) malloc (sizeof(ABC));
		
		nuevoabc->letra= temp;
		
		nuevoabc->siguienteabc=NULL;
	
		if(primeroabc==NULL){
			printf("Primer elemento\n");
			primeroabc= nuevoabc;
			ultimoabc= nuevoabc;
		}else{
			ultimoabc->siguienteabc= nuevoabc;
			ultimoabc= nuevoabc;
    }
    	url *auxiliar; 
		int g; g=0;

		auxiliar = primero;
    }
    
    ABC *auxiliar2; 
	int g; g=0;

	auxiliar2 = primeroabc;
	char nuevaUrl[20]= "brnarl.co/";
	
    while (auxiliar2!=NULL && g<19) {
			int x= (char)auxiliar2->letra;
			char y = (char)x;
			    
			if((auxiliar2->letra)%2!=0){
			
				strcat(nuevaUrl, &y);
			}
			auxiliar2 = auxiliar2->siguienteabc;
			g++;
		}
	printf("%s", nuevaUrl);
	
    /*--------------*/
    printf("Por favor ingrese la URL corta brindada.(ESCRIBA CUALQUIERA.)\n");
    fflush(stdout);
    fgets(nuevo-> shortUrl, MAX_NAME, stdin);
	
	printf("Ingrese una descripcion esta URL.\n");
    fflush(stdout);
    fgets(nuevo-> descripcion, MAX_NAME, stdin);

	nuevo->contVisitas=0;
	
	
	
	nuevo->siguiente=NULL;
	
    if(primero==NULL){
    	printf("Primer elemento\n");
    	primero= nuevo;
    	ultimo= nuevo;
    }else{
    	ultimo->siguiente= nuevo;
    	ultimo= nuevo;
    }
    insertarTabla(nuevo);
}
/*----FUNCIONALIDAD 2--------------------------------------------*/
/*------BUSCAR URL-----------------------------------------------*/

void buscarURL(){
	/*
	F: Busca un elemento en la lista enlazada del tipo url que coincida con el que el usuario busca y lo muestra con su información.
	E: Url a buscar
	S: Información de la URL
	*/
	char urlAux[MAX_NAME];
	url *auxiliar;
	auxiliar = primero;
	int i; i=0;
	printf("Indique el URL que está buscando: \n");
	fflush(stdout);
	scanf("%s", urlAux);
	while (auxiliar!=NULL){
		printf("%s", auxiliar->longUrl);
		if(auxiliar->longUrl == urlAux){
			printf("Articulo encontrado: Posición#%d\n\nDetalles:\n", i+1);
			printf( "Nombre: \t\t%s\nDescripcion de la url: \t%s\nCodigo URL: \t\t%s\nShort URL: \t\t%s\n",
			auxiliar->nombre,
			auxiliar->descripcion, 
			auxiliar->longUrl,
			auxiliar->shortUrl);
			break;
		}else{
			i++;
			auxiliar=auxiliar->siguiente;
		}
	}
	if (auxiliar == NULL){
		printf("\nNo se encontró\n");}
}
/*----FUNCIONALIDAD 3--------------------------------------------*/
/*------MOSTRAR URLs---------------------------------------------*/
void mostrarRegistros(){
	/*
	F: Muestra como una lista tipo factura todos los elementos registrados
	E: NA
	S: Imprime en pantalla todo lo que hay en la lista enlazada.
	*/
	url *auxiliar; 
	int i; i=0;

	auxiliar = primero;

	printf("\nMostrando la lista completa:\n\n");

	while (auxiliar!=NULL) {
		printf("Registro #%d-------------------\n", i+1);
		printf( "Nombre: \t\t%s\nDescripcion de la url: \t%s\nCodigo URL: \t\t%s\nShort URL: \t\t%s\n\n",
		auxiliar->nombre,
		auxiliar->descripcion, 
		auxiliar->longUrl,
		auxiliar->shortUrl);
		auxiliar = auxiliar->siguiente;
		i++;
	}
	if (i==0) printf( "\nLa lista está vacía!!\n" );
}

/*----FUNCIONALIDAD D--------------------------------------------*/
/*----BORRAR URLs------------------------------------------------*/
void borrarRegistro(){
	/*
	F: Elimina el nodo registrado en la lista enlazada de este tipo de Struct
	E: qué nodo se desea eliminar
	S: Lista enlazada sin el nodo previamente eliminado.
	*/
	int posc;
	url *auxiliar;
	auxiliar = primero;
	url *temporal;
	temporal=primero;
	
	printf("Qué posición de URL desea eliminar?: ");
	fflush(stdout);
	scanf("%d", &posc);
	
	while ((posc-1)!=0){
		printf("%p\n", auxiliar);
		auxiliar = auxiliar->siguiente;
		posc-=1;
		}
	if(primero==ultimo){
		printf("1");
		ultimo=NULL;
		primero= NULL;
		}
	else if(auxiliar==ultimo){
		printf("2");
		temporal=primero;
		while((temporal->siguiente)!=ultimo){
			temporal=temporal->siguiente;}
			free(ultimo);
			ultimo=temporal;
			ultimo->siguiente=NULL;
		}
	else if(auxiliar==primero){
		printf("3");
		auxiliar= auxiliar->siguiente;
		primero= auxiliar;
		free(auxiliar);
		}
	else{
		printf("4");
		while((auxiliar->siguiente)!=NULL){
			auxiliar=auxiliar->siguiente;}
			free(auxiliar->siguiente);
			auxiliar->siguiente=NULL;
			ultimo=auxiliar;
		}
	printf("Eliminado.");	
}

/*----FUNCIONALIDAD G--------------------------------------------*/
/*----VISUALIZAR LINKTREE----------------------------------------*/
void visualizarLinkTreeGeneral(){
	/*
	F: Muestra el nombre de los linktrees preexistentes
	E: NA
	S: Los linktrees preexistentes.
	*/
	linkTree *auxiliar1; /* para recorrer la lista */
	int i; i=0;
	auxiliar1 = primeroLk;
	printf("\nMostrando la lista completa:\n\n");
	while (auxiliar1!=NULL) {
		printf("%d.- %s\n", i+1, auxiliar1->nombreLinkTree);
		auxiliar1= auxiliar1->siguienteLk;
		i++;
	}
	if (i==0) {
		printf( "\nLa lista está vacía!!\n" );
	}
}

void visualizarLinkTree(){
	/*
	F: Especifica para escoger el link tree que se desea observar.
	E: Qué linktree se desea ver bien
	S: Interior de cada linktree o url.
	*/
	int posc;
	
	linkTree *auxiliar;
	auxiliar= primeroLk;
	
	visualizarLinkTreeGeneral();
	if(auxiliar==NULL) return;
	printf("Cuál posición de linkTree quiere visualizar?: ");
	fflush(stdout);
	scanf("%d", &posc);
	
	posc-=1;
	
	while (posc!=0){
		printf("%p\n", auxiliar);
		auxiliar = auxiliar->siguienteLk;
		posc-=1;
		break;}
	printf("\nNombre: \t\t%s\n1-\t%s\n", auxiliar-> nombreLinkTree, (auxiliar->primerLk)->nombre);
	if(auxiliar->segundoLk!=NULL){
		printf("2-\t%s\n", (auxiliar->segundoLk)->nombre);
	};
	if(auxiliar->tercerLk!=NULL){
		printf("3-\t%s\n", (auxiliar->tercerLk)->nombre);
	}
	
	int posc2;
	printf("Cuál posición de linkTree quiere visualizar?: ");
	fflush(stdout);
	scanf("%d", &posc2);
	if (posc2==1){
		printf("1\n-URL largo: \t\t%s\n-Url Corto: \t\t%s\n\n", (auxiliar->primerLk)->longUrl, (auxiliar->primerLk)->longUrl);
		int contV;
		contV= (auxiliar->primerLk)->contVisitas;
		contV+=1;
		(auxiliar->primerLk)->contVisitas= contV;
	}else if (posc2==2){
		printf("2\n-URL largo: \t\t%s\n-Url Corto: \t\t%s\n\n", (auxiliar->segundoLk)->longUrl, (auxiliar->segundoLk)->longUrl);
		int contV;
		contV= (auxiliar->segundoLk)->contVisitas;
		contV+=1;
		(auxiliar->segundoLk)->contVisitas= contV;
	}else{
		printf("3\n-URL largo: \t\t%s\n-Url Corto: \t\t%s\n\n", (auxiliar->tercerLk)->longUrl, (auxiliar->tercerLk)->longUrl);
		int contV;
		contV= (auxiliar->tercerLk)->contVisitas;
		contV+=1;
		(auxiliar->tercerLk)->contVisitas= contV;
	}
	
}

/*----FUNCIONALIDAD F--------------------------------------------*/
/*----CREAR LINKTREE---------------------------------------------*/

void modificarLinkTree(){
	/*
	F: Añadir elementos al linktree
	E: Qué linktree desea modificar
	S: LinkTree modificado
	*/
	visualizarLinkTreeGeneral();
	
	int posc;
	linkTree *auxiliar;
	auxiliar= primeroLk;
	
	printf("Cuál posición de linkTree quiere modificar?: ");
	fflush(stdout);
	scanf("%d", &posc);
	
	posc-=1;
	
	while (posc!=0){
		printf("%p\n", auxiliar);
		auxiliar = auxiliar->siguienteLk;
		posc-=1;
		break;}
	
	int urlAux;
	url *auxiliarUrl;
	auxiliarUrl = primero;
	
	printf("Indique el numero de URL que desearía agregar a su LinkTree: \n");
	fflush(stdout);
	scanf("%d", &urlAux);
	
	urlAux-=1;
	
	while(urlAux> 0){
		auxiliarUrl= auxiliarUrl-> siguiente;
		urlAux-=1;
	}
	printf("El link que se va a utilizar va a ser:\n%s", auxiliarUrl->longUrl);
	
	if(auxiliar->segundoLk==NULL){
		auxiliar->segundoLk=auxiliarUrl;
	}else if(auxiliar->tercerLk==NULL){
		auxiliar->tercerLk=auxiliarUrl;
	}else{
		printf("El linkTree está lleno.");
	}
	
	
}
/*------------------------------*/
void CrearLinkTree(unsigned* arr[MAX_NAME]){
	/*
	F: Crea un nodo del tipo linktree y lo añade a una lista enlazada
	E: el alias y el elemento primero de la lista
	S: elemento creado y enlazado
	*/
	int urlAux;
	int cont; cont=0;
	int linktreeRevisar;
	char nombre[MAX_NAME];
	
	linkTree *nuevo;
	nuevo = (linkTree *) malloc (sizeof(linkTree));
	
	url *auxiliar;
	auxiliar = primero;

	if (nuevo == NULL) printf("No hay memoria disponible!\n");
	printf("\nNuevo elemento\n");
	
	printf("Indique el nombre clave del Linktree: ");
	fflush(stdout);
	fgets(nuevo->nombreLinkTree, MAX_NAME, stdin);
	fgets(nuevo->nombreLinkTree, MAX_NAME, stdin);
	
	printf("Indique el numero de URL que desearía agregar para inicializar su LinkTree: \n");
	fflush(stdout);

	scanf("%d", &urlAux);
	
	urlAux-=1;
	while(urlAux> 0){
		auxiliar= auxiliar-> siguiente;
		urlAux-=1;
	}
	printf("El link que se va a utilizar va a ser:\n%s", auxiliar->longUrl);
	nuevo->primerLk= auxiliar;
	printf("LinkTree inicializado exitosamente, y link agregado. Utilice la funcionalidad \"Modificar LinkTree preexistente\" para agregar más links.\n");
	
	printf("Prueba punteros: %s\n", (nuevo->primerLk)->longUrl);
	
	nuevo -> siguienteLk= NULL;
	if (primeroLk==NULL) {
		printf( "Primer elemento\n");
		primeroLk = nuevo;
		ultimoLk = nuevo;
	} else {
		ultimoLk->siguienteLk = nuevo;
		ultimoLk = nuevo;
	}
}

void mostrarMenuLinkTree(){
	/*
	F: Imprime las opciones de la funcion de mostrarMenu()
	E: NA
	S: texto de menú
	*/
	printf("\n\nMenú LinkTree:\n=====\n\n");
	printf("1.- Crear linktree.\n");
	printf("2.- Modificar LinkTree preexistente.\n");
	printf("3.- Ver la lista de URLs ingresados.\n");
	printf("4.- Salir al menu principal.\n");
}

void crearModificarLinktree(unsigned* arr[MAX_NAME]){
	/*
	F: Menu para ver si el usuario quiere modificar o crear un linktree
	E: Qué opción desea hacer
	S: La funcionalidad correspondiente
	*/
	char opcion;
	do{
		mostrarMenuLinkTree();
		opcion = getchar();
		switch ( opcion ) {
			case '1': CrearLinkTree(arr); break;
			case '2': modificarLinkTree(arr); break;
			case '3': mostrarRegistros(arr); break;
			case '4': return; break;
		default:
			printf("Topamos un error");
			break;
		}
	}while(opcion!='4');
}

/*----FUNCIONALIDAD H--------------------------------------------*/
/*----BORRAR LINKTREE--------------------------------------------*/
void borrarLinktree(){
	/*
	F: Elimina un nodo del tipo LinkTree de la lista enlazada
	E: Slicita qué nodo quiere eliminar
	S: Lista enlazada sin el nodo eliminado
	*/
	int posc;
	linkTree *auxiliar;
	auxiliar = primeroLk;
	linkTree *temporal;
	temporal=primeroLk;
	
	printf("Qué posición de LinkTree desea eliminar?: ");
	fflush(stdout);
	scanf("%d", &posc);
	
	while ((posc-1)!=0){
		printf("%p\n", auxiliar);
		auxiliar = auxiliar->siguienteLk;
		posc-=1;
		}
	if(primeroLk==ultimoLk){
		printf("1");
		ultimoLk=NULL;
		primeroLk= NULL;
		}
	else if(auxiliar==ultimoLk){
		printf("2");
		temporal=primeroLk;
		while((temporal->siguienteLk)!=ultimoLk){
			temporal=temporal->siguienteLk;}
			free(ultimoLk);
			ultimoLk=temporal;
			ultimoLk->siguienteLk=NULL;
		}
	else if(auxiliar==primeroLk){
		printf("3");
		auxiliar= auxiliar->siguienteLk;
		primeroLk= auxiliar;
		free(auxiliar);
		}
	else{
		printf("4");
		while((auxiliar->siguienteLk)!=NULL){
			auxiliar=auxiliar->siguienteLk;}
			free(auxiliar->siguienteLk);
			auxiliar->siguienteLk=NULL;
			ultimoLk=auxiliar;
		}
	printf("Eliminado.");
}
/*----FUNCIONALIDAD I--------------------------------------------*/
/*----INSPECCIONAR..---------------------------------------------*/
void inspeccionarUrl(){
	/*
	F: inspecciona los elementos dentro de la lista enlazada de este tipo de struct
	E: NA
	S: Inspección de datos.
	*/
	url *auxiliar; 
	int i; i=0;

	auxiliar = primero;

	printf("\nMostrando la lista de URLs:\n\n");

	while (auxiliar!=NULL) {
		printf("Registro #%d-------------------\n", i+1);
		printf("\t\t\tTamaños || Posiciones de memoria\n");
		printf("-nombre:\t\t%li\t\t%p\n", sizeof(auxiliar->nombre), auxiliar->nombre);
		printf("-longUrl:\t\t%li\t\t%p\n", sizeof(auxiliar->longUrl), auxiliar->longUrl);
		printf("-shortUrl:\t\t%li\t\t%p\n", sizeof(auxiliar->shortUrl), auxiliar->shortUrl);
		auxiliar = auxiliar->siguiente;
		i++;
	}
	if (i==0) printf( "\nLa lista de URLs está vacía!!\n" );
}

void inspeccionarLinkTree(){
	/*
	F: inspecciona los elementos dentro de la lista enlazada de este tipo de struct
	E: NA
	S: Inspección de datos.
	*/
	linkTree *auxiliar; 

	auxiliar = primeroLk;

	printf("\nMostrando la lista de LinkTrees:\n\n");

	printf("Registro #-------------------\n");
	printf("\t\t\tTamaños || Posiciones de memoria\n");
	printf("-nombre:\t\t%li\t\t%p\n", sizeof(auxiliar->nombreLinkTree), auxiliar->nombreLinkTree);

	printf("Link 1\t\t%li\t\t%p\n", sizeof((auxiliar->primerLk)->shortUrl), (auxiliar->primerLk)->shortUrl);
		
	if(auxiliar->segundoLk!=NULL){
		printf("Link 2\t\t%li\t\t%p\n", sizeof((auxiliar->segundoLk)->shortUrl), (auxiliar->segundoLk)->shortUrl);
	};
	if(auxiliar->tercerLk!=NULL){
		printf("Link 3\t\t%li\t\t%p\n", sizeof((auxiliar->tercerLk)->shortUrl), (auxiliar->tercerLk)->shortUrl);
	}
}
void modoInspeccionar(){
	/*
	F: Imprime las posiciones en memmoria y los tamaños de los structs y solicita a las funciones auxiliares lo mismo de los elementos que los conforman.
	E: NA
	S: Información de tamaños y posiciones de memoria.
	*/
	printf("Struct Url:\n");
	printf("-Posición en memoria:\t%p\n", &primero);
	printf("-Tamaño en memoria de\ncada elemento:\t\t%li\n", sizeof(primero));
	printf("longUrl:\t\t%li\n", sizeof(primero->longUrl));
	printf("shortUrl:\t\t%li\n", sizeof(primero->shortUrl));
	printf("nombre:\t\t\t%li\n", sizeof(primero->nombre));
	printf("descripcion:\t\t%li\n", sizeof(primero->descripcion));
	
	printf("\n\nStruct linkTree:\n");
	printf("-Posición en memoria:\t%p\n", &primeroLk);
	printf("-Tamaño en memoria de\ncada elemento:\t\t%li\n", sizeof(primeroLk));
	printf("-nombre:\t\t%li\n", sizeof(primeroLk->nombreLinkTree));
	printf("-Tamaño en memoria de\ncada url enlazada:\t%li\n", sizeof(primero));
	inspeccionarUrl();
	inspeccionarLinkTree();
}
/*----MENU PRINCIPAL---------------------------------------------*/
/*---------------------------------------------------------------*/
void mostrarMenu() {
	/*
	F: Imprime las opciones a destacar en el menu
	E: NA
	S: NA
	*/
	printf("\n\nMenú:\n=====\n\n");
	printf("1.- Ingresar URL / Acortar URL\n");
	printf("2.- Buscar codigo URL\n");
	printf("3.- Mostrar todos los registros almacenados, por orden de numero de registro\n");
	printf("4.- Borrar registro URL\n");
	printf("5.- Mostrar registros de la tabla HASH\n");
	printf("6.- Crear linktree\n");
	printf("7.- Visualizar Linktree\n");
	printf("8.- Borrar link.tree\n");
	printf("9.- Modo inspeccionar\n");
	printf("s.- Salir\n\n");
	printf("Escoge una opción: ");
	fflush(stdout);
}

int menu(unsigned* arr[MAX_NAME]) {
	/*
	F: Solicita qué funcionalidad quiere hacer el usuario, es un bucle.
	E: Opcion del usuario
	S: funcionalidad solicitada
	*/
	char opcion;
	do{
		mostrarMenu();
		opcion = getchar();
		switch ( opcion ) {
			case '1': annadirUrl(); break;
			case '2': buscarURL(); break;
			case '3': mostrarRegistros(); break;
			case '4': borrarRegistro(); break;
			case '5': imprimirTabla(); break;
			case '6': crearModificarLinktree(arr);break;
			case '7': visualizarLinkTree();break;
			case '8': borrarLinktree();break;
			case '9': modoInspeccionar();break;
			case 's': exit( 1 );
			case 'S': exit( 1 );
		default:
			printf("Topamos un error");
			break;
		}
	}while(opcion!='s');
}


int main(){
	/*
	F: Funcion principal del programa
	E: NA
	S: El programa, basicamente.
	*/

	unsigned* arr[MAX_NAME]={NULL};
	inicializarTablaHash();
	menu(arr);
	
	return 0;
}
