#include <stdio.h>
#include <memory.h>
#define n_of_elements(vector)   (sizeof(vector)/ sizeof(typeof(vector[0])))
#include <stdlib.h>

void vector_print2(int  *array,int end);

int main() {
    char str1[] = "Teste!";
    int data1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char str2[1000];
    int data2[1000] = {0}; // Makes sure that al numbers are 0


    strcpy(str2,str1);
    memcpy(data2,data1,sizeof(data1));

    printf("str1 = %s\nstr2 = %s \nSize of str1: %ld \nSize of str2: %ld", str1,str2, sizeof(str1) ,sizeof(str2));


    printf("\n\ndata1 = ");
    vector_print2(data1, n_of_elements(data1));
    printf("\ndata2 = ");
    vector_print2(data2,n_of_elements(data2));
    printf("\nSize of data1: %d\nSize of data2: %d\n",sizeof(data1), sizeof(data2));
//    char wtest_1[] = "Frase";
//    char wtest_2[] = "Frase";
//    int var1;
//    var1 = strcmp(wtest_1,wtest_2);
//    printf("Teste %d", var1);
    return 0;
}


void vector_print2(int  *array,int size){

    printf("%d",*array);
    array++;
    for(int i= 1 ; i< size; i++)
    {
        printf(", %d",*array);
        array++;
        if (i==30){ //limits the number of printed char
            printf("...");
            break;
        }
    }

}