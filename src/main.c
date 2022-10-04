#include <stdio.h>
#include <uncertain.h>

void readMatrix(int n, double M[n][n+1]){
    int i,j;
for(i=0;i<n;i++){
    for(j=0;j<(n+1);j++){
        printf("M[%d][%d]:", i,j);
        scanf("%d",&M[i][j]);
    }
  }
}

void printMatrix(int n, double M[n][n+1]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%lf\t",matrix[i][j]);
        }
        printf("\n");
    }
}

void double GE_upper(int n, double M[n][n+1], double x[n]){
    
    int i,j,k;
    
    /*the multiplier*/
    double s;
    
    /*
     elimitation(upper triangular matrix)
     */
    for (i=0;i<n;i++){
        for(j=1; j<n;j++ ){
            s=M[j][i]/M[i][i];
            for (k=0; k<n+1;k++ )
            {M[j][k]=M[j][k]-s*M[i][k]
                
            }
        }
    }
    /*the result of solving the trangular matrix x[n-1] might be zero
     */
    double  sum=0.0;
    
    x[n-1]=M[n-1][n]/M[n-1][n-1];
    for (i=n-2;i>=1;i--){
        sum=x[i+1]*M[i][i+1]+sum;
        x[i]= (M[i][n]-sum)/M[i][i]
    }
    
}


int
main(int argc, char *  argv[])
{
	double	a, b, c;

	a = libUncertainDoubleUniformDist(0.5, 1.0);
	printf("a = %lf\n", a);

	b = libUncertainDoubleUniformDist(10.0, 20.0);
	printf("b = %lf\n", b);

	c = (a+b)/(a-b);
	printf("c = %lf\n", c);
	

	    /* get the matrix*/
    int n;
    printf("the dimension of matrix M:");
    scanf("%d",&n );
    
    double M1[n][n+1],M2[n][n+1],x[n];
    
    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
    readMatrix(n,M1[n][n+1])
    int i,j;
        for(i=0;i<n;i++){
            for(j=0;j<(n+1);j++){
                M2[i][j]=M1[i][j];
            }
        }
    }
printf("\nThe original matrix is:\n\n");
printMatrix(n,M2);
GE_upper(n,M1,x);
printf("\nThe upper Triangular matrix after Gaussian Eliminiation is:\n\n");
printMatrix(n.M1);
    
    
    printf("The solution is:\n")
    for (i=0;i<n;i++){
        printf("\nx[%d]=%d\t",i+1,x[i])
    }

#ifdef DEBUG
	printf("debug message\n");
#endif

	return 0;
}

