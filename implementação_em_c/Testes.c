#include<stdio.h>
void mesclar(int *a, int n, int *b, int m, int *c){
    int i = 0;
    int j = 0;
    int k = 0;
    while( k < (n + m)){

        if( i >= n){
            for(; k < (n + m); k++){
                c[k] = b[j];
                j++;
            }
            break;
        } else if( j >= m){
            for(; k < (n + m); k++){
                c[k] = a[i];
                i++;
            }
            break;
        }
        else if(a[i] > b[j]) {
            c[k] = b[j];
            j++;
        } else {
            c[k] = a[i];
            i++;
        }
        k++;
    }
}

int main(){

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 5  };
    int n = 5;
    int m = 3;
    int c[8];
    mesclar(a, n, b, m, c);


    for(int i = 0; i < n + m; i++){
        printf("%d, ", c[i]);
    }

    return 0;
}
