#include "paginator.tpp"
#include <gtest/gtest.h>

TEST(Paginator, Pages) {
    paginator::Paginator<int> paginator({1, 2, 3, 4, 5}, 1);
    EXPECT_EQ(paginator.pages(), 5);

    paginator.size = 2;
    EXPECT_EQ(paginator.pages(), 3);

    paginator.size = 3;
    EXPECT_EQ(paginator.pages(), 2);

    paginator.size = 4;
    EXPECT_EQ(paginator.pages(), 2);

    paginator.size = 5;
    EXPECT_EQ(paginator.pages(), 1);

    paginator.size = 6;
    EXPECT_EQ(paginator.pages(), 1);

    paginator.size = 0;
    EXPECT_EQ(paginator.pages(), 0);
}

TEST(Paginator, Page) {
    paginator::Paginator<int> paginator({1, 2, 3, 4, 5}, 2);
    EXPECT_EQ(paginator.page(), std::vector<int>({1, 2}));

    paginator.index = 1;
    EXPECT_EQ(paginator.page(), std::vector<int>({3, 4}));

    paginator.index = 2;
    EXPECT_EQ(paginator.page(), std::vector<int>({5}));

    paginator.index = 3;
    EXPECT_EQ(paginator.page(), std::vector<int>({}));

    paginator.index = 0;
    paginator.size  = 0;
    EXPECT_EQ(paginator.page(), std::vector<int>({}));
}

TEST(Paginator, Empty) {
    EXPECT_TRUE(paginator::Paginator<int>().empty());
    EXPECT_FALSE(paginator::Paginator<int>({1}).empty());
}

TEST(Paginator, Bounds) {
    paginator::Paginator<int> paginator({1, 2, 3, 4, 5}, 2);
    EXPECT_TRUE(paginator.first());
    EXPECT_FALSE(paginator.last());

    paginator.index = 1;
    EXPECT_FALSE(paginator.first());
    EXPECT_FALSE(paginator.last());

    paginator.index = 2;
    EXPECT_FALSE(paginator.first());
    EXPECT_TRUE(paginator.last());

    paginator.index = 3;
    EXPECT_FALSE(paginator.first());
    EXPECT_FALSE(paginator.last());
}

TEST(Paginator, Steps) {
    paginator::Paginator<int> paginator({1, 2, 3, 4, 5}, 2);
    paginator.previous();
    EXPECT_EQ(paginator.index, 0);

    paginator.next();
    EXPECT_EQ(paginator.index, 1);

    paginator.next();
    EXPECT_EQ(paginator.index, 2);

    paginator.next();
    EXPECT_EQ(paginator.index, 2);
}
