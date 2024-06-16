#pragma once
#include "JsonValue.h"
#include <string>
#include <regex>

class SimpleValue : public JsonValue
{
private:
	std::string value;
public:
	SimpleValue(const std::string& key, const std::string& );

	std::string getKey();
	std::string getValue();
	void write(std::ostream& out) const override;
    void findIn(const std::string& key, std::list<JsonValue*>& values) override;

};

