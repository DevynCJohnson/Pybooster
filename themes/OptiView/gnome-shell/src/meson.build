# Destination Directory
install_dir = join_paths(gnomeshell_theme_dir, 'gnome-shell')

# Generate CSS Files
theme_sources = files([
  'gnome-shell-high-contrast.scss',
  'gnome-shell.scss',
  'gnome-shell-sass/_colors.scss',
  'gnome-shell-sass/_common.scss',
  'gnome-shell-sass/_drawing.scss',
  'gnome-shell-sass/_extensions.scss',
  'gnome-shell-sass/_high-contrast-colors.scss',
])

styles = [
  'gnome-shell-high-contrast',
  'gnome-shell'
]

theme_deps = []

sassc = find_program('sassc')
foreach style: styles
  theme_deps += custom_target(
    'style-' + style,
    input: '@0@.scss'.format(style),
    output: '@0@.css'.format(style),
    command: [sassc, '-M', '-t', 'compact', '@INPUT@', '@OUTPUT@'],
    install: true,
    install_dir: install_dir,
    depend_files: theme_sources
  )
endforeach

# Static Files to Copy
data_sources = [
  'activities-active.svg',
  'activities.svg',
  'calendar-today.svg',
  'checkbox-off.svg',
  'checkbox.svg',
  'close-window.svg',
  'close.svg',
  'd2p-activities-active.svg',
  'd2p-activities.svg',
  'dash-placeholder.svg',
  'filter-selected-ltr.svg',
  'filter-selected-rtl.svg',
  'logged-in-indicator.svg',
  'more-results.svg',
  'no-events.svg',
  'no-notifications.svg',
  'noise-texture.png',
  'process-working.svg',
  'running-indicator.svg',
  'source-button-border.svg',
  'summary-counter.svg',
  'switch-off.svg',
  'switch-on.svg',
  'transparent.png',
  'ws-switch-arrow-down.png',
  'ws-switch-arrow-up.png',
]

# Install Static Data Files
install_data(data_sources, install_dir: install_dir)
