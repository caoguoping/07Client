#include "MTNotificationQueue.h"

mutex shareNotificationQueueLock;
mutex shareEventQueueLock;

MTNotificationQueue* MTNotificationQueue::mInstance = NULL;

MTNotificationQueue::MTNotificationQueue()
{
}

MTNotificationQueue::~MTNotificationQueue()
{
}

void MTNotificationQueue::postNotifications(float dt)
{
	LifeCircleMutexLock(&shareNotificationQueueLock);

	for (size_t i = 0; i < vecNotifications.size(); i++)
	{
		NotificationArgs &arg = vecNotifications[i];
		NotificationCenter::getInstance()->postNotification(arg.name.c_str(), arg.obj);
	}

	vecNotifications.clear();
}

void MTNotificationQueue::postNotification(const char* name, Ref* object)
{
	LifeCircleMutexLock(&shareNotificationQueueLock);

	NotificationArgs arg;
	arg.name = name;
	arg.obj = object;

	vecNotifications.push_back(arg);
}
