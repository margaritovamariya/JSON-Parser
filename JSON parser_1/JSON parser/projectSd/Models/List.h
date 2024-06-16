#pragma once
#include "Object.h"
#include "SimpleValue.h"
#include <list>

class List : public JsonValue
{
private:
	std::list<Object*> listValues;
public:
	List();
	void write(std::ostream& out) const override;
	void findIn(const std::string& key, std::list<JsonValue*>& values) override;
	int getSize() const;
};

