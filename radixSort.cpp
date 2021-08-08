//count sort function

void countSort(vector<int> &arr,int place){
int n = size(arr);
vector<int> hashArr(10);
for(auto &x:arr) 
  hashArr[x/place%10]++;
  
for (int i = 1; i < size(hashArr); ++i) 
   hashArr[i]+=hashArr[i-1];
  
vector<int> sortedArr(n);
for (int i = n-1; i >=0; --i){
     int x = arr[i];
     sortedArr[--hashArr[x/place%10]]=x;
}
for(int i=0;i<n;i++) 
   arr[i]=sortedArr[i];
}

//radix sort function

void radixSort(vector<int> &arr){
int maxValue = *max_element(arr.begin(),arr.end());
int place = 1; //units place
while(place <= maxValue){
  countSort(arr,place);
  place*=10;
}
}
