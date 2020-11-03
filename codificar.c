#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void codUrl(){
    /*
    F: Codifica la url.
    E: url.
    S: url codificada.*/
    char nuevaUrl[200]= "brenarl.com/";
    char url[200];
    printf("Ingrese la URL:\n");
    fflush(stdout);
    scanf("%s", url);
    
    int letras[10]={1,3,4,5,2,8,8,7,1,2};
    
    printf("%s\n", nuevaUrl);
    printf("%s\n", url);
    printf("Ahora analizare los valores para crear una nueva url.\n");
    
    char valorUrlStr[6];
    
    for (int i=0; i<10; i++){
    char temp = url[letras[i]];
    strcat(nuevaUrl, &temp);
    }
    printf("%s\n", nuevaUrl);
}

int main(){
    codUrl();
}
