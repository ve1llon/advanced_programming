import qbs

CppApplication {
    consoleApplication: true
    install: true
    files: [
        "components.h",
        "composite.h",
        "flyweight_leaves.h",
        "main.cpp",
    ]
}
