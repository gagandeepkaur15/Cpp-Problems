#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;

    int *first=new int[len1];
    int *second=new int[len2];

    //Copy values in newly created arrays
    int mainArrayIndex=s;
    for(int i=0; i<len1; i++){
        first[i]=arr[mainArrayIndex++];
    }

    mainArrayIndex=mid+1;
    for(int i=0; i<len2; i++){
        second[i]=arr[mainArrayIndex++];
    }

    //Merge the two sorted arrays
    int index1=0;
    int index2=0;
    mainArrayIndex=s;

    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++]=first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }

    while(index1<len1){
        arr[mainArrayIndex++]=first[index1++];
    }

    while(index2<len2){
        arr[mainArrayIndex++]=second[index2++];
    }
}

void mergeSort(int *arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    
    //sort left part
    mergeSort(arr,s,mid);

    //sort right part
    mergeSort(arr,mid+1,e);

    //merge
    merge(arr,s,e);
}

int main(){
    int arr[5]={6,3,8,2,5};
    int n=5;

    mergeSort(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}