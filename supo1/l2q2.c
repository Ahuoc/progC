#include <stdio.h>
#include <stdlib.h>

int *mergedArrays(int *arr1, int *arr2, int arr1Size, int arr2Size) {
    int *finalIdx1 = arr1 + arr1Size;
    int *finalIdx2 = arr2 + arr2Size;
    int *combined = malloc((arr1Size + arr2Size) * sizeof(int));
    int *combined_current = combined;
    while (arr1 < finalIdx1 || arr2 < finalIdx2) {
        if (arr2 >= finalIdx2) {
            *combined_current = *arr1;
            combined_current++;
            arr1++;
        }
        else if (arr1 >= finalIdx1) {
            *combined_current = *arr2;
            combined_current++;
            arr2++;
        }
        else {
            if (*arr1 < *arr2) {
                *combined_current = *arr1;
                combined_current++;
                arr1++;
            }
            else {
                *combined_current = *arr2;
                combined_current++;
                arr2++;
            }
        }
    }
    return combined;
}

int *mergeSort(int arr[], int arrSize) {
    if (arrSize == 1) {
        int *single = malloc(sizeof(int));
        *single = *arr;
        return single;
    }
    int split = arrSize/2;
    int *left = mergeSort(arr, split); // Pass pointer to start, size=split
    int *right = mergeSort(arr + split, arrSize - split); // Pass pointer to arr[split], remaining size
    int *merged = mergedArrays(left, right, split, arrSize-split);
    free(left);
    free(right);
    return merged;
}


int main() {
    int i[] = {8,3,5,4,9,2,10,-20,-1};
    int iSize = sizeof(i)/sizeof(i[0]);

    int *sortedArray = mergeSort(i, iSize);

    for (int idx=0; idx<iSize; idx++)
        printf("%d\n",sortedArray[idx]);
    
    free(sortedArray);
    return 0;
}