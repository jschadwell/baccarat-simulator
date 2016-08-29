/*
 * baccarat-stats.cpp
 *
 *  Created on: Aug 26, 2016
 *      Author: jeff
 */

#include <iostream>
#include <iterator>
#include <boost/program_options.hpp>
#include "baccarat_simulator.h"

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    int cycles(0);
    int shuffles(0);

    try {
        po::options_description desc("Allowed options");
        desc.add_options()
			        ("help", "produce help message")
			        ("cycles,c", po::value<int>(&cycles)->required(), "number of times to cycle through a full shoe")
			        ("shuffles,s", po::value<int>(&shuffles)->required(), "number of shuffles to perform on each new shoe")
			        ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            return 0;
        }
    }
    catch(std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch(...) {
        std::cerr << "Unknown error" << std::endl;
    }

    if (cycles <= 0) {
        std::cerr << "Error: 'cycles' must be greater than zero" << std::endl;
    }

    if (shuffles <= 0) {
        std::cerr << "Error: 'shuffles' must be greater than zero" << std::endl;
    }

    BaccaratSimulator simulator(cycles, shuffles);
    simulator.run();

    std::cout << "Baccarat Simulator" << std::endl << std::endl;
    std::cout << "Cycles through the shoe: " << cycles << std::endl;
    std::cout << "Shuffles per cycle: " << shuffles << std::endl;
    std::cout << "Total hands: " << simulator.getTotalHands() << std::endl;
    std::cout << "Player wins: " << simulator.getPlayerWins() << std::endl;
    std::cout << "Banker wins: " << simulator.getBankerWins() << std::endl;
    std::cout << "Ties: " << simulator.getTies() << std::endl;
}

