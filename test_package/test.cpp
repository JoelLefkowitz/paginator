#include <paginator/paginator.tpp>
#include <vector>

int main() {
    paginator::Paginator<int> paginator({1, 2, 3, 4, 5}, 2);
    return 0;
}
