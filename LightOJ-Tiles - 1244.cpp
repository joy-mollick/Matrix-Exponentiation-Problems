
/// Time - 1.532s
/// Classical One and Not Easy One 
/// You have to do some work on this 

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

 ll mod=10007;


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

       |  1   1  1   1  |    | f(n-1) |   | f(n)   |
       |  1   0  0   0  |    | f(n-2) |   | f(n-1) |
       |  0   1  0   1  | X  | g(n-1) | = | g(n)   | ,we have to find the value of f(n) .
       |  0   1  1   0  |    | h(n-1) |   | h(n)   |
*/

/// Driver code
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,tc,ans;
    matrix a;
    cin>>tc;
    int caso=0;
   while(tc--)
   {
       caso++;
      a.row=a.column=4;
      for(int i=0;i<4;i++) for(int j=0;j<4;j++) a.m[i][j]=1ll;///fill with ones
      a.m[1][1]=a.m[1][2]=a.m[1][3]=0ll;
      a.m[2][0]=a.m[2][2]=0ll;
      a.m[3][0]=a.m[3][3]=0ll;
      cin>>n;
      if(n == 1) ans = 1;
      else if(n == 2) ans = 2;
      else{
      matrix mat=power(a,n-3);/// it return a^(n-2)
      /// f(2) is 2 , f(1) is 1 , g(2) is 1 , h(2) is 1 ,so multiply this with obtained matrix and take summation of these 
      ans=(mat.m[0][0]*2ll)%mod+(mat.m[0][1])%mod+mat.m[0][2]%mod+mat.m[0][3]%mod;
      ans=ans%mod;}
      cout<<"Case "<<caso<<": "<<ans<<endl;
   }
   return 0;
}
