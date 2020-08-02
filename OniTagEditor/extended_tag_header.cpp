#include "extended_tag_header.h"
#include <sstream>


std::istream& operator>>(std::istream& is, extended_tag_header& eth)
{
	is.read((char *)eth.header_size.data(), eth.header_size.size());
	is.read((char *)eth.flags.data(), eth.flags.size());
	is.read((char *)eth.padding_size.data(), eth.padding_size.size());
	is.read((char *)eth.crc_data.data(), eth.crc_data.size());

	}

std::ostream& operator<<(std::ostream& os, extended_tag_header& eth)
{
	os << "Extended Header is " << (unsigned)eth.get_header_size() << " bytes." << std::endl;

	bool crc_present = eth.crc_data_present();
	std::string crc_set = crc_present ? "is" : "isn't";

	os << "Crc data " << crc_set << " set" << std::endl;

	if (crc_present) 
	{
		os << "\t Crc is: " << eth.get_crc_data() << std::endl;

	}

	return os;
}


unsigned extended_tag_header::get_header_size() {

	return header_size[3] << 24 |
				 header_size[2] << 16 |
				 header_size[1] << 8  |
				 header_size[0];

}

bool extended_tag_header::crc_data_present() {

	return flags[0] | 0x80;

}

unsigned extended_tag_header::get_padding_size() {
	
	return padding_size[3] << 24 |
				 padding_size[2] << 16 |
				 padding_size[1] << 8 |
				 padding_size[0];
}

unsigned extended_tag_header::get_crc_data() {

	return 0;
}
