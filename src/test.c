#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "lib.c"

// Very small test helpers
int failed = 0;
#define TEST(name) void name()
#define RUN_TEST(name) printf("\n\033[1m%s\n\033[0m", #name); name()
#define ASSERT(expr) if (!(expr)) { \
  failed = 1; \
  printf("\033[0;31mFAIL: %s\n\033[0m", #expr); \
} else { \
  printf("\033[0;32mPASS: %s\n\033[0m", #expr); \
}
#define ASSERT_STR_EQ(str1, str2) if (!(strcmp(str1, str2) == 0)) { \
  failed = 1; \
  printf("\033[0;31mFAIL: %s != %s\n\033[0m", str1, str2); \
} else { \
  printf("\033[0;32mPASS: %s == %s\n\033[0m", str1, str2); \
}
// End of test helpers

TEST(test_add) {
  ASSERT(add(1, 2) == 3);
  ASSERT(add(0, 0) == 0);
  ASSERT(add(-1, -1) == -2);
}

TEST(test_subtract) {
  ASSERT(subtract(1, 2) == -1);
  ASSERT(subtract(0, 0) == 0);
  ASSERT(subtract(-1, -1) == 0);
}

TEST(test_divide) {
  ASSERT(divide(2, 2) == 1);
  ASSERT(divide(10, 2) == 5);
  ASSERT(divide(-6, 2) == -3);
}
 
TEST(test_mult){
  ASSERT(mult(2, 2) == 4);
}

TEST(test_string_assert) {
  ASSERT_STR_EQ("hello", "hello");
}

TEST(test_xor) {
  ASSERT(xor(0, 0) == 0);
  ASSERT(xor(1, 0) == 1);
  ASSERT(xor(0, 1) == 1);
  ASSERT(xor(1, 1) == 0);
  ASSERT(xor(5, 3) == 6);  // 101 ^ 011 = 110 (binary) = 6 (decimal)
}

int main() {
  // Add a `RUN_TEST` line for each test function
  RUN_TEST(test_add);
  RUN_TEST(test_subtract);
  RUN_TEST(test_divide);
  RUN_TEST(test_mult);
  RUN_TEST(test_string_assert);
  RUN_TEST(test_xor);
  return failed;
}
