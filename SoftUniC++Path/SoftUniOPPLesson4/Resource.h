#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h" // Ensure ResourceType.h is in the same directory as Resource.h
#include <sstream>
#include <string>
#include <ostream> // Include for std::ostream

namespace SoftUni {
	class Resource {
		int id;
		ResourceType type;
		std::string link;

		public:
			inline int getId() const { return id; } 
			inline std::string getLink() const { return link; }

            inline ResourceType getType() const { return type; }

			friend std::istream& operator>>(std::istream& in, Resource& resource) {
				std::string strType;
				in >> resource.id >> strType >> resource.link;

				if (strType == "Presentation") resource.type = ResourceType::PRESENTATION;
				else if (strType == "Demo") resource.type = ResourceType::DEMO;
				else if (strType == "Video") resource.type = ResourceType::VIDEO;

				return in;
			}

			// Add the missing friend operator<< for std::ostream
			friend std::ostream& operator<<(std::ostream& out, const Resource& resource) {
				out << resource.id << " " << resource.type << " " << resource.link;
				return out;
			}
			
	};
	bool operator<(const Resource& lhs, const Resource& rhs) {
		return lhs.getId() < rhs.getId(); // Now compatible with const objects
	}
}

#endif // !RESOURCE_H
