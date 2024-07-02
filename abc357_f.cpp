// USER: "Ab.Mahin"
// Problem: C - From AB
// Contest: Virtual Judge - FSI Contest 04
// URL: https://vjudge.net/contest/633943#problem/C
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define m 998244353

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cout.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

const int N = 2e5 + 5;
int a[N], b[N];
struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) | 1)
  
  long long lazy[2][4 * N], sumA[4 * N],  sumB[4 * N], t[4 * N];
  inline void push(int n, int s, int e) {
  	      	
  	sumA[n] = (sumA[n] + (lazy[0][n] * (e - s + 1)) % m) % m;
  	t[n] = (t[n] + (sumB[n] * lazy[0][n]) % m) % m;
  	
  	sumB[n] = (sumB[n] + (lazy[1][n] * (e - s + 1)) % m) % m;
  	t[n] = (t[n] + (sumA[n] * lazy[1][n]) % m) % m;
    
    if (s != e) {
      lazy[0][lc] = (lazy[0][lc] + lazy[0][n]) % m;
      lazy[0][rc] = (lazy[0][rc] + lazy[0][n]) % m;
      lazy[1][lc] = (lazy[1][lc] + lazy[1][n]) % m;
      lazy[1][rc] = (lazy[1][rc] + lazy[1][n]) % m;
    }
    lazy[0][n] = lazy[1][n] = 0;
  }
  inline long long combine(long long a,long long b) {
    return (a + b) % m;
  }
  inline void pull(int n) {
  	t[n] = (t[lc] + t[rc]) % m;
    sumA[n] = (sumA[lc] + sumA[rc]) % m;
    sumB[n] = (sumB[lc] + sumB[rc]) % m;
  }
  void build(int n, int s, int e) {
    lazy[0][n] = lazy[1][n] = 0;
    if (s == e) {
      sumA[n] = 0;
      sumB[n] = 0;
      t[n] = 0;
      return;
    }
    int mid = (s + e) >> 1;
    build(lc, s, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int s, int e, int i, int j, long long v, int op) {
    push(n, s, e);
    if (j < s || e < i) return;
    if (i <= s && e <= j) {
      lazy[op][n] = (lazy[op][n] + v) % m; //set lazy
      push(n, s, e);
      return;
    }
    int mid = (s + e) >> 1;
    upd(lc, s, mid, i, j, v, op);
    upd(rc, mid + 1, e, i, j, v, op);
    pull(n);
  }
  long long query(int n, int s, int e, int i, int j) {
  	push(n, s, e);
    if (i > e || s > j) return 0; //return null
    if (i <= s && e <= j) return t[n];
    int mid = (s + e) >> 1;
    return combine(query(lc, s, mid, i, j), query(rc, mid + 1, e, i, j));
  }
};
int32_t main() {
    int n, q;
    cin >> n >> q;
    
    ST T;
    T.build(1, 1, n);
    
    for(int i = 1; i <= n; i++) cin >> a[i], T.upd(1, 1, n, i, i, a[i], 0);
    for(int i = 1; i <= n; i++) cin >> b[i], T.upd(1, 1, n, i, i, b[i], 1);
    
    
    while(q--){
    	int op;
    	cin >> op;
    	if(op <= 2){
    		op--;
    		int l, r, val;
    		cin >> l >> r >> val;
    		T.upd(1, 1, n, l, r, val, op);
    	}
    	else{
    		int l, r;
    		cin >> l >> r;
    		
    		long long int ans = T.query(1, 1, n, l, r) % m;
    		cout << ans << '\n';
    	}
    }
    
    
}