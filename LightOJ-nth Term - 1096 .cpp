
/// Time - 0.004s

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod=10007ll;


/// we initialize a structure because we can easily return this from a function after multiplication
 struct matrix {
  ll m[4][4];
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
            M.m[i][j]=0;
      for (int k = 0; k < a.column;  k++) {
        M.m[i][j]=((M.m[i][j]%mod)+((a.m[i][k]%mod) * (b.m[k][j]%mod))%mod)%mod;
      }
    }
  }
  return M; /// after multiplication of matrices a and b

}


/// Function to compute a raise to power (b+1).
matrix power(matrix a, int b)
{
   matrix ans=a;/// Initialize ans with   | 1 1 |
               ///                        | 1 0 | that's why it returns a^(b+1) ,as ans is initialized with already a

    while(b>=1) /// calculating a^b
    {
        if(b&1) ans=mul(ans,a);/// it is nothing but ans*a
        b=b>>1;
        a=mul(a,a);/// it is nothing but a*a
    }
    return (ans);/// return result
}

/*

| a  b  1 |   |(f(n-1))|   | f(n)   |
| 1  0  0 | x |(f(n-2))| = | f(n-1) |
| 0  0  1 |   |  c     |   |    c   |
*/

/// Driver code
int main()
{
    ll n,A,b,tc,m,c;
    matrix a;
    cin>>tc;
    int caso=0;
   while(tc--)
   {
       caso++;
       cin>>n>>A>>b>>c;
        a.row = a.column = 4;
        for(int i=0;i<a.row;i++) for(int j=0;j<a.column;j++) a.m[i][j]=0ll;/// initialize with zero
       a.m[0][0] = A%mod ; a.m[0][2] = b%mod;a.m[0][3]=1;
       for(int i=1;i<3;i++) a.m[i][i-1]=1ll;/// diagonally 1 without last row
       a.m[3][3]=1ll;/// it is for adjusting c constant
        if (n <=2)
        {
          cout<<"Case "<<caso<<": ";
          cout<<"0"<<endl;continue;
        }
       matrix mat=power(a,n-3); /// it returns a^(n-2)
       ll res=(mat.m[0][3]*c);
       res=(res)%mod;
       cout<<"Case "<<caso<<": ";
       cout<<res<<endl;
   }
   return 0;
}
