
/// Time-0.08s

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const ll mod = 1000000007;

/// we initialize a structure because we can easily return this from a function after multiplication
 struct matrix {
  ll m[3][3];
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
        M.m[i][j]=((M.m[i][j])+((a.m[i][k]) * (b.m[k][j]))%mod)%mod;
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
    ll n,k;
    scanf("%llu",&n);
     if(n==1)
        printf("2\n");
    else if(n==2)
        printf("3\n");
    else if(n==3)
        printf("4\n");
        else{
    a.row=a.column=3;
    a.m[0][0]=a.m[0][2]=a.m[1][0]=a.m[2][1]=1ll;
    a.m[0][1]=a.m[1][1]=a.m[1][2]=a.m[2][0]=a.m[2][2]=0ll;
    matrix mat=power(a,n-4);/// return a^(n-3)
    /// f(3)=4,f(2)=3,f(1)=2
    ll res=(4ll*mat.m[0][0]+3ll*mat.m[0][1]+2ll*mat.m[0][2])%mod;
    printf("%llu\n",res);
        }
    return 0;

}
