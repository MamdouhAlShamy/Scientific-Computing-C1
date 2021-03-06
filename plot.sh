if [ "$1" == "--help" ] 
then
 echo  "./plot.sh <True data> <Output data> <Out image>"
 exit 0
fi

True_data=$1
Out_data=$2
OutputImage=$3
gnuplot  << __EOF
set autoscale
set term png
set output '$OutputImage'
plot '$True_data' w points ,'$Out_data' w linespoints
__EOF
eog $OutputImage &
