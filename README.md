# Rubik’s Cube Solver – Multi-Representation + Generic Solver Framework

This project implements a complete Rubik’s Cube engine with multiple internal representations, a generic abstract cube interface, and several solving algorithms (DFS, BFS, IDDFS, and IDA* with Pattern Databases). The goal is to provide a reusable, extensible, high-performance Rubik’s Cube solver framework that supports:

- 3D Array Representation  
- 1D Array Representation  
- Bitboard Representation  
- Generic Template-Based Solvers  
- Corner Pattern Database + IDA* (Korf’s Algorithm)

---

##  Features

### **1. Generic Rubik’s Cube Abstract Class**
A common interface for all cube models:
- 18 face rotations (F, F’, F2, U, U’, U2, …)
- `isSolved()`
- `print()`
- `randomShuffle()`
- Comparison operators (`==`)
- Pure virtual functions for all cube-specific operations

This ensures you can write **one solver** that works for **all cube representations**.

---

##  Cube Representations

### **2. 3D Array Representation**
Cube stored as:
6 faces × 3 × 3 matrix
Implements:
- `rotateFace()`
- All face moves (U, R, L, F, D, B)
- `getColor()`
- `isSolved()`
- `operator==`
- Hashing (`Hash3d`)

---

### **3. 1D Array Representation**
Cube stored as a linear array of 54 stickers:
cube[0..53]

Functions implemented:
- `getIndex(x, y, face)` → convert (3D) to 1D index
- `rotateFace()`
- Face turns with adjacent-sticker movement
- `isSolved()`
- `operator==` and assignment
- `Hash1d`

1D arrays allow faster operations and simpler copying.

---

### **4. Bitboard Representation (6 × 64-bit integers)**
Each face is a 64-bit integer encoding 8 stickers (centre is static).  
Each sticker stored in 8-bit color codes:

| Color  | Binary      |
|--------|-------------|
| White  | 00000001    |
| Green  | 00000010    |
| Red    | 00000100    |
| Blue   | 00001000    |
| Orange | 00010000    |
| Yellow | 00100000    |

Key advantages:
- Extremely compact representation
- Face rotation = **16-bit circular rotation**
- Fast hashing
- Used for pattern database indexing

Implements:
- `rotateFace()`
- `rotateSide()`
- Full move set
- `getColor()`
- `isSolved()`
- `HashBitboard`
- Corner extraction helpers

---

##  Cube Operations

### **Moves Supported (18 Standard WCA Moves)**

F, F’, F2
U, U’, U2
L, L’, L2
D, D’, D2
R, R’, R2
B, B’, B2


Random shuffling is done by applying a sequence of random valid moves *to guarantee solvability*.

---

##  Solvers Implemented

### **1. Depth-First Search (DFS)**
- Limited to max depth (usually ≤ 20)
- Does not use “visited” set (to avoid pruning valid paths)
- Guarantees solution if depth ≥ God’s number

---

### **2. Breadth-First Search (BFS)**
- Level-order expansion
- Always finds optimal solution
- Heavy on memory (O(b^d))

---

### **3. Iterative Deepening DFS (IDDFS)**
- DFS space efficiency
- BFS-like optimality
- Visits top levels multiple times but cheap in practice

---

### **4. IDA\* Solver (Korf’s Algorithm)**
The most efficient solver in this project.

Uses:
- A* evaluation: `f(n) = g(n) + h(n)`
- IDDFS-style thresholding
- Pattern Database Heuristics (Corners)

---

##  Pattern Databases

### **Corner Pattern Database**
Cube state represented using:
- 8 corner permutations → `8!`
- 7 corner orientations → `3^7`

Total states:
8! × 3^7 = 88,179,840


We use:
- **Nibble Array** (4-bit storage per entry)
- **Permutation Indexer**  
  Converts cube corners → unique sequential index

Final index:
index = perm_rank * (3^7) + orient_rank

Stored using:
- File-based persistence
- Load at solver startup
- Provides heuristic value for IDA*

---

##  Building & Running

g++ -O2 -std=c++17 -o cube main.cpp
./cube


---

##  Solvability
The cube is scrambled only using valid moves, ensuring:
- No illegal permutations  
- No parity issues  
- Always solvable  

(Checking solvability explicitly is outside project scope.)

---

##  Why Multiple Representations?

- **3D** → Easy to visualize  
- **1D** → Fast + simple indexing  
- **Bitboard** → Best for hashing, solvers, PDBs  

All implement the **same abstract base class**, so the solver works with all representations.

---

##  Why Abstract Class + Templates?

To allow:
- One solver  
- Multiple cube models  
- Zero duplicated logic  

 Acknowledgements

Inspired by:

Korf’s optimal solver

Pattern database research

Standard WCA cube notation
