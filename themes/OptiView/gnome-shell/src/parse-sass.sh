#!/bin/sh


if [ ! -x "$(command -v sassc)" ]; then
   printf 'sassc needs to be installed to generate the CSS files.\n'
   exit 1
fi


printf 'Generating CSS\n'

sassc -M -t compact gnome-shell.scss gnome-shell.css &
sassc -M -t compact gnome-shell-high-contrast.scss gnome-shell-high-contrast.css

wait

exit 0
