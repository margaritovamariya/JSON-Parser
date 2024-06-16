// projectSd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <fstream>
#include "App/App.h"


int main()
{
	App* app = new App();
	app->run();


	delete app;

	/*Json firstTry;

	const std::string& filePath = "newFile.json";
	std::cout << std::boolalpha<< firstTry.validationCheck(filePath);

	std::string patternLine = "\\s*(.+)\\w(.+):(.+)[\\w\\s](.+)";
	std::regex regexRuleForLine(patternLine);

	std::string patternLine2 = "\\s*(.+)\\w(.+):\\s[[]";
	std::regex regexRuleForLine(patternLine2);

	std::string str = " \"name\": [";

	bool isValid = regex_match(str, regexRuleForLine);

    std::string patternLine = "(\\s*([\"])(\\w*)([\"])):[\"][(.*)\\w\\s-*]*[\"](.*)";
	std::regex regexRuleForLine(patternLine);

	std::string str = "\"birthdate\":\"mimi e top\"";

	std::cout<<regex_match(str, regexRuleForLine);*/

}
