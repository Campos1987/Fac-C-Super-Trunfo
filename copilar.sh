#!/bin/bash

# Compila o projeto
# Adicionamos -Wall para ver avisos e -I para ajudar o GCC a achar os headers (.h)
gcc \
    interface/start/*.c \
    main.c \
    -o jogo \
    -Wall

# Só executa o jogo se a compilação tiver sucesso
if [ $? -eq 0 ]; then
    echo "Compilação concluída com sucesso! Iniciando..."
    ./jogo
else
    echo "Erro na compilação. O jogo não será iniciado."
fi