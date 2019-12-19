#!/bin/sh


rm -f ./assets/*.png || true

[ -x "$(command -v minifyxml)" ] && find ./ -type f -name '*.svg' -print0 | xargs -0 -L 1 -P 0 minifyxml --svg --inplace --remove-all-metadata
[ -x "$(command -v xmllint)" ] && find ./ -type f -name '*.svg' -exec xmllint --valid --nowarning --noout {} \;

while read -r filename; do
    if [ -n "${filename}" ] && [ ! -f "assets/${filename}.png" ]; then
        inkscape --export-id="${filename}" --export-dpi=180 --export-id-only --export-png="assets/${filename}.png" assets.svg 2> /dev/null > /dev/null &
    fi
    if [ -n "${filename}" ] && [ ! -f "assets/${filename}@2.png" ]; then
        inkscape --export-id="${filename}" --export-dpi=360 --export-id-only --export-png="assets/${filename}@2.png" assets.svg 2> /dev/null > /dev/null &
    fi
done < assets.txt

while read -r filename; do
    if [ -n "${filename}" ] && [ ! -f "assets/${filename}.symbolic.png" ]; then
        inkscape --export-png="assets/${filename}.symbolic.png" "assets/${filename}.svg" 2> /dev/null > /dev/null &
    fi
    if [ -n "${filename}" ] && [ ! -f "assets/${filename}@2.symbolic.png" ]; then
        inkscape --export-dpi=180 --export-png="assets/${filename}@2.symbolic.png" "assets/${filename}.svg" 2> /dev/null > /dev/null &
    fi
done < files.txt

wait

[ -x "$(command -v pngshrink)" ] && [ -x "$(command -v rename)" ] && find . -type f -name '*.png' -print0 | xargs -0 -P 0 pngshrink && find . -type f -name '*_reduced.png' -print0 | xargs -0 -P 8 rename --force 's/_reduced.png/.png/'

exit 0
