#include <iostream>
#include <string>
#include <map>
#include <set>


void addToMap(const std::string& str, std::map<std::string, int>& aMap);
void strToComb(const std::string& str, int combLength, std::set<std::string>& aSet, std::map<std::string, int>& aMap);
void print(const std::set<std::string>& aSet, const std::map<std::string, int>& aMap);

int main()
{
    int cycles;
    std::set<std::string> pointsSet;
    std::map<std::string, int> verticesMap;

    ///get input -> split -> add to STL containers
    std::cin >> cycles;
    for (int i = 0; i < cycles; i++)
    {
        std::string str;
        std::cin >> str;
        strToComb(str, 3, pointsSet, verticesMap);
    }

    print(pointsSet, verticesMap);
    return 0;
}

void strToComb(const std::string& str, int combLength, std::set<std::string>& aSet, std::map<std::string, int>& aMap)
{
    std::string prevSubStr = str.substr(0, combLength);
    aSet.insert(prevSubStr);

    for (int i = 1; i + 2 < str.length(); i++)
    {
        std::string subStr = str.substr(i, combLength);
        aSet.insert(subStr);

        std::string subStrPair = prevSubStr + subStr;
        addToMap(subStrPair, aMap);

        prevSubStr = subStr;
    }
}

void addToMap(const std::string& str, std::map<std::string, int>& aMap)
{
    if (aMap.find(str) != aMap.end())
        aMap[str] += 1;
    else
        aMap[str] = 1;
}

void print(const std::set<std::string>& aSet, const std::map<std::string, int>& aMap)
{
    std::cout << aSet.size() << std::endl;
    std::cout << aMap.size() << std::endl;

    for (const std::pair<const std::string, int>& elem: aMap) ///Alternatively can use 'auto' or 'iterator'
    {
        std::cout << elem.first.substr(0, 3) << " " << elem.first.substr(3, 3) << " " << elem.second << "\n";
    }
}