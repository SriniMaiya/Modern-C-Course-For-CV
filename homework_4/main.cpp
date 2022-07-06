#include "homework_4.hpp"

int main(int argc, char const *argv[])
{
    // ipb::named_vector<std::string> vec("test", {"a", "bc", "def"});
    ipb::named_vector<int> vec("test", {-22, -18, -6, 0, 2, 3, 10, 18, 11});

    ipb::print(vec);
    std::cout << "Capacity: " << vec.capacity() << std::endl;
    vec.resize(8);
    std::cout << "Resize (8) Capacity: " << vec.capacity() << std::endl;
    vec.vector();
    vec.reserve(20);
    std::cout << "Reserve (20) Capacity: ";
    vec.vector();
    std::cout << vec.capacity() << std::endl;
    std::cout << "Sum of all elements: " << ipb::accumulate(vec) << std::endl;
    vec.capacity();
    std::cout << "The vector is all even:  " << ipb::all_even(vec) << std::endl;
    std::cout << "10 in vector: " << ipb::find(vec, 10) << std::endl;

    ipb::toupper(vec);
    std::cout << "Vector name to upper: \n";
    ipb::print(vec);
    std::cout << "Clamp the vector to [-5, 5]: \n";
    ipb::clamp(vec, -5, 5);
    ipb::print(vec);

    std::cout << "Rotate with pivot: pos 2\n";
    ipb::rotate(vec, 2);
    ipb::print(vec);

    std::cout << "Flip the vector: \n";
    ipb::reverse(vec);
    ipb::print(vec);

    std::cout << "Fill the vector with '0': \n";
    ipb::fill(vec, 0);
    ipb::print(vec);

    return 0;
}