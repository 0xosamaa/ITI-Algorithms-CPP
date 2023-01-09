#include <iostream>


int binary_search(int arr[], int key, int size) {
    int start = 0, end = size-1, mid = end/2;
   

    while (start <= end) {
        
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            end = mid - 1;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }

        mid = (end + start) / 2;
    
    }

    return -1;
}

int binary_search_recursive(int arr[], int key, int start, int end) {
    int mid = (start + end) / 2;

        if (start > end) {
            return -1;
        }
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            return binary_search_recursive(arr, key, start, mid - 1);
        }
        else if (arr[mid] < key) {
            return binary_search_recursive(arr, key, mid + 1, end);
        }
    return -1;
}

int binary_search_string(std::string arr[], std::string key, int n) {
    int lower = 0;
    int upper = n - 1;
    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;
        if (key.compare(arr[mid])==0)
            return mid;
        if (key.compare(arr[mid]) > 0)
            lower = mid + 1;
        else
            upper = mid - 1;
    }
    return -1;
}

int main()
{

    int numbers[6] = {1,2,3,4,5,6};

    std::cout<<binary_search(numbers, 4, 6)<<std::endl;
    std::cout << binary_search_recursive(numbers, 6, 0, 6)<<std::endl;

    std::string words[] = { "abc", "def", "hij" , "klm" , "nope" };
    std::string key = "abc";
    int result = binary_search_string(words, key, 5);
    
    std::cout << result<< std::endl;
    
}
