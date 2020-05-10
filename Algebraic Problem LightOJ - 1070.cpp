

/// Time-0.114s
/// Nice one problem 

#include<bits/stdc++.h>

using namespace std;

typedef  unsigned long long ll;

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
            M.m[i][j]=0;
      for (int k = 0; k < a.column;  k++) {
        M.m[i][j]=((M.m[i][j])+((a.m[i][k]) * (b.m[k][j])));
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
    This can be easily seen that  f(n)= a^n+b^n=(a^n-1 + b^n-1 )*(a+b) -ab(a^n-2 +b^n-2 )
                                               = ( fn-1) *(a+b) -ab*(fn-2) ,where first term of f i.e. f1 is (a+b) and f0 is 1+1 =2

                                               |a_plus_b   -a_mul_b |   | fn-1 | = | fn   |
                                               |   1            0   | X | fn-2 |   | fn-1 |

*/

/// Driver code
int main()
{
    ll a_plus_b,a_mul_b,n;
    ll res;
    int tc;
    matrix a;
    cin>>tc;
    int caso=0;
   while(tc--)
   {
       caso++;
       cin>>a_plus_b>>a_mul_b>>n;
       if(n<1ll) res = 2ll;
       else if(n == 1ll) res = a_plus_b;
       else{
       a.row=a.column=2;
       a.m[0][0]=a_plus_b;a.m[0][1]=-a_mul_b;
       a.m[1][0]=1ll; a.m[1][1]=0ll;
       matrix mat=power(a,n-2); /// It returns a^(n-1)
       res=mat.m[0][0]*a_plus_b+mat.m[0][1]*2ll;
       }
       printf("Case %d: %llu\n",caso,res);
   }
}
