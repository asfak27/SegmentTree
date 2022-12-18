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
string s;
ll tree[N*4][28];

void build_tree(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node][s[b-1]-'a']=1;
        return;
    }
    ll leftnode = node*2;
    ll rightnode = node*2+1;
    ll mid = (b+e)/2;

    build_tree(leftnode,b,mid);
    build_tree(rightnode,mid+1,e);

    for(ll i=0; i<=26; i++)
    {
        tree[node][i]=tree[leftnode][i]+tree[rightnode][i];
    }
}

void update(ll node,ll b,ll e,ll index,ll val)
{

    if (index>e || index<b)return;
    if (b>=index && e<=index)
    {
        for(ll i=0; i<26; i++)
        {
            tree[node][i]=0;
        }
        tree[node][val]=1;
        return;
    }

    ll left=node<<1;
    ll right=(node<<1)+1;
    ll mid=(b+e)>>1;

    update(left,b,mid,index,val);
    update(right,mid+1,e,index,val);

    for(ll i=0; i<26; i++)
    {
        tree[node][i]=tree[left][i]+tree[right][i];
    }
}
ll query(ll node,ll b,ll e,ll i,ll j,ll val)
{
    if (i>e || j < b)return 0;
    if (b>=i && e<=j)
    {
        return tree[node][val];
    }

    ll left=node<<1;
    ll right=(node << 1)+1;
    ll mid=(b + e)>>1;

    ll l = query(left, b, mid, i, j,val);
    ll r = query(right, mid + 1, e, i, j,val);

    return l+r;
}


void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    map<ll,ll>pp;
    ll n,e,i,j,l,m,x,y,z,r,k;
    cin>>s;
    n=s.size();
    build_tree(1,1,n);
    cin>>k;
    while(k--)
    {
        cin>>x;
        if(x == 1)
        {
            ll index,val;
            char ch;
            cin>>index>>ch;
            val=ch-'a';
            update(1, 1, n, index,val);
        }
        else
        {
            cin>>l>>r;
            ll ans=0;
            for(i=0;i<26;i++)
            {
                if(query(1, 1, n, l, r, i))ans++;
            }
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
abacaba
5
2 1 4
1 4 b
1 5 b
2 4 6
2 1 7

output_iterator_tag3
1
2
*/
