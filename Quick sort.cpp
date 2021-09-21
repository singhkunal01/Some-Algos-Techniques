// Partition to find the pivot element everytime..

int partition(vector<int> &arr,int start,int end){
int pivotElement = arr[end];
int i = start-1; //index is zero based
for(int j = start;j<end;j++){
    if(arr[j]<=pivotElement){
        i+=1;
        swap(arr[i],arr[j]);
    }
}
swap(arr[i+1],arr[end]);
return i+1;
}

void quickSort(vector<int> &arr, int start, int end) {
    if(start < end) {
        int part = partition(arr, start, end);
        quickSort(arr, start, part - 1);
        quickSort(arr, part + 1, end);
    }
}

//Time Complexity : 	Best and Average: O(n*log(n))  	Worst: O(n^2)
