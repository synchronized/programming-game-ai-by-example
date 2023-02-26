
#include "windows.h"
#include "EntityNames.h"
#include "Locations.h"
#include "Miner.h"
#include "misc/ConsoleUtils.h"

int main() {
    //create a miner
    WestWorld::Miner miner(WestWorld::ent_Miner_Bob);

    //simply run the miner through a few Update calls
    for (int i=0; i<20; ++i) {
        miner.Update();

        Sleep(800);
    }

    //wait for a keypress before exiting
    PressAnyKeyToContinue();

    return 0;
}
