

#include "towermenu_logic.h"




#include <isola/isola.h>

#include <scene/scene.h>

#include <module/digitfps/digitfps_logic.h>
#include <module/bitmenu/bitmenu_logic.h>




extern struct SCENE_state towermenuState;




void quitMainmenu(void){

	towermenuState.run = 0;
}

void playMainmenu(void){

	towermenuState.returnControlValue = 1;
	towermenuState.run = 0;
}




void towermenuLogicUpdate(void){

	updateBitmenu();


	if (isolaInfoWindow.height > 720 && isolaInfoWindow.width > 1280) {
		digitfps.pixelSize = 8*2;
	}else {
		digitfps.pixelSize = 8*1;
	}
}


void towermenuLogicCreate(void){

	createBitmenu();


	bitmenuBuildMenu();
	bitmenuBuildGroup(-1,1,1,1);
	bitmenuBuildScreen(2);
	bitmenuBuildObject("play",playMainmenu);
	bitmenuBuildObject("options",0);
	bitmenuBuildGroup(-1,1,1,1);
		bitmenuBuildScreen(2);
		bitmenuBuildObject("these are options :)",0);
		bitmenuBuildObject("press q to go back to last menu",0);
	bitmenuBuildGroupLeave();
	bitmenuBuildObject("quit",quitMainmenu);
}


void towermenuLogicDestroy(void){

	destroyBitmenu();
}


void towermenuLogicStep(void){

	stepBitmenu();
}



