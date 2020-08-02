#pragma once
#include <array>
class frame_header //:public header
{
public:
	frame_header() = default;
	/*frame_header(unsigned char frameID[4], unsigned char remainingFrameSize[4],
		unsigned char flags[2]);*/

private:
	std::array<char, 4> frame_id;
	std::array<unsigned char, 4> remaining_frame_size;
	std::array<unsigned char, 2> flags;
};