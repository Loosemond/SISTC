#include <stdio.h>
#include <memory.h>
#define n_of_elements(vector)   (sizeof(vector)/ sizeof(typeof(vector[0])))
#include <stdlib.h>

int comparador_strings(char *original,char *teste){
    for (int i=0;i< sizeof(original)/sizeof(char);i++){
        if(original[i]!=teste[i]){

            return 0;

        }
    }

    return 1;

}


int main() {
    char frase[]="Teste";
    char teste[40];

    scanf("%s",teste);
    printf("%i",comparador_strings(frase,teste));
}