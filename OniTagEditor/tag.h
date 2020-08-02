#pragma once

#include <string>
#include <fstream>
#include <iostream> //or put in sub class?? dont need to so should >> be virtual??

class tag
{
public:
	tag() = default;
	virtual ~tag() = 0;

	virtual tag* read_tag(std::string filename);
	virtual tag* read_tag(std::ifstream& file) = 0;

	//void, bool or int?
	//tags cant contain files else this could not be const 
	virtual void write_tag(std::string filename) const;
	virtual void write_tag(std::ofstream& file) const = 0;

	virtual void display_tag() const = 0;

	virtual void edit_tag() = 0;

	//Change Flac and Mp4 to name of actual tag type, something and atoms...
	enum class tag_type { ID3v1, ID3v2, Flac, Mp4 };

	virtual tag_type get_tag_type() const = 0;

};

