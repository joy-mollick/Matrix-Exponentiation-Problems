
/// Time-0.100s
/// Easy One
/// Just Implementation 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod;


/// we initialize a structure because we can easily return this from a function after multiplication
 struct matrix {
  ll m[17][17];/// k can be maximum 21
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
        M.m[i][j]=((M.m[i][j]%mod)+((a.m[i][k]%mod) * (b.m[k][j]%mod)));
        M.m[i][j]%=mod;
      }
    }
  }
  return M; /// after multiplication of matrices a and b

}


/// Function to compute a raise to power (b+1).
matrix power(matrix a, int b)
{
   matrix ans=a;/// Initialize with a ,that's why it returns a^(b+1) ,as ans is initialized with already a

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,A,b,tc,m,k,d;
    matrix a;

   while( cin>>d>>n>>m && (d!=0 && n!=0 && m!=0) )
   {
        mod=m;
        ll arr[d]; /// this array holds the value of the multiplication constant.
        ll f[d]; /// this array holds the value of the recurrence array element.
        for(int i=0;i<d;i++)   {cin>>arr[i];arr[i]=(arr[i]%m)+m;arr[i]%=m;}
        for(int i=0;i<d;i++)   {cin>>f[i];f[i]=(f[i]%m)+m;f[i]%=m;}
        if(n <= d) { /// if n is below than k there is no effect of c constant ,so answer is arr[n].
            cout<< f[n-1]<<endl;
            continue;
        }
        a.row = a.column = d;///  row and column will be (k+1) and (k+1)

        for(int i=0;i<d;i++) for(int j=0;j<d;j++) a.m[i][j]=0ll;/// fill with zeros

        for(int i=0;i<d;i++) a.m[0][i]=arr[i];/// first row with constant c array

        for(int i=1;i<d;i++) a.m[i][i-1]=1ll;/// place diagonally 1 in matrix with also last row,there is no extra constant in this recurrence

       matrix mat=power(a,(n-d)-1); /// it returns a^(n-d) , here , here first d elements of f elements from 1 index ,so n-(d) should be power
       ll res=0ll;
       for(int i=0;i<d;i++) {res=(res+(f[d-i-1]*mat.m[0][i])%mod)%mod;}
       cout<<res<<endl;
   }
   return 0;
}
