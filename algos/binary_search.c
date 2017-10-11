#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ////////////////////////////////////////////////////////////
int binary_search(int[], int, int);
/*
 * returns the index of the specified key in the integer array
 *
 * @param array array of integers sorted in ascending order
 * @param length length of the array
 * @param key the search key
 * @return index of key in array if present; -1 otherwise
 */
int binary_search(int array[], int length,  int key)
{
    int lo = 0; // element 0 of the array to be searched

    while (lo <= length)
    {
        int mid = lo + (length - lo) / 2;  // overflow safe avg calculation
        if (key < array[mid])
        {
            length = mid - 1;
        }
        else if (key > array[mid]) 
        {
            lo = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}


int main ( ) 
{
    int myArray[10] = { 1, 12, 33, 34, 34, 45, 47, 192, 212, 254 };
    int length = (sizeof(myArray) / sizeof(myArray[0])) - 1;

    int rc;
    int search_value;
    int expected_value;

    search_value = 12;
    expected_value = 1; // position in array
    rc = binary_search (myArray, length, search_value);
    printf ("%s key = %d, index found = %d\n",((rc == expected_value)?"PASS":"FAIL"), search_value, rc);

    search_value = 35;
    expected_value = -1; // position in array - not found
    rc = binary_search (myArray, length, search_value);
    printf ("%s key = %d, index found = %d\n",((rc == expected_value)?"PASS":"FAIL"), search_value, rc);

    search_value = 254;
    expected_value = 9; // position in array
    rc = binary_search (myArray, length, search_value);
    printf ("%s key = %d, index found = %d\n",((rc == expected_value)?"PASS":"FAIL"), search_value, rc);
}
