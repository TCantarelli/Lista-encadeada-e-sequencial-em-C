cmake_minimum_required(VERSION 4.3)
project(ED1 C)

set(CMAKE_C_STANDARD 23)

add_executable(ED1 main.c
        readFile.c
        declarations.h
        imprimir.c
        redFileSequencial.c
        pesquisaEncadeada.c
        pesquisaSimples.c
        showMenuPrimary.c
        showMenuFile.c
        addFinalEncadeada.c
        addFinalSequencial.c
        addInicioEncadeada.c
        addInicioSequencial.c
        addMeioEncadeada.c
        addMeioSequencial.c
        removerPosicaoEncadeada.c
        "removerPosicaoSequencial.c")
