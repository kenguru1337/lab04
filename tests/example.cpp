// Copyright 2021 Alexey <leo678337@gmail.com>

#include <gtest/gtest.h>

#include <header.hpp>
#include <stdexcept>

TEST(Example, EmptyTest) {
    EXPECT_THROW(example(), std::runtime_error);
}
