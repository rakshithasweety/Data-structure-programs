#include<stdio.h>
int main()
{
    int matrix[10][10],sparse[50][3];
    int i,j,rows,cols,k=0;
    printf("enter rows and columns:\n");
    scanf("%d %d",&rows,&cols);
    printf("enter matrix elements:\n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("&d",&matrix[i][j]);
}
}
for(i=0;i<rows;i++){
    for(j=0;j<cols;j++){
    if(matrix[i][j]!=0){
sparse[k][0]=i;
sparse[k][1]=j;
sparse[k][2]=matrix[i][j];
k++;
}
}
}
printf("\nSparse matrix (3-tuple representation):\n");
    printf("Row col value\n");
        printf("%d %d %d\n",rows,cols,k);
            for(i=0;i<k;i++){
                printf("%d %d %d\n", sparse[i][0], sparse[i][j], sparse[i][2]);
            }
            return 0;
            }


