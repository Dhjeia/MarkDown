#include<iostream>
using namespace std;

int findMaxSubarraySum(int arr[], int start, int end){

	int currentSum = 0;
	if(start == end){
		//currentSum = arr[start] > 0 ? arr[start] : 0;
        if(arr[start] > 0) currentSum = arr[start];
        else currentSum = 0;    //就是不要这一个数字了
	}
	else{
		int mid = (start + end) / 2;
		int leftPartSum = findMaxSubarraySum(arr, start, mid);
		int rightPartSum = findMaxSubarraySum(arr, mid + 1, end);

		int leftMax = 0;    // leftMax是从左边开始的最大子段和
		int leftAccum = 0;  // leftAccum是从左边开始的累积和
		int i = mid;
        while (i >= start) {
            leftAccum += arr[i];
            if (leftAccum > leftMax) leftMax = leftAccum;
            i--;    //
        }
	
		int rightMax = 0;
		int rightAccum = 0;
		int j = mid + 1;
        while (j <= end) {
            rightAccum += arr[j];
            if (rightAccum > rightMax) rightMax = rightAccum;
            j++;
        }

		currentSum = leftMax + rightMax;
		if(currentSum < leftPartSum) currentSum = leftPartSum;	
		if(currentSum < rightPartSum) currentSum = rightPartSum;
	}
	return currentSum;
}

int getMaxSum(int arr[], int length){
	return findMaxSubarraySum(arr, 0, length - 1);
}

int main(){
	int b[] = {-2, 11, -4, 13, -5, -2};
	//           left             right
	for(int i = 0; i < 6; i++)
	{
		cout << b[i] << " ";
	}	 
	cout << endl;
	cout << "数组b的最大连续子段和为：" << getMaxSum(b, 6) << endl;
	return 0;
}
