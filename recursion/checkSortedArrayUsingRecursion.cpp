#include<bits/stdc++.h>
using namespace std;

#define llt long long int
#define modm 1000000007
bool isSorted(int arr[], int n){
    if(n == 0 || n == 1)
        return true;
    if(arr[0] < arr[1] and isSorted(arr + 1, n - 1))
        return true;
    return false;

}
bool isSorted2(int arr[], int i, int n){
    if(i == n - 1)
        return true;
    if(arr[i] < arr[i + 1] and isSorted2(arr, i + 1, n))
        return true;
    return false;

}
int main() {
   int arr[] = { 1,2,3,5,25};
   int n = sizeof(arr) / sizeof(arr[0]);
   cout<< isSorted2(arr, 0, n);
}
