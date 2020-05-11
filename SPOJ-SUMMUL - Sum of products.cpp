
/// Time-0.00s
///It is nothing but , after doing some patterns .You will get ans(n)=fib(2*n)-n. Now use matrix exponentiation .Nice one .


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    ll ans,N;
   while(tc--)
   {
       scanf("%lld",&n);
       N=n;
       ans=0ll;
       if(n<=1ll) {printf("0\n");continue;}
       n=2ll*n;
       a.row=a.column=2;
       a.m[0][0]=a.m[0][1]=a.m[1][0]=1ll;
       a.m[1][1]=0ll;
       matrix mat=power(a,n-3ll);/// it returns a^(n-2)
       ans=(mat.m[0][0]%mod+mat.m[0][1]%mod)%mod;
       ///cout<<mat.m[0][0]<<" "<<mat.m[0][1]<<" "<<ans<<endl;
       ans=((ans-N)%mod+mod)%mod;
       printf("%lld\n",ans);
   }
   return 0;
}
