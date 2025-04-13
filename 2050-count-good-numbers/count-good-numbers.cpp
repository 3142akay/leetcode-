#define mod 1000000007
class Solution {
public:
    long long myPow(long long x,long long y)
    {
        x=x%mod;
       
        if(y==0)
        {
            return 1;
        }
        if(y%2==0)
        {
            return myPow((x*x)%mod,y/2);
        }
        else{
            return (x*myPow((x*x)%mod,(y-1)/2))%mod;
        }
       
    }
    int countGoodNumbers(long long n) {
        long long odd= n/2;
        long long even = n/2+n%2;
        return (myPow(5,even)*myPow(4,odd))%mod;
    }
};