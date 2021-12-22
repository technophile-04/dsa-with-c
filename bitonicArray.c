#include <stdlib.h>
#include <stdio.h>

int binarySearch(int *arr, int s, int e, int target, char order)
{

    switch (order)
    {

    case 'i':
        while (s <= e)
        {

            int mid = (s + e) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return -1;
        break;

    case 'd':

        while (s <= e)
        {

            int mid = (s + e) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] < target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        return -1;
        break;

    default:
        break;
    }

    return -1;
}

int findPeak(int *arr, int s, int e)
{

    while (s < e)
    {

        int mid = (s + e) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }

    return s;
}

int findTrough(int *arr, int s, int e)
{

    while (s < e)
    {

        int mid = (s + e) / 2;

        if (arr[mid] > arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }

    return s;
}

int searchElementInBitonicArray(int *arr, int n, int target)
{
    int peak = -1, finalAns = -1;

    peak = findPeak(arr, 0, n - 1);

    finalAns = binarySearch(arr, 0, peak, target, 'i');

    if (finalAns == -1)
    {
        int trough = findTrough(arr, peak + 1, n - 1);

        finalAns = binarySearch(arr, peak + 1, trough, target, 'd');

        if (trough != n - 1 && finalAns == -1)
        {

            finalAns = binarySearch(arr, trough + 1, n - 1, target, 'i');
        }
    }

    return finalAns;
}

int main()
{

    int n, target, targetIndex = -1, peak = -1;
    printf("Enter the number of elements of bitonic: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements : \n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched : ");
    scanf("%d", &target);

    targetIndex = searchElementInBitonicArray(arr, n, target);

    if (targetIndex == -1)
    {
        printf("Element %d is not found in the array", target);
    }
    else
    {
        printf("Element found at index %d", targetIndex);
    }

    free(arr);

    return 0;
}