#include "gui.hpp"
#include "config.hpp"
#include "cartridge.hpp"
#include "gui.hpp"

int main(int argc, char *argv[])
{
//    GUI::load_settings();
    GUI::init();
    Cartridge::load("../roms/tmnt2.nes");
    GUI::toggle_pause();

    GUI::run ();
    return 0;
}
