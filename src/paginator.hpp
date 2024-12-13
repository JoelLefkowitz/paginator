#ifndef PAGINATOR_PAGINATOR_HPP
#define PAGINATOR_PAGINATOR_HPP

#include <cstddef>
#include <vector>

namespace paginator {
    template <typename T>
    class Paginator {
      private:
        std::vector<T> vector;

      public:
        size_t size;
        size_t index;

        explicit Paginator(std::vector<T> vector = {}, size_t size = 1UL, size_t index = 0UL);

        size_t pages();

        std::vector<T> page();

        bool empty();

        bool first();
        bool last();

        void previous();
        void next();
    };
} // namespace paginator

#endif
