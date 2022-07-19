#!/bin/bash
set -e

# echo $URL_LIST | xargs -n 1 -P 8 wget -q

Z_VALUE=17
X_START=69588
Y_START=44703

x_size=19
y_size=24

X_END=$(expr $X_START + $x_size - 1)
Y_END=$(expr $Y_START + $y_size - 1)

files=""
for y in $(seq $Y_START $Y_END) 
do
    for x in $(seq $X_START $X_END) 
    do
        files+=" ./cache/${Z_VALUE}_${x}_${y}.png"
    done
done

echo $files

montage -mode concatenate -tile ${x_size}x${y_size} $files out.png