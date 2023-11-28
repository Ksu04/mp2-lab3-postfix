#include "pch.h"
#include "gtest\gtest.h"
#include "../Stack/include/Header.h"

TEST(Stack, can_create_default_stack) {
	ASSERT_NO_THROW(Stack<int>st);
}
TEST(Stack, can_create_stack_with_a_given_size) {
	ASSERT_NO_THROW(Stack<int>st(5));
}
TEST(Stack, can_not_create_stack_with_a_negative_size) {
	ASSERT_ANY_THROW(Stack<int>st(-3));
}
TEST(Stack, can_push_an_element_in_stack) {
	Stack<int>st(5);
	ASSERT_NO_THROW(st.Push(5));
}
TEST(Stack, can_push_an_element_in_full_stack) {
	Stack<int>st(3);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	ASSERT_NO_THROW(st.Push(4));
}
TEST(Stack, func_size_returns_current_size_of_stack) {
	Stack<int>st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	EXPECT_EQ(st.Size(), 3);
}
TEST(Stack, func_Top_returns_the_latest_element) {
	Stack<int>st;
	st.Push(5);
	st.Push(3);
	st.Push(6);
	st.Top();
	EXPECT_EQ(st.Top(), 6);
}
TEST(Stack, func_Pop_removes_the_latest_element) {
	Stack<int>st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Pop();
	EXPECT_EQ(st.Size(), 2);
}
TEST(Stack, func_Pop_returns_popped_element) {
	Stack<int>st;
	st.Push(3);
	EXPECT_EQ(st.Pop(), 3);
}
TEST(Stack, func_Pop_throws_when_stack_is_empty) {
	Stack<int>st;
	ASSERT_ANY_THROW(st.Pop());
}
TEST(Stack, func_isEmpty_returns_true_when_stack_is_empty) {
	Stack<int> st;
	EXPECT_TRUE(st.IsEmpty());
}
TEST(Stack, func_isEmpty_returns_false_when_stack_contains_element) {
	Stack<int> st;
	st.Push(5);
	EXPECT_FALSE(st.IsEmpty());
}
