#include "lychral.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>


#ifdef _DEBUG
#include <cassert>
#include <iostream>
void test_num_len()
{
	assert(peuler::num_len(123u) == 3u);
	std::cout << "num len 123u = 3u Ok!\n";
	assert(peuler::num_len(1u) == 1u);
	std::cout << "Num len 1u ok!\n";
	assert(peuler::num_len(12345678910u) == 11u);
	std::cout << "Num len 12345678910u == 11u ok!\n";
}

void test_reverse_number()
{	
	assert(peuler::reverse_number(123u) == 321u);
	assert(peuler::reverse_number(1u) == 1u);
	assert(peuler::reverse_number(12345678910u) == 1987654321u);
}

void test_is_palindrome()
{
	assert(peuler::is_palindrome(121u));
	assert(!peuler::is_palindrome(1234123u));
	assert(peuler::is_palindrome(7337u));
	assert(peuler::is_palindrome(boost::multiprecision::uint128_t{ "4668731596684224866951378664" }));
}

void test_is_lychral()
{
	assert(peuler::is_lychral(196u));
	assert(!peuler::is_lychral(349u));
}
#endif


using boost::multiprecision::uint128_t;

uint128_t peuler::next_iter(uint128_t num)
{
	return num + reverse_number(num);
}

uint128_t peuler::reverse_number(uint128_t num)
{
	uint128_t reverse;
	reverse = 0u;
	while(num!=0) {
		reverse *= 10;
		reverse += num % 10;
		num /= 10;
	}
	return reverse;
}

uint8_t peuler::num_len(uint128_t num)
{
	uint8_t len{ 0 };
	while(num!=0) {
		num /= 10;
		++len;
	}
	return len;
}

bool peuler::is_palindrome(uint128_t num)
{
	try {
		auto number = num.convert_to<std::string>();
		auto check_len = number.size() / 2;
		auto s_iter = number.begin(); // Iterator from start of string
		auto e_iter = s_iter + static_cast<long long>(number.size()) - 1; // iterator at end of string
		for (uint64_t i{ 0 };i < check_len;++i) {
			if(*e_iter!=*s_iter) {
				return false;
			}
			--e_iter; ++s_iter; // Increment iterators.
		}
	} catch (...) {
		return false; // Incase boost lexical cast fails.
	}
	return true;
}

bool peuler::is_lychral(uint128_t base)
{
	auto tmp = next_iter(base);
	for (uint_fast8_t i{ 0 };i < 50u;++i) {
		if (is_palindrome(tmp)) return false;
		tmp = next_iter(tmp);
	}
	return true;
}

int peuler::number_of_lychrel()
{
	uint64_t limit{ 10000u };
	uint128_t init_test;
	init_test = 1u;
	int sum{ 0 };
	for (uint64_t i{ 1 };i < limit;++i) {
		if (is_lychral(init_test)) ++sum;
		++init_test;
	}
	return sum;
}
