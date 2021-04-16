#pragma once
#include <vector>
#include <string>

#include "PieceDescription.h"

struct Assets
{
public:
    Assets();
    void load_assets(std::string path);
    std::vector<PieceDescription> piece_descriptions;
};

