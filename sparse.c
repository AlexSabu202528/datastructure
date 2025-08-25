#include <stdio.h>

int main()
{
    int row1, colm1, row2, colm2;
    int mat1[10][10], mat2[10][10];
    int spar1[100][3], spar2[100][3], sparResult[200][3];
    int sparTranspose[200][3];
    int i, j, k;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &row1, &colm1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &row2, &colm2);
    if (row1 != row2 || colm1 != colm2)
    {
        printf("Matrices must have the same dimensions for addition.\n");
        return 0;
    }
    printf("Enter elements of first matrix:\n");
    for(i = 0; i < row1; i++)
        for(j = 0; j < colm1; j++)
            scanf("%d", &mat1[i][j]);
    printf("Enter elements of second matrix:\n");
    for(i = 0; i < row2; i++)
        for(j = 0; j < colm2; j++)
            scanf("%d", &mat2[i][j]);
    k = 0;
    for(i = 0; i < row1; i++)
    {
        for(j = 0; j < colm1; j++)
        {
            if(mat1[i][j] != 0)
            {
                spar1[k][0] = i;
                spar1[k][1] = j;
                spar1[k][2] = mat1[i][j];
                k++;
            }
        }
    }
    int nonZero1 = k;
    k = 0;
    for(i = 0; i < row2; i++)
    {
        for(j = 0; j < colm2; j++)
        {
            if(mat2[i][j] != 0)
            {
                spar2[k][0] = i;
                spar2[k][1] = j;
                spar2[k][2] = mat2[i][j];
                k++;
            }
        }
    }
    int nonZero2 = k;
    int p1 = 0, p2 = 0, p3 = 0;
    while(p1 < nonZero1 && p2 < nonZero2)
    {
        int r1 = spar1[p1][0], c1 = spar1[p1][1];
        int r2 = spar2[p2][0], c2 = spar2[p2][1];

        if(r1 < r2 || (r1 == r2 && c1 < c2))
        {
            sparResult[p3][0] = r1;
            sparResult[p3][1] = c1;
            sparResult[p3][2] = spar1[p1][2];
            p1++; p3++;
        }
        else if(r2 < r1 || (r1 == r2 && c2 < c1))
        {
            sparResult[p3][0] = r2;
            sparResult[p3][1] = c2;
            sparResult[p3][2] = spar2[p2][2];
            p2++; p3++;
        }
        else
        {
            int sum = spar1[p1][2] + spar2[p2][2];
            if(sum != 0)
            {
                sparResult[p3][0] = r1;
                sparResult[p3][1] = c1;
                sparResult[p3][2] = sum;
                p3++;
            }
            p1++; p2++;
        }
    }
    while(p1 < nonZero1)
    {
        sparResult[p3][0] = spar1[p1][0];
        sparResult[p3][1] = spar1[p1][1];
        sparResult[p3][2] = spar1[p1][2];
        p1++; p3++;
    }

    while(p2 < nonZero2)
    {
        sparResult[p3][0] = spar2[p2][0];
        sparResult[p3][1] = spar2[p2][1];
        sparResult[p3][2] = spar2[p2][2];
        p2++; p3++;
    }
    printf("\nResultant Sparse Matrix (row col value):\n");
    for(i = 0; i < p3; i++)
    {
        printf("%d %d %d\n", sparResult[i][0], sparResult[i][1], sparResult[i][2]);
    }
    for(i = 0; i < p3; i++)
    {
        sparTranspose[i][0] = sparResult[i][1]; 
        sparTranspose[i][1] = sparResult[i][0];
        sparTranspose[i][2] = sparResult[i][2];
    }
    printf("\nTranspose of Resultant Sparse Matrix (row col value):\n");
    for(i = 0; i < p3; i++)
    {
        printf("%d %d %d\n", sparTranspose[i][0], sparTranspose[i][1], sparTranspose[i][2]);
    }

    return 0;
}
