#include "id3v2.h"


id3v2::id3v2(): extended_header(0)
{
}


id3v2::~id3v2()
{
}

id3v2* id3v2::read_tag(std::ifstream& file)
{

	return nullptr;
}

void id3v2::write_tag(std::ofstream& file) const
{
}

void id3v2::display_tag() const
{
}

void id3v2::edit_tag()
{
}

tag::tag_type id3v2::get_tag_type() const
{
	return tag_type::ID3v2;
}

std::istream& operator>>(std::istream& is, id3v2& id)
{
	tag_header header;

	is >> header;

	return is;

}
