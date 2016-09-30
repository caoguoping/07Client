#ifndef  _MusicService_
#define  _MusicService_

#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "BlueSky.h"
#include "EventType.h"
#include<map>

using namespace CocosDenshion;

class MusicService : public BlueSkyService
{
public:
	MusicService();
	~MusicService(){};
	void onEvent(int i, void* data);
	static const string NAME;
	void loadMusic();

	//
	static bool getBackGroundMusicState();
	static bool getEffectMusicState();
	static bool getCanBackgroundMusic();

private:
	void init();
	map<string, bool> isLoadMusic;
	void preloadAndPlayEffect(const char* s);
	static bool canPlayEffect;
	static bool canVibrate;
	static bool canPlayBackgroundMusic;
	static bool isInDesk;
};

#endif