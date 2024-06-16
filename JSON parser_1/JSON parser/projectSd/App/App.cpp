#include "App.h"
#include "../Models/Object.h"
#include <exception>

//main command implementation where the customer can choose what exactly to do with the files and the JSON object
void App::run()
{
	std::cout << "      JSON PARSER----TRY IT NOW:" << std::endl;
	while (true)
	{
		try
		{
			std::cout << std::endl;
			std::cout << "Enter a command: " << std::endl;
			std::string input;
			std::getline(std::cin, input);

			std::vector<std::string> args = split(input);
			std::string comand = args[0];

			if (comand == "validate")
			{
				validate(args[1]);
			}
			//not created
			else if (comand == "read")
			{
				read();
			}
			else if (comand == "find")
			{
				find(args[1]);
			}
			else if (comand == "print")
			{
				print();
			}
			//not created
			else if (comand == "change")
			{
				change();
			}
			//not created
			else if (comand == "delete")
			{
				deleteObject(args[1],args[2]);
			}
			//not created
			else if (comand == "move")
			{
				move();
			}
			else if (comand == "save")
			{
				save(args[1]);
			}
			else
			{
				throw ("Put a valid command!");
			}
		}
		catch (const char* msg)
		{
			std::cout << msg << std::endl;
		}
	}
}


//hardcoded because read method is not implemented and by this way I create the object
App::App()
{
	object.addElement(new SimpleValue("this", "project"));
	object.addElement(new SimpleValue("is", "amazing"));
	object.addElement(new Object());
	object.addElement(new List());
}

//all methods use the implementation in Json.cpp where the whole idea is presented and the main bussines logic is placed
//check if it is valid file data and return the proper message
void App::validate(const std::string& filePath)
{
	std::cout << "Is file valid: " <<std::endl;
	if (object.validationCheck(filePath))
	{
		std::cout <<"Validation passed! No mistakes found!" << std::endl;
	}
	else
	{
		std::cout << "Validation NOT passed! Please repair your file!" << std::endl;
	}
}

//print the object info
void App::print()
{
	object.print(std::cout);
}

//find specific element by given key. It could be many
void App::find(const std::string& key)
{
	std::list<JsonValue*> values = object.find(key);
	int count = 0;
	if (values.size() == 0)
	{
		std::cout << "There is no such element! " << std::endl;
		std::cout << "Plese enter valid one! " << std::endl;
		return;
	}
	std::cout << "[" << std::endl;
	for (JsonValue* element : values)
	{
		element->write(std::cout); 
	}
	std::cout << "]" << std::endl;
}

void createFile(std::string fileName)
{
	std::fstream file;
	file.open(fileName, std::ios::out);

	if (!file)
	{
		std::cout << "Error in creating file!!!";
	}

	std::cout << "File created successfully."<<std::endl;
	file.close();
}

void App::saveFile(const std::string& filePath)
{
	std::ofstream out(filePath, std::ios::out | std::ios::trunc);
	object.print(out);
	out.close();
	std::cout << "Successfully saved file!" << std::endl;
}

//save sife but first check if it already exist or not and give different options to the customer
void App::save(const std::string& filePath)
{
	if (std::ifstream(filePath))
	{
		std::string yesOrNo;
		std::string fileName;
		std::cout << "File already exists..." << std::endl;
		std::cout << "Do you want to create new one: ";

		std::cin >> yesOrNo;

		if (yesOrNo == "yes")
		{
			std::cout << "Create name for the new file: ";
			std::cin >> fileName;
			createFile(fileName);
			saveFile(fileName);
		}
		else if (yesOrNo == "no")
		{
			std::cout << "Create new file name: ";
			std::cin >> fileName;
			rename(filePath.c_str(), fileName.c_str());
			std::cout << "Succesfully saved file. ";
			saveFile(fileName);
		}
	}
	else
	{
		saveFile(filePath);
	}

}

void App::deleteObject(const std::string& key, const std::string& value)
{

}

void App::move()
{
}

void App::change()
{
}

void App::read()
{
}
	


