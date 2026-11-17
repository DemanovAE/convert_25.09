#!/bin/bash

INPUT_DIR="/eos/nica/bmn/exp/dst/run8/25.09.0"
OUTPUT_DIR="/eos/nica/bmn/users/demanov/run8_2509_301026"

# Проверка существования директорий
if [ ! -d "$INPUT_DIR" ]; then
    echo "Ошибка: входная директория '$INPUT_DIR' не существует"
    exit 1
fi

if [ ! -d "$OUTPUT_DIR" ]; then
    echo "Ошибка: выходная директория '$OUTPUT_DIR' не существует"
    exit 1
fi

missing_count=0
total_count=0

echo "Проверка отсутствующих файлов..."
echo "Входная директория: $INPUT_DIR"
echo "Выходная директория: $OUTPUT_DIR"
echo "----------------------------------------"

# # Проходим по всем .root файлам во входной директории
# for input_file in "$INPUT_DIR"/*.root; do
#     # Проверяем, что файл существует (на случай если нет .root файлов)
#     [ -e "$input_file" ] || continue
    
#     total_count=$((total_count + 1))
    
#     # Получаем имя файла без пути
#     filename=$(basename "$input_file")
    
#     # Преобразуем имя: mpd_run_Top_6987_ev1_p1.root -> mpd_run_Top_6987_ev1_p1.tree.root
#     # Убираем .root и добавляем .tree.root
#     base_name="${filename%.root}"
#     expected_output="${base_name}.tree.root"
    
#     # Проверяем наличие соответствующего файла в выходной директории
#     if [ ! -f "$OUTPUT_DIR/$expected_output" ]; then
#         echo "ОТСУТСТВУЕТ: $filename -> ожидается: $expected_output"
#         missing_count=$((missing_count + 1))
#     fi
# done

# Собираем отсутствующие файлы
for input_file in "$INPUT_DIR"/*.root; do
    [ -e "$input_file" ] || continue
    
    filename=$(basename "$input_file")
    base_name="${filename%.root}"
    expected_output="${base_name}.tree.root"
    
    if [ ! -f "$OUTPUT_DIR/$expected_output" ]; then
        echo "$filename"
    fi
done


#echo "----------------------------------------"
#echo "Всего входных файлов: $total_count"
#echo "Отсутствующих выходных файлов: $missing_count"

if [ $total_count -eq 0 ]; then
    echo "Предупреждение: во входной директории не найдено .root файлов"
fi

exit 0