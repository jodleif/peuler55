#include "lychral.h"
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>


#ifdef _DEBUG
#include <cassert>
#include <iostream>
void test_num_len()
{
	assert(peuler::num_len(123u) == 3u, "123u != 3u");
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
}
#endif


using boost::multiprecision::uint128_t;
uint128_t peuler::next_iter(uint128_t num)
{
	return num + reverse_number(num);
}

uint128_t peuler::reverse_number(uint128_t num)
{
	uint128_t reverse{ 0 };
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
		auto number = boost::lexical_cast<std::string>(num);
		auto check_len = number.size() / 2;
		auto b_iter = number.rbegin();
		auto s_iter = number.begin();
		for (auto i{ 0 };i < check_len;++i) {
			if(*b_iter!=*s_iter) {
				return false;
			}
			++b_iter;
			++s_iter;
		}
	} catch (...) {
		return false;
	}
	return true;
}

int peuler::number_of_lychrel()
{
	return 0;
}
