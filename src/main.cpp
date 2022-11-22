#include <iostream>
#include <iomanip>
#include "Parser.h"
#include "Simulation.h"

using std::cout;
using std::endl;



int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "usage: " << argv[0] << " <config_path>" << endl;
        return -1;
    }

    // read simulation from config filequick
    const string config_path = argv[1];
    Simulation simulation = Parser::readSimulation(argv[1]);

    // run simulation and store json state after each iteration
    vector<json> outPerIter = {Parser::makeJson(simulation)};
    int count = 0;
    while (!simulation.shouldTerminate())
    {
        std::cout << "Start Iteration#" << count << std::endl;
        simulation.step();
        std::cout << "End Iteration#" << count << std::endl;
        outPerIter.push_back(Parser::makeJson(simulation));
        count++;
    }

    // writing the outputs list to a file
    const string output_path = config_path.substr(0, config_path.find_last_of('.')) + ".out";
    std::ofstream outputFile(output_path);
    outputFile << std::setw(4) << json(outPerIter) << endl;

    return 0;
}