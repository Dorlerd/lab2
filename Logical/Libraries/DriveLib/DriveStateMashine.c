
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void DriveStateMashine(struct DriveStateMashine* inst)
{
	inst->command = CMD_SHUTDOWN;
	
	if (inst->enable == 0 || inst->state & 0x6F != STATE_SWITCHED_ON)
	{
		inst->command = CMD_SHUTDOWN;	
	}
	else
	{
		if (inst->state & 0x6F != STATE_SWITCHED_ON)
		{
			inst->command = CMD_SWITCH_ON;
		}
		else
		{
			inst->command = CMD_ENABLE;
		}
	}
}
