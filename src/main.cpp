#include <iostream>
#include <sstream>
#include <string>

#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "waveforms/SquareWave.h"

static const std::string VERSION = "1.0";
static const std::string USAGE = ""
"Usage: wfg [-hv]\n"
"       wfg [-0 <duration>] [-1 <duration>] square\n"
"\n"
"Options:\n"
"  -h, --help              Print this menu and exit.\n"
"  -v, --version           Print the program version and exit.\n"
"  -0                      The milliseconds for active low.\n"
"  -1                      The milliseconds for active high.\n"
"\n";

int main(int argc, char **argv)
{
    int opt;
    int optionIndex;
    int lowDuration = 1000000;
    int highDuration = 1000000;
    struct option options[] = {
        { "help", no_argument, NULL, 'h' },
        { "version", no_argument, NULL, 'v' },
        { 0, 0, 0, 0 },
    };

    while (1) {
        opt = getopt_long(argc, argv, "hv0:1:", options, &optionIndex);

        if (opt == -1) {
            break;
        }

        switch (opt) {
        case 'h':
            std::cout << USAGE << std::endl;
            return 0;

        case 'v':
            std::cout << VERSION << std::endl;
            return 0;

        case '0': {
            std::stringstream str(optarg);
            str >> lowDuration;
            break;
        }

        case '1': {
            std::stringstream str(optarg);
            str >> highDuration;
            break;
        }

        case 0:
        case '?':
        default:
            return 1;
        }
    }

    if ((argc - optind) < 1) {
        std::cerr << "No waveform type specified. See -h for usage." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string waveStr(argv[optind]);

    if (waveStr == "square") {
        SquareWave wave(lowDuration, highDuration);
        wave.SetDuration(5000000);
        wave.Generate();
    }

    return 0;
}
