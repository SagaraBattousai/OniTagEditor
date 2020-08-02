#pragma once
#include <array>
#include <vector>

namespace crc32 {

	static constexpr unsigned polynomial = 0x04C11DB7;

	unsigned calculate_crc(std::vector<unsigned char>& bytes);

	namespace {
		// when >> ints if -ve FF is filled over 0;s
		template <unsigned char top_bit, unsigned crc, int n = 8>
		struct crc32_construct;

		template <unsigned crc, int n>
		struct crc32_construct<1, crc, n> {
			enum { c = (unsigned)((crc << 1) ^ polynomial), value = crc32_construct<((unsigned)c >> 31), c, n - 1 >::value };
		};

		template <unsigned crc, int n>
		struct crc32_construct<0, crc, n> {
			enum { c = (unsigned)(crc << 1), value = crc32_construct<((unsigned)c >> 31), c, n - 1>::value };
		};

		template <unsigned crc>
		struct crc32_construct<0, crc, 0> {
			enum { value = crc };
		};

		template <unsigned crc>
		struct crc32_construct<1, crc, 0> {
			enum { value = crc };
		};

		template <unsigned char byte, unsigned crc = 0>
		struct crc32_table {
			enum { c = crc ^ ((unsigned)byte << 24), value = crc32_construct<((unsigned)c >> 31), c, 8>::value };
		};

		std::array<unsigned, 0x100> generate_crc32_table();
	}
}