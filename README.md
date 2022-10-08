[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-dark-v6.png#gh-dark-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/signaloid/Signaloid-Demo-General-C#gh-dark-mode-only)
[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-light-v6.png#gh-light-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/signaloid/Signaloid-Demo-General-C#gh-light-mode-only)

# Gaussian Elimitation Algorithm
Gaussian elimitaiton is a method for solving linear equations. Usually, it contains $n$ being-solved variables, $n\times n$ matrix and $n$ vector placed on the right hand side of systems. When considerating it in programming, we abbrievate the matrix and the vector into a matrix with indices $n\times (n+1)$. After applying the gaussian elimitation, we will first get an upper triangular matrix after elementary operations to matrices, and the solution of the system by solving directly the reduced matrix. 

To see the accuracy of the results obtained by C0 processor, we can actually compare it with a matrix with certain data. A brief statement of the observation is that: the reduced upper triangular matrix of uncertain matrix is very near to the true reduced matrix once the inputs data have the expectations which are near to the true data; however, the solution of equations depends on the distribution of inputs data.

In other words, in order to get a relatively accurate result with implementation on Signaloid platform, it's needed to restrict the expectation and variance of input data: the expectation should be near to the true data and the variance should be small.
## Specific Algorithm of Gaussian Elimitation
### Obtaining the Reduced Upper Triangular Matrix
1. Keeping the first row $M_{1}$ unchanged, then calculate the multipiliers $s_{i}$ of other $n-1$ rows such that the first element of each row becomes zero when we do elementary operation $M_{i}-s_{i}\times M_{1}$.
2. Starting again form the second row where the first element has already been reduced to zero, then calculate the multipiliers $s_{j}$ of other $n-2$ rows such that the second element of each row becomes zero when we do elementary operations as before.
3. Iterate the above procedure until all the elements below $M_{i,i},i=1,2,\dots, n$ are zero.


### Getting the Solution by Operating Directly on the Reduced Matrix
1. For convenience, $M^{* }$ is denoted to be the reduced upper triangular matrix. At the first step, we could easily get the last element of solution $x_{n}$ by inserting $x_{n}=\frac{M_{n,n+1}^{* }}{M_{n,n}^{* }}$.
2. Then, we substitute $x_{n}$ to its original place at the $(n-1)th$ row of $M^{* }$ and calculate $x_{n-1}$.
3. Again, iterating the above procedures could get all the elements in solution.

## Experiments 
### the Control Unit
To better understand the performance of Signaloid C0 processor, a simple 2-dimensional linear equation systems is chosen to be the control unit.
1,1,2;1,2,3
with its solution 1,1

The control unit is:
1.000000	1.000000	2.000000	
1.000000	2.000000	3.000000	
The upper triangular matrix is:
1.000000	1.000000	2.000000	
0.000000	1.000000	1.000000	
The solution to the equations is:
x[0]=1.000000	x[1]=1.000000	

verify the correctness of GE alg.

### Uniform Distribution Entries

#### Expectation Near to the True Data and Low Variance
#### Expectation Near to the True Data and High Variance

### Gaussian Distribution Entries

#### Expectation Near to the True Data and Low Variance
#### Expectation Near to the True Data and High Variance

### Exponential Distribution Entries

#### Expectation Near to the True Data and Low Variance
#### Expectation Near to the True Data and High Variance



