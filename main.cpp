#include <iostream>
#include <fstream>


constexpr std::size_t POPUP_CALL_ADDR { 0x3a32 };
constexpr const char* X86_NOP_PAYLOAD { "\x90\x90\x90\x90\x90" };


int main() {
    std::fstream pj64exe { "Project64.exe", std::ios_base::in | std::ios_base::out | std::ios_base::binary };

    if (!pj64exe) {
        std::cerr << R"(Cannot open Project64.exe, please check this executable is in the same directory )";
        std::cerr << R"(than Project64 executable which usually is "C:\\Program Files (x86)\\Project64 3.0". )";
        std::cerr << std::endl;

        std::cerr << "Please also check you're running this pj64_remove_popup.exe as Administrator." << std::endl;
        std::cin.get();

        return 1;
    }

    pj64exe.seekp(POPUP_CALL_ADDR);
    pj64exe << X86_NOP_PAYLOAD;

    return 0;
}
