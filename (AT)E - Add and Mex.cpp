// USER: "Ab.Mahin"
// Problem: F - Medium 06
// Contest: Virtual Judge - Weekly Contest 10
// URL: https://vjudge.net/contest/577773?fbclid=IwAR22vr0Rn0yu_BuVVy0-Xe8iS_Jom_aD5GrEHQAkmsTVx_qnwkmQgGtX7tM#problem/F
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007


template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Findout buggs:

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

//...................
const ll N = 2e5 + 5;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll n, m;
    cin >> n >> m;
    
    ll ans[m + 1], a[n + 1];
    
    set<ll> v[m + 1];
    
    for(ll i = 1; i <= n; i++){
    	cin >> a[i];
    	
    	ll l = a[i] < 0 ? (a[i] - i + 1) / -i : 1;
    	ll r = a[i] > n ? 1 : min(m + 1, (n - a[i] + i - 1) / i);
    	
    	r = min(r, m + 1);
    	//bug(l, r);
    	for(ll j  = l; j < r; j++){
    		v[j].insert(a[i] + (j * i));
    	}
    }
    
    for(ll i = 0; i <= m; i++){
    	ll cnt = 0;
    	if(v[i].size()){
    	auto it = v[i].begin();
    		while(1){
    			if(cnt == v[i].size() || cnt != *it) break;
    			cnt++;
    			it++;
    		}
    	}
    	ans[i] = cnt;
    }
    
    for(ll i = 1; i <= m; i++) cout << ans[i] << '\n';
    
    
    
    return 0;
}