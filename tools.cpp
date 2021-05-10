#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include "tools.h"




std::string HexToStr( const std::vector<uint8_t>& in) {
	std::stringstream str;
	for(size_t i=0;i<in.size();i++)	{
		str << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(in[i]);
	}
	return str.str();
}
std::string HexToStr( const uint8_t* in, int len) {
    std::stringstream str;
    for(size_t i=0;i<len;i++)	{
        str << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(in[i]);
    }
    return str.str();
}
std::vector<uint8_t> StrToHex( const std::string& in) {
	std::vector<uint8_t> hex;
	std::string val;

	if(in.length()%2==0) {
		val=in;
	} else {
		val="0"+in;
	}

	for(size_t i=0; i < val.length(); i+=2){
		int num;
		std::stringstream(val.substr(i,2)) >> std::hex >> num;
		//std::cout << std::hex << "i: " << num << std::endl;
		hex.push_back(static_cast<uint8_t>(num));
	}
	return hex;
}



std::string HexString(const std::string& val){
	std::stringstream ss;
	for (size_t i=0; i< val.size(); i++){
		ss << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(static_cast<uint8_t>(val[i]));
	}
	return ss.str();
}

// Fixed len BCD
std::string PaddedFixedLenString(const std::string& val,int len, char ch){
	std::string str=std::string(len-val.size(),ch)+val;
	return str;
}


std::string AsciiToHex(const std::string& str){
	return HexString(str);
}
std::string HexToAscii(std::vector<uint8_t> binary){
	std::stringstream ss;
	for(size_t i=0; i<binary.size();i++){
		ss << binary[i] ;
	}
	return ss.str();
}
std::string HexToAscii(const std::string& str){
	std::stringstream ss;
	std::vector<uint8_t> binary=StrToHex(str);
	for(size_t i=0; i<binary.size();i++){
		ss << binary[i] ;
	}
	return ss.str();
}

std::string FixedLenHexString(uint32_t val,int len){
	std::string ss = FixedLenDecString(val,len/2);
	return HexString(ss);
}


int StrToHex( const char *in, int len, uint8_t *out)	{
	int i,j;
	char temp[3];
	if(len%2!=0){
		return 0;
	}
	for (i = 0, j=0; i < len; i+=2, j++){
		temp[0]=in[i];
		temp[1]=in[i+1];
		temp[2]=0;
		out[j] = strtol(temp, NULL, 16);
	}
	return j;
}

