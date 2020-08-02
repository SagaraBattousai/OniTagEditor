#pragma once
#include "tag.h"

class id3v1 :
	public tag
{
public:
	id3v1(std::string filename);
	//can cross dll??
	id3v1(std::fstream& file);
	~id3v1();

	virtual id3v1* read_tag(std::ifstream& file) override;
	virtual void edit_tag() override; //No idea what the parameter is!
	virtual void write_tag(std::ofstream& file) const override;
	virtual void display_tag() const override;
	virtual tag::tag_type get_tag_type() const override;

private:
	char check_for_album_track();

	constexpr static char id[3] = { 'T', 'A', 'G' };
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[28];
	char track;
	char genre;

};

