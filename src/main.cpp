#include <iostream>
#include <string>

#include <getopt.h>

static const std::string VERSION = "1.0";
static const std::string USAGE = ""
"Usage: wfg [-hv]\n"
"\n"
"Options:\n"
"  -h, --help              Print this menu and exit.\n"
"  -v, --version           Print the program version and exit.\n"
"\n";

int main(int argc, char **argv)
{
    int opt;
    int optionIndex;
    struct option options[] = {
        { "help", no_argument, NULL, 'h' },
        { "version", no_argument, NULL, 'v' },
        { 0, 0, 0, 0 },
    };

    while (1) {
        opt = getopt_long(argc, argv, "hv", options, &optionIndex);

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

        case 0:
        case '?':
        default:
            return 1;
        }
    }

    return 0;
}
