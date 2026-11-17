#!/bin/bash

#SBATCH -p nica
#SBATCH -J MainConv
#SBATCH -o /nica/mpd1/demanov/convert/convert_run8_25.09/start_%A.log
#SBATCH -x ncx113,ncx145,ncx154,ncx159,ncx187,ncx131,ncx156

LIST_DIR=/nica/mpd1/demanov/convert/convert_run8_25.09/lists
OUTPUT_DIR=/eos/nica/bmn/users/demanov/run8_2509_301026

echo "========================================="
echo "STARTING MASTER SCRIPT"
echo "Output dir: ${OUTPUT_DIR}"
echo "Input lists dir: ${LIST_DIR}"
echo "Start time: $(date)"
echo "========================================="
echo ""

# Запускаем по одному листу
for list in list_00{02..15}.list; do
    echo "========================================="
    echo "Processing: $list"
    echo "Start time: $(date)"
    echo "========================================="
    
    echo "Submitting $list..."
    job_id=$(sbatch --parsable run8_convert.sh ${LIST_DIR}/$list ${OUTPUT_DIR})
    echo "Job ID: $job_id"
    
    # Ждем пока завершится
    while squeue -h -u $USER | grep -q "$job_id"; do
        echo "Waiting for $list to finish..."
        sleep 60
    done
    
    echo "$list finished!"
    echo "Finish time: $(date)"
    echo "========================================="
    echo ""
done

echo "========================================="
echo "ALL DONE!"
echo "End time: $(date)"
echo "========================================="