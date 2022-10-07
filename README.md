[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-dark-v6.png#gh-dark-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/signaloid/Signaloid-Demo-General-C#gh-dark-mode-only)
[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-light-v6.png#gh-light-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/signaloid/Signaloid-Demo-General-C#gh-light-mode-only)

# Gaussian Elimitation Algorithm
Gaussian elimitaiton is a method for solving linear equations. Usually, it contains $n$ being-solved variables, $n\times n$ matrix and $n$ vector placed on the right hand side of systems. When considerating it in programming, we abbrievate the matrix and the vector into a matrix with indices $n\times (n+1)$. After applying the gaussian elimitation, we will first get an upper triangular matrix after elementary operations to matrix, and the solution of the system by solving directly the reduced matrix. 

While using Signaloid processor, we are able to see how the uncertainty of the inputs affect the results. We can actually compare it with a matrix with certain data. A brief statement of the observation is that: the reduced upper triangular matrix of uncertain matrix is very near to the true reduced matrix once the inputs data have the expectations which are near to the true data; however, the solution depends highly on the variance of the iputs data, and once the variance is too high, the accuracy decreases largely.

In other words, in order to get a relatively accurate result with implementation on Signaloid platform, it's needed to restrict the expectation and variance of input data: the expectation should be near to the true data and the variance should be small.(Normalization is a good method, we could see examples below.)
## Specific Algorithm of Gaussian Elimitation
1. Keeping the first row $M_{1}$ unchanged, then calculating the multipiliers $s$ of other $n-1$ rows such that the first element of each row becomes zero when we do elementary operation $M_{i}-s_{i}\times M_{1}$.
2. 
3. 

## Repository Structure


### Configuring the Build (`config.mk`)



#### 🎓 Example




### Headers


### Libraries


## 🍰 Accessing Your GitHub Repository from the Signaloid Cloud Developer Platform


### Option 1:  Using the “Add to signaloid.io” Button


### Option 2: Manually Adding Repositories to the Signaloid Cloud Developer Platform

