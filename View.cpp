#ifndef _IOSTREAM_
#include <iostream>
#endif // !_IOSTREAM_
#ifndef _STRING_
#include <string>
#endif // !_STRING_
#ifndef _VECTOR_
#include <vector>
#endif // !_VECTOR_
using namespace std;

class View{
public:
	string field;
	bool inputtable;
	View() { inputtable = 0; }

	View init(const std::string field, bool inputtable)
	{
		this->field = field;
		this->inputtable = inputtable;
		return *this;
	}
};


class Page : protected::View
{
protected:
	std::vector<View> pages;
public:
	bool Add_Page(const std::string field, bool inputtable)
	{
		pages.push_back(init(field, inputtable));
		return 1;
	}

	bool Clear_Page()
	{
		if (!pages.empty())
			pages.clear();
		return 1;
	}

	string Control_page() {
		for (size_t i = 0; i < pages.size(); i++)
		{	
			if (!pages[i].inputtable)
				cout << pages[i].field;

			else if (pages[i].inputtable)
			{
				return Set_answer(i);
			}
		}
	}

	string Set_answer(int i)
	{
		cin >> pages[i].field;
		return pages[i].field;
	}
};
