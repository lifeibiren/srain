desktop_conf = configuration_data()
desktop_conf.set('icon', application_id)
desktop_conf.set('application_id', application_id)
desktop = i18n.merge_file(
  type: 'desktop',
  input: configure_file(
    input: 'org.gnome.Todo.desktop.in.in',
    output: 'org.gnome.Todo.desktop.in',
    configuration: desktop_conf
  ),
  output: '@0@.desktop'.format(application_id),
  po_dir: po_dir,
  install: true,
  install_dir: join_paths(gnome_todo_datadir, 'applications')
)

install_data(
  'org.gnome.todo.gschema.xml',
  install_dir: gnome_todo_schemadir
)

subdir('metainfo')
subdir('icons')
