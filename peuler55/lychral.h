#pragma once
#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>
namespace peuler {
	using boost::multiprecision::uint128_t;
	uint128_t next_iter(uint128_t num);
	//uint64_t reverse_number(uint64_t num);
	uint128_t reverse_number(uint128_t num);
	uint8_t num_len(uint128_t num);
	bool is_palindrome(uint128_t num);
	bool is_lychral(uint128_t base);
	int number_of_lychrel();
}

#ifdef _DEBUG
	void test_num_len();
	void test_reverse_number();
	void test_is_palindrome();
	void test_is_lychral();
#endif
