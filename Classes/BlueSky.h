#ifndef __BlueSkyRegister__
#define __BlueSkyRegister__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include<map>
#include<string>
#include <list>


#include "SimpleAudioEngine.h"  //added by cgp
using namespace CocosDenshion;


using namespace std;
USING_NS_CC;
using namespace ui;
#define BTN_TOUCH_HANDLE(__CLASSTYPE__,__NAME__,__EVENT_NUM__) \
int is##__NAME__##TouchNum = 0; \
__CLASSTYPE__ * _##__NAME__; \
	void __NAME__##Handler(Ref *pSender, Widget::TouchEventType type) \
{ \
	if (type == Widget::TouchEventType::ENDED) \
	{ \
	BlueSkyRegister::getInstance()->btnIndex[__EVENT_NUM__] = false; \
	blueSkyDispatchEvent(__EVENT_NUM__); \
	} \
	if (type == Widget::TouchEventType::BEGAN)\
	{ \
	BlueSkyRegister::getInstance()->btnIndex[__EVENT_NUM__] = true; \
	SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3"); \
	} \
} \
void __NAME__##ChangeHandler(float dt) \
{ \
	if (BlueSkyRegister::getInstance()->btnIndex[__EVENT_NUM__]) \
	{ \
		if (is##__NAME__##TouchNum < 3) \
		{ \
			is##__NAME__##TouchNum++; \
			_##__NAME__->setScaleX(_##__NAME__->getScaleX() - 0.01f); \
			_##__NAME__->setScaleY(_##__NAME__->getScaleY() - 0.01f); \
		} \
	} \
	else \
	{ \
		if (is##__NAME__##TouchNum > 0) \
		{ \
			is##__NAME__##TouchNum--; \
			_##__NAME__->setScaleX(_##__NAME__->getScaleX() + 0.01f); \
			_##__NAME__->setScaleY(_##__NAME__->getScaleY() + 0.01f); \
		} \
	} \
} 


#define BTN_ADD_TOUCH_EVENTLISTENER(__CLASSTYPE__,__CLASS__,__NAME__,__EVENT_NUM__,__NODE__,__PARENT_NODE__) \
	BlueSkyRegister::getInstance()->btnIndex[__EVENT_NUM__] = false; \
	if (__PARENT_NODE__ == NULL) \
	{ \
		_##__NAME__ = dynamic_cast<__CLASSTYPE__*>(rootNode->getChildByName(__NODE__)); \
	} \
	else \
	{ \
		_##__NAME__ = dynamic_cast<__CLASSTYPE__*>(rootNode->getChildByName(__PARENT_NODE__)->getChildByName(__NODE__)); \
	} \
	_##__NAME__->addTouchEventListener(CC_CALLBACK_2(__CLASS__::__NAME__##Handler, this)); \
	schedule(schedule_selector(__CLASS__::__NAME__##ChangeHandler), 0.03f);


#define BTN_REMOVE_TOUCH_EVENTLISTENER(__CLASS__,__NAME__,__EVENT_NUM__) \
	unschedule(schedule_selector(__CLASS__::__NAME__##ChangeHandler)); \
	BlueSkyRegister::getInstance()->btnIndex[__EVENT_NUM__] = false; \
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(_##__NAME__);
	
	
class BlueSkyEvent;
class BlueSkyTouchEvent;
class BlueSkyService;
class BlueSkyView;
class BlueSkyModel;
class BlueSkyMediator;
class BlueSkyCommand;
class BlueSkyContext;
class BlueSkyRegister;

static int blueSkyIndex = 0;






class BlueSkyEvent 
{
public:
	BlueSkyEvent();
	~BlueSkyEvent();
	virtual void onEvent(int i, void* data);
	int blueSkyOnEventID = 0;
};
class BlueSkyService :public BlueSkyEvent
{
public:
	BlueSkyService();
	~BlueSkyService();
	public:
	/**
	����������
	*/
	Scene* getcontainer();

	/**
	��ȡ����ģ��
	*/
	void* getModel(string name);
	/**
	��ȡ����
	*/
	void* getService(string name);
	/**
	�����¼�
	*/
	void blueSkyDispatchEvent(int type, void* data = NULL);
	/**
	������ʾ����
	*/
	void creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData = NULL);

};
class BlueSkyView :public Layer
{
public:
	BlueSkyView();
	~BlueSkyView();
	Node* rootNode;

public:
	/**
	����������
	*/
	Scene* getcontainer();
	
	/**
	��ȡ����ģ��
	*/
	void* getModel(string name);
	/**
	��ȡ����
	*/
	void* getService(string name);

	/**
	�����¼�
	*/
	void blueSkyDispatchEvent(int type, void* data = NULL);

	void creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData = NULL);
};
class BlueSkyModel
{
public:
	BlueSkyModel();
	~BlueSkyModel();

protected:
	/**
	��ȡ����ģ��
	*/
	void* getModel(string name);
};
class BlueSkyMediator :public BlueSkyEvent
{
private:
	void* _noteData;
	BlueSkyView* _view;
public:
	BlueSkyMediator();
	~BlueSkyMediator();
	/**
	��ʼִ�к���
	*/
	virtual void OnRegister();
	/**
	��������ִ�к���
	*/
	virtual void onRemove();
	virtual Layer* getLayer(){ return NULL; };
	void setView(BlueSkyView* view);
	/**
	��ȡ�����Ӧ��View
	*/
	BlueSkyView* getView();
	/**
	* ����ʱ��͸������
	*/
	void* getNoteData();
	void setNoteData(void* data);
protected:
	/**
	����������
	*/
	Scene* getcontainer();

	/**
	��ȡ����ģ��
	*/
	void* getModel(string name);
	/**
	��ȡ����
	*/
	void* getService(string name);
	/**
	�����¼�
	*/
	void blueSkyDispatchEvent(int type, void* data = NULL);
	/**
	������ʾ����
	*/
	void creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData = NULL);
	/**
	ɾ����ʾ����
	*/
	void removeView(BlueSkyMediator *mediator);



	


};
class BlueSkyCommand
{
public:
	BlueSkyCommand();
	~BlueSkyCommand();
	/**
	�¼�ִ֪ͨ�к���
	*/
	virtual void execute(void* data);
protected:
	/**
	����������
	*/
	Scene* getcontainer();

	/**
	��ȡ����ģ��
	*/
	void* getModel(string name);
	/**
	��ȡ����
	*/
	void* getService(string name);
	/**
	�����¼�
	*/
	void blueSkyDispatchEvent(int type, void* data = NULL);

	/**
	������ʾ����
	*/
	void creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData = NULL);


};
class BlueSkyContext
{
private:
	EventDispatcher _buleSkyEventDispatcher;
public:
	BlueSkyContext();
	~BlueSkyContext();
	void constructor(Scene* container);
protected:
	/**
	����������
	*/
	Scene* getcontainer();
	/**
	�����¼�
	*/
	void blueSkyDispatchEvent(int type, void* data = NULL);
	/**
	ע������ģ��
	*/
	void registerModel(string name, BlueSkyModel *model);
	/**
	ע�����
	*/
	void registerService(string name, BlueSkyService *service);
	/**
	���¼�
	*/
	void registerCommand(int type, BlueSkyCommand *command);
	
};
struct EventVO
{
	int type;
	void* data;
};
class BlueSkyRegister
{
	public:
	static BlueSkyRegister *_instance;
	list<EventVO*> *eventVOList;
	bool isInEvent = false;
	void blueSkyDispatchEventHandler();
public:
	BlueSkyRegister();
	~BlueSkyRegister();
	Scene* container;
	static BlueSkyRegister * getInstance()
	{
		if (_instance == NULL)  //�ж��Ƿ��һ�ε���  
		{
			_instance = new BlueSkyRegister();
		}
		return _instance;
	};
	map<string, void*> gameModel;
	map<string, void*> gameService;
	map<int, BlueSkyCommand*> gameCommand;

	map<int, bool> btnIndex;

	void creatView(BlueSkyView *view, BlueSkyMediator *mediator, void* noteData = NULL);
	void removeView(BlueSkyMediator *mediator);
	/**
	�����¼�
	*/
	void blueSkyDispatchEvent(int type, void* data);

	list<BlueSkyEvent*> *gameOnEventList;
	void registerOnEvent(BlueSkyEvent *blueSkyEvent);
	void deleteOnEvent(BlueSkyEvent *blueSkyEvent);

};
#endif