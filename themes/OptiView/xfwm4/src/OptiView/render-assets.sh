#!/bin/sh


rm -f ./*.png || true

[ -x "$(command -v minifyxml)" ] && find ./ -type f -name '*.svg' -print0 | xargs -0 -L 1 -P 0 minifyxml --svg --inplace --remove-all-metadata > /dev/null
[ -x "$(command -v xmllint)" ] && find ./ -type f -name '*.svg' -exec xmllint --valid --nowarning --noout {} \;

while read -r filename; do
    if [ -n "${filename}" ] && [ ! -f "${filename}.png" ]; then
        inkscape --export-id="${filename}" --export-dpi=180 --export-id-only --export-png="${filename}.png" assets.svg 2> /dev/null > /dev/null &
    fi
done < assets.txt

wait

[ -x "$(command -v pngshrink)" ] && [ -x "$(command -v rename)" ] && find . -type f -name '*.png' -print0 | xargs -0 -P 0 pngshrink 2> /dev/null > /dev/null && find . -type f -name '*_reduced.png' -print0 | xargs -0 -P 8 rename --force 's/_reduced.png/.png/'

exit 0
