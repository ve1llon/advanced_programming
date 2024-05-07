import qbs

CppApplication {
    consoleApplication: false

    files: [
        "builder.h",
        "main.cpp"
    ]

    // Настройки установки (необязательно)
    install: true
    // Укажите, куда установить файлы
    installDir: "/path/to/install/directory"
}
