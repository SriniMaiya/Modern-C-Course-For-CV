#include <iostream>
#include <optional>
#include <utility>
#include <variant>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <tuple>
#include <any>

std::optional<std::string> MultipleStrings(int option)
{
    switch (option)
    {
    case 1:
        return "Option 1\n";
    case 2:
        return "Option 2\n";
    case 3:
        return "Option 3\n";
    }
    return {};
}

void PrintStudent(std::tuple<float, char, std::string> student)
{
    std::cout << "GPA: " << std::get<float>(student)
              << "\tGrade: " << std::get<char>(student)
              << "\tName: " << std::get<std::string>(student) << std::endl;
}

int main(int argc, char const *argv[])
{
    int a = 7, b = 23;
    std::cout << "-->  1. SWAP \n";
    std::cout << "a: " << a << "\tb: " << b << "<-- Before swap\n";
    std::swap(a, b);
    std::cout << "a: " << a << "\tb: " << b << "<-- After swap\n";
    std::cout << "\n-->  2. VARIANT\n";
    std::variant<int, float, char> v1;
    v1 = 8.3452f; // float
    std::cout << "std::variant<int, float, char> v1: \n Float: " << std::get<1>(v1) << std::endl;
    std::variant<int, float, char> v2;
    v2 = 't'; // char
    std::cout << "std::variant<int, float, char> v2 \n Char [4]: " << std::get<char>(v2) << std::endl;
    std::cout << "\n-->  3. ANY\n";
    std::any any_v;
    any_v = 1.3585; // double
    std::cout << "\nstd::any any_v = 1.3585\nany_v -> int: " << (int)std::any_cast<double>(any_v) << std::endl;
    std::cout << "any_v -> float: " << std::any_cast<double>(any_v) << std::endl;
    std::cout << "any_v -> std::string: " << std::to_string(std::any_cast<double>(any_v)) << std::endl;

    std::any any_v2 = true;
    std::cout << "\nstd::any any_v2 = true\nany_v2 -> bool: " << std::any_cast<bool>(any_v2) << std::endl;
    std::cout << "any_v2 -> bool: " << std::boolalpha << std::any_cast<bool>(any_v2) << std::endl;
    std::cout << "\n-->  4. OPTIONAL\n";
    std::cout << MultipleStrings(2).value_or(":\\");
    std::cout << MultipleStrings(0).value_or(":\\") << "\n";
    std::cout << "\n-->  5. TUPLE\n";
    std::tuple<float, char, std::string> student{1.1, 'A', "BarFoo"};
    using Student = std::tuple<float, char, std::string>;
    Student student2{1.41, 'A', "FooBar"};
    PrintStudent(student2);

    auto [gpa, grade, name] = student;
    std::cout << "GPA: " << gpa
              << "\tGrade: " << grade
              << "\tName: " << name << std::endl;
    std::cout << "\n-->  6. CHRONO\n";

    auto start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::microseconds(1500));
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout << "System slept for : " << diff.count() * 1e3 << " seconds.\n";
    return 0;
}
