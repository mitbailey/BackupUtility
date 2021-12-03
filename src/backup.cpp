/**
 * @file backup.cpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief Recursively copies a directory, generating an identical directory whose name is appended with the date and time.
 * @version See Git tags for version information.
 * @date 2021.11.26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <cstdio>
#include <iostream>
#include <filesystem>
#include <time.h>

int main(int argc, char* argv[])
{
    // Defaults to copying the current directory to its parent directory.
    char dest_dirname[256] = "..";
    char trgt_dirname[256] = ".";
    std::filesystem::path trgt_as_path = std::filesystem::current_path();

    // Command line argument handler.
    switch (argc)
    {
        case 1:
        {
            std::cout << "Backup will be placed in current directory's parent." << std::endl;
            break;
        }
        case 2:
        {
            snprintf(dest_dirname, 256, "%s", argv[1]);
            std::cout << "Backup will be placed in: " << dest_dirname << std::endl;
            break;
        }
        case 3:
        {
            snprintf(dest_dirname, 256, "%s", argv[1]);
            snprintf(trgt_dirname, 256, "%s", argv[2]);
            trgt_as_path = trgt_dirname;
            std::cout << "Backup of " << trgt_dirname << " will be placed in: " << dest_dirname << std::endl;
            break;
        }
        default:
        {
            std::cout << "Usage:\nbackup\nOR\nbackup C:/path/to/output\nOR\nbackup C:/path/to/output C:/path/to/input" << std::endl;
            return -1;
        }
    }

    // Status printouts.
    // std::cout << "Generating backup for current directory: " <<  std::filesystem::current_path() << std::endl;
    std::cout << "Working..." << std::endl;

    // Grab the current time.
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Set the name of the backup directory: the name of the original file concatenated with date and time.
    char bkup_dirname[256] = {0};
    snprintf(bkup_dirname, 256, "%s/%s_%d%02d%02dT%02d%02d%02d", dest_dirname, trgt_as_path.filename().string().c_str(), 1900 + tm.tm_year, tm.tm_mon, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Perform recursive copy operation.
    std::filesystem::copy(trgt_dirname, bkup_dirname, std::filesystem::copy_options::recursive);

    // Operation complete.
    std::cout << "Everything is OK." << std::endl;

    return 0;
}