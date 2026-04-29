#pragma once
#include "Resource.h"
#include "ResourceType.h"
#include <sstream>

namespace SoftUni {
	class Lecture {

		std::set<Resource>lectures;

		public:
			int operator[](const ResourceType &type) {
				std::map<ResourceType, int> resTypes;

				for (const Resource & resource : *this) {
					resTypes[resource.getType()]++;
				}

				return resTypes[type];
			}
			
			
			inline std::set<Resource>::iterator begin() {return lectures.begin();}
			inline std::set<Resource>::iterator end() {return lectures.end();}

			Lecture& operator <<(const Resource &resource) {
				std::set<Resource>::iterator itFound = lectures.find(resource);
				if (itFound != lectures.end()) {
					lectures.erase(itFound);
				}
				lectures.insert(resource);

				return *this;
			}
	};
	std::vector<ResourceType>& operator <<(std::vector<ResourceType> &resourceTypes, Lecture &lecture) {
		std::map<ResourceType, int> resTypes;

		for (const Resource& resource : lecture) {
			resTypes[resource.getType()]++;
		}
		for (auto curr : resTypes) {
			resourceTypes.push_back(curr.first);
		}
		return resourceTypes;
	 }
}
