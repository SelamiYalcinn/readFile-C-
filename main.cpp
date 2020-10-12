#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#define columb_Number 4//Input your columb Number(Kendi dosyanızdaki kolon sayısını giriniz.)

static std::vector<std::string> arStr;

bool ReadFile() {
	std::string text{}, lastLine{};
	std::ifstream hwFile("Source.txt");//Dosya yolunu değiştirebilirsiniz.(You can change your .txt filename)
	int plus = 0;
	int idx = 0;
	if (hwFile.is_open())
	{
		
		while (std::getline(hwFile, text))
		{
			for (size_t i = 0; i < columb_Number; ++i)
			{
				idx = text.find(" ", plus);
				if (idx != std::string::npos)
				{
					std::string str = text.substr(plus, idx-plus);
					arStr.push_back(str);
					idx = text.find_first_not_of(" ", idx);
					if (idx != std::string::npos)
					{
						plus = idx;
					}
				}
			}
			idx = 0;
			plus = 0;
			lastLine = text;
			text.clear();
		}
		idx= lastLine.rfind(" ");
		std::string str = lastLine.substr(idx+1);
		arStr.push_back(str);
		for (int i = 0; i < arStr.size(); i++)
		{
			std::cout << i << ". index: " << arStr[i] << '\n';
		}
		return true;
	}
	else
	{
		std::cout << "error\n";
		return false;
	}
}

int main()
{
	auto statStep1 = ReadFile();
}
