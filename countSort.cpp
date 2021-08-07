
// COUNT SORT: Time complexity of This Sort it O(n) where as Space Complexity is also O(n)

void countSort(vector<int> &arr){
	int n=size(arr);
	int BiggestElem=*max_element(begEnd(arr));
	vector<int> hashArr(BiggestElem+1);
for(auto x:arr) hashArr[x]++; //to find the count of each element using hashmap
vector<int> prefixArr(BiggestElem+1);
for (int i = 1; i <=size(prefixArr); ++i) prefixArr[i]=prefixArr[i-1]+hashArr[i];
vector<int> sortedArr(n);
for (int i = n-1; i >=0; --i) {
sortedArr[--prefixArr[arr[i]]]=arr[i];
}
cout << "Sorted Array is: ";
for(auto &val:sortedArr) cout << val<<sp;
}
