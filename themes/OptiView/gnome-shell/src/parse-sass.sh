#!/bin/sh


if [ ! -x "$(command -v pysassc)" ]; then
   printf 'pysassc needs to be installed to generate the CSS files.\n'
   exit 1
fi


printf 'Generating CSS\n'

pysassc --omit-sourcemap-url -t compact gnome-shell.scss gnome-shell.css &
pysassc --omit-sourcemap-url -t compact gnome-shell-high-contrast.scss gnome-shell-high-contrast.css

wait

exit 0
