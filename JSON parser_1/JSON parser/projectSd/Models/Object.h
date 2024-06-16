#pragma once
#include "JsonValue.h"
#include <string>
#include <list>
#include <regex>

class Object : public JsonValue
{
private:
	std::list<JsonValue*> jsonChilds;
public:
	Object();
	Object(std::string key, std::list<JsonValue*> list);
	
	void write(std::ostream& out) const override;
	int getSize() const;
	void findIn(const std::string& key, std::list<JsonValue*>& values) override;
};

