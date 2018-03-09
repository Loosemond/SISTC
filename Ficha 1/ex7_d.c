#include <stdio.h>
#include <memory.h>
#define n_of_elements(vector)   (sizeof(vector)/ sizeof(typeof(vector[0])))
#include <stdlib.h>


int vector_compare(int *vetor1[],int *vetor2[]){

    for (int i=0;i< sizeof(vetor1)/sizeof(int);i++){

        if(vetor1[i]!=vetor2[i]){

            return 0;
        }
    }
    return 1;
}

int main() {

    int original[]={10,15,2};
    int teste[]={10,15,2};

    printf("%i",vector_compare(original,teste));

}