/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define FILL(arr, val)  memset(arr, val, sizeof(arr))

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

struct Matrix{
    vector< vector<int> > mat; // the contents of matrix as a 2D-vector
    int n_rows, n_cols; // number of rows and columns

    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n){
        // Return I_n - the identity matrix of size n.
        // This function is static, because it creates a new Matrix instance
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const {
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < n_cols; k++) {
                    result[i][j] = (result[i][j] + mat[i][k] * 1ll * other.mat[k][j]) % MOD;
                }
            }
        // Multiply matrices as usual, then return the result as the new Matrix
        return Matrix(result);
    }

    inline bool is_square() const{
        return n_rows == n_cols;
    }
};

Matrix fast_exponentiation(Matrix m, int power){
    assert(m.is_square());
    Matrix result = Matrix::identity_matrix(m.n_rows);

    while(power) {
        if(power & 1)
            result = result * m;
        m = m * m;
        power >>= 1;
    }

    return result;
}

int main(){
    io;
    Matrix M({{1,0,0},
    		  {1,1,1},
    		  {1,1,0}});
    Matrix init({{1,1,0}});
 	int t;
 	cin >> t;
 	while(t--){
 		int n, m;
 		cin >> n >> m;
 		//P(m)-P(n-1)
 		ll ans1, ans2;
 		if(m == 0){
 			cout << 0 << endl;
 		}else{
 			ans1 = (init*fast_exponentiation(M,m-1)).mat[0][0];
 			if(n == 0 || n == 1)
 				cout << ans1%MOD << endl;
 			else{
 				ans2 = (init*fast_exponentiation(M,n-2)).mat[0][0];
 				ll ans = ans1-ans2;
 				if(ans < 0)
 					ans = (ans+MOD)%MOD;
 				cout << ans << endl;
 			}
 		}
 	}   
    return 0;
}