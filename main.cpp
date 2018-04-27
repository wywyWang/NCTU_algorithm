#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    long long int m;
    cin>>m;
    for(int qq=0;qq<m;qq++){
        int p,q,r,x,y,z;
        cin>>p>>q>>r;   //a
        cin>>x>>y>>z;   //b
        long long int n;
        cin>>n;
        long long int imin=0,imax=n,i,j,max_left,min_right;
        while(imin<=imax){
            i=(imin+imax)/2;
            j=n-i;

            //cout<<"a[i]="<<p*i*i+q*i+r<<endl;
            //cout<<"a[i-1]"<<p*(i-1)*(i-1)+q*(i-1)+r<<endl;
            //cout<<"b[j]="<<x*j*j+y*j+z<<endl;
            //cout<<"b[j-1]="<<x*(j-1)*(j-1)+y*(j-1)+z<<endl;
            if(i<n&&j>0&&(x*(j-1)*(j-1)+y*(j-1)+z)>(p*i*i+q*i+r))
                imin=i+1;   //i is too small,must increase it
            else if(i>0&&j<n&&(p*(i-1)*(i-1)+q*(i-1)+r)>(x*j*j+y*j+z))
                imax=i-1;   //i is too big,must decrease it
            else{
                //i is perfect
                if(i==0) max_left=x*(j-1)*(j-1)+y*(j-1)+z;
                else if(j==0) max_left=p*(i-1)*(i-1)+q*(i-1)+r;
                else max_left=max((p*(i-1)*(i-1)+q*(i-1)+r),(x*(j-1)*(j-1)+y*(j-1)+z));
                break;
            }
            //cout<<"i="<<i<<" j="<<j<<endl;
            //cout<<"imin="<<imin<<" imax="<<imax<<endl;
        }
        /*if(i==n) min_right=(x*j*j+y*j+z);
        else if(j==n) min_right=(p*i*i+q*i+r);
        else min_right=min((x*j*j+y*j+z),(p*i*i+q*i+r));*/
        cout<<max_left<<endl;
    }
}
