
/// Time-0.000s
/// Nice one 

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

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
        M.m[i][j]=((M.m[i][j])+((a.m[i][k]) * (b.m[k][j])));
        if(M.m[i][j]>=mod) M.m[i][j]%=mod;
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

/*
 Think about the recurrence relation and do some work paper on this problem .


*/

/// Driver code
int main()
{
    matrix a;
    a.row=a.column=2;
    a.m[0][0]=a.m[0][1]=a.m[1][0]=1ll;
    a.m[1][1]=0ll;
    int tc;
    ll n,M;
    scanf("%d",&tc);
    while(tc--){
    scanf("%llu%llu",&n,&M);
    mod=1ll<<M;
    n=n+1ll;
    matrix mat=power(a,n-3);/// return a^(n-2)
    ll res=(mat.m[0][0]+mat.m[0][1])%mod;
    printf("%llu\n",res);
        }
    return 0;

}
