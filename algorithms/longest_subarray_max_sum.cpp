#include <bits/stdc++.h>

using namespace std;

int low=0,high=0;

int maxsum_subarray(int* arr,int size){
	int sum=arr[0],check_sum=0;
	for(int i=1;i<=size;i++){
		for(int j=0;j<size;j++){
			if(j+i>size)
				break;
			for(int k=j;k<j+i;k++)
				check_sum +=arr[k];
			if(check_sum>sum){
				sum = check_sum;
				low = j;
				high = j+i-1;
			}
			check_sum = 0;
		}
	}
	return sum;
}

int main(){
	int size;
	cout<<"enter the size of the array\n";
	cin>>size;
	int arr[size];
	cout<<"enter the elements of the array\n";
	for(int i=0;i<size;i++)
		cin>>arr[i];
	cout<<maxsum_subarray(arr,size)<<endl;
	cout<<low<<"----"<<high;
}