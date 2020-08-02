#include "tag.h"

tag* tag::read_tag(std::string filename)
{
	std::ifstream file(filename);
	tag *tag = read_tag(file);
	file.close();
	return tag;
}

void tag::write_tag(std::string filename) const
{
	std::ofstream file(filename);
	write_tag(file);
	file.close();
}