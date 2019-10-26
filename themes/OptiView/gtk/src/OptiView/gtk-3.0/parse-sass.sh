#!/bin/sh


if [ ! -x "$(command -v sassc)" ]; then
   printf 'sassc needs to be installed to generate the CSS\n'
   exit 1
fi


printf 'Generating the CSS\n'

sassc -M -t compact gtk.scss gtk.css &
sassc -M -t compact gtk-dark.scss gtk-dark.css &

wait
