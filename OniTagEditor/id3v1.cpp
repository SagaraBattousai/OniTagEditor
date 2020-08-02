
#include "id3v1.h"


id3v1::id3v1(std::string filename)
{

}

id3v1::id3v1(std::fstream& file)
{
}


id3v1::~id3v1()
{
}

id3v1* id3v1::read_tag(std::ifstream& file)
{

}

void id3v1::write_tag(std::ofstream& file) const
{
}

void id3v1::edit_tag()
{

}

void id3v1::display_tag() const
{

}

tag::tag_type id3v1::get_tag_type() const
{
	return tag_type::ID3v1;
}
