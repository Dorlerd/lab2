
TYPE
	list_of_state : 
		(
		STATE_SWITCHED_ON := 1,
		STATE_READY := 2
		);
	list_of_door : 
		(
		ST_INIT := 1,
		ST_UNKNOWN := 2,
		ST_OPEN := 3,
		ST_DEC_NEG := 4,
		ST_DEC_POS := 5,
		ST_NEG := 6,
		ST_POS := 7,
		ST_ACC_NEG := 8,
		ST_ACC_POS := 9,
		ST_CLOSE := 10
		);
	list_of_command : 
		(
		CMD_ENABLE := 1,
		CMD_SWITCH_ON := 2,
		CMD_SHUTDOWN := 3
		);
END_TYPE
