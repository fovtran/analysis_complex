#include <iostream>
#include <complex>
#include <vector>
#include <numeric>
#include <concepts>
#include <ranges>
#include <array>
#include <iterator>

template<typename T> 
concept ComplexOrFloat = std::floating_point<T>
    || std::floating_point<typename T::value_type>;

template<typename R> 
requires std::ranges::range<R> 
    && ComplexOrFloat<std::ranges::range_value_t<R>>
constexpr std::ranges::range_value_t<R> average(R range) {
    if (std::ranges::size(range) == 0) 
        throw std::domain_error("Cannot take average of zero-length range");
    using T = std::ranges::range_value_t<R>;
    return std::accumulate(std::ranges::begin(range), std::ranges::end(range), T{0}) 
        / (T)(std::ranges::size(range));
}

int main() {
    using namespace std::complex_literals;
    constexpr std::array<std::complex<double>,3> points{{ {4,5}, {30,6}, {20,25} }};
    std::cout << average(std::views::all(points)) << "\n";

    constexpr std::array<std::complex<double>,3> points2{
        {  24.0 + 7.0i, 22.0 + 9.0i, 8.0 + 20.0i }
    };
    std::cout << average(std::views::all(points2)) << "\n";

    constexpr double numbers[]{1, -2, 3, 7, -8};
    std::cout << average(std::views::all(numbers)) << "\n";

    const std::vector<float> numbers2{-7, -2, 3, 7, -8};
    std::cout << average(std::views::all(numbers2)) << "\n";

    const std::vector<float> mt{};
    try {
        std::cout << average(std::views::all(mt)) << "\n";
    } catch (std::domain_error& err) {
        std::cerr << "ERROR: " << err.what() << "\n";
    }

#if 0
    int intnumbers[]{1, -2, 3, 7, -8};
    // won't compile because an `int` is not floating point or complex floating point
    std::cout << average(std::views::all(intnumbers)) << "\n";
#endif
}