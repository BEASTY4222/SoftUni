#pragma once

#include <string>

class SolfegeNoteNaming {
public:
	char operator()(const std::string &text) const {
		//Do Re Mi Fa Sol La Si unknown end
		//C D E F G A B ?
		if (text == "Do") {
			return 'C';
		}else if (text == "Re") {
			return 'D';
		}
		else if (text == "Mi") {
			return 'E';
		}
		else if (text == "Fa") {
			return 'F';
		}
		else if (text == "Sol") {
			return 'G';
		}
		else if (text == "La") {
			return 'A';
		}
		else if (text == "Si") {
			return 'B';
		}
		else {
			return '?';
		}
	}
};