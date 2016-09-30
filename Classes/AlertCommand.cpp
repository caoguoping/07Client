#include "AlertCommand.h"
void AlertCommand::execute(void* data)
{
	AlertVO *alertVO = (AlertVO *)data;
	creatView(new WarningView(alertVO), new WarningMediator());
}