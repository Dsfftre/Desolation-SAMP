/*#if defined _inc_anticheat
	#undef _inc_anticheat
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

new anticheatWarns[MAX_PLAYERS]; //s

public OnPlayerViolate(playerid, severity, violationCode, violationName[]) {
    if(IsPlayerNPC(playerid))
		return 1;
    printf("OnPlayerViolate(playerid %d, severity %d, violationCode %d , violationName %s)", playerid, severity, violationCode, violationName);
    if(violationCode == 0)
        return 1;

    new sendText[256];
    format(sendText, sizeof sendText, "AdmWarn: %s[%d] has triggered anticheat: severity %d, violationCode %d, violationName %s [Total warns: %d/12]", PlayerName(playerid), playerid, severity, violationCode, violationName, anticheatWarns[playerid]);
    new adminseen = SendAdminMessage(HEX_LRED, sendText, false);//SET TO TRUE UNLESS TESTING ((DEBUG))
    if(!adminseen)
        ++anticheatWarns[playerid];
    if(!Bit_Get(loggedin, playerid) && severity == SEVERITY_CASE_THREE)
        return IssueBan(playerid, "Desolation anticheat", violationName);
    else if(!Bit_Get(loggedin, playerid) && anticheatWarns[playerid] > 3)
        return IssueBan(playerid, "Desolation anticheat", violationName);
    else if(anticheatWarns[playerid] > 12 && severity >= SEVERITY_CASE_TWO)
        return IssueBan(playerid, "Desolation anticheat", violationName);
    
    if(anticheatWarns[playerid] > 12) {
        if(violationCode == VIOLATION_CODE_CARSWING) return IssueBan(playerid, "Desolation anticheat", violationName);
        if(violationCode == VIOLATION_CODE_AIRBRAKE) return IssueBan(playerid, "Desolation anticheat", violationName);
        if(violationCode == VIOLATION_CODE_SPEEDING) return IssueBan(playerid, "Desolation anticheat", violationName);
        if(violationCode == VIOLATION_CODE_FAKECONNECT) return IssueBan(playerid, "Desolation anticheat", violationName);
        if(violationCode == VIOLATION_CODE_WEPHACKS && level[playerid] < 2) return IssueBan(playerid, "Desolation anticheat", violationName);
    }


    return 1;
}

hook OnPlayerDisconnect(playerid, reason) {
    if(IsPlayerNPC(playerid))
        return Y_HOOKS_CONTINUE_RETURN_1;
    anticheatWarns[playerid] = 0;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ) {
    if(IsPlayerNPC(playerid))
        return Y_HOOKS_CONTINUE_RETURN_1;

    if (hittype == BULLET_HIT_TYPE_PLAYER) {
        new
            Float:fOriginX, Float:fOriginY, Float:fOriginZ,
            Float:fHitPosX, Float:fHitPosY, Float:fHitPosZ;

        GetPlayerLastShotVectors(playerid, fOriginX, fOriginY, fOriginZ, fHitPosX, fHitPosY, fHitPosZ);
        new Float:BulletDistanceForHit = GetPlayerDistanceFromPoint(hitid, fHitPosX, fHitPosY, fHitPosZ);
        if (BulletDistanceForHit == 0 && (weaponid > 21 && weaponid != 35 && weaponid != 42 && weaponid < 47)) {
            return Y_HOOKS_BREAK_RETURN_0; //It prevents the bullet from reaching the target player.
        }
    }

    if(!random(3)) {
        if (!GetPlayerWeapon(playerid)) {
            CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -1, "Shooting while unarmed");
        }
        if (weaponid == 0) {
            CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -1, "Shooting with fists");
        }
        if(weaponid > 21 && weaponid < 37) {
            if(!HasPlayerItem(playerid, GetItemFromWeapon(weaponid), 1)) {
                new string[128];
                format(string, sizeof(string), "Shooting without weapon in inventory (%s)", DeathReason(weaponid));
                CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_THREE, -1, string);
            }              
        }
        /*if (hittype == 1) { 
            new Float:ox, Float:oy, Float:oz, Float:hx, Float:hy, Float:hz;
            GetPlayerLastShotVectors(playerid, ox, oy, oz, hx, hy, hz);
            new Float:hitposdistance = GetPlayerDistanceFromPoint(hitid, hx, hy, hz);
            if (hitposdistance == 0) {
                CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -3, "Silent aimbot (Shot a target who had no distance from the hitting bullet)");
            }
            if (hitposdistance > 5.0) {
                new string[128];
                format(string, sizeof(string), "Silent aimbot (Shot a target who was too far away (%f) from the bullet)", hitposdistance);
                CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -3, string);
            }
            new Float:xyz[3];
            GetPlayerPos(hitid,xyz[0],xyz[1],xyz[2]);
            new Float:Distance = GetPlayerDistanceFromPoint(playerid,xyz[0],xyz[1],xyz[2]);
            switch(weaponid) {
                case 30: {
                    if(Distance > 90) return CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -2, "Rage shot (Shooting too far with AK)");
                }
                case 31: {
                    if(Distance > 110) return CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -2, "Rage shot (Shooting too far with M4)");
                }
                case 33: {
                    if(Distance > 1200) return CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -2, "Rage shot (Shooting too far with county rifle)");
                }
                case 34: {
                    if(Distance > 220) return CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -2, "Rage shot (Shooting too far with sniper)");
                }
                case 25: {
                    if(Distance > 50) return CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -2, "Rage shot (Shooting too far with shotgun)");
                }
                case 29: {
                    if(Distance > 60) return CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -2, "Rage shot (Shooting too far with MP5)");
                }
                case 22: {
                    if(Distance > 70) return CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -2, "Rage shot (Shooting too far with 9mm)");
                }
                case 23: {
                    if(Distance > 70) return CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -2, "Rage shot (Shooting too far with silenced 9mm)");
                }
                case 24: {
                    if(Distance > 70) return CallLocalFunction("OnPlayerViolate", "iiis", playerid, SEVERITY_CASE_TWO, -2, "Rage shot (Shooting too far with Deagle)");
                }
            }
        }*/
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

