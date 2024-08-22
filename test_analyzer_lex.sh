#!/bin/bash

# Diretórios
input_dir="in/lexerr"
output_dir="out/lexerr"

# Arquivo executável do analisador
EXE="./a.out"

# Checar se o executável existe
if [ ! -f $EXE ]; then
    echo "Executável não encontrado. Compile o projeto primeiro."
    exit 1
fi

# Iterar sobre todos os arquivos .c na pasta de entrada
for input_file in "$input_dir"/*.c; do
    # Nome do arquivo sem extensão
    base_name=$(basename "$input_file" .c)
    
    # Arquivo de saída esperado
    expected_output="$output_dir/$base_name.out"
    
    # Arquivo de saída gerado
    generated_output="$output_dir/$base_name.generated.out"
    
    # Executar e redirecionar a saída para o arquivo gerado
    $EXE < "$input_file" > "$generated_output"
    
    # Comparar a saída gerada com a saída esperada
    if diff -u "$expected_output" "$generated_output"; then
        echo "$base_name: OK"
    else
        echo "$base_name: FALHA"
    fi
    
    # Remover o arquivo de saída gerado
    rm "$generated_output"
done