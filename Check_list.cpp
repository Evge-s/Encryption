#pragma once
#ifndef _STRING_
#include <string>
#endif // !_STRING_
#include "C:\Users\KDFX Team\source\repos\Encryption_project\Encryption.cpp"
#include "C:\Users\KDFX Team\source\repos\Encryption_project\FileWork.cpp"

class Email { // pass validation
private:
	string email;
public:
	bool Set_email(const std::string& mail) {
		email = mail;
		return 1;
	}
	std::string Get_email() { return email; }
};

class Password {	// pass	validation
private:
	std::string password;
public:		
	bool Set_password(const std::string& pass) {
		password = pass;
		return 1;
	}
	std::string Get_password() { return password; }
};


class Check_List {
protected:
	Ecode crypt;
	WFile file;
	Email email;
	Password password;
public:

	bool Reg_Email(const std::string& mail) {	
		try
		{
			email.Set_email(mail);
			file.Comparing_email(crypt.Set_data(email.Get_email()));	// check mail for uniqueness		
		}
		catch (const char* error)
		{
			cout << error << endl << endl;
			return 0;
		}
		return 1;
	}
	bool Reg_Password(const std::string& pass) {
		try
		{
			password.Set_password(pass);
		}
		catch (const char* error)
		{
			cout << error << endl << endl;
			return 0;
		}
		return 1;
	}

	bool Save_data()		// write data to db
	{
		try {
			file.Write_to_file(crypt.Set_data(email.Get_email() + " " + password.Get_password()));
		}
		catch (const char* error)
		{
			cout << error << endl << endl;
			return 0;
		}
		return 1;
	}

	bool Login (const std::string& data){		
		try {
			if (file.Comparing_user_data(crypt.Set_data(data)))	//	comparing input data
				return 1;
			else
				return 0;
		}
		catch (const char* error)
		{
			cout << error << endl << endl;
			return 0;
		}
		return 1;
	}
};