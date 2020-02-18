#ifndef _IOSTREAM_
#include <iostream>
#endif // !_IOSTREAM_
#ifndef _STRING_
#include <string>
#endif // !_STRING_
#ifndef _MAP_
#include <map>
#endif // _MAP_
#include "C:\Users\KDFX Team\source\repos\Encryption_project\Check_list.cpp"
#include "C:\Users\KDFX Team\source\repos\Encryption_project\View.cpp"

class Controller {
protected:
	Page one;
	Check_List check_list;
	string data;
public:
	// pass import init block to View
	bool Main_menu() {	// init the fields of page	
		one.Clear_Page();
		one.Add_Page("\t\t\t Authorization\n\n", 0);
		one.Add_Page("1. Registration\n", 0);
		one.Add_Page("2. Login\n", 0);
		one.Add_Page("0. Exit\n\n", 0);
		one.Add_Page("-> ", 1);
		return 1;
	}
	
	bool Reg_email() {	
		one.Clear_Page();
		one.Add_Page("\t\t\t Registration\n\n", 0);
		one.Add_Page("1. Enter your email: ", 0);
		one.Add_Page("-> ", 1);
		return 1;
	}

	bool Reg_password() {
		one.Clear_Page();
		one.Add_Page("\t\t\t Registration\n\n", 0);
		one.Add_Page("2. Enter your password: ", 0);
		one.Add_Page("-> ", 1);
		return 1;
	}
	
	bool Reg_end() {
		one.Clear_Page();
		one.Add_Page("\n\t\t\t Congratulations, you are now a registered user\n\n", 0);
		one.Add_Page("-> ", 1);
		return 1;
	}

	bool Log_email() {
		one.Clear_Page();
		one.Add_Page("\t\t\t Login\n\n", 0);
		one.Add_Page("1. Enter your email: ", 0);
		one.Add_Page("-> ", 1);
		return 1;
	}

	bool Log_password() {
		one.Clear_Page();
		one.Add_Page("\t\t\t Login\n\n", 0);
		one.Add_Page("1. Enter your password: ", 0);
		one.Add_Page("-> ", 1);
		return 1;
	}

	bool Log_True() {
		one.Clear_Page();
		one.Add_Page("\n\t\t\t Welcome to Data Base\n\n", 0);
		one.Add_Page("-> ", 1);
		return 1;
	}

	bool Log_False() {
		one.Clear_Page();
		one.Add_Page("\n\Invalid e-mail or password!\n\n", 0);
		one.Add_Page("-> ", 1);
		return 1;
	}

	bool Data_Base() {
		one.Clear_Page();
		one.Add_Page(data, 0);
		return 1;
	}
	
	void Start() {			// navigations logic of pages
		system("cls");
		Main_menu();
		while (99) {
			data = one.Control_page();
			if (data == "1")
			{
				system("cls");
				Reg_email();
				data = one.Control_page();
				system("cls");
				if (!check_list.Reg_Email(data))
				{
					system("pause");
					Start();
				}
				Reg_password();
				data = one.Control_page();
				system("cls");
				if (!check_list.Reg_Password(data))
				{
					system("pause");
					Start();
				}			
				Reg_end();
				check_list.Save_data();
				data = one.Control_page();
				if (data == "0")
					break;
				else
					Start();
			}
			if (data == "2") {
				system("cls");
				Log_email();
				data = one.Control_page();
				system("cls");
				Log_password();
				data += " " + one.Control_page();
				system("cls");
				if(check_list.Login(data))
					Log_True();
				else
					Log_False();
				data = one.Control_page();
				if (data == "0")
					break;
				else
					Start();
			}
			if(data == "0") {
				system("cls");
				break;
			}
			else {
				one.Clear_Page();
				Start();
			}
		}
		
	}


};