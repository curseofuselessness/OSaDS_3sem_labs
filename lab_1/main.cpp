#include <iostream>

int binSearchIndex(int* arr, int x, int size) {
    if (size == 1 and arr[0] == x)return 1;
    if (size == 1 and arr[0] != x)return 0;
    if (size == 0)return 0;

    int r = size-1;
    int l = 0;
    int mid = 0;
    int res_ind = mid;
    bool flag = 0;
    while (l<=r and flag!=1) {
         mid = (l + r) / 2;
         if (arr[mid] == x) flag = 1;
        if (arr[mid] > x) {
            r = mid - 1;
        }
        else {
            l = mid+1;
        }
    }
        return flag;
    
    
}

int binSearchIndexBigger(int* arr, int x, int size) {
    if (size == 1 and arr[0] <= x)return size;
    if (size == 1 and arr[0] > x)return 0;
    if (size == 0)return size;


    int r = size - 1;
    int l = 0;
    int mid = 0;
    int res_ind = mid;
    bool flag = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid] == x){
         l = mid + 1;
        }
        if (arr[mid] > x) {
            flag = 1;
            res_ind = mid;
            r = mid - 1;
        }
        if (arr[mid] < x) {
            l = mid + 1;
        }
      
    }
  if(flag){
    return res_ind;
    }
   else {
    return size;
   }

    

}

int binSearchIndexBiggerOrEqual(int* arr, int x, int size) {
    if (size == 1 and arr[0] >= x)return 0;
    if (size == 1 and arr[0] < x)return size;
    if (size == 0)return size;


    int r = size - 1;
    int l = 0;
    int mid = 0;
    int res_ind = mid;
    bool flag = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid] == x) {
            flag = 1;
            res_ind = mid;
            r = mid - 1;
        }
        if (arr[mid] > x) {
            flag = 1;
            res_ind = mid;
            r = mid - 1;
        }
        if (arr[mid] < x) {
            l = mid + 1;
        }

    }
    if (flag) {
        return res_ind;
    }
    else {
        return size;
    }

}



int main() {
    int n, n_keys, a;
    
    std::cin >> n;
    int* ar = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        ar[i] = a;
    }
    std::cin >> n_keys;
   // std::cout << binSearchIndexBiggerOrEqual(ar, n_keys, n) << " ";
    
    for (int i = 0; i < n_keys; i++) {
        std::cin >> a;      
        
            std::cout << binSearchIndex(ar, a, n) << " ";
            std::cout << binSearchIndexBiggerOrEqual(ar, a, n) << " ";
            std::cout << binSearchIndexBigger(ar, a, n) << "\n";
    }
    
    
    


    return 0;
}