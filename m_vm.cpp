#include <iostream>
#include <string>
#include <chrono>

#include "m_obj.hpp"
#include "m_cstate.hpp"

int main() {
    cstate state;
	
	std::string input;
	
	while (true) {
		std::getline(std::cin, input);

		if (input == ".run") {
			break;
		}	
		state.instructions.push_back(input);
	}

    /* Create a main function and push a frame for it */
    m_frame mf;
    mf.cline = -1;
    mf.f_name = "$main";
    state.m_cstack.push_back(mf);    
	
	auto start = std::chrono::high_resolution_clock::now();
    state.compute();
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish-start;
	std::cout << "Execution Finished in : " << elapsed.count() << '\n';
}
