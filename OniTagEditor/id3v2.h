#pragma once
#include "tag.h"
#include "tag_header.h"
#include "frame.h"
#include <map>

class id3v2 :
	public tag
{
public:
	id3v2();
	virtual ~id3v2();

	virtual id3v2* read_tag(std::ifstream& file) override;
	virtual void write_tag(std::ofstream& file) const override;
	virtual void display_tag() const override;
	virtual void edit_tag() override;
	virtual tag_type get_tag_type() const override;

	friend std::istream& operator>>(std::istream& is, id3v2& id);

private:

	//frame get_next_frame(); //const??

	tag_header header;
	extended_tag_header *extended_header;
	//maybe change key type
	std::map<char[4], frame> frames;
	long padding_location;
	unsigned padding_length;
};

