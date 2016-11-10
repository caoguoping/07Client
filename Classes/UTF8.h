#ifndef  _UTF8_
#define  _UTF8_

#include "cocos2d.h"

using namespace std;
USING_NS_CC;
class UTF8
{
private:
	static UTF8 *_instance;
public:
	UTF8(){};
	~UTF8(){};
	void ToUTF8(string& dest, const wstring& src);
	string WStrToUTF8(const wstring& str);
	string getString(string parentName, string name);
	void split(std::string& s, std::string& delim, std::vector< std::string >* ret);
	static UTF8 * getInstance()
	{
		if (_instance == NULL)  //判断是否第一次调用  
		{
			_instance = new UTF8();
		}
		return _instance;
	};
};

#define UTF8String(dict, key)	 UTF8::getInstance()->getString(dict, key)

#endif