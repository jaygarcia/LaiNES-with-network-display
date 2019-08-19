#include "gui.hpp"
#include "config.hpp"
#include "cartridge.hpp"
#include "gui.hpp"

int main(int argc, char *argv[])
{
//    GUI::load_settings();
    GUI::init();
    Cartridge::load("../roms/Teenage Mutant Ninja Turtles (U).nes");
//    Cartridge::load("../roms/Ninja Gaiden (U).nes");
//    Cartridge::load("../roms/Galaga (U).nes");
    GUI::toggle_pause();

    GUI::run ();
    return 0;
}
