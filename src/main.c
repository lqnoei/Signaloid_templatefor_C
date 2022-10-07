#include <stdio.h>
#include <uncertain.h>

void printMatrix(int n, double M[n][n+1]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            printf("%lf\t",M[i][j]);
        }
        printf("\n");
    }
}

void  GE_upper(int n, double M[n][n+1], float x[n]){
    
    int i,j,k,C,V;
    
    /*the multiplier*/
    double s;
    
    /*
     elimitation(upper triangular matrix)
     */
    for (i=0;i<n;i++){
        for(j=1+i ; j<n;j++ ){
            s=M[j][i]/M[i][i];
            for (k=0; k<=n;k++ ){
                M[j][k]=M[j][k]-s*M[i][k];
            }
        }
    }
    /*the result of solving the trangular matrix x[n-1] might be zero
     */
    x[n-1]=(M[n-1][n])/(M[n-1][n-1]);
    for (C=n-2;C>=0;C--){
        x[C]=M[C][n];
        for(V=C+1;V<n;V++){
            x[C]=x[C]-(x[V]*M[C][V]);
        }
        x[C]= x[C]/(M[C][C]);
    }
    
}


    
    int
    main(int argc, char *  argv[])
{
        /* get the dimension*/
        int n;
        n=2;

        /*construct a matrix where entries are distributed variables */
        
        double M1[n][n+1];
        M1[0][0]=libUncertainDoubleExponentialDist(10.5);
        M1[0][1]=libUncertainDoubleExponentialDist(10.5);
        M1[1][0]=libUncertainDoubleExponentialDist(10.5);
        M1[1][1]=libUncertainDoubleExponentialDist(20.5);
        M1[0][2]=libUncertainDoubleExponentialDist(20.5);
        M1[1][2]=libUncertainDoubleExponentialDist(30.5);
        /*View the original matrix*/
        printf("The original matrix is:\n");
        printMatrix(n, M1);
        
        /* do the gaussian elimitation*/
        
        float x[n];
        
        GE_upper(n, M1,x);
        printf("The upper triangular matrix is:\n");
        printMatrix(n, M1);
        printf("The printed solution to the equations is:\n");
        int r;
        for (r=0;r<n;r++){
            printf("x[%d]=%lf\t", r, x[r]);
        }


        printf("\nThe expected solution to the equations is:\n");
        double x_E[n];
        int i;
        for (i=0;i<n;i++){
            x_E[i]=libUncertainDoubleNthMoment(x[i],1);
            printf("x[%d]=%lf\t", i, x_E[i]);
        }
    
#ifdef DEBUG
        printf("debug message\n");
#endif
        
        return 0;
    }

