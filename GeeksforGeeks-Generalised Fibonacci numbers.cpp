
/// Time-0.01s


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
    ll n,A,b,c,tc;
    matrix a;
       /// Initialize     with   | a b 1|                   |f(n-1)|                  | f(n)   |         
      ///                        | 1 0 0| as multiply it by |f(n-2)|                  | f(n-1) |
      ///                        | 0 0 1|                   | c    | will be equal to | c      | 
      cin>>tc;
   while(tc--)
   {
       cin>>A>>b>>c>>n>>mod;
        a.row = a.column = 3;
       a.m[0][0] = A ;a.m[0][1] =b; a.m[1][0] = 1;a.m[0][2] =1; a.m[2][2] =1 ;
        a.m[1][1] = a.m[1][2] = a.m[2][0] = a.m[2][1] =0 ;
       matrix mat=power(a,n-3); /// it returns a^(n-2)
       ll res=(mat.m[0][0]%mod)+(mat.m[0][1]%mod)+(c*(mat.m[0][2]%mod))%mod;
       res=res%mod;
       cout<<res<<endl;
   }
   return 0;
}
