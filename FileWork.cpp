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
using namespace std;

class WFile {
private:
	string path;
public:
	WFile() { path = "base.txt"; }

	bool Set_path(const string& path) {			// Set path to file with data base
		this->path = path;
		return 1;
	}

	string Get_path() { return path; }

	bool Write_to_file(const string& data)		// write to file
	{											
		fstream file(path, std::ios::app);
		if (!file.is_open())
			throw "can't open file for write!";
		else
			file << endl << data << endl;
		file.close();
		return 1;
	}

	bool Comparing_user_data(const string& data)	 // read from file for comparing user data ( email + password )
	{											
		fstream file(path);
		if (!file.is_open())
			throw "can't open file for read!";
		else {
			string buff;
			while (!file.eof()) {
				getline(file, buff);
				if (data == buff)
				{
					file.close();
					return 1;
				}
			}
		}
		file.close();
		return 0;
	}

	bool Comparing_email(const string& data)		 // read from file for mail uniqueness checks
	{
		fstream file(path);
		if (!file.is_open())
			throw "can't open file for read!";
		else {
			string buff;
			while (!file.eof()) {
				getline(file, buff);
				if (buff.find(data) != -1)
				{
					file.close();
					throw "This email is already in use";
				}				
			}
		}
		file.close();
		return 1;
	}

	std::string Read_from_file()				// read from file to string to decrypt later
	{
		string temp;
		fstream file(path, std::ios::in);
		if (!file.is_open())
			throw "can't open file for read!";
		else {
			while (!file.eof()) {
				getline(file, temp);
				temp += "\n";
			}
		}
		file.close();
		return temp;
	}
};