//
// Created by zhanggyb on 16-9-19.
//

#ifndef SKLAND_TEST_BASE_DEQUE_HPP_
#define SKLAND_TEST_BASE_DEQUE_HPP_

#include <gtest/gtest.h>

class TestCountedDeque : public testing::Test {

 public:

  TestCountedDeque() = default;

  ~TestCountedDeque() override = default;

 protected:

  void SetUp() final {}

  void TearDown() final {}

};

#endif // SKLAND_TEST_BASE_COUNTED_DEQUE_HPP_
