# 🧱 Enclosure Detection in a Maze (C++)
This is a simple C++ console program that determines whether a selected point is located inside a closed room in a 10x10 maze. The maze is defined as a grid of walls (#) and paths ( ). The user-defined point is marked with an X, and the algorithm analyzes the horizontal and vertical directions from the point to determine enclosure.
# 📌 Features
- Hardcoded 10×10 maze (2D char array)
- Struct-based point creation (Punkt1)
- Checks if a point is enclosed by walls in both horizontal and vertical directions
- Uses simple parity logic:
  - Counts the number of wall segments in both directions
  - If any segment count is odd, it assumes the point is inside a chamber
# 🧪 How It Works
1. A point (Punkt1) is created using utworzPunkt(x, y) and placed in the maze.
2. The maze is scanned left-right and top-down from that point.
3. The number of wall (#) segments between open spaces ( ) is counted.
4. If any of these wall segment counts is odd, the point is considered inside a chamber.
# 💡 Example Output
```shell
##########
#        #
# ###    #
# # #    #
### ###X #
       # #
       # #
######## #
#        #
##########

Punkt znajduje się w komnacie
```
# 🧱 Maze Key
- "#" → Wall
- ' ' → Path / Open space
- X → Target point
