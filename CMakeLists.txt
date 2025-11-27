cmake_minimum_required(VERSION 4.0)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubiksCubeSolver main.cpp
        Model/GenericRubiksCube.cpp
        Model/GenericRubiksCube.h
        Model/RubiksCube3dArray.cpp
        Model/RubiksCube1dArray.cpp
        Model/RubiksCubeBitboard.cpp
        Solver/DFSSolver.h
        Solver/BFSSolver.h
        Solver/IDDFSSolver.h
        Solver/IDAstarSolver.h
        PatternDatabases/NibbleArray.h
        PatternDatabases/NibbleArray.cpp
        PatternDatabases/PatternDatabase.h
        PatternDatabases/PatternDatabase.cpp
        PatternDatabases/math.h
        PatternDatabases/math.cpp
        PatternDatabases/PermutationIndexer.h
        PatternDatabases/CornerPatternDatabase.h
        PatternDatabases/CornerPatternDatabase.cpp)
