
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	DoorStateMashine(&Door);
	if (Door.sw1 || Door.sw4)
	{Motor.enable = 1;}
	else
	{Motor.enable = 0;}
	Motor.speed = Door.speed;
	DriveStateMashine(&Motor);

}
