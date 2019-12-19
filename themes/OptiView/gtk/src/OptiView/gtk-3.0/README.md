Tweaking the Theme
==================

GTK themes are complex, so to keep it maintainable it is written and processed in SASS.

| File    | Description                                                             |
|:--------|:------------------------------------------------------------------------|
| _apps.scss          | Application specific styles.
| _colors-public.scss | SCSS colors exported through GTK to allow for 3rd-party app color mixing.
| _common.scss        | Actual definitions of style for each widget.
| _drawing.scss       | Drawing helper mixings/functions to allow easier definition of widget drawing under specific context.
| _variables.scss     | Global color definitions and commonly used variables.

Once changes are made to the the SCSS files, use `./parse-sass.sh` to generate the CSS files.

SASS Documentation: [http://sass-lang.com/documentation/](http://sass-lang.com/documentation/)


Editing the Assets
==================

The assets are created in the `assets.svg` file and then rendered with `./render-assets.sh` by fetching the object ID name from `assets.txt`. When editing the SVG files, ensure that the object IDs remain the same. When creating new assets, be sure to add the object ID in `assets.txt`.
