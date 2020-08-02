#pragma once
#include "frame_header.h"
#include "frame_body.h"

class frame
{
public:
	//frame() = default;
	~frame();
private:
	frame_header header;
	frame_body *body;
	long frame_location;
};

