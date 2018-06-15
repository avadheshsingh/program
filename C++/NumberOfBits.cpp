//counting numberOfbits;
#include<iostream>
using namespace std;
int countbitsMethod1(int k){
int count=0;
while(k>0){
	k=k&(k-1);
	count++;
}
return count;
}

int countbitsMethod2(int k){
	int mask=1;
	int count=0;
	int i=0;
	while(mask<=k){
		i++;
		k&mask>0?count++:count;
		mask=mask<<i;
	}
	return count;
}

int main(){
	int key;
	cin>>key;
	while(key!=0){
	cout<<countbitsMethod1(key)<<endl;
	cout<<countbitsMethod2(key)<<endl;
	cin>>key;}
	
	return 0;
}