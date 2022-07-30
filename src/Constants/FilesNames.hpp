#pragma once
#include "string"

using std::string;

namespace Constants
{
    struct File
    {
        const string name;
        const string type;
    };

    namespace PeopleFilesNames
    {
        const File NAME_AND_ID_10 = { "NomeRG10", "txt" };
        const File NAME_AND_ID_50 = { "NomeRG50", "txt" };
        const File NAME_AND_ID_100 = { "NomeRG100", "txt" };
        const File NAME_AND_ID_1K = { "NomeRG1K", "txt" };
        const File NAME_AND_ID_10K = { "NomeRG10K", "txt" };
        const File NAME_AND_ID_1M = { "NomeRG1M", "txt" };
        const File NAME_AND_ID_100M = { "NomeRG100M", "txt" };
    }

    namespace ApplicationCommands
    {
        const string INSERT_AT_BEGIN = "insert_at_begin";
    }
}