#include "UTF8.h"
UTF8* UTF8::_instance;
void UTF8::ToUTF8(string& dest, const wstring& src)
{
	dest.clear();

	for (size_t i = 0; i < src.size(); i++){
		wchar_t w = src[i];
		if (w <= 0x7f)
			dest.push_back((char)w);
		else if (w <= 0x7ff)
		{
			dest.push_back(0xc0 | ((w >> 6) & 0x1f));
			dest.push_back(0x80 | (w & 0x3f));
		}
		else if (w <= 0xffff)
		{
			dest.push_back(0xe0 | ((w >> 12) & 0x0f));
			dest.push_back(0x80 | ((w >> 6) & 0x3f));
			dest.push_back(0x80 | (w & 0x3f));
		}
		else if (sizeof(wchar_t) > 2 && w <= 0x10ffff)
		{
			dest.push_back(0xf0 | ((w >> 18) & 0x07)); // wchar_t 4-bytes situation  
			dest.push_back(0x80 | ((w >> 12) & 0x3f));
			dest.push_back(0x80 | ((w >> 6) & 0x3f));
			dest.push_back(0x80 | (w & 0x3f));
		}
		else
			dest.push_back('?');
	}
}
string UTF8::WStrToUTF8(const wstring& str)
{
	string result;
	ToUTF8(result, str);
	return result;
}

string UTF8::getString(string parentName, string name)
{
	const char* testPlistPath = "word.plist";
	string fullPath = CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile("word.plist", testPlistPath);
	CCDictionary *plistDic = CCDictionary::createWithContentsOfFile(testPlistPath);
	CCDictionary* levelDic = dynamic_cast<CCDictionary*>(plistDic->objectForKey("guandan"));
	CCDictionary* farScene = dynamic_cast<CCDictionary*>(levelDic->objectForKey(parentName));
	CCString* farScenePath = dynamic_cast<CCString*>(farScene->objectForKey(name));
	if (farScenePath == NULL)  //找不到返回空字符串
	{
		return "";
	}
	return farScenePath->getCString();
}
//注意：当字符串为空时，也会返回一个空字符串  
void UTF8::split(std::string& s, std::string& delim, std::vector< std::string >* ret)
{
	size_t last = 0;
	size_t index = s.find_first_of(delim, last);
	while (index != std::string::npos)
	{
		ret->push_back(s.substr(last, index - last));
		last = index + 1;
		index = s.find_first_of(delim, last);
	}
	if (index - last>0)
	{
		ret->push_back(s.substr(last, index - last));
	}
}