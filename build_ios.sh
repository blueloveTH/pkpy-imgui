mkdir -p build/ios
cd build/ios

FLAGS="-DCMAKE_TOOLCHAIN_FILE=~/ios-cmake/ios.toolchain.cmake -DDEPLOYMENT_TARGET=13.0"

cmake -B os64 -G Xcode $FLAGS -DPLATFORM=OS64 ../..
cmake --build os64 --config Release

cmake -B simulatorarm64 -G Xcode $FLAGS -DPLATFORM=SIMULATORARM64 ../..
cmake --build simulatorarm64 --config Release

function merge() {
    find $1/**/$2/*.a | xargs libtool -static -o $1/libGame-$1.a
}

merge os64 Release-iphoneos
merge simulatorarm64 Release-iphonesimulator

xcodebuild -create-xcframework \
    -library os64/libGame-os64.a \
    -library simulatorarm64/libGame-simulatorarm64.a \
    -output Game.xcframework
