/*****************************************************************//**
 * \file   GoddessAnimeVersionManager.cpp
 * \brief  
 * This file contains the implementation of the GoddessAnimeVerionManager class,
 *   which is responsible for managing the versions of the github repository of the
 *   Goddess Anime project.
 * \author 0xhylia
 * \date   July 2023
 *********************************************************************/


#include <iostream>   // For input/output operations
#include <cstdlib>    // For system() function
#include <string>     // For string manipulation

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <tag>" << std::endl;  // Print usage if the program is not provided with exactly one command-line argument
        return 1;  // Exit the program with an error code
    }

    std::string arg1(argv[1]);  // Store the command-line argument in a string variable
    std::string url = "https://update-goddess.hylia.dev/tag/" + arg1;  // Create the URL by concatenating the argument with a base URL

    std::string command;
#ifdef _WIN32
    // Windows command to open default browser
    command = "start ";
#elif __APPLE__
    // macOS command to open default browser
    command = "open ";
#else
    // Linux command to open default browser
    command = "xdg-open ";
#endif

    command += url;  // Append the URL to the command

    // Execute the command to open the default browser
    if (system(command.c_str()) == 0) {  // Execute the command and check the return value
        std::cout << "Redirecting to " << url << std::endl;  // Print the URL if the command executed successfully
    }
    else {
        std::cerr << "Failed to open the default browser." << std::endl;  // Print an error message if the command execution failed
        return 1;  // Exit the program with an error code
    }

    return 0;  // Exit the program successfully
}
