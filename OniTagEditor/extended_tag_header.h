#pragma once
#include <array>
#include <fstream>

class extended_tag_header
{
public:
	extended_tag_header() = default;

	unsigned get_header_size(); //$xx xx xx xx (6 or 10 bytes)
	bool crc_data_present(); //$xx xx (will always add crc thefor will always become 
	unsigned get_padding_size(); //$xx xx xx xx Total Tag Size - frames and headers
	unsigned get_crc_data(); //optional of format $xx xx xx xx


	friend std::istream& operator>>(std::istream& is, extended_tag_header& etg);
	friend std::ostream& operator<<(std::ostream& os, extended_tag_header& eth);

private:
	std::array<unsigned char, 4> header_size; //$xx xx xx xx (6 or 10 bytes)
	std::array<unsigned char, 2> flags; //$xx xx (will always add crc thefor will always become 
	std::array<unsigned char, 4> padding_size; //$xx xx xx xx Total Tag Size - frames and headers
	std::array<unsigned char, 4> crc_data; //optional of format $xx xx xx xx
};

