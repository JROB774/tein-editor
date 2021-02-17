
IncludeDirs="-I ../../third_party/freetype/include -I ../../third_party/freetype/include/freetype -I ../../third_party/glad/osx -I ../../third_party/glm -I ../../third_party/gon -I ../../third_party/sdl2/include -I ../../third_party/stb"
LibraryDirs="-L ../../third_party/freetype/lib/osx"

Libraries="-lfreetype"

Frameworks="-F ../../third_party/sdl2/lib/osx -framework SDL2 -rpath ../../third_party/sdl2/lib/osx"

Defines="-D PLATFORM_OSX"

cd ../../binary/osx
g++ -std=c++17 ../../source/main.cpp -o TheEndEditor $IncludeDirs $Defines $LibraryDirs $Libraries $Frameworks

#  -I ./SDL2/SDL2.framework/Headers -F ./SDL2 -framework SDL2 -rpath ./SDL2
