#include <iostream>
#include<vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int qq=0;qq<t;qq++){
        vector<long long int> a,c;
        long long int n,k,p,q,r;
        cin>>n>>k>>p>>q>>r;
        a.resize(n+1,0);
        for(int i=1;i<=n;i++){
            a[i]=(p*i*i+q*i+r)%1000000;
            //cout<<a[i]<<" ";
        }
        //cout<<endl;

        c.resize(1000000,0);
        for(int i=1;i<=n;i++){
            c[a[i]]++;
        }
        for(int i=1;i<=1000000;i++){
            c[i]+=c[i-1];
            if(c[i]>=k){
                cout<<i<<endl;
                break;
            }
        }
        /*b.resize(n+1,0);
        for(int i=n;i>=1;i--){
            b[c[a[i]]]=a[i];
            c[a[i]]--;
        }
        cout<<b[k]<<endl;*/
    }

}
