#!/bin/sh


if [ ! -x "$(command -v pysassc)" ]; then
   printf 'pysassc needs to be installed to generate the CSS\n'
   exit 1
fi


printf 'Generating CSS\n'

pysassc --omit-sourcemap-url -t compact gtk.scss gtk.css &
pysassc --omit-sourcemap-url -t compact gtk-dark.scss gtk-dark.css &

wait
