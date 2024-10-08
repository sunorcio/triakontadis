

#include "towermenu_scene_logic.h"




#include <isola/isola.h>

#include <scene/scene.h>

#include <module/digitfps/digitfps_logic.h>
#include <module/bitmenu/bitmenu_logic.h>




static void quitTowermenu(void){

	currentScene->state.run = 0;
}

static void playTowermenu(void){

	currentScene->state.returnControlValue = 1;
	currentScene->state.run = 0;
}




void towermenuLogicUpdate(void){

	updateBitmenu();
}


void towermenuLogicCreate(void){

	createBitmenu();


	bitmenuBuildMenu();
	bitmenuBuildGroup(-1,1,1,1);
	bitmenuBuildScreen(2);
	bitmenuBuildObject("MENU - 'j'/'k' - up/down",0);
	bitmenuBuildObject("MENU - 'return' - activate option",0);
	bitmenuBuildObject("edit rules",0);
	bitmenuBuildGroup(-1,1,1,1);
		bitmenuBuildScreen(2);
		bitmenuBuildObject("these are rules :)",0);
		bitmenuBuildObject("press q to go back to last menu",0);
	bitmenuBuildGroupLeave();
	bitmenuBuildObject("play",playTowermenu);
	bitmenuBuildObject("join",0);
	bitmenuBuildObject("host",0);
	bitmenuBuildObject("options",0);
	bitmenuBuildGroup(-1,1,1,1);
		bitmenuBuildScreen(2);
		bitmenuBuildObject("these are options :)",0);
		bitmenuBuildObject("press q to go back to last menu",0);
	bitmenuBuildGroupLeave();
	bitmenuBuildObject("quit",quitTowermenu);
}


void towermenuLogicDestroy(void){

	destroyBitmenu();
}


void towermenuLogicStep(void){

	stepBitmenu();
}




