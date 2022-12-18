#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long
#define mod      1000007
#define N        200005
#define yes      cout<<"Yes"<<endl
#define no      cout<<"No"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll arr[N];
struct info
{
    ll ev,od;
} tree[N*4];

void init(ll node,ll b,ll e)
{
    if(b==e)
    {
        if(arr[b]%2==0)
        {
            tree[node].ev=1;
            tree[node].od=0;
        }
        else
        {
            tree[node].ev=0;
            tree[node].od=1;
        }
        return;
    }
    ll leftnode = node*2;
    ll rightnode = node*2+1;
    ll mid = (b+e)/2;

    init(leftnode,b,mid);
    init(rightnode,mid+1,e);

    tree[node].ev=tree[leftnode].ev+tree[rightnode].ev;
    tree[node].od=tree[leftnode].od+tree[rightnode].od;
}

void update(ll node,ll b,ll e,ll index,ll val)
{

    if(b==e)
    {
        if(arr[b]%2==0)
        {
            tree[node].ev=0;
            tree[node].od=1;
        }
        else
        {
            tree[node].ev=1;
            tree[node].od=0;
        }
        arr[index]=val;
        return;
    }

    ll left=node<<1;
    ll right=(node<<1)+1;
    ll mid=(b+e)>>1;

    if(index<=mid) update(left,b,mid,index,val);
    else update(right,mid+1,e,index,val);

    tree[node].ev=tree[left].ev+tree[right].ev;
    tree[node].od=tree[left].od+tree[right].od;
}
ll getEven(ll node,ll b,ll e,ll i,ll j)
{
    if (i>e || j < b)return 0;
    if (b>=i && e<=j)
    {
        return tree[node].ev;
    }

    ll left=node<<1;
    ll right=(node << 1)+1;
    ll mid=(b + e)>>1;

    ll l = getEven(left, b, mid, i, j);
    ll r = getEven(right, mid + 1, e, i, j);

    return l+r;
}
ll getOdd(ll node,ll b,ll e,ll i,ll j)
{
    if (i>e || j < b)return 0;
    if (b>=i && e<=j)
    {
        return tree[node].od;
    }

    ll left=node<<1;
    ll right=(node << 1)+1;
    ll mid=(b + e)>>1;

    ll l = getOdd(left, b, mid, i, j);
    ll r = getOdd(right, mid + 1, e, i, j);

    return l+r;
}

void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    map<ll,ll>pp;
    ll n,e,i,j,l,m,x,y,z,r,k;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    init(1,1,n);
    cin>>k;
    for(i=0; i<k; i++)
    {
        cin>>x;
        if(x == 0)
        {
            ll index,val;
            cin>>index>>val;
            if((arr[index] % 2) == (val % 2)) continue;
            else update(1, 1, n, index,val);
        }
        else if(x == 1)
        {
            cin>>l>>r;
            cout<<getEven(1, 1, n, l, r)<<endl;
        }
        else
        {
            cin>>l>>r;
            cout<<getOdd(1, 1, n, l, r)<<endl;
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


