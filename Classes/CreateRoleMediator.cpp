#include "CreateRoleMediator.h"
#include "ViewManager.h"
CreateRoleMediator::CreateRoleMediator(registLogin data)
{
	rLogin = new registLogin();
	rLogin->ip = data.ip;
	rLogin->type = data.type;
	rLogin->cbGender = data.cbGender;
	rLogin->szAccounts = data.szAccounts;
	rLogin->szLogonPass = data.szLogonPass;
}

CreateRoleMediator::~CreateRoleMediator()
{
	delete getView();
	setView(NULL);
}

/**
��ʼִ�к���
*/
void CreateRoleMediator::OnRegister()
{
	createRoleView = (CreateRoleView*)getView();

	//
	createRoleView->initView();

	//
	nameText = dynamic_cast<TextField*>(getView()->rootNode->getChildByName("nameText"));

	//name1 = new vector<string>();
	name2 = new vector<string>();
	name3 = new vector<string>();

	string s = ",";
//	string s1 = UTF8::getInstance()->getString("name", "name1");
	string s2 = UTF8::getInstance()->getString("name", "name2");
	string s3 = UTF8::getInstance()->getString("name", "name3");
//	UTF8::getInstance()->split(s1, s, name1);
	UTF8::getInstance()->split(s2, s, name2);
	UTF8::getInstance()->split(s3, s, name3);
	clickAutoBtnHander();
}

/**
��������ִ�к���
*/
void CreateRoleMediator::onRemove()
{

}

/*
�¼���Ӧ����
*/
void CreateRoleMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case 10022:
		clickCharacter1BtnHander();
		break;
	case 10023:
		clickCharacter2BtnHander();
		break;
	case 10024:
		clickCharacter3BtnHander();
		break;
	case 10025:
		clickCharacter4BtnHander();
		break;
	case 10026:
		clickAutoBtnHander();
		break;
	case 10027:
		clickCreateBtnHander();
		break;
	case EventType::LOGIN_COMPLETE:
		removeView(this);
		break;
	case EventType::ERROR_MSG:
		if (*(int*)data == 7)
		{
			removeView(this);
		}
		break;
	}
}

/*
��ʾ�㼶���ú���
*/
Layer* CreateRoleMediator::getLayer()
{
	return VIEW->mainLayer;
}


//��ɫѡ��
void CreateRoleMediator::clickCharacter1BtnHander()
{
	PLayEffect(EFFECT_BTN);
	faceID = 2;   //���´��
	createRoleView->setCharacterState(1);
}

void CreateRoleMediator::clickCharacter2BtnHander()
{
	PLayEffect(EFFECT_BTN);
	faceID = 4;  //������װ˧��
	createRoleView->setCharacterState(2);
}

void CreateRoleMediator::clickCharacter3BtnHander()
{
	PLayEffect(EFFECT_BTN);
	faceID = 3;
	createRoleView->setCharacterState(3);
}

void CreateRoleMediator::clickCharacter4BtnHander()
{
	PLayEffect(EFFECT_BTN);
	faceID = 1;   //��ɫ�ി��ü
	createRoleView->setCharacterState(4);
}

//����ǳ�
void CreateRoleMediator::clickAutoBtnHander()
{
	PLayEffect(EFFECT_BTN);
	/*time_t rawtime;
	time(&rawtime);
	rLogin->szNickName = ctime(&rawtime);*/
//	int l1 = name1->size() - 1;
	int l2 = name2->size() - 1;
	int l3 = name3->size() - 1;
//	int i1 = random(0, l1);
	int i2 = random(0, l2);
	int i3 = random(0, l3);
//	string s1 = (*name1)[i1];
	string s2 = (*name2)[i2];
	string s3 = (*name3)[i3];
	/*string s = s1 + s2 + s3;*/
	string s = s2 + s3;
	nameText->setString(s);
}

//ȷ��
void CreateRoleMediator::clickCreateBtnHander()
{
	PLayEffect(EFFECT_BTN);
	std::string atring;
	atring.data();
	rLogin->szNickName = (nameText->getString()).data();
	rLogin->wFaceID = faceID;
	blueSkyDispatchEvent(EventType::SOCKET_INIT, rLogin);
}
