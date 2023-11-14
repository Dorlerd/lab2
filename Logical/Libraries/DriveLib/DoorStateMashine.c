
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
void DoorStateMashine(struct DoorStateMashine* inst)
{
	if (inst->state == ST_INIT)
	{inst->state = ST_UNKNOWN; 
		inst->led_state.state=0000; LedStateMashine(&inst->led_state); 
		inst->led_state.state=1111; LedStateMashine(&inst->led_state); 
		inst->led_state.state=0000; LedStateMashine(&inst->led_state);
		return;
	}
	if (inst->state == ST_UNKNOWN)
	{
		if (inst->sw1 == 1 && inst->direction == 0)
		{inst->state = ST_OPEN;inst->led_state.state=0000; LedStateMashine(&inst->led_state); inst->speed = 0;}
		else if (inst->sw2 == 1 && inst->direction == 1)
		{inst->state = ST_CLOSE; inst->led_state.state=1111; LedStateMashine(&inst->led_state); inst->speed = 0;}
		return;
	}
	
	if (inst->state == ST_OPEN && inst->direction == 1)
	{inst->state = ST_ACC_POS; inst->led_state.state=1000; LedStateMashine(&inst->led_state); inst->speed = 10; return;}
	
	if (inst->state == ST_CLOSE && inst->direction == 0)
	{inst->state = ST_ACC_NEG; inst->led_state.state=1110; LedStateMashine(&inst->led_state); inst->speed = -10; return;}
	
	if (inst->state == ST_ACC_POS)
	{
		if (inst->direction == 1)
		{inst->state = ST_DEC_NEG; inst->led_state.state=1000; LedStateMashine(&inst->led_state); inst->speed = -10;}
		else if (inst->sw2 == 1)
		{inst->state = ST_POS; inst->led_state.state=1100; LedStateMashine(&inst->led_state); inst->speed = 100;}
		return;
	}
	
	if (inst->state == ST_ACC_NEG)
	{
		if (inst->direction == 0)
		{inst->state = ST_DEC_POS; inst->led_state.state=1110; LedStateMashine(&inst->led_state);inst->speed = 10; }
		else if (inst->sw3 == 1)
		{inst->state = ST_NEG; inst->led_state.state=1100; LedStateMashine(&inst->led_state); inst->speed = -100;}
		return;
	}
	
	if (inst->state == ST_POS)
	{
		if (inst->direction == 1)
		{inst->state = ST_NEG; inst->led_state.state=1100; LedStateMashine(&inst->led_state); inst->speed = -100;}
		else if (inst->sw3 == 1)
		{inst->state = ST_DEC_POS; inst->led_state.state=1110; LedStateMashine(&inst->led_state); inst->speed = 10;}
		return;
	}
	
	if (inst->state == ST_NEG)
	{
		if (inst->direction == 0)
		{inst->state = ST_POS; inst->led_state.state=1100; LedStateMashine(&inst->led_state); inst->speed = 100;}
		else if (inst->sw2 == 1)
		{inst->state = ST_DEC_NEG;inst->led_state.state=1000; LedStateMashine(&inst->led_state); inst->speed = -10;}
		return;
	}
	
	if (inst->state == ST_DEC_POS && inst->sw4 == 1)
	{inst->state = ST_CLOSE; inst->led_state.state=1111; LedStateMashine(&inst->led_state); inst->speed = 0; return;}
	
	if (inst->state == ST_DEC_NEG && inst->sw1 == 1)
	{inst->state = ST_OPEN; inst->led_state.state=0000; LedStateMashine(&inst->led_state); inst->speed = 0; return;}
	
}
