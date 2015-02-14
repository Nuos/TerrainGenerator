# TerrainGenerator
![Terrain Image]
(https://github.com/sksharan/TerrainGenerator/blob/master/TerrainGenerator/images/terrain.png)

**TerrainGenerator** is a program that generates infinite landscapes using OpenGL 4.3. The landscape is generated in chunks, and each chunk uses a modified "split-only" version of the ROAM algorithm for level of detail. Textures are applied to the terrain based on the slope of the land (e.g., grass on flat land, rock on steep land), and grass blades are generated at runtime through the use of a geometry shader.
OpenMP is used for added performance; one thread handles the main loop logic while another thread focuses solely on updating the landscape.

This GitHub repository contains the Visual Studio 2013 Solution file. When running the program, use W, A, S, D to move around, E to switch between walk mode and fly mode, R to toggle wireframe on/off, and ESC to exit the program.

ROAM is a continuous level of detail algorithm conceived in the 1990s. The original paper can be found at https://graphics.llnl.gov/ROAM/roam.pdf. ROAM is implemented in this project for learning purposes, but on modern computers it would be more effective to use other algorithms (e.g., GPU-based tessellation using the new tessellation shaders). The picture below shows the wireframe for a single chunk of terrain, with the viewer at the lower left corner. Using ROAM, the number of triangles is greatest closest to the viewer since that is where the most detail in the terrain is required.

![ROAM Wireframe]
(https://github.com/sksharan/TerrainGenerator/blob/master/TerrainGenerator/images/roam_wireframe.png)
