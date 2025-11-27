//
// Created by Ayush Agrawal on 27/11/25.
//

#ifndef RUBIKSCUBESOLVER_CORNERPATTERNDATABASE_H
#define RUBIKSCUBESOLVER_CORNERPATTERNDATABASE_H

#include "../Model/GenericRubiksCube.h"
#include "PatternDatabase.h"
#include "PermutationIndexer.h"
using namespace std;

class CornerPatternDatabase : public PatternDatabase {

    typedef GenericRubiksCube::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const GenericRubiksCube& cube) const;

};

#endif //RUBIKSCUBESOLVER_CORNERPATTERNDATABASE_H