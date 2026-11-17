#!/bin/bash
# Использование: ./bad_nodes.sh <директория_с_логами> [порог]

LOGS_DIR="${1:-.}"
THRESHOLD="${2:-5}"
declare -A cnt

while IFS= read -r -d '' log; do
    grep -q "Convert_done" "$log" && continue
    n=$(grep -m1 "^Node name:" "$log" | sed 's/^Node name:[[:space:]]*//')
    [ -n "$n" ] && cnt[$n]=$(( ${cnt[$n]:-0} + 1 ))
done < <(find "$LOGS_DIR" -maxdepth 1 -type f -print0)

for n in "${!cnt[@]}"; do
    [ "${cnt[$n]}" -gt "$THRESHOLD" ] && echo "$n"
done | paste -sd, -