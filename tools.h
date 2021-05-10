#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <sstream>
#include <vector>
#include <iterator>
#include <string>
#include <cstdio>
#include <stdint.h>


union intUnion {
	uint8_t i8[8];
	uint16_t i16[4];
	uint32_t i32[2];
	uint64_t i64[1];
};


std::string HexToStr( const uint8_t* in, int len);
std::string HexToStr( const std::vector<uint8_t>& in);
std::vector<uint8_t> StrToHex( const std::string& in);

std::string HexToAscii(const std::string& str);
std::string AsciiToHex(const std::string& str);

std::string HexToAscii(std::vector<uint8_t> binary);

std::string HexString(const std::string& val);
std::string FixedLenPadString(const std::string& val,int len);
std::string PaddedFixedLenString(const std::string& val,int len, char ch='0');

std::string FixedLenHexString(uint32_t val,int len);
int StrToHex( const char *in, int len, uint8_t *out);

#endif //_TOOLS_H_

