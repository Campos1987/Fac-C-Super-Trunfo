#!/bin/bash

# ... (compilação) ...

# Usamos um subshell para agrupar os comandos e enviar para o jogo
(
  echo "A"
  echo "São Paulo"
  echo "12325000"
  echo "1521.11"
  echo "699.28"
  echo "50"
  echo "B"
  echo "Rio de Janeiro"
  echo "6748000"
  echo "1200.25"
  echo "300.50"
  echo "30"
  # O script Bash espera aqui antes de mandar o último '1'
  ##read -p "Pressione ENTER no terminal para mandar o último atributo..." >&2
  echo "2"
  echo "1"
) | ./jogo

echo -e "\n------------------------------------------"
echo "Teste finalizado com sucesso!"
echo "------------------------------------------"