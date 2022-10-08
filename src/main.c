#include <stdio.h>
#include <uncertain.h>

void printSolution(int n, float x[n]){
    int r;
    for (r=0;r<n;r++){
        printf("x[%d]=%lf\t", r, x[r]);
    }
}



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

        /*There would be 7 matrices in total */
        double M1[n][n+1],M2[n][n+1],M3[n][n+1],M4[n][n+1],M5[n][n+1],M6[n][n+1],M7[n][n+1];
        float x1[n],x2[n], x3[n],x4[n],x5[n],x6[n],x7[n];

        /*construct a matrix with certain data as control unit*/
       M1[0][0]=1;
       M1[0][1]=1;
       M1[1][0]=1;
       M1[1][1]=2;
       M1[0][2]=2;
       M1[1][2]=3;
       printf("The control unit is:\n");
       printMatrix(n, M1);
       GE_upper(n, M1,x1);
       printf("The upper triangular matrix is:\n");
       printMatrix(n, M1);

       printf("The solution to the equations is:\n");
       printSolution(n,x1);

        /*construct matrices where entries are distributed variables */

        /*Uniform distributed with low variance*/
       M2[0][0]=libUncertainDoubleUniformDist(0.90,1.10);
       M2[0][1]=libUncertainDoubleUniformDist(0.90,1.10);
       M2[1][0]=libUncertainDoubleUniformDist(0.90,1.10);
       M2[1][1]=libUncertainDoubleUniformDist(1.90,2.10);
       M2[0][2]=libUncertainDoubleUniformDist(1.90,2.10);
       M2[1][2]=libUncertainDoubleUniformDist(2.90,3.10);

       printf("\nThe Matrix with entries in uniform distribution data(low variance) is:\n");
       printMatrix(n, M2);
       GE_upper(n, M2,x2);
       printf("The upper triangular matrix is:\n");
       printMatrix(n, M2);
       printf("The solution to the equations is:\n");
       printSolution(n,x2);
        
        /*Uniform distributed with high variance*/
       M3[0][0]=libUncertainDoubleUniformDist(0.50,1.50);
       M3[0][1]=libUncertainDoubleUniformDist(0.50,1.50);
       M3[1][0]=libUncertainDoubleUniformDist(0.50,1.50);
       M3[1][1]=libUncertainDoubleUniformDist(1.50,2.50);
       M3[0][2]=libUncertainDoubleUniformDist(1.50,2.50);
       M3[1][2]=libUncertainDoubleUniformDist(2.50,3.50);

       printf("\nThe Matrix with entries in uniform distribution data(high variance) is:\n");
       printMatrix(n, M3);
       GE_upper(n, M3,x3);
       printf("The upper triangular matrix is:\n");
       printMatrix(n, M3);
       printf("The solution to the equations is:\n");
       printSolution(n,x3);
        
           /*Gaussian distributed with low variance*/
       M4[0][0]=libUncertainDoubleGaussDist(1.0,0.1);
       M4[0][1]=libUncertainDoubleGaussDist(1.0,0.1);
       M4[1][0]=libUncertainDoubleGaussDist(1.0,0.1);
       M4[1][1]=libUncertainDoubleGaussDist(2.0,0.1);
       M4[0][2]=libUncertainDoubleGaussDist(2.0,0.1);
       M4[1][2]=libUncertainDoubleGaussDist(3.0,0.1);

       printf("\nThe Matrix with entries in Gaussian distribution data(low variance) is:\n");
       printMatrix(n, M4);
       GE_upper(n, M4,x4);
       printf("The upper triangular matrix is:\n");
       printMatrix(n, M4);
       printf("The solution to the equations is:\n");
       printSolution(n,x4);
        

             /*Gaussian distributed with high variance*/
       M5[0][0]=libUncertainDoubleGaussDist(1.0,0.8);
       M5[0][1]=libUncertainDoubleGaussDist(1.0,0.8);
       M5[1][0]=libUncertainDoubleGaussDist(1.0,0.8);
       M5[1][1]=libUncertainDoubleGaussDist(2.0,0.8);
       M5[0][2]=libUncertainDoubleGaussDist(2.0,0.8);
       M5[1][2]=libUncertainDoubleGaussDist(3.0,0.8);

       printf("\nThe Matrix with entries in Gaussian distribution data(high variance) is:\n");
       printMatrix(n, M5);
       GE_upper(n, M5,x5);
       printf("The upper triangular matrix is:\n");
       printMatrix(n, M5);
       printf("The solution to the equations is:\n");
       printSolution(n,x5);

        /*Exponential distribution with low variance*/
       M6[0][0]=libUncertainDoubleExponentialDist(1.0);
       M6[0][1]=libUncertainDoubleExponentialDist(1.0);
       M6[1][0]=libUncertainDoubleExponentialDist(1.0);
       M6[1][1]=libUncertainDoubleExponentialDist(2.0);
       M6[0][2]=libUncertainDoubleExponentialDist(2.0);
       M6[1][2]=libUncertainDoubleExponentialDist(3.0);

       printf("\nThe Matrix with entries in exponential distribution data(low variance) is:\n");
       printMatrix(n, M6);
       GE_upper(n, M6,x6);
       printf("The upper triangular matrix is:\n");
       printMatrix(n, M6);
       printf("The solution to the equations is:\n");
       printSolution(n,x6);

         /*Exponential distribution with high variance*/
       M7[0][0]=libUncertainDoubleExponentialDist(10.0);
       M7[0][1]=libUncertainDoubleExponentialDist(10.0);
       M7[1][0]=libUncertainDoubleExponentialDist(10.0);
       M7[1][1]=libUncertainDoubleExponentialDist(20.0);
       M7[0][2]=libUncertainDoubleExponentialDist(20.0);
       M7[1][2]=libUncertainDoubleExponentialDist(30.0);

       printf("\nThe Matrix with entries in exponential distribution data(high variance) is:\n");
       printMatrix(n, M7);
       GE_upper(n, M7,x7);
       printf("The upper triangular matrix is:\n");
       printMatrix(n, M7);
       printf("The solution to the equations is:\n");
       printSolution(n,x7);
        
       
#ifdef DEBUG
        printf("debug message\n");
#endif
        
        return 0;
    }
