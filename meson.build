project(
  'srain', 'c',
  version: '1.1.0',
  license: 'GPL3',
  meson_version: '>= 0.49.0'
)

glib_compile_resources = find_program('glib-compile-resources', required: true)
desktop_file_validate = find_program('desktop-file-validate', required: false)
appstream_util = find_program('appstream-util', required: false)

prefix = get_option('prefix')
bindir = prefix / get_option('bindir')
localedir = prefix / get_option('localedir')

datadir = prefix / get_option('datadir')
pkgdatadir = datadir / meson.project_name()
iconsdir = datadir / 'icons'
podir =meson.source_root () / 'po'
gettext_package = meson.project_name()

dependency('gtk+-3.0', version: '>= 3.22.0'),

subdir('data')
subdir('po')
subdir('src')
