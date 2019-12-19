### Requirements

- GNOME Shell 3.30+
- GTK 3.24.6+

Other distros may have named the below packages differently.

* Arch/Manjaro/Antergos - `pacman -S git gtk-engine-murrine gtk-engines meson ninja pysassc`
* Debian/Ubuntu/Mint - `apt install git gtk2-engines-murrine gtk2-engines-pixbuf meson ninja-build pysassc`
* Fedora - `dnf install git gtk-murrine-engine gtk2-engines meson ninja-build pysassc`
* Opensuse - `zypper in git gtk2-engine-murrine gtk2-engines meson ninja pysassc`

Installing the following font packages (using Debian names) is recommended: fonts-emojione fonts-font-awesome fonts-fork-awesome fonts-noto-cjk fonts-noto-cjk-extra fonts-noto-color-emoji fonts-noto-core fonts-noto-extra fonts-noto-hinted fonts-noto-mono fonts-noto-ui-core fonts-noto-ui-extra fonts-octicons fonts-open-sans fonts-opensymbol fonts-roboto-hinted fonts-roboto-slab fonts-roboto-unhinted fonts-symbola fonts-unfonts-core fonts-unfonts-extra

## Installation

When the above requirements are installed, simply run `sh ./install.sh`

The themes will be installed in `/usr/share/themes`.

### Updating the Theme

```bash
sudo ninja -C build install
```

#### Changing Themes

Use `gnome-tweaks`, `xfce4-appearance-settings`, or some alternative to change themes. Alternatiely, Xfce users can change themes under `Settings > Appearance` and `Settings > Window manager`

A terminal can also be used to change the GTK theme.

```bash
# Changing the theme to OptiView-Dark, simply run
gsettings set org.gnome.desktop.interface gtk-theme OptiView-Dark

# Reverting the change to the default GNOME theme
gsettings set org.gnome.desktop.interface gtk-theme Adwaita
```

#### Uninstalling the Themes

With root privileges, remove the `OptiView OptiView-Dark OptiView-shell` folders located in `/usr/share/themes`
