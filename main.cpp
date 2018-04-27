#include <iostream>
#include<vector>
#include<map>
#define MOD 29989

using namespace std;



//O(logn)
long long int f(long long int n){

	static map<long long int,long long int> mem;

	if (n<=1)return n;
	long long int &ans = mem[n];
	if (ans!=0)return ans;
	else {

		long long int i=n/2;
        long long int f2=f(i);
        long long int f3=f(i-1);

        if(n%2==0){
            //long long int tmp=(f2*(2*f3+f2));
            long long int tmp3=((f3%MOD)*2)%MOD;
            long long int tmp1=((tmp3%MOD)+f2)%MOD;
            long long int tmp2=((f2%MOD)*tmp1)%MOD;
            mem[n]=tmp2;
            return tmp2;
        }
        else{
            long long int tmp1=((f2%MOD)+f3)%MOD;
            long long int tmp2=((f2%MOD)*f2)%MOD;
            long long int tmp3=((tmp1%MOD)*tmp1)%MOD;
            long long int tmp_fnl=((tmp3%MOD)+tmp2)%MOD;
            mem[n]=tmp_fnl;
            return tmp_fnl;
            //((f2+f3)*(f2+f3)+f2*f2)
        }
        //return ans;
	}

    /*if(n<=1){
        return n;
    }
    else{
        long long int i=n/2;
        long long int f2=f(i);
        long long int f3=f(i-1);

        if(n%2==0){
            //long long int tmp=(f2*(2*f3+f2));
            long long int tmp3=((f3%MOD)*2)%MOD;
            long long int tmp1=((tmp3%MOD)+f2)%MOD;
            long long int tmp2=((f2%MOD)*tmp1)%MOD;
            return tmp2;
        }
        else{
            long long int tmp1=((f2%MOD)+f3)%MOD;
            long long int tmp2=((f2%MOD)*f2)%MOD;
            long long int tmp3=((tmp1%MOD)*tmp1)%MOD;
            long long int tmp_fnl=((tmp3%MOD)+tmp2)%MOD;
            return tmp_fnl;
            //((f2+f3)*(f2+f3)+f2*f2)
        }
    }*/
}

int main()
{
    long long int t;
    cin>>t;
    long long int n;
    for(int i=0;i<t;i++){
        cin>>n;
        long long int fnl=f(n);
        cout<<fnl<<endl;
    }
}
