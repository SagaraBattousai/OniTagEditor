#pragma once
#include <fstream>
#include <array>
#include <string>

class tag_header //:public header
{
public:
	tag_header() = default;
	/*tag_header(unsigned char buf[3], unsigned char version,
	unsigned char min, unsigned char flags,
	unsigned char remainingTagSize[4]);*/

	//human readable and not file understandable getters.
	std::string get_file_id();
	std::string get_version();
	bool unsync_set();
	bool extended_header_set();
	bool experimental_indicator_set();
	unsigned get_remaining_tag_size();

	std::array<char, 1> minor;
	std::array<char, 1> flags;
	std::array<char, 4> remaining_tag_size;


	friend std::istream& operator>>(std::istream& is, tag_header& th);
	friend std::ostream& operator<<(std::ostream& os, tag_header& th);

private:
	unsigned char get_major_version();
	unsigned char get_minor_version();

	std::array<char, 3> file_id;
	//hex
	std::array<unsigned char, 2> version;
	//std::array<char, 1> minor;
	unsigned char flags;
	std::array<unsigned char, 4> remaining_tag_size;



	
};