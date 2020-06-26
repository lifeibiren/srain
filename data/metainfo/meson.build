metainfo_conf = configuration_data()
metainfo_conf.set('appid', application_id)
metainfo = i18n.merge_file(
  type: 'xml',
  input: configure_file(
    input: 'srain.metainfo.xml.in.in',
    output: 'srian.metainfo.xml.in',
    configuration: metainfo_conf,
  ),
  output: '@0@.metainfo.xml'.format(application_id),
  po_dir: po_dir,
  install: true,
  install_dir: join_paths(datadir, 'metainfo')
)
