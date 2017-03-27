# Cabinetry
Eases the burden of calculating the dimensions required for crafting European style (no face frame) cabinet boxes and doors. Displays a summary of necessary materials, with cut list and sheet layout.

The sheet layout is calculated with a modified 2D bin packing algorithm, taken from [https://github.com/juj/RectangleBinPack](https://github.com/juj/RectangleBinPack) as an example. The base algorithm used is the **SHELF-FF**, with a modification that considers cabinet doors look best with a vertical grain orientation.

The above algorithm was chosen with the intent of producing sheet layouts that eased the burden of cutting the sheets with a track (circular) saw. A 'shelf' layout provides straight lines that are easy to break down quickly, while minimizing human error.

If you are planning to adapt this to set up a cut list (and toolpath) for a CNC machine, this changes the layout consideration significantly. Guillotine based algorithms [1](https://github.com/juj/RectangleBinPack/blob/master/GuillotineBinPack.cpp), [2](http://www.win.tue.nl/~nikhil/pubs/Bansal-packing.pdf) are significantly more efficient and should be considered, since there is limited human involvement. If you do adapt this, please let me know / contribute!

## Operation Assumptions
Choosing axes in space when computing the breakdown of sheet goods and cabinet design is challenging. To introduce sanity, the following standards have been adhered to:

### Coordinate axes chosen for cabinets.
* The axis parallel to the ground is always X (Length).
* The axis pointing to the ceiling is always Y (Width).
* The axis perpendicular to both X and Y is Z (Depth).

### Coordinate axes chosen for wood pieces.
* If a piece has wood grain (or veneer), the direction parallel to the grain is always considered X (length).
* If no grain is present, the longest side of the parent (or sheet) piece is considered X.
* The axis that is perpendicular to X, and across the face of the wood piece is then Y (width).
* The axis perpendicular to both X and Y is then Z (depth).
