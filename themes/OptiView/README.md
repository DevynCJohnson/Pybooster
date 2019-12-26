Requirements
------------

- GNOME Shell 3.30+
- GTK 3.24.6+

Other distros may have named the below packages differently.

- Arch/Manjaro/Antergos - `pacman -S git gtk-engine-murrine gtk-engines meson ninja pysassc`
- Debian/Ubuntu/Mint - `apt install git gtk2-engines-murrine gtk2-engines-pixbuf meson ninja-build pysassc`
- Fedora - `dnf install git gtk-murrine-engine gtk2-engines meson ninja-build pysassc`
- Opensuse - `zypper in git gtk2-engine-murrine gtk2-engines meson ninja pysassc`

Installing the following font packages (using Debian names) is recommended: fonts-emojione fonts-font-awesome fonts-fork-awesome fonts-noto-cjk fonts-noto-cjk-extra fonts-noto-color-emoji fonts-noto-core fonts-noto-extra fonts-noto-hinted fonts-noto-mono fonts-noto-ui-core fonts-noto-ui-extra fonts-octicons fonts-open-sans fonts-opensymbol fonts-roboto-hinted fonts-roboto-slab fonts-roboto-unhinted fonts-symbola fonts-unfonts-core fonts-unfonts-extra


Installation
------------

When the above requirements are installed, run `sh ./install.sh` with root privileges.

The themes will be installed in `/usr/share/themes`.


Uninstalling the Themes
-----------------------

With root privileges, remove the `OptiView OptiView-Dark OptiView-shell` folders located in `/usr/share/themes`


Changing Themes
---------------

Use `gnome-tweaks`, `xfce4-appearance-settings`, or some alternative to change themes. Alternatiely, Xfce users can change themes under `Settings > Appearance` and `Settings > Window manager`

A terminal can also be used to change the GTK theme. To change the theme to OptiView-Dark, run `gsettings set org.gnome.desktop.interface gtk-theme OptiView-Dark`. To revert back to Adwaita, for instance, run `gsettings set org.gnome.desktop.interface gtk-theme Adwaita`.


Helpful Links
-------------

- [GTK3 API Index](https://developer.gnome.org/gtk3/3.24/api-index-full.html)


Definitions of Abbreviations
----------------------------

The below abbreviations are seen in the SCSS code.

- **CSD:** Client-Side Decoration
- **OSD:** On-Sceen Display
