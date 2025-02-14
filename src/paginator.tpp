#ifndef PAGINATOR_PAGINATOR_TPP
#define PAGINATOR_PAGINATOR_TPP

#include "paginator.hpp"
#include <cmath>
#include <cstddef>
#include <vector>

template <typename T>
paginator::Paginator<T>::Paginator(std::vector<T> vector, size_t size, size_t index)
    : vector(std::move(vector))
    , size(size)
    , index(index) {
}

template <typename T>
size_t paginator::Paginator<T>::pages() {
    return size == 0 ? 0 : std::ceil(static_cast<double>(vector.size()) / static_cast<double>(size));
}

template <typename T>
std::vector<T> paginator::Paginator<T>::page() {
    return std::vector<int>(
        vector.begin() + std::min(vector.size(), index * size),
        vector.begin() + std::min(vector.size(), (index + 1) * size)
    );
}

template <typename T>
bool paginator::Paginator<T>::empty() {
    return vector.empty();
}

template <typename T>
bool paginator::Paginator<T>::first() {
    return index == 0;
}

template <typename T>
bool paginator::Paginator<T>::last() {
    auto limit = pages();
    return limit == 0 || index + 1 == limit;
}

template <typename T>
void paginator::Paginator<T>::previous() {
    if (index > 0) {
        --index;
    }
}

template <typename T>
void paginator::Paginator<T>::next() {
    if (index + 1 < pages()) {
        ++index;
    }
}

#endif
