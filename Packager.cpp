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

#include <iostream>
#include "Packager.h"
#include "tools.h"

std::vector<uint8_t> Packager::pack(int tag,const std::string &value,int lenbyte) const {
	std::vector<uint8_t> buffer;
    std::vector<uint8_t> output;
	

	if (format.dataFormat==BCD  || format.dataFormat==HEX){		
	
        buffer=StrToHex(value);
	}
	else if (format.dataFormat==ASC){
	
		buffer=StrToHex(AsciiToHex(value));
	
	}

	output.push_back(tag);
	{
		std::string lenStr = PaddedFixedLenString(toString(buffer.size()),2*format.len);	
	    std::vector<uint8_t> lenValue = StrToHex(lenStr); 
		output.insert(output.end(),lenValue.begin(),lenValue.end());
	}

	output.insert(output.end(),buffer.begin(),buffer.end());
    return output;	
}

int Packager::unpack(const std::vector<uint8_t>& msg,std::string &value) const{
    std::vector<uint8_t> lenValue(msg.begin()+1, msg.begin()+format.len+1); 
	int len = atoi(HexToStr(lenValue).c_str());			
    std::vector<uint8_t> tempValue(msg.begin() + format.len +1, msg.begin()+ len +format.len +1); 

	if (format.dataFormat==BCD || format.dataFormat==HEX){
		value=HexToStr(tempValue);			
	}
	else{
		value=HexToAscii(tempValue);
	}
	return tempValue.size()+format.len+1;//lenght of message	
}




