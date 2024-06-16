#pragma once
#include "JsonValue.h"
#include "List.h"
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <regex>
#include <stack>
#include <list>
class Json
{
private:
	std::list<JsonValue*> jsonValues;

public:
	Json();
	bool validation(std::istream&);
	bool validationCheck(const std::string&);
	void addElement(JsonValue* value);
	void print(std::ostream&) const;
	std::list<JsonValue*> find(const std::string& key);
	void removeElement(JsonValue* value);
};

