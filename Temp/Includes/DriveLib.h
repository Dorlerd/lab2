/* Automation Studio generated header file */
/* Do not edit ! */
/* DriveLib  */

#ifndef _DRIVELIB_
#define _DRIVELIB_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Datatypes and datatypes of function blocks */
typedef enum list_of_state
{	STATE_SWITCHED_ON = 1,
	STATE_READY = 2
} list_of_state;

typedef enum list_of_door
{	ST_INIT = 1,
	ST_UNKNOWN = 2,
	ST_OPEN = 3,
	ST_DEC_NEG = 4,
	ST_DEC_POS = 5,
	ST_NEG = 6,
	ST_POS = 7,
	ST_ACC_NEG = 8,
	ST_ACC_POS = 9,
	ST_CLOSE = 10
} list_of_door;

typedef enum list_of_command
{	CMD_ENABLE = 1,
	CMD_SWITCH_ON = 2,
	CMD_SHUTDOWN = 3
} list_of_command;

typedef struct DriveStateMashine
{
	/* VAR_INPUT (analog) */
	unsigned short state;
	unsigned short sta;
	/* VAR_OUTPUT (analog) */
	unsigned short command;
	signed short speed;
	unsigned short com;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DriveStateMashine_typ;

typedef struct LedStateMashine
{
	/* VAR_INPUT (analog) */
	unsigned short state;
	/* VAR_OUTPUT (analog) */
	signed short timer;
	/* VAR_OUTPUT (digital) */
	plcbit led1;
	plcbit led2;
	plcbit led3;
	plcbit led4;
} LedStateMashine_typ;

typedef struct DoorStateMashine
{
	/* VAR_INPUT (analog) */
	enum list_of_door state;
	/* VAR_OUTPUT (analog) */
	signed short speed;
	/* VAR (analog) */
	struct LedStateMashine led_state;
	/* VAR_INPUT (digital) */
	plcbit sw1;
	plcbit sw2;
	plcbit sw3;
	plcbit sw4;
	plcbit direction;
} DoorStateMashine_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void DriveStateMashine(struct DriveStateMashine* inst);
_BUR_PUBLIC void DoorStateMashine(struct DoorStateMashine* inst);
_BUR_PUBLIC void LedStateMashine(struct LedStateMashine* inst);


#ifdef __cplusplus
};
#endif
#endif /* _DRIVELIB_ */

