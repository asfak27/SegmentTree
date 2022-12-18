///lazy propagation used to update range to lase time complexity
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long
#define mod      1000007
#define N        10005
#define yes      cout<<"Yes"<<endl
#define no      cout<<"No"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll arr[N];
struct info{
    ll prop,sum;
}tree[N*4]; ///tree array
///info tree[N*4];
///initilization tree array
void init(ll node,ll b,ll e)///b=begin node,e=end node
{
    if(b==e)
    {
        tree[node].sum=arr[b];
        return;
    }
    ll leftnode = node*2;///indexing child left and right node
    ll rightnode = node*2+1;
    ll mid = (b+e)/2;
    init(leftnode,b,mid);///break the array into two part
    init(rightnode,mid+1,e);
    tree[node].sum=tree[leftnode].sum+tree[rightnode].sum;///store the value in parent node
}
void update(ll node,ll b,ll e,ll i,ll j,ll x)///add value
{
    if (i>e || j<b)return;

    if(b>=i && e<=j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }
    ll left=node<<1;///index do left node
    ll right=(node<<1)+1;
    ll mid=(b+e)>>1;

    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);

    tree[node].sum=tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;///updating node
}
ll query(ll node,ll b,ll e,ll i,ll j,ll carry=0)
{
    if (i>e || j < b)return 0;
    if (b>=i && e<=j)
    {
        return tree[node].sum+carry*(e-b+1);
    }

    ll left=node<<1;
    ll right=(node << 1)+1;
    ll mid=(b + e)>>1;

    ll sumleft = query(left, b, mid, i, j, carry+tree[node].prop);
    ll sumright = query(right, mid + 1, e, i, j, carry+tree[node].prop);

    return sumleft+sumright;///sum of left and right node
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    map<ll,ll>pp;
    ll n,e,i,j,l,m,x,y,z,r,k;
    cin>>n>>k;
    for(i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    init(1,1,n);
    for(i=0; i<k; i++)
    {
        cin>>x;
        if(x==1)
        {
            ll val;
            cin>>r>>l>>val;
            update(1,1,n,r,l,val);
        }
        else
        {
            cin>>r>>l;
            ll ans=query(1,1,n,r,l);
            cout<<ans<<endl;
        }

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

/*
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long
#define mod      1000007
#define N        2000005
#define yes      cout<<"Yes"<<endl
#define no      cout<<"No"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
struct obj{
    ll sum,mx;
}tree[N];
ll arr[N];
void build_tree(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node].sum=arr[b];
        tree[node].mx=arr[b];
        return;
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(b+e)>>1;

    build_tree(left,b,mid);
    build_tree(right,mid+1,e);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].mx=max(tree[left].mx,tree[right].mx);
}
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(j<b || e<i)return 0;
    if(i<=b && e<=j)
    {
        return tree[node].sum;
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(b+e)>>1;

    ll x=query(left,b,mid,i,j);
    ll y=query(right,mid+1,e,i,j);

    return x+y;
}

void range_update(ll node,ll b,ll e,ll i,ll j,ll MOD)
{
    if(b>j || e<i || tree[node].mx<MOD)return;

    if(b==e)
    {
        tree[node].sum%=MOD;
        tree[node].mx%=MOD;
        return;
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(b+e)>>1;

    range_update(left,b,mid,i,j,MOD);
    range_update(right,mid+1,e,i,j,MOD);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].mx=max(tree[left].mx,tree[right].mx);
}

void index_update(ll node,ll b,ll e,ll index,ll val)
{
    if(b==e)
    {
        tree[node].sum=val;
        tree[node].mx=val;
        return;
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(b+e)>>1;

    if(index<=mid)index_update(left,b,mid,index,val);
    else index_update(right,mid+1,e,index,val);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].mx=max(tree[left].mx,tree[right].mx);
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,vector<ll>>mp;
    map<ll,ll>pp;
    ll n,e,i,j,l,m,x,y,z,r,k;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build_tree(1,1,n);
    while(k--)
    {
        cin>>x;
        if(x==1)
        {
            cin>>l>>r;
            ll res=query(1,1,n,l,r);
            cout<<res<<endl;
        }
        else if(x==2)
        {
            ll MOD;
            cin>>l>>r>>MOD;
            range_update(1,1,n,l,r,MOD);
        }
        else if(x==3)
        {
            ll index,val;
            cin>>index>>val;
            index_update(1,1,n,index,val);
        }
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


*
