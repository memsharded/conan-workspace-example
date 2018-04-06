import os

def run(cmd):
    ret = os.system(cmd)
    if ret!=0:
        raise Exception("Cmd failed: %s" % cmd)


# First a normal conan install, but there is a conan-project above it
run("cd A && conan install . --build -if=build")
run("cd A && conan build . -bf=build")
app_release = os.sep.join([".", "A", "build", "Release", "app"])
run(app_release)

# Debug
run("cd A && conan install . --build -if=build -s build_type=Debug")
run("cd A && conan build . -bf=build")
app_debug = os.sep.join([".", "A", "build", "Debug", "app"])
run(app_debug)

# Meta project
run('cmake . -G "Visual Studio 15 Win64"')
# Open Visual Studio or use command line:
run('cmake --build . --config Release')
run(app_release)
# Modify code
run('cmake --build . --config Release')
run(app_release)