
/*
Here after some work on paper for finding pattern , G(n) = fib(2*n) x fib(2*n+1) .
So , here you can find the value of fib(2*n) and fib(2*n+1) separately .
But , you can optimize it by finding the matrix power for fib(2*n+2) ,because it is actually summation of fib(2*n) + fib(2*n+1) .
So ,then you can find matrix power for fib(2*n+2) and multiply m[0][0]*m[0][1] which in turn means fib(2*n) x fib(2*n+1)
*/

/// Time-0.08s

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const ll mod = 1000000007;

/// we initialize a structure because we can easily return this from a function after multiplication
 struct matrix {
  ll m[2][2];
  int row, column;
};

/// it will d*d*d complexity ,where d is matrix size
matrix mul(matrix a, matrix b) {

  matrix M;/// initialize one
  /// it is pretty easy ,when mul ( a x b ) where a and b is matrix

  M.row = a.row; /// initialize new matrix's row
  M.column = b.column; /// initialize new matrix's column
  for (int i = 0; i < M.row; i++) {
    for (int j = 0; j < M.column; j++) {
            M.m[i][j]=0ll;
      for (int k = 0; k < a.column;  k++) {
        M.m[i][j]=((M.m[i][j])+((a.m[i][k]%mod) * (b.m[k][j]%mod)%mod))%mod;
      }
    }
  }
  return M; /// after multiplication of matrices a and b

}


/// Function to compute a raise to power (b+1).
matrix power(matrix a, ll b)
{
   matrix ans=a;

    while(b>=1ll) /// calculating a^b
    {
        if(b&1ll) ans=mul(ans,a);/// it is nothing but ans*a
        b >>= 1ll;/// it is more faster than b=b>>1ll;
        a=mul(a,a);/// it is nothing but a*a
    }
    return (ans);/// return result
}


/// Driver code
int main()
{
    matrix a;
    ll n;
    int k;
    int tc;
    scanf("%d",&tc);
    int caso=1;
    ll ans1,ans2,N,ans;
   while(tc--)
   {
       scanf("%llu",&n);
       N=n;
       if(n<=1ll) {printf("2\n");continue;}
       n=(2ll*n)+2ll;/// fib(2n+2)=fib(2n+1)+fib(2n) ,so find fib(2n+2) 
       a.row=a.column=2;
       a.m[0][0]=a.m[0][1]=a.m[1][0]=1ll;
       a.m[1][1]=0ll;
       matrix mat=power(a,n-3ll);/// it returns a^(n-2)
       ans=((mat.m[0][0]%mod)*(mat.m[0][1]%mod))%mod;
       printf("%llu\n",ans);
   }
   return 0;
}
