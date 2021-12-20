#ifndef INCLUDE_BOARDING_PASS_H_
#define INCLUDE_BOARDING_PASS_H_

#include <fstream>
#include <vector>

class Boarding_Pass
{
public:
	Boarding_Pass() = default;

	void column_reveal(std::string i);
	void row_reveal(std::string i);

	int row = 0;
	int column = 0;
	int seat_ID = 0;
	uint32_t lower = 0;
	uint32_t upper = 127;
	uint32_t r = 7;
	uint32_t l = 0;
};
std::vector<std::string> decode_input(std::fstream &file);
int decode_seat(std::string i);
#endif /* INCLUDE_BOARDING_PASS_H_ */