void mostrarRegistros(){
	LINKS *auxiliar; 
	int i; i=0;

	auxiliar = primero;

	printf("\nMostrando la lista completa:\n\n");

	while (auxiliar!=NULL) {
		printf( "Nombre: \t\t%s\nDescripcion de la url: \t%s\nCodigo URL: \t\t%s\nShort URL: \t\t%s\n",
		auxiliar->nombre,
		auxiliar->descripcion, 
		auxiliar->longUrl,
		auxiliar->shortUrl);
		auxiliar = auxiliar->siguiente;
		i++;
	}
	if (i==0) printf( "\nLa lista está vacía!!\n" );
}
