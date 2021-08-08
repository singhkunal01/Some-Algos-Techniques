
// COUNT SORT: Time complexity of This Sort it O(n) where as Space Complexity is also O(n)

//FIRST APPROACH WITHOUT USING MIN VALUE WE CAN TAKE THE SIZE OF BIGGEST ELEMENT IN THE WHOLE ARRAY
void countSort(vector<int> &arr){
int n = size(arr);
int BiggestElem = *max_element(arr.begin(),arr.end());
	
//frequency of each value
vector<int> hashArr(BiggestElem+1);
for(auto &x:arr) 
  hashArr[x]++;
	
//prefix sum of hashArr
for (int i = 1; i <= BiggestElem; ++i) 
   hashArr[i]+=hashArr[i-1];
	
//filling of array in a sorted way
vector<int> sortedArr(n);
for (int i = n-1; i >=0; --i) 
     sortedArr[--hashArr[arr[i]]]=arr[i];

//place all items from the sorted array into the given array
for(int i=0;i<n;i++) 
   arr[i]=sortedArr[i];
}
