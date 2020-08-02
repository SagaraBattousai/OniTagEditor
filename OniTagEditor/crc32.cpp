#include "crc32.h"

namespace crc32 {

	unsigned calculate_crc(std::vector<unsigned char>& bytes)
	{
		std::array<unsigned, 0x100> table = generate_crc32_table();

		unsigned crc = 0xFFFFFFFF;

		for (unsigned char& b : bytes)
		{
			unsigned char lookup = (crc ^ ((unsigned)b << 24)) >> 24;

			crc = (unsigned)((crc << 8) ^ (unsigned)(table[lookup]));
		}

		return crc;
	}


	namespace {

		std::array<unsigned, 0x100> generate_crc32_table()
		{
			std::array<unsigned, 0x100> crc_table;

			crc_table[0x0] = crc32_table<0x0>::value;       crc_table[0x1] = crc32_table<0x1>::value;
			crc_table[0x2] = crc32_table<0x2>::value;       crc_table[0x3] = crc32_table<0x3>::value;
			crc_table[0x4] = crc32_table<0x4>::value;       crc_table[0x5] = crc32_table<0x5>::value;
			crc_table[0x6] = crc32_table<0x6>::value;       crc_table[0x7] = crc32_table<0x7>::value;
			crc_table[0x8] = crc32_table<0x8>::value;       crc_table[0x9] = crc32_table<0x9>::value;
			crc_table[0xa] = crc32_table<0xa>::value;       crc_table[0xb] = crc32_table<0xb>::value;
			crc_table[0xc] = crc32_table<0xc>::value;       crc_table[0xd] = crc32_table<0xd>::value;
			crc_table[0xe] = crc32_table<0xe>::value;       crc_table[0xf] = crc32_table<0xf>::value;
			crc_table[0x10] = crc32_table<0x10>::value;     crc_table[0x11] = crc32_table<0x11>::value;
			crc_table[0x12] = crc32_table<0x12>::value;     crc_table[0x13] = crc32_table<0x13>::value;
			crc_table[0x14] = crc32_table<0x14>::value;     crc_table[0x15] = crc32_table<0x15>::value;
			crc_table[0x16] = crc32_table<0x16>::value;     crc_table[0x17] = crc32_table<0x17>::value;
			crc_table[0x18] = crc32_table<0x18>::value;     crc_table[0x19] = crc32_table<0x19>::value;
			crc_table[0x1a] = crc32_table<0x1a>::value;     crc_table[0x1b] = crc32_table<0x1b>::value;
			crc_table[0x1c] = crc32_table<0x1c>::value;     crc_table[0x1d] = crc32_table<0x1d>::value;
			crc_table[0x1e] = crc32_table<0x1e>::value;     crc_table[0x1f] = crc32_table<0x1f>::value;
			crc_table[0x20] = crc32_table<0x20>::value;     crc_table[0x21] = crc32_table<0x21>::value;
			crc_table[0x22] = crc32_table<0x22>::value;     crc_table[0x23] = crc32_table<0x23>::value;
			crc_table[0x24] = crc32_table<0x24>::value;     crc_table[0x25] = crc32_table<0x25>::value;
			crc_table[0x26] = crc32_table<0x26>::value;     crc_table[0x27] = crc32_table<0x27>::value;
			crc_table[0x28] = crc32_table<0x28>::value;     crc_table[0x29] = crc32_table<0x29>::value;
			crc_table[0x2a] = crc32_table<0x2a>::value;     crc_table[0x2b] = crc32_table<0x2b>::value;
			crc_table[0x2c] = crc32_table<0x2c>::value;     crc_table[0x2d] = crc32_table<0x2d>::value;
			crc_table[0x2e] = crc32_table<0x2e>::value;     crc_table[0x2f] = crc32_table<0x2f>::value;
			crc_table[0x30] = crc32_table<0x30>::value;     crc_table[0x31] = crc32_table<0x31>::value;
			crc_table[0x32] = crc32_table<0x32>::value;     crc_table[0x33] = crc32_table<0x33>::value;
			crc_table[0x34] = crc32_table<0x34>::value;     crc_table[0x35] = crc32_table<0x35>::value;
			crc_table[0x36] = crc32_table<0x36>::value;     crc_table[0x37] = crc32_table<0x37>::value;
			crc_table[0x38] = crc32_table<0x38>::value;     crc_table[0x39] = crc32_table<0x39>::value;
			crc_table[0x3a] = crc32_table<0x3a>::value;     crc_table[0x3b] = crc32_table<0x3b>::value;
			crc_table[0x3c] = crc32_table<0x3c>::value;     crc_table[0x3d] = crc32_table<0x3d>::value;
			crc_table[0x3e] = crc32_table<0x3e>::value;     crc_table[0x3f] = crc32_table<0x3f>::value;
			crc_table[0x40] = crc32_table<0x40>::value;     crc_table[0x41] = crc32_table<0x41>::value;
			crc_table[0x42] = crc32_table<0x42>::value;     crc_table[0x43] = crc32_table<0x43>::value;
			crc_table[0x44] = crc32_table<0x44>::value;     crc_table[0x45] = crc32_table<0x45>::value;
			crc_table[0x46] = crc32_table<0x46>::value;     crc_table[0x47] = crc32_table<0x47>::value;
			crc_table[0x48] = crc32_table<0x48>::value;     crc_table[0x49] = crc32_table<0x49>::value;
			crc_table[0x4a] = crc32_table<0x4a>::value;     crc_table[0x4b] = crc32_table<0x4b>::value;
			crc_table[0x4c] = crc32_table<0x4c>::value;     crc_table[0x4d] = crc32_table<0x4d>::value;
			crc_table[0x4e] = crc32_table<0x4e>::value;     crc_table[0x4f] = crc32_table<0x4f>::value;
			crc_table[0x50] = crc32_table<0x50>::value;     crc_table[0x51] = crc32_table<0x51>::value;
			crc_table[0x52] = crc32_table<0x52>::value;     crc_table[0x53] = crc32_table<0x53>::value;
			crc_table[0x54] = crc32_table<0x54>::value;     crc_table[0x55] = crc32_table<0x55>::value;
			crc_table[0x56] = crc32_table<0x56>::value;     crc_table[0x57] = crc32_table<0x57>::value;
			crc_table[0x58] = crc32_table<0x58>::value;     crc_table[0x59] = crc32_table<0x59>::value;
			crc_table[0x5a] = crc32_table<0x5a>::value;     crc_table[0x5b] = crc32_table<0x5b>::value;
			crc_table[0x5c] = crc32_table<0x5c>::value;     crc_table[0x5d] = crc32_table<0x5d>::value;
			crc_table[0x5e] = crc32_table<0x5e>::value;     crc_table[0x5f] = crc32_table<0x5f>::value;
			crc_table[0x60] = crc32_table<0x60>::value;     crc_table[0x61] = crc32_table<0x61>::value;
			crc_table[0x62] = crc32_table<0x62>::value;     crc_table[0x63] = crc32_table<0x63>::value;
			crc_table[0x64] = crc32_table<0x64>::value;     crc_table[0x65] = crc32_table<0x65>::value;
			crc_table[0x66] = crc32_table<0x66>::value;     crc_table[0x67] = crc32_table<0x67>::value;
			crc_table[0x68] = crc32_table<0x68>::value;     crc_table[0x69] = crc32_table<0x69>::value;
			crc_table[0x6a] = crc32_table<0x6a>::value;     crc_table[0x6b] = crc32_table<0x6b>::value;
			crc_table[0x6c] = crc32_table<0x6c>::value;     crc_table[0x6d] = crc32_table<0x6d>::value;
			crc_table[0x6e] = crc32_table<0x6e>::value;     crc_table[0x6f] = crc32_table<0x6f>::value;
			crc_table[0x70] = crc32_table<0x70>::value;     crc_table[0x71] = crc32_table<0x71>::value;
			crc_table[0x72] = crc32_table<0x72>::value;     crc_table[0x73] = crc32_table<0x73>::value;
			crc_table[0x74] = crc32_table<0x74>::value;     crc_table[0x75] = crc32_table<0x75>::value;
			crc_table[0x76] = crc32_table<0x76>::value;     crc_table[0x77] = crc32_table<0x77>::value;
			crc_table[0x78] = crc32_table<0x78>::value;     crc_table[0x79] = crc32_table<0x79>::value;
			crc_table[0x7a] = crc32_table<0x7a>::value;     crc_table[0x7b] = crc32_table<0x7b>::value;
			crc_table[0x7c] = crc32_table<0x7c>::value;     crc_table[0x7d] = crc32_table<0x7d>::value;
			crc_table[0x7e] = crc32_table<0x7e>::value;     crc_table[0x7f] = crc32_table<0x7f>::value;
			crc_table[0x80] = crc32_table<0x80>::value;     crc_table[0x81] = crc32_table<0x81>::value;
			crc_table[0x82] = crc32_table<0x82>::value;     crc_table[0x83] = crc32_table<0x83>::value;
			crc_table[0x84] = crc32_table<0x84>::value;     crc_table[0x85] = crc32_table<0x85>::value;
			crc_table[0x86] = crc32_table<0x86>::value;     crc_table[0x87] = crc32_table<0x87>::value;
			crc_table[0x88] = crc32_table<0x88>::value;     crc_table[0x89] = crc32_table<0x89>::value;
			crc_table[0x8a] = crc32_table<0x8a>::value;     crc_table[0x8b] = crc32_table<0x8b>::value;
			crc_table[0x8c] = crc32_table<0x8c>::value;     crc_table[0x8d] = crc32_table<0x8d>::value;
			crc_table[0x8e] = crc32_table<0x8e>::value;     crc_table[0x8f] = crc32_table<0x8f>::value;
			crc_table[0x90] = crc32_table<0x90>::value;     crc_table[0x91] = crc32_table<0x91>::value;
			crc_table[0x92] = crc32_table<0x92>::value;     crc_table[0x93] = crc32_table<0x93>::value;
			crc_table[0x94] = crc32_table<0x94>::value;     crc_table[0x95] = crc32_table<0x95>::value;
			crc_table[0x96] = crc32_table<0x96>::value;     crc_table[0x97] = crc32_table<0x97>::value;
			crc_table[0x98] = crc32_table<0x98>::value;     crc_table[0x99] = crc32_table<0x99>::value;
			crc_table[0x9a] = crc32_table<0x9a>::value;     crc_table[0x9b] = crc32_table<0x9b>::value;
			crc_table[0x9c] = crc32_table<0x9c>::value;     crc_table[0x9d] = crc32_table<0x9d>::value;
			crc_table[0x9e] = crc32_table<0x9e>::value;     crc_table[0x9f] = crc32_table<0x9f>::value;
			crc_table[0xa0] = crc32_table<0xa0>::value;     crc_table[0xa1] = crc32_table<0xa1>::value;
			crc_table[0xa2] = crc32_table<0xa2>::value;     crc_table[0xa3] = crc32_table<0xa3>::value;
			crc_table[0xa4] = crc32_table<0xa4>::value;     crc_table[0xa5] = crc32_table<0xa5>::value;
			crc_table[0xa6] = crc32_table<0xa6>::value;     crc_table[0xa7] = crc32_table<0xa7>::value;
			crc_table[0xa8] = crc32_table<0xa8>::value;     crc_table[0xa9] = crc32_table<0xa9>::value;
			crc_table[0xaa] = crc32_table<0xaa>::value;     crc_table[0xab] = crc32_table<0xab>::value;
			crc_table[0xac] = crc32_table<0xac>::value;     crc_table[0xad] = crc32_table<0xad>::value;
			crc_table[0xae] = crc32_table<0xae>::value;     crc_table[0xaf] = crc32_table<0xaf>::value;
			crc_table[0xb0] = crc32_table<0xb0>::value;     crc_table[0xb1] = crc32_table<0xb1>::value;
			crc_table[0xb2] = crc32_table<0xb2>::value;     crc_table[0xb3] = crc32_table<0xb3>::value;
			crc_table[0xb4] = crc32_table<0xb4>::value;     crc_table[0xb5] = crc32_table<0xb5>::value;
			crc_table[0xb6] = crc32_table<0xb6>::value;     crc_table[0xb7] = crc32_table<0xb7>::value;
			crc_table[0xb8] = crc32_table<0xb8>::value;     crc_table[0xb9] = crc32_table<0xb9>::value;
			crc_table[0xba] = crc32_table<0xba>::value;     crc_table[0xbb] = crc32_table<0xbb>::value;
			crc_table[0xbc] = crc32_table<0xbc>::value;     crc_table[0xbd] = crc32_table<0xbd>::value;
			crc_table[0xbe] = crc32_table<0xbe>::value;     crc_table[0xbf] = crc32_table<0xbf>::value;
			crc_table[0xc0] = crc32_table<0xc0>::value;     crc_table[0xc1] = crc32_table<0xc1>::value;
			crc_table[0xc2] = crc32_table<0xc2>::value;     crc_table[0xc3] = crc32_table<0xc3>::value;
			crc_table[0xc4] = crc32_table<0xc4>::value;     crc_table[0xc5] = crc32_table<0xc5>::value;
			crc_table[0xc6] = crc32_table<0xc6>::value;     crc_table[0xc7] = crc32_table<0xc7>::value;
			crc_table[0xc8] = crc32_table<0xc8>::value;     crc_table[0xc9] = crc32_table<0xc9>::value;
			crc_table[0xca] = crc32_table<0xca>::value;     crc_table[0xcb] = crc32_table<0xcb>::value;
			crc_table[0xcc] = crc32_table<0xcc>::value;     crc_table[0xcd] = crc32_table<0xcd>::value;
			crc_table[0xce] = crc32_table<0xce>::value;     crc_table[0xcf] = crc32_table<0xcf>::value;
			crc_table[0xd0] = crc32_table<0xd0>::value;     crc_table[0xd1] = crc32_table<0xd1>::value;
			crc_table[0xd2] = crc32_table<0xd2>::value;     crc_table[0xd3] = crc32_table<0xd3>::value;
			crc_table[0xd4] = crc32_table<0xd4>::value;     crc_table[0xd5] = crc32_table<0xd5>::value;
			crc_table[0xd6] = crc32_table<0xd6>::value;     crc_table[0xd7] = crc32_table<0xd7>::value;
			crc_table[0xd8] = crc32_table<0xd8>::value;     crc_table[0xd9] = crc32_table<0xd9>::value;
			crc_table[0xda] = crc32_table<0xda>::value;     crc_table[0xdb] = crc32_table<0xdb>::value;
			crc_table[0xdc] = crc32_table<0xdc>::value;     crc_table[0xdd] = crc32_table<0xdd>::value;
			crc_table[0xde] = crc32_table<0xde>::value;     crc_table[0xdf] = crc32_table<0xdf>::value;
			crc_table[0xe0] = crc32_table<0xe0>::value;     crc_table[0xe1] = crc32_table<0xe1>::value;
			crc_table[0xe2] = crc32_table<0xe2>::value;     crc_table[0xe3] = crc32_table<0xe3>::value;
			crc_table[0xe4] = crc32_table<0xe4>::value;     crc_table[0xe5] = crc32_table<0xe5>::value;
			crc_table[0xe6] = crc32_table<0xe6>::value;     crc_table[0xe7] = crc32_table<0xe7>::value;
			crc_table[0xe8] = crc32_table<0xe8>::value;     crc_table[0xe9] = crc32_table<0xe9>::value;
			crc_table[0xea] = crc32_table<0xea>::value;     crc_table[0xeb] = crc32_table<0xeb>::value;
			crc_table[0xec] = crc32_table<0xec>::value;     crc_table[0xed] = crc32_table<0xed>::value;
			crc_table[0xee] = crc32_table<0xee>::value;     crc_table[0xef] = crc32_table<0xef>::value;
			crc_table[0xf0] = crc32_table<0xf0>::value;     crc_table[0xf1] = crc32_table<0xf1>::value;
			crc_table[0xf2] = crc32_table<0xf2>::value;     crc_table[0xf3] = crc32_table<0xf3>::value;
			crc_table[0xf4] = crc32_table<0xf4>::value;     crc_table[0xf5] = crc32_table<0xf5>::value;
			crc_table[0xf6] = crc32_table<0xf6>::value;     crc_table[0xf7] = crc32_table<0xf7>::value;
			crc_table[0xf8] = crc32_table<0xf8>::value;     crc_table[0xf9] = crc32_table<0xf9>::value;
			crc_table[0xfa] = crc32_table<0xfa>::value;     crc_table[0xfb] = crc32_table<0xfb>::value;
			crc_table[0xfc] = crc32_table<0xfc>::value;     crc_table[0xfd] = crc32_table<0xfd>::value;
			crc_table[0xfe] = crc32_table<0xfe>::value;     crc_table[0xff] = crc32_table<0xff>::value;

			return crc_table;
		}
	}
}