typedef struct {
	char id[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[30];
	char genre;
}id3v1;

typedef struct {
	char id[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[28];
	//Empty Byte
	char empty;
	char track;
	char genre;
}id3v1_1;

typedef struct {
	unsigned char buf[3];
	unsigned char ver;
	unsigned char min;
	unsigned char flags;
	unsigned char remainingTagSize[4];
}tagHeader;

typedef struct {
	unsigned char frameID[4];
	unsigned char remainingFrameSize[4];
	unsigned char flags[2];
}frameHeader;

typedef struct {
	unsigned char textEncoding;
	char *info;
}textBodyFrame;

typedef struct {
	frameHeader *header;
	void *frameBody;
	long frameLocation;
}frame;

typedef struct {
	tagHeader *header;
	hashmap_t *frames;//frame *frames;
	long padding_location;
	unsigned padding_length;
}mp3Tag;

typedef struct {
	const char *filename;
	long amountRead;
	long fileLength;
	mp3Tag *tag;
}mp3Info;