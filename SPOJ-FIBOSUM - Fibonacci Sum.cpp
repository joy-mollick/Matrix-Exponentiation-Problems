
/// Time-0.02s
/*

Here ,we have to find the summation of fib(i++) till N from i=0 ,called fibsum(N) .
Now think about we have find out fibsum(6)=fib(0)+fib(1)+fib(2)+fib(3)+fib(4)+fib(5)+fib(6)
                   fibsum(6)+fib(1)=fib(0)+fib(1)+fib(1)+fib(2)+fib(3)+fib(4)+fib(5)+fib(6) .
                   fibsum(6)+fib(1)=fib(1)+fib(2)+fib(2)+fib(3)+fib(4)+fib(5)+fib(6) 
                   fibsum(6)+fib(1)=fib(3)+fib(2)+fib(3)+fib(4)+fib(5)+fib(6) 
                                   =fib(4)+fib(3)+fib(4)+fib(5)+fib(6)
                                   =fib(5)+fib(4)+fib(5)+fib(6)
                                   =fib(6)+fib(5)+fib(6)
                                   =fib(7)+fib(6)
                                   =fib(8)
                                   
                      fibsum(6) = fib(8)-fib(1) = fib(8)-1 .           
                      fibsum(n) = fib(n+2)-1. It is our desired formula.
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

 ll mod;

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
        M.m[i][j]=((M.m[i][j])+((a.m[i][k]%mod) * (b.m[k][j]%mod))%mod)%mod;
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

ll fibsum(ll n,matrix &a)
{
    if(n<=0) return 0;
    if(n==1) return 1;

    n=n+2ll;
    matrix mat = power(a,n-3ll);/// returning a^(n-2)
    return (((mat.m[0][0]+mat.m[0][1]-1)%mod)+mod)%mod;
}

/// Driver code
int main()
{
    matrix a;
    a.row=a.column=2;
    a.m[0][0]=a.m[0][1]=a.m[1][0]=1ll;
    a.m[1][1]=0ll;
    int tc;
    ll N,M;
    mod=1000000007ll;
    scanf("%d",&tc);
    while(tc--){
    scanf("%lld%lld",&N,&M);
    ll fibsum_M=fibsum(M,a);
    ll fibsum_N_minus_1=fibsum(N-1ll,a);
    ll ans=(((fibsum_M-fibsum_N_minus_1)%mod)+mod)%mod;
    printf("%lld\n",ans);
        }
    return 0;

}
