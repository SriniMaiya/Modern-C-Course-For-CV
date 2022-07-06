#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <initializer_list>

namespace ipb
{

    template <typename T>
    class named_vector
    {
    private:
        std::string Name;
        std::vector<T> List;

    public:
        named_vector(){};
        ~named_vector(){};
        named_vector(std::string, std::initializer_list<T>);
        size_t size();
        void resize(int);
        size_t capacity();
        void reserve(int);
        std::vector<T> vector();
        std::string name();

        template <class T1>
        friend void toupper(ipb::named_vector<T1> &vec);

        template <typename T1>
        void sort(ipb::named_vector<T1> &vec);

        template <typename T1>
        friend void clamp(ipb::named_vector<T1> &vec, T1 min, T1 max);

        template <typename T1>
        friend void rotate(ipb::named_vector<T1> &vec, int pos);

        template <typename T1>
        friend void reverse(ipb::named_vector<T1> &vec);

        template <typename T1>
        friend void fill(ipb::named_vector<T1> &vec, T1 fillval);
    };

    template <typename T>
    named_vector<T>::named_vector(std::string s, std::initializer_list<T> list) : Name(s)
    {
        for (auto x : list)
            List.emplace_back(x);
    }

    template <typename T>
    size_t named_vector<T>::size()
    {
        if (Name.size() == 0 || List.size() == 0)
            return 0;
        return Name.size() + List.size();
    }

    template <typename T>
    void named_vector<T>::reserve(int size)
    {
        List.reserve(size);
    }

    template <typename T>
    void named_vector<T>::resize(int size)
    {
        List.resize(size);
    }

    template <typename T>
    size_t named_vector<T>::capacity()
    {
        return List.capacity();
    }

    template <typename T>
    std::vector<T> named_vector<T>::vector()
    {
        return this->List;
    }

    template <typename T>
    std::string named_vector<T>::name() { return Name; }

    // ipb_algorithm

    template <typename T>
    T accumulate(ipb::named_vector<T> vec)
    {
        T ret{};
        std::vector<T> temp = vec.vector();
        for (auto x : temp)
            ret += x;
        return ret;
    }

    template <typename T>
    void print(ipb::named_vector<T> vec)
    {
        std::cout << "Name:  " << vec.name() << std::endl;
        for (auto x : vec.vector())
            std::cout << x << "\t";
        std::cout << std::endl
                  << std::endl;
    }

    template <typename T>
    auto count(ipb::named_vector<T> vec, T val)
    {
        return std::count(vec.vector().begin(), vec.vector().end(), val);
    }

    template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
    bool all_even(ipb::named_vector<T> vec)
    {
        auto temp = vec.vector();

        return std::all_of(temp.begin(), temp.end(), [](int i)
                           { return i % 2 == 0; });
    }

    template <typename T>
    bool find(ipb::named_vector<T> vec, T val)
    {
        auto temp = vec.vector();
        auto ind = std::find(temp.begin(), temp.end(), val);

        if (ind != temp.end())
            return true;
        else
            return false;
    }

    template <typename T>
    void toupper(ipb::named_vector<T> &vec)
    {
        if (vec.name().size() != 0)
            std::transform(vec.Name.begin(), vec.Name.end(), vec.Name.begin(), ::toupper);
    }

    template <typename T>
    void sort(ipb::named_vector<T> &vec)
    {
        std::sort(vec.List.begin(), vec.List.end());
    }

    template <typename T>
    void clamp(ipb::named_vector<T> &vec, T min, T max)
    {
        static_assert(std::is_arithmetic<T>::value, "Must be of numeric value!");
        std::transform(vec.List.begin(), vec.List.end(), vec.List.begin(), [=](auto i)
                       { return std::clamp(i, min, max); });
    };

    template <typename T>
    void rotate(ipb::named_vector<T> &vec, int pos)
    {
        std::rotate(vec.List.begin(), vec.List.begin() + pos, vec.List.end());
    }

    template <typename T>
    void reverse(ipb::named_vector<T> &vec)
    {
        std::reverse(vec.List.begin(), vec.List.end());
    }

    template <typename T1>
    void fill(ipb::named_vector<T1> &vec, T1 fillval)
    {
        std::fill(vec.List.begin(), vec.List.end(), fillval);
    }
}