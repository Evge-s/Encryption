// encryption code
#pragma once
#ifndef _IOSTREAM_
#include <iostream>
#endif // !_IOSTREAM_
#ifndef _FSTREAM_
#include <fstream>
#endif // !_FSTREAM_
#ifndef _STRING_
#include <string>
#endif // !_STRING_
#ifndef _VECTOR_
#include <vector>
#endif // !_VECTOR_

class Ecode {	
public:
	std::string Set_data(const std::string& data) {		// Encryption
		std::string temp;
		for (int i = 0; i < data.size(); i++)
			temp += ((int)data[i] + 9);
		return temp;
	}

	std::string Uncode(std::string& data){		// Decryption
		std::string temp;
		for (int i = 0; i < data.size(); i++)
			temp += ((int)data[i] - 9);
		return temp;
	}

};