{
  'targets': [
    {
      'target_name': 'uchardet',
      'include_dirs': [
        '<!(node -e "require(\'nan\')")'
      ],
      'sources': [
        'src/binding.cpp',
      ],
      'dependencies': [
        'deps/uchardet.gyp:uchardet',
      ]
    }
  ]
}
