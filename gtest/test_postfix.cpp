#include "pch.h"
#include "gtest\gtest.h"
#include "../Stack/include/Stack.h"
#include "../Stack/include/Postfix.h"
#include "../Stack/src/Postfix.cpp"

TEST(Postfix, can_create_postfix) {
	ASSERT_NO_THROW(Postfix a("1+1"));
}
TEST(Postfix, cant_create_postfix_from_incorrect_string) {
	ASSERT_ANY_THROW(Postfix a("1+(1*2"));
}
TEST(Postfix, cant_create_postfix_from_empty_string) {
	ASSERT_ANY_THROW(Postfix a(""));
}
TEST(Postfix, cant_create_postfix_from_string_ending_in_an_operation) {
	ASSERT_ANY_THROW(Postfix a("1+2-"));
}
TEST(Postfix, can_get_infix) {
	Postfix a("1+1");
	ASSERT_NO_THROW(a.GetInfix());
}
TEST(Postfix, can_get_postfix) {
	Postfix a("1+1");
	EXPECT_TRUE(a.GetPostfix() == "11+");
}
TEST(Postfix, func_GetOperands_returns_operands) {
	Postfix a("6-2*(5-4)");
	bool s = a.GetOperands()[0] == '2' && a.GetOperands()[1] == '4' && a.GetOperands()[2] == '5' && a.GetOperands()[3] == '6';
	EXPECT_TRUE(s);
}
TEST(Postfix, func_GetLexems_returns_lexems) {
	Postfix a("1+5");
	bool s = (a.GetLexems()[0] == '1' && a.GetLexems()[1] == '+' && a.GetLexems()[2] == '5');
	EXPECT_TRUE(s);
}
TEST(Postfix, func_Calculate_gives_right_answer) {
	Postfix a("6-2*(5-4)");
	EXPECT_EQ(a.Calculate(), 4);
}


