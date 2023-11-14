
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif+
/* TODO: Add your comment here */
void LedStateMashine(struct LedStateMashine* inst)
{
	if (inst->timer % 10 < 5)
	{
		inst->led1 = 0;
		inst->led2 = 0;
		inst->led3 = 0;
		inst->led4 = 0;
	}
	else 
	{
		inst->led1 = inst->state & 0x00;
		inst->led2 = inst->state & 0x01;
		inst->led3 = inst->state & 0x02;
		inst->led4 = inst->state & 0x03;
	}
}
