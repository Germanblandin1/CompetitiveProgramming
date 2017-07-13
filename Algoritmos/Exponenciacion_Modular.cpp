#include<bits/stdc++.h>
#define LL long long
using namespace std;
 
/* Function to calculate (base^exponent)%modulus */
long long int modular_pow(LL base, LL exponent,LL modulus){
    LL result = 1LL;
    while (exponent > 0){
        if (exponent & 1LL)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

LL fpow(LL a, LL e, LL m){
	LL x = 1, y = a;
	while(e > 0LL){
		if(e & 1LL) x = mulmod(x,y,m);
		y = mulmod(y,y,m);
		e>>=1LL;
	}
	return x%m;
}