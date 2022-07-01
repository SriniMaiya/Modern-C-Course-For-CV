#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define NL std::cout << std::endl \
                     << std::endl

template <std::size_t SIZE>
void printArray(std::array<int, SIZE> &arr)
{
    for (auto i : arr)
        std::cout << i << "\t";
    NL;
}

inline bool divByThree(int i) { return i % 3 == 0; }

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    const int randomIndex = std::rand() % 9 + 0;
    int val = -1;

    std::array<int, 10> arr;

    for (int i = 0; i < 10; i++)
    {
        arr[i] = std::rand() % 1000 + 0;
        if (i == randomIndex)
            val = arr[i];
    }

    std::cout << "---> 1. SORT \n\n";
    std::cout << "std::array<int, 10> arr\n\nBefore sorting: \n";
    printArray(arr);

    std::sort(arr.begin(), arr.end()); // 1. Sort

    std::cout << "After sorting [std::sort(arr.begin(), arr.end())]: \n";
    printArray(arr);
    std::cout << "---> 2. FIND\n\n";

    auto foundIndex = std::find(arr.begin(), arr.end(), val); // 2. find

    if (foundIndex != arr.end())
        std::cout << val << " found at the address " << foundIndex << " in the array arr \n"
                  << std::endl;
    else if (foundIndex == arr.end())
        std::cout << val << " not found in array arr\n"
                  << std::endl;
    std::cout << "---> 3. FILL \n\n";

    std::fill(arr.begin(), arr.end(), -1); // 3. fill
    std::cout << "After filling the array arr with -1: \n";
    printArray(arr);

    std::cout << "---> 4. COUNT \n\n";

    int c1 = std::count(arr.begin(), arr.end(), -1);
    int c2 = std::count(arr.begin(), arr.end(), 255);

    std::cout << "Array arr: ";
    printArray(arr);
    std::cout << "-1 found in arr: " << c1 << " times\n";
    std::cout << "255 found in arr: " << c2 << " times\n\n";

    std::cout << "---> 5. COUNT_IF \n\n";
    for (int i = 0; i < 10; i++)
        arr[i] = std::rand() % 1000 + 0;

    std::cout << "Array arr: ";
    printArray(arr);

    int div_by_3 = std::count_if(arr.begin(), arr.end(), divByThree);
    std::cout << div_by_3 << " number of elements are divisible by 3 in the above\n";
    return 0;
}
