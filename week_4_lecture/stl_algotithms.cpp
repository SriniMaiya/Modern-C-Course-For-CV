#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
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
inline bool even(int i) { return i % 2 == 0; }

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
    std::cout << div_by_3 << " number of elements are divisible by 3 in the above\n\n";
    std::cout << "---> 6. FOR_EACH \n\n";
    std::cout << "Array arr: \n";
    printArray(arr);
    auto add10 = [](int &n)
    { n = n + 10; };
    std::for_each(arr.begin(), arr.end(), add10);
    std::cout << "After adding 10 to each element of array arr: \n";
    printArray(arr);
    std::cout << "---> 6. PARTIAL_SUM\n\n";
    std::array<int, 10> arr3;
    std::cout << "Array : ";
    std::fill(arr3.begin(), arr3.end(), 2);
    printArray(arr3);
    std::partial_sum(arr3.cbegin(), arr3.cend(), arr3.begin());
    std::cout << "Array after partial sum: ";
    printArray(arr3);
    std::cout << "---> 7. ALL_OF\n\n";
    std::cout << "Array : ";
    printArray(arr3);
    bool even_array = std::all_of(arr3.begin(), arr3.end(), even);
    std::cout << "All the elements of arr3 " << (even_array ? "are" : "are not")
              << " even\n\n";
    std::cout << "---> 8. ROTATE\n\n";
    std::cout << "Before rotating, Array : ";
    printArray(arr3);
    std::rotate(arr3.begin(), arr3.end() - 3, arr3.end());
    std::cout << "After rotating, Array : ";
    printArray(arr3);
    std::cout << "Index 7 is index 0 \n\n";

    return 0;
}
