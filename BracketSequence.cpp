///https://codeforces.com/contest/380/problem/C
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long
#define mod      1000007
#define N        2000005
#define yes      cout<<"Yes"<<endl
#define no      cout<<"No"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
string s;
struct obj
{
    ll open=0,close=0,cnt=0;
};
obj tree[N*4];

void build_tree(ll node,ll b,ll e)
{
    if(b==e)
    {
        if(s[b]=='(')tree[node].open++;
        else tree[node].close++;
        return;
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(b+e)>>1;

    build_tree(left,b,mid);
    build_tree(right,mid+1,e);

    ll common=min(tree[left].open,tree[right].close);

    tree[node].cnt=tree[left].cnt+tree[right].cnt+common;
    tree[node].open=tree[left].open+tree[right].open-common;
    tree[node].close=tree[left].close+tree[right].close-common;
}
obj query(ll node,ll b,ll e,ll i,ll j)
{
    obj res;
    if(j<b || i>e)
    {
        return res;
    }
    if (b>=i && e<=j)
    {
        return tree[node];
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(b+e)>>1;

    obj leftnode=query(left,b,mid,i,j);
    obj rightnode=query(right,mid+1,e,i,j);


    ll common=min(leftnode.open,rightnode.close);

    res.cnt=leftnode.cnt+rightnode.cnt+common;
    res.open=leftnode.open+rightnode.open-common;
    res.close=leftnode.close+rightnode.close-common;
    return res;
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,vector<ll>>mp;
    map<ll,ll>pp;
    ll n,e,i,j,l,m,x,y,z,r,k;
    cin>>s;
    n=s.size();
    build_tree(1,0,n-1);
    cin>>k;
    while(k--)
    {
        cin>>l>>r;
        obj ob=query(1,0,n-1,l-1,r-1);
        ll ans=ob.cnt<<1;
        cout<<ans<<endl;
    }
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}

