# CompositeLamainateTool
Composite CLT Analysis Tool

Outline of Tool

1.  Materials database
1.1  Load existing database of materials or create new materials
1.2  Includes material properties, allowables, modification factors due to environment (wet, dry, hot, cold), and can vary by temperature
1.3  Modified material properties can be saved to existing or new database
1.4  Load in material definitions from bdf

2.  Loads database
2.1  Load existing database of loads of create new loads (for now this can just be a simple text file, although being able to load in a punch file or even an f06 file would be useful)
2.2  Includes all 6 components of loading (Nxx, Nyy, Nxy, Mxx, Myy, Mxy)
2.3  Load in multiple databases (flight loads database, thermal loads database, pressure loads database, etc.)
2.4  Create load combinations between databases to be used in analysis (flight + thermal + pressure, etc.).  Somehow the environment conditions should be specified with these load sets so that when used in the analysis, the appropriate allowables are used.

3.  Laminate database
3.1  Load existing database of composite laminates of create new laminates
3.2  Load in PCOMP definitions from bdf

4.  Analysis
4.1  Typical analysis options - choose laminate, load sets, failure criteria, etc.
4.2  Define custom failure criteria

5.  Results
5.1  Show results in some pretty format -- critical elements, loadcases, plies, etc.
5.2  Save results to some format that can be plotted in FEMAP or PATRAN
5.3  Save inputs
