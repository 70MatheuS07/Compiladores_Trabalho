#!/bin/bash

# Diretórios
input_dir="in/noerr"
output_dir="new_out"

# Cria o diretório de saída, caso não exista
mkdir -p "$output_dir"

# Percorre os arquivos de entrada
for input_file in "$input_dir"/*.c; do
    # Extrai o nome do arquivo sem extensão
    base_name=$(basename "$input_file" .c)

    # Redireciona a saída do a.out para arquivo .dot
    ./a.out < "$input_file" 2> "$output_dir/$base_name.dot"

    # Converte o arquivo .dot em PDF
    dot -Tpdf "$output_dir/$base_name.dot" -o "$output_dir/$base_name.pdf"
    
    echo "Processado $base_name.c: saída em $base_name.pdf"
done
