#include <iostream>
#include <fstream>

int main()
{
	std::fstream fs;
	fs.open("./test.txt",std::fstream::in | std::fstream::out | std::fstream::app); 
	if(fs.is_open())
	{
		std::cout << "open file successfully" << std::endl;
		char c = fs.get();
		while(fs.good())
		{
      std::cout << c << std::endl;
			c = fs.get();
    }
		// fs << "lorem ipsum";
		fs.close();
	}
	else
	{
		std::cout << "open file failure" << std::endl;
	}
	
	return 0;
}