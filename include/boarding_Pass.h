#ifndef INCLUDE_BOARDING_PASS_H_
#define INCLUDE_BOARDING_PASS_H_

#include <fstream>
#include <vector>

#define LOWER 0
#define UPPER 127
#define MOST_SIGNIFICAT 7

class BoardingPass
{
public:
	BoardingPass() = default;

	void columnReveal(std::string i);
	void rowReveal(std::string i);

	int row = 0;
	int column = 0;
	int seatID = 0;
	uint32_t lower = LOWER;
	uint32_t upper = UPPER;
	uint32_t r = MOST_SIGNIFICAT;
	uint32_t l = 0;

private:
	uint32_t changeUpper();
	uint32_t changeLower();
	uint32_t changeR();
	uint32_t changeL();
};

std::vector<std::string> decodeInput(std::fstream &file);
int decodeSeat(std::string i);

#endif /* INCLUDE_BOARDING_PASS_H_ */