#!/bin/bash

#SBATCH -p nica
#SBATCH -J Converter
#SBATCH -a 1-1000
#SBATCH -o /nica/mpd1/demanov/convert/convert_run8_25.09/log/%A_%a.log
#SBATCH -x ncx111,ncx112,ncx113,ncx115,ncx117,ncx121,ncx123,ncx127,ncx158,ncx159,ncx171,ncx172,ncx177,ncx181,ncx207,ncx214,ncx216,ncx222,ncx223,ncx224,ncx225,ncx227,ncx208,ncx180,ncx203,ncx146,ncx156,ncx157,ncx160,ncx180,ncx141,ncx111,ncx112,ncx113,ncx115,ncx117,ncx121,ncx127,ncx146,ncx169,ncx171,ncx172,ncx174,ncx181,ncx185,ncx187,ncx203,ncx207,ncx208,ncx211,ncx213,ncx215,ncx216,ncx217,ncx222,ncx223,ncx224,ncx225,ncx226,ncx227,ncx143

bmn_root_prod="25.09.0"
bmn_root_path=/cvmfs/bmn.jinr.ru/bmnroot/${bmn_root_prod}/x86_64-centos7/bmnroot_config.sh
digi_directory=/eos/nica/bmn/exp/digi/run8/${bmn_root_prod}
dst_directory=/eos/nica/bmn/exp/dst/run8/${bmn_root_prod}

path_to_macro=/nica/mpd1/demanov/convert/convert_run8_25.09
calib_file1=${path_to_macro}/additional_files/run8_dedx_calibR_coeff.root
calib_file2=${path_to_macro}/additional_files/run8_dedx_calibS_coeff.root
pid_file1=${path_to_macro}/additional_files/pars400_25.09.root
pid_file2=${path_to_macro}/additional_files/pars700_25.09.root
vtxXYZ_corr_file=${path_to_macro}/additional_files/run8_25.09_corr_VtxXYZ.root
bc1_fd_corr_file=${path_to_macro}/additional_files/run8_25.09_corr_bc1fd.root
tof_corr_file=${path_to_macro}/additional_files/tof_time_shift_calib_230726.root

CONVERTER_MACRO=${path_to_macro}/convertBmn_run8.C

TASK_ID=$SLURM_ARRAY_TASK_ID

file_list=$1
out_dir=$2

mkdir -p $out_dir
mkdir -p "${out_dir}/log"
cd $out_dir

name_file_root=$(basename $(head -n $TASK_ID $file_list | tail -n 1 ))
name_file=${name_file_root%.root*}
input_file_dst=${dst_directory}/${name_file}.root
input_file_digi=${digi_directory}/${name_file}.root
output_file=${out_dir}/${name_file}.tree.root
output_log=${out_dir}/log/${SLURM_ARRAY_JOB_ID}_${TASK_ID}_${name_file}.log

source /cvmfs/bmn.jinr.ru/config/x86_64-centos7/cluster_config.sh
source $bmn_root_path

echo "bmnroot path: ${bmn_root_path}" &>> $output_log
echo "Node name: ${SLURMD_NODENAME}" &>> $output_log
echo "Job ID: ${SLURM_ARRAY_JOB_ID}" &>> $output_log
echo "Task ID: ${TASK_ID}" &>> $output_log
echo "line: ${TASK_ID}" &>> $output_log
echo "name: ${name_file}" &>> $output_log
echo "input digi: ${input_file_digi}" &>> $output_log
echo "input dst: ${input_file_dst}" &>> $output_log
echo "output tree: ${output_file}" &>> $output_log
echo "calib file 1: ${calib_file1}" &>> $output_log
echo "calib file 2: ${calib_file2}" &>> $output_log
echo "pid file 1: ${pid_file1}" &>> $output_log
echo "pid file 2: ${pid_file2}" &>> $output_log
echo "Vtx XYZ corr file: ${vtxXYZ_corr_file}" &>> $output_log
echo "BC1 FD corr file: ${bc1_fd_corr_file}" &>> $output_log
echo "TOF corr file: ${tof_corr_file}" &>> $output_log
echo "output log: ${output_log}" &>> $output_log

time root -l -b -q ${CONVERTER_MACRO}"(\"${input_file_dst}\", \"${input_file_digi}\",\"${calib_file1}\",\"${calib_file2}\",\"${output_file}\",\"${pid_file1}\",\"${pid_file2}\",\"${vtxXYZ_corr_file}\",\"${bc1_fd_corr_file}\",\"${tof_corr_file}\")" &>> $output_log
#root -l -q -b convertBmn_run8.C'("/eos/nica/bmn/exp/dst/run8/25.09.0/mpd_run_Top_8000_ev0_p17.root","/eos/nica/bmn/exp/digi/run8/25.09.0/mpd_run_Top_8000_ev0_p17.root","/eos/nica/mpd/users/demanov/bmn/convert_run8_25.09/run8_dedx_calibR_coeff.root","/eos/nica/mpd/users/demanov/bmn/convert_run8_25.09/run8_dedx_calibS_coeff.root","/path_to_oFile/oFile.tree.root")

echo "Done!" &>> $output_log

#grep -o "mpd_run_Top_[0-9]*_ev[0-9]*_p[0-9]*" bad.list | awk '{print $0 ".root"}' > bad_list.list