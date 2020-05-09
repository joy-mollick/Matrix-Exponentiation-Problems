
/// Time - 0.927s
/// Classical One 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

 ll mod;


/// we initialize a structure because we can easily return this from a function after multiplication
 struct matrix {
  ll m[6][6];
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

       | a1  b1  0   0   0   c1|    | f(n-1) |   | f(n)   |
       |  1   0  0   0   0   0 |    | f(n-2) |   | f(n-1) |
       |  0   1  0   0   0   0 | X  | f(n-3) | = | f(n-2) | ,we have to find the value of f(n) and g(n) from here.Now this problem is nothing but an easy one !!.
       |  0   0  c2  a2  b2  0 |    | g(n-1) |   | g(n)   |
       |  0   0  0   1   0   0 |    | g(n-2) |   | g(n-1) |
       |  0   0  0   0   1   0 |    | g(n-3) |   | g(n-2) |

*/

/// Driver code
int main()
{
    ll a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2,m,tc,q,n;
    matrix a;
    cin>>tc;
    int caso=0;
   while(tc--)
   {
       caso++;
      cin>>a1>>b1>>c1;
      cin>>a2>>b2>>c2;
      cin>>f0>>f1>>f2;
      cin>>g0>>g1>>g2;
      cin>>m;
      mod=m;
      ll extra[6]={f2,f1,f0,g2,g1,g0};
      ll f[3]={f0,f1,f2};
      ll g[3]={g0,g1,g2};
      a.row=a.column=6;
      for(int i=0;i<6;i++) for(int j=0;j<6;j++) a.m[i][j]=0;///fill with zeros
      a.m[0][0]=a1;a.m[0][1]=b1;a.m[0][5]=c1;
      a.m[3][2]=c2;a.m[3][3]= a2;a.m[3][4]=b2 ;
      for(int i=1;i<6;i++) {if(i!=3) {a.m[i][i-1]=1ll;}}/// fill up rest diagonal by 1
       ll res1=0ll;
       ll res2=0ll;
       cin>>q;
       cout<<"Case "<<caso<<":"<<endl;
       while(q--)
       {
           cin>>n;
           res1=0ll;res2=0ll;
           if(n<3) {cout<<(f[n]%mod)<<" "<<(g[n]%mod)<<endl;continue;}
           matrix mat=power(a,n-3);/// it returns a^(n-2)
           for(int i=0;i<6;i++) {res1=(res1+((mat.m[0][i]*extra[i])%mod))%mod;}
           for(int i=0;i<6;i++) {res2=(res2+((mat.m[3][i]*extra[i])%mod))%mod;}
           cout<<res1<<" "<<res2<<endl;
       }
   }
   return 0;
}
