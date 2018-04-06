# conan-project-example

works from source branch: https://github.com/memsharded/conan/tree/feature/conan_project

conan-project works putting a conan-project.yml in the current folder or one of the parents folder. Conan will go up until a conan-project.yml is found (or none)

The syntax of conan-project.yml is:

```yaml
HelloB: # The package name that will be remapped to user instead of cache
    folder: B # The relative path in which this package is (relative to conan-rpoject)
    includedirs: src # Path to look for includes
    cmakedir: src # Information to generate meta-project
    build: build # Relative path to put the build
    libdirs: build/{build_type} # Path to look for libs
    # package: pkg # If your build already creates the package use this instead of includedirs/libdirs
HelloC:
    folder: C
    includedirs: src
    cmakedir: src
    build: build
    libdirs: build/{build_type}
HelloA:
    folder: A
    cmakedir: src
    build: build

generator: cmake # Meta generator
name: MyProject #Name of the meta project
```

It works with the same ``install``

```bash
$ cd A && conan install . --build -if=build
$ cd A && conan build . -bf=build
$ ./A/build/Release/app

# Debug
$ cd A && conan install . --build -if=build  -s build_type=Debug
$ cd A && conan build . -bf=build
$ ./A/build/Debug/app

# Meta project
$ cmake . -G "Visual Studio 15 Win64"
# Open Visual Studio or use command line:
$ cmake --build . --config Release
$ ./A/build/Release/app
# Modify code of B and/or C
$ cmake --build . --config Release
$ ./A/build/Release/app
```