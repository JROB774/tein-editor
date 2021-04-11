# The End is Nigh: Editor

An unofficial level and world map editor for the game **[The End is Nigh](https://store.steampowered.com/app/583470/The_End_Is_Nigh/)**, by Edmund McMillen and Tyler Glaiel.

![Screenshot of The Editor in Use](https://img.itch.zone/aW1hZ2UvNjYyODkxLzM1NzgwNzMucG5n/original/UhhS%2Bm.png)

The editor provides the necessary tools for modders to unpack the game's resources, modify and create new levels, and modify the world map, all with an easy-to-use interface.

## Building

For those interested in contributing to the editor's development, building the executable is as simple as running one of the available build scripts.
All of the code dependencies and external third party libraries have been included within this repository, so there is no need to fetch them manually.

### Windows

A version of Visual Studio with C++17 support is required. To build the editor run the `build\win32\build.bat` script. To modify build parameters and
flags open the `build\win32\config.bat` script and tweak the values to change how the editor is built (e.g. release or debug mode, 32-bit or 64-bit).

### MacOS

The build script `build\osx\build.sh` is available for compiling on MacOS. However, a full build process and support for this platform has not been
fully implemented in the editor, and therefore the program cannot be expected to work as intended due to some missing platform-specific features.

## License

The project's code is available under the **[MIT License](https://github.com/JROB774/tein-editor/blob/master/LICENSE)**.
