project(
  'srain', 'c',
  version: '1.1.0',
  license: 'GPL3',
  meson_version: '>= 0.49.0'
)

prefix = get_option('prefix')
bindir = prefix / get_option('bindir')
localedir = prefix / get_option('localedir')
datadir = prefix / get_option('datadir')
pkgdatadir = datadir / meson.project_name()
iconsdir = datadir / 'icons'
podir = meson.source_root () / 'po'
gettext_package = meson.project_name()

subdir('data')
subdir('po')
subdir('src')
