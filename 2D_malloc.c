#include<stdio.h>
#include<stdlib.h>
int main(){
    int r = 3, c = 4;
    int **arr;
    int *brr[r];
    arr = (int **)malloc(r * sizeof(int *));
    for(int i = 0; i < r; i++){
        arr[i] = (int *)malloc(c * sizeof(int));
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            arr[i][j] = i+j;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    /*arr++;
    for(int i = 0; i < r-1; i++){
        for(int j = 0; j < c; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/

    for(int i=0; i < r; i++){
        free(arr[i]);
    }
    free(arr);

    for(int i = 0; i < r; i++){
        brr[i] = (int *)malloc(c * sizeof(int *));
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            brr[i][j] = i+j;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d", brr[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i < r; i++){
        free(brr[i]);
    }
    free(brr);
    return 0;
}