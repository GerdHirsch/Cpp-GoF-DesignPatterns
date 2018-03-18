#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <iostream>
#include <string>

class TextField
{
public:
	void setText(std::string text)
	{
		std::cout << "TextField text: " << text << std::endl;
	}
};

#endif //TEXTFIELD_H