#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"
int main()
{
    MATRIX* mat;
    mat = createMat(3, 4);
    setMatrix(mat);
    printMat(mat);
    printf("Hello world!\n");
    return 0;
}
