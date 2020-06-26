#####################
# Project meta info #
#####################

project(
  'srain', 'c',
  version: '1.1.0',
  license: 'GPL3',
  meson_version: '>= 0.49.0'
)

app_id = 'im.srain.Srain'
name_suffix = ''

if get_option('profile') == 'dev'
  profile = 'dev'
  name_suffix = ' (Development)'
  app_id += '.Dev'
endif

############################
# Installation directories #
############################

prefix = get_option('prefix')
bin_dir = prefix / get_option('bindir')
locale_dir = prefix / get_option('localedir')
data_dir = prefix / get_option('datadir')
pkg_data_dir = datadir / meson.project_name()
icons_dir = datadir / 'icons'
po_dir = meson.source_root () / 'po'
gettext_package = meson.project_name()
sys_conf_dir = prefix / get_option('sysconfdir')


gnome = import('gnome')
i18n = import('i18n')

meta_h = configuration_data()
meta_h.set_quoted('GETTEXT_PACKAGE', meson.project_name())
meta_h.set_quoted('PACKAGE', meson.project_name())
meta_h.set_quoted('PACKAGE_NAME', meson.project_name())
meta_h.set_quoted('PACKAGE_VERSION', meson.project_version())
meta_h.set_quoted('PACKAGE_DESC', '')
meta_h.set_quoted('PACKAGE_APPID', app_id)
meta_h.set_quoted('PACKAGE_BUILDID', app_id)
meta_h.set_quoted('PACKAGE_WEBSITE', 'https://srain.im')
meta_h.set_quoted('PACKAGE_BUGREPORT', 'https://github.com/SrainApp/' + meson.project_name() + '/issues/new')
meta_h.set_quoted('PACKAGE_COPYRIGHT_DATES', '2016 - 2020')
meta_h.set_quoted('PACKAGE_DATA_DIR', pkgdatadir)
meta_h.set_quoted('PACKAGE_CONFIG_DIR', '')

subdir('data')
subdir('po')
subdir('src')
