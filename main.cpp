#include <bits/stdc++.h>
using namespace std;

void display(vector<int> arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

bool comp_asc(int a,int b){
    return a<b;
}
bool comp_desc(int a,int b){
    return a>b;
}

void selection_sort(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        int min = i;
        for(int j=i+1;j<arr.size();j++){
            if(comp_asc(arr[j],arr[min])){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

void insertion_sort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int key = arr[i];
        int curr;
        for(curr=i-1;curr>=0;curr--){
            if(comp_asc(key,arr[curr])){
                arr[curr+1] = arr[curr];
            }else{
                break;
            }
        }
        arr[curr+1] = key;
    }
}

void bubble_sort(vector<int> &arr){

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void merge(vector<int> &arr,int a,int b,int mid){
    vector<int> arr1(arr.begin()+a,arr.begin()+mid+1);
    vector<int> arr2(arr.begin()+mid+1,arr.begin()+b+1);

    int i=0,j=0,k=a;
    while (i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            arr[k] = arr1[i];
            i++;k++;
        }
        else{
            arr[k] = arr2[j];
            j++;k++;
        }
    }
    while(i<arr1.size()){
        arr[k] = arr1[i];
        i++;k++;
    }
    while(j<arr2.size()){
        arr[k] = arr2[j];
        j++;k++;
    }

}

void Merge_sort(vector<int> &arr,int a,int b){
    if(a>=b) return;
    int mid = (a+b)/2;

    Merge_sort(arr,a,mid);
    Merge_sort(arr,mid+1,b);

    merge(arr,a,b,mid);
}

int partition(vector<int> &arr,int l,int r){
    int pi = arr[r];
    int i = l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pi){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return (i+1);
}

void Quick_sort(vector<int> &arr,int l,int r){
    if(l<r){
        int pivot = partition(arr,l,r);
        Quick_sort(arr,l,pivot-1);
        Quick_sort(arr,pivot+1,r);
    }
}

void Count_sort(vector<int> &arr){
    int ma;
    for(int i=0;i<arr.size();i++){
//        if(arr[i]>max){
//            max = arr[i];
//        }
        ma = max(ma,arr[i]);
    }
    int count[10] = {0};
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=ma;i++){
        count[i]+=count[i-1];
    }
    int output[arr.size()];
    for(int i=arr.size()-1;i>=0;i--){
        output[--count[arr[i]]] = arr[i];
     }

    for(int i=0;i<arr.size();i++){
        arr[i] = output[i];
    }

}

void Bucket_sort(vector<int> &arr){
    map<int,int> buckets;
    for(int i: arr){
        buckets[i]++;
    }
    for(auto row : buckets){
        cout<< row.first<<" "<<row.second<<endl;
    }
    int i=0;
    for(auto row:buckets){
        int key = row.first;
        int count = row.second;
        while(count>0){
            arr[i] = key;
            i++;
            count--;
        }
    }


}

void sort(vector<int> &arr){
//    selection_sort(arr);
//    display(arr);
//    insertion_sort(arr);
//    display(arr);
//    bubble_sort(arr);
//    display(arr);
//    Merge_sort(arr,0,arr.size()-1);
//    display(arr);
//    Quick_sort(arr,0,arr.size()-1);
//    display(arr);
//    Count_sort(arr);
//    display(arr);
    Bucket_sort(arr);
    display(arr);
}

int main() {
    vector<int> arr = {2 ,5, 9, 1, 4,5,11,22,11,1,1,2,3,4,5,2,3,4,5,3,2,2,2,1,1 ,9 ,23,98,43 };
    sort(arr);


//    Inbuild sort function

    //For ascending order same
    /*sort(arr.begin(),arr.end());
    display(arr);
    sort(arr.begin(),arr.end(), comp_asc);
    display(arr);*/



    //For descending order same
    /*sort(arr.begin(),arr.end(),greater<int>());
    display(arr);
    sort(arr.begin(),arr.end(), comp_desc);
    display(arr);*/

    return 0;
}
