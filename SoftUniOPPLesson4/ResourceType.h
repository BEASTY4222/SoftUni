#ifndef RESOURCE_TYPE_H
#define RESOURCE_TYPE_H

#include <sstream>// not in the skeleton

namespace SoftUni {
	enum ResourceType {
		PRESENTATION,
		DEMO,
		VIDEO
	};

	inline std::ostream& operator<<(std::ostream& out, enum ResourceType t) {
		switch (t)
		{
		case ResourceType::PRESENTATION:
			out << "Presentation";
			break;
		case ResourceType::DEMO:
			out << "Demo";
			break;
		case ResourceType::VIDEO:
			out << "Video";
			break;
		default:
			out << "[unknown]";
			break;
		}

		return out;
	}
}

#endif // !RESOURCE_TYPE_H

