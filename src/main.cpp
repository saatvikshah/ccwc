#include <tclap/CmdLine.h>

#include <filesystem>
#include <iostream>
#include <span>

namespace fs = std::filesystem;

auto main(int anArgc, char* anArgv[]) -> int {
    try {
        TCLAP::CmdLine myCmd("Count bytes in file", ' ', "0.1");  // NOLINT

        TCLAP::SwitchArg myBytesOnlySwitch("c", "bytes", "Only count bytes", myCmd, false);
        TCLAP::UnlabeledValueArg<std::string> myFilenameArg("filename", "Input file", true, "",
                                                            "filename");
        myCmd.add(myFilenameArg);
        myCmd.parse(anArgc, anArgv);

        bool myIsBytesOnly = myBytesOnlySwitch.getValue();
        const auto& myFilename = myFilenameArg.getValue();

        if (myIsBytesOnly) {
            auto myFileSize = fs::file_size(myFilename);
            std::cout << myFileSize << " " << myFilename << '\n';
        }
    } catch (const std::exception& anError) {
        std::cerr << "Error: " << anError.what() << '\n';
        return 1;
    }
    return 0;
}