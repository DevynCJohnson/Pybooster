#!/bin/sh


if [ ! -x "$(command -v pysassc)" ]; then
   printf 'pysassc needs to be installed to generate the CSS files.\n'
   exit 1
fi


printf 'Generating CSS\n'

pysassc --precision=4 -t compact gtk.scss gtk.css &
pysassc --precision=4 -t compact gtk-dark.scss gtk-dark.css &

wait

exit 0
