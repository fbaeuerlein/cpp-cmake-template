#include <gmock/gmock.h>
#include <gtest/gtest.h>

////////////////
// GTEST examples
////////////////

// simple test
TEST(MyFirstTest, test1) { EXPECT_EQ(1, 1); }

// value parameterized test
typedef testing::TestWithParam<int> intParameterizedTest;

TEST_P(intParameterizedTest, test1)
{
    auto x = GetParam();
    EXPECT_GT(x, 0);
}

INSTANTIATE_TEST_SUITE_P(SomeParameterizedTest, intParameterizedTest,
                         testing::Values(1, 2, 3));

// typed test

template <typename T>
class SomeTypedTest : public testing::Test
{
  public:
    SomeTypedTest() {}
};

using MyTypesToTest = ::testing::Types<float, int, double>;

TYPED_TEST_SUITE(SomeTypedTest, MyTypesToTest);

TYPED_TEST(SomeTypedTest, test1)
{

    TypeParam n{};
    n += 1;

    EXPECT_GT(n, 0);
}

////////////////
// GMOCK example
////////////////
struct X
{
    virtual void someFunc1() const = 0;
};

struct MockX : public X
{
    MOCK_METHOD(void, someFunc1, (), (const));
};

TEST(MockTest, test1)
{
    MockX mock;
    EXPECT_CALL(mock, someFunc1).Times(1);

    mock.someFunc1();
}