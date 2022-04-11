#pragma once
#include <string>

namespace Constants
{
    namespace ApplicationCommands
    {
        const std::string QUIT_APPLICATION = "quit_application";
    }

    namespace ListCommands
    {
        const struct Insert
        {
            const std::string INSERT_AT_BEGIN = "insert_at_begin";
            const std::string INSERT_AT_POSITION = "insert_at_position";
            const std::string INSERT_AT_END = "insert_at_end";
        } INSERT;

        const struct Remove
        {
            const std::string REMOVE_AT_BEGIN = "remove_at_begin";
            const std::string REMOVE_AT_POSITION = "remove_at_position";
            const std::string REMOVE_AT_END = "remove_at_end";
        } REMOVE;

        
        const std::string DISPLAY = "display";
        
        const std::string SEARCH = "search";

        const struct File
        {
            const std::string SAVE = "save";
            const std::string LOAD = "load";
        } FILE;
    }
}
