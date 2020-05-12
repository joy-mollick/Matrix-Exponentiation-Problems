

/// Time-0.200s

/*
Think about our series F(n)=A + A^2 +A^3 +A^4 +A^5 + ......+ A^n.,where A is a given matrix.
So , F(n+1) = F(n) + A^(n+1) .Our relation becomes F(n) = F(n-1) + A^(n) .
So by expanding A^(n) we can build our matrix sketch like  M X B = A . No , we can't .As the power of every A is different.
So we have to find another way of relation so that we can do it efficiently .

Now think about a number series like    Solve(n)=x + x^2 +x^3......+ x^n , where x is a number 

Here relation can be build recursively like  Solve(n) = ( 1 + x^(n/2) ) * Solve(n/2) . when n is even .Do it by your hand and check .

                                             Solve(n) = ( 1 + x^(n/2) ) *( Solve(n/2) + x^n . when n is odd .
                                                                           
                                                        ----------------------------- +-----
                                             Solve(n)   Solve(n-1)                    + x^n . [ as (n-1)/2 and (n)/2 is same for any odd number (n) that's why for odd n we have to extra x^n to come up with a solution .
                                                                          
    Now we can build our solution of Exact problem equivalently below 
    
                                             Solve(n) = ( I + A^(n/2) ) * Solve(n/2) . when n is even  .

                                             Solve(n) = ( I + A^(n/2) ) *( Solve(n/2) + A^n . when n is odd .
                                                                           
                                                        ----------------------------- +-----
                                             Solve(n)   Solve(n-1)                    + A^n .
                                                                          
    I stated for identity matrix (filled up all diagonals with 1 ) which is equivalent to 1 ,I works as like as (one)1 all time in calculation of matrix . and A is equivalent to our x . 
    We can find A^n and A^(n/2) by using our previous power function of matrix . we have to write another function add for adding I to A^(n/2) . So now we can do it recursively .                                                                       
                                                                                                                   
According to question constraints .

if(k%2==0)
 A+A^2+A^3+.....+A^k = (I+A^(k/2))*(A+A^2+....+A^k/2)
                                                                          
 else
    A+A^2+A^3+.....+A^k = (I+A^(k/2))*(A+A^2+....+A^k/2) + (A^k)
                                                                          
*/

/// Time-0.08s

#include<bits/stdc++.h>

using namespace std;

const int mod = 10;

/// we initialize a structure because we can easily return this from a function after multiplication
 struct matrix {
  int m[41][41];
  int row, column;
};

matrix I;

/// it will d*d*d complexity ,where d is matrix size
matrix mul(matrix a, matrix b) {

  matrix M;/// initialize one
  /// it is pretty easy ,when mul ( a x b ) where a and b is matrix

  M.row = a.row; /// initialize new matrix's row
  M.column = b.column; /// initialize new matrix's column
  for (int i = 0; i < M.row; i++) {
    for (int j = 0; j < M.column; j++) {
            M.m[i][j]=0;
      for (int k = 0; k < a.column;  k++) {
        M.m[i][j]=((M.m[i][j])+((a.m[i][k]) * (b.m[k][j])))%mod;
      }
    }
  }
  return M; /// after multiplication of matrices a and b

}


matrix add( matrix  A, matrix B) {
    matrix res;
    res.row=A.row;
    res.column=A.column;
    for (int i = 0; i < res.row; i++) {
        for (int j = 0; j < res.column; j++) {
            res.m[i][j] = (A.m[i][j] + B.m[i][j])%mod;
        }
    }
    return res;
}


/// Function to compute a raise to power (b+1).
matrix power(matrix a, int b)
{
   matrix ans=a;

    while(b>=1) /// calculating a^b
    {
        if(b&1) ans=mul(ans,a);/// it is nothing but ans*a
        b >>= 1;/// it is more faster than b=b>>1ll;
        a=mul(a,a);/// it is nothing but a*a
    }
    return (ans);/// return result
}


matrix solve(matrix A, int n) {

    if (!n) return I;/// when there is n=0 ,so return identity matrix A^0 = identity matrix like as x^0=1 for any number ,x .

    if (n == 1) return A;/// when n is 1 ,then return the real matrix ,like as x^1 =x ,return x itself .

    matrix ret = add(I ,power( A , (n / 2)-1 )); /// ret = I + (A ^ (n / 2)) .

    ret = mul(ret,solve(A, n / 2));/// ret= ret*solve(A, n / 2) = I + (A ^ (n / 2)) * solve(A, n / 2)
         
    if (n % 2) ret = add(ret ,power( A,n-1 ) ); /// when n is odd ,then  ret = I + (A ^ (n / 2)) * solve(A, n / 2) + A^n

    return ret; /// when n is even , ret =  I + (A ^ (n / 2)) * solve(A, n / 2) .
}



/// Driver code
int main()
{
    matrix a;
    int n,k;
     while (scanf("%d%d", &n, &k) == 2 && n) {
            a.row=a.column=I.row=I.column=n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a.m[i][j]);
                a.m[i][j] %= mod;
                I.m[i][j]=0;
            }
        }
        for(int i=0;i<n;i++) I.m[i][i]=1;
        matrix mat=solve(a, k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                printf("%d ",mat.m[i][j]);
            }
            printf("%d\n", mat.m[i][n - 1]);
        }
        printf("\n");
    }

    return 0;

}
