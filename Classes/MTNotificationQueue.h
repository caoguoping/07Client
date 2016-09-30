/***********************************************************************************
 *Copyright(C),2010-2011,SAINTGAME Company
 *FileName: MTNOTIFICATIONQUEUE.H
 *Author  : young
 *Version : 1.0
 *Date    : 2015/3/18
 *Description: �̰߳�ȫ����Ϣ�أ������߳�ͬ������
 *Others:
 *History:        //�޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ��
     1.Date:
       Author:
       Modification:
**************************************************************************************/

#ifndef __MTNotificationQueue_H__
#define __MTNotificationQueue_H__

#include "cocos2d.h"
#include <mutex>

;USING_NS_CC;
using namespace std;

class MTNotificationQueue : public Ref
{
private:
	/**
	 *@name:��Ϣ����
	 *@obj:���ݶ���
	 */
	typedef struct
	{
		string   name;
		Ref*     obj;
	} NotificationArgs;

private:
	MTNotificationQueue();
	~MTNotificationQueue();

public:
	static MTNotificationQueue* getInstance()
	{
		if (mInstance == NULL)
		{
			mInstance = new MTNotificationQueue;
		}
		return mInstance;
	}

	void postNotifications(float dt);
	void postNotification(const char* name, Ref* object);

private:
	static MTNotificationQueue      *mInstance;
	vector<NotificationArgs>    vecNotifications;

};

/************************************
 * ȫ�ֻ�����                                                            
 ************************************/
extern mutex shareNotificationQueueLock;
extern mutex shareEventQueueLock;

/************************************
 * ����������������                                                            
 ************************************/
class LifeCircleMutexLocker
{
public:
	LifeCircleMutexLocker(mutex *m) : mt(m)
	{
		mt->lock();
	}

	~LifeCircleMutexLocker()
	{
		mt->unlock();
	}
private:
	mutex *mt;
};

#define LifeCircleMutexLock(_mutex_) LifeCircleMutexLocker __locker__(_mutex_)

#endif //__MTNotificationQueue_H__
