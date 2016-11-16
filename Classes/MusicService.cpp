#include "MusicService.h"
static MusicService *_instance = NULL;

MusicService *  MusicService::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new MusicService();
		_instance->init();
	}
	return _instance;
};



void MusicService::init()
{
	//预加载音乐和音效文件
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(BG_MUSIC);
	playMusic(BG_MUSIC);

}

void MusicService::playEffect(const char*  fileName)
{
	if (isEffectOn)
	{
		SimpleAudioEngine::getInstance()->playEffect(fileName);
	}
}

void MusicService::playMusic(const char*  fileName)
{
	if (isMusicOn)
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic(fileName);
	}
}







