if [ "$1" == "--help" ] 
then
 echo  "./plot.sh <True data> <Output data> <Out image>"
 exit 0
fi

True_data=$1
newton_data=$2
cubic_data=$3
OutputImage=$4
gnuplot  << __EOF
set autoscale
set term png
set output '$OutputImage'
plot '$True_data' w linespoints ,'$newton_data' w linespoints ,'$cubic_data' w linespoints
__EOF
eog $OutputImage &
