/** Packager.h
 *
 * License: This source code can be used and/or modified without restrictions.
 * It is provided as is and the author disclaims all warranties, expressed 
 * or implied, including, without limitation, the warranties of
 * merchantability and of fitness for any purpose. The user must assume the
 * entire risk of using the Software.
 *
 * @author Samira Lagzian
 *
 * @version 0.1 -- 28 October 2019
 */

#pragma once
#include <string>
#include <vector>


#define RET_NOK      -1
#define RET_OK        0



enum TypeDataFormat{BCD=1,HEX=2,ASC=3};

struct DataFormat{
	int len;
	TypeDataFormat dataFormat;
	DataFormat(int len,TypeDataFormat dataFormat):len(len),dataFormat(dataFormat){};
	DataFormat ():len(0),dataFormat(BCD){};
};

class Packager {
public:

	std::vector<uint8_t> pack(int tag,const std::string &value,int lenbyte=1) const;
    int unpack(const std::vector<uint8_t>& msg,std::string &value) const;
	const Packager& setFormat(const DataFormat& df){
		format=df;
		return *this;
	}

private:
	DataFormat format;
	
};

