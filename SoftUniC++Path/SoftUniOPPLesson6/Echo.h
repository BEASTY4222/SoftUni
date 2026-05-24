#pragma once

#include <string>
#include <iostream>

static bool echoOn = true;

class echo {
	std::string text;


public:

	echo(const std::string &ntext):text(ntext) {
		if(echoOn)
			std::cout << text << std::endl;
	
	}
};
