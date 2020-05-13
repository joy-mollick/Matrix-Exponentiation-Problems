
/// Time - 0.359s

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod;


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
    ll n,A,b,tc,m;
    matrix a;
    cin>>tc;
    int caso=1;
       /// Initialize     with   | a b |                   |f(n-1)|                   | f(n)   | where a and b will be equal to 1 and 1 and f(n-1) f1 and f(n-2) f0 will be given b and a,so end fo that means ,we have to find out the power (n-1) instead of (n-2)
      ///                        | 1 0 | as multiply it by |f(n-2)| will be equal to  | f(n-1) |
      ///
   while(tc--)
   {
       cin>>A>>b>>n>>m;
       mod=1ll;
       for(int i=0;i<m;i++) mod*=10ll;/// when you want to find last digit only , you take mod of ten only .so  it's(m digits) nothing but taking mod of taking m zero ended after 1
        a.row = a.column = 2;
       a.m[0][0] = 1 ;a.m[0][1] =1; a.m[1][0] = 1;
        a.m[1][1] = 0;
        if (n <2)
        {
      if (n == 0) { cout << A << endl;}
      if (n == 1) {cout << b << endl; }
        }
       matrix mat=power(a,n-2); /// it returns a^(n-1)
       ll res=(b*mat.m[0][0]%mod)+(A*mat.m[0][1]%mod);
       res=(res)%mod;
       cout<<"Case "<<caso<<": ";
       cout<<res<<endl;
       caso++;
   }
   return 0;
}
