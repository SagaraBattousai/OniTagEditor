#include "tag_header.h"
#include <sstream>


std::istream& operator>>(std::istream& is, tag_header& th)
{
	is.read(th.file_id.data(), th.file_id.size());
	is.read((char *) th.version.data(), th.version.size());
	//is.read(th.minor.data(), th.minor.size());
	is.read((char *) &(th.flags), 1);
	is.read((char *)th.remaining_tag_size.data(), th.remaining_tag_size.size());
}

std::ostream& operator<<(std::ostream& os, tag_header& th)
{
	os << "File ID: " << th.get_file_id() << std::endl
		<< "Version: 2." << th.get_version() << std::endl
		<< "Flags Set:" << std::endl
		<< "\t Unsyncronization: " << th.unsync_set() << std::endl
		<< "\t Extended Header: " << th.extended_header_set() << std::endl
		<< "\t Experimental: " << th.experimental_indicator_set() << std::endl
		<< "Remaining Tag Size: " << th.get_remaining_tag_size() << std::endl;

	return os;
}

std::string tag_header::get_file_id()
{
	return std::string(file_id.data(), file_id.size());
}

std::string tag_header::get_version()
{
	std::stringstream ss;

	//Ive forgotten why i made it std::hex!
	ss << std::hex << (unsigned) get_major_version() << "." << (unsigned) get_minor_version();

	return ss.str();

}

unsigned char tag_header::get_major_version()
{
	return version[0];
}

unsigned char tag_header::get_minor_version()
{
	return version[1];
}

bool tag_header::unsync_set()
{
	return flags & 0x80;
}

bool tag_header::extended_header_set()
{
	return flags & 0x40;
}

bool tag_header::experimental_indicator_set()
{
	return flags & 0x20;
}

unsigned tag_header::get_remaining_tag_size()
{
	return remaining_tag_size[0] << 21 |
				 remaining_tag_size[1] << 14 |
				 remaining_tag_size[2] << 7 |
				 remaining_tag_size[3];
}
