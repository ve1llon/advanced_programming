import qbs

CppApplication {
    consoleApplication: true
    install: true
    files: [
        "abstract_realization.h",
        "abstraction.h",
        "concrete_realization.h",
        "main.cpp",
    ]
}
