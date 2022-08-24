// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

/**
 * Custom Atcommands
 * Place the body of custom atcommands in this file.
 * Format:
 *	ACMD_FUNC(command_name)
 *	{
 *		<code>;
 *	}
 **/

//ACMD_FUNC(newcommand)
//{
//	clif_displaymessage(fd, "It works!");
//	clif_specialeffect(&sd->bl, EF_HEARTCASTING, AREA);
//	return 0;
//}

/**
* @afk
**/

ACMD_FUNC(afk) {
 
        nullpo_retr(-1, sd);
				
				if( map_getcell(sd->bl.m,sd->bl.x,sd->bl.y,CELL_CHKNOVENDING) ) {
					clif_displaymessage(fd, "ไม่สามารถใช้ คำสั่ง @afk ใกล้ NPC ได้");
				return true;
				}
				
				if( pc_isdead(sd) ) {
					clif_displaymessage(fd, "ไม่สามารถใช้คำสั่ง @afk ถ้าคุณตาย.");
				return -1;
				}
				
                if( battle_config.autotrade_mapflag == map_getmapflag(sd->bl.m, MF_AUTOTRADE))
                {

                if(map_getmapflag(sd->bl.m, MF_PVP)  || map_getmapflag(sd->bl.m, MF_GVG)){
					clif_displaymessage(fd, "ไม่สามารถใช้คำสั่ง@afk ในแมพ PVP หรือ GVG.");
                return -1;}

                        sd->state.autotrade = 1;
			 			pc_setsit(sd);
                        skill_sit(sd,1);
                        clif_sitting(&sd->bl);                     
                        if( battle_config.afk_timeout )
                        {
                                int timeout = atoi(message);
                                status_change_start(NULL, &sd->bl, SC_AUTOTRADE, 10000,0,0,0,0, ((timeout > 0) ? min(timeout,battle_config.afk_timeout) : battle_config.afk_timeout)*60000,0);
                        }
                        clif_authfail_fd(fd, 15);
                } else
					clif_displaymessage(fd, "ไม่สามารถใช้ คำสั่ง @afk ในแมพนี้ได้.");
        return 0;
}
