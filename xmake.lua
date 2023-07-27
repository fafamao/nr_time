target("library")
    set_kind("static")
    add_files("src/*.cpp")
    add_includedirs("inc")

target("practice")
    set_kind("binary")
    add_includedirs("inc")
    add_deps("library")
    add_files("main.cpp")

target("fp")
    set_kind("binary")
    add_files("src/fp.c")

target("macro")
    set_kind("binary")
    add_files("src/macro.c")

target("sm")
    set_kind("binary")
    add_files("src/sm.c")
