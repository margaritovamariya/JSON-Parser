#pragma once
#include "..\Utils\strHelper.h"
#include "..\Models\Json.h"
#include "..\Models\SimpleValue.h"
#include "..\Models\List.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <list>
class App
{
private:

	Json object;
	std::string filePath;
	
	void print();
	void validate(const std::string&);
	void find(const std::string&);
	void save(const std::string& filePath); 
	void saveFile(const std::string& filePath);
	void read();
	void change();
	void deleteObject(const std::string& key, const std::string& value);
	void move();
	
public:
	App();
	void run();
};

