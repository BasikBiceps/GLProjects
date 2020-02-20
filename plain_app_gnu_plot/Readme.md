The steps that you must complete to start the project:
1. Install gnuplot source files.
2. Open INSTALL file and read how to configure and install gnuplot.
3. TODO configure and install gnuplot.
4. If you haven't a boost on your PC, you must to isntall it.
5. TODO clone of special interface for communicate with gnuplot: http://stahlke.org/dan/gnuplot-iostream/
6. Take gnuplot-iostream.h and move it to your project.
7. If you wonna, you can move this header in separate directory and after this in CMakeLists.txt write include_directories("your include path").
8. Finally, you need to register dependencies of your target on boost libraries as in example.
9. TODO include in your own project and just use :)

