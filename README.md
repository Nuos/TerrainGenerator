# TerrainGenerator
![Terrain Image]
(https://github.com/sksharan/TerrainGenerator/blob/master/TerrainGenerator/images/terrain.png)

**TerrainGenerator** is a program that generates infinite landscapes using OpenGL 4.3. The landscape is generated in chunks, and each chunk uses the ROAM algorithm for level of detail. Textures are applied to the terrain based on the slope of the land (e.g., grass on flat land, rock on steep land), and grass blades are generated at runtime through the use of a geometry shader.

This GitHub repository contains the Visual Studio 2013 Solution file. When running the program, use W, A, S, D to move around, E to switch between walk mode and fly mode, R to toggle wireframe on/off, and ESC to exit the program.
