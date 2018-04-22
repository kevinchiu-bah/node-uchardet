{
  'includes': [
    'common.gypi',
  ],
  'targets': [
    {
      'target_name': 'uchardet',
      'defines': [
        'NAPI_CPP_EXCEPTIONS',
      ],
      'dependencies': [
        "<!(node -p \"require('node-addon-api').gyp\")",
        'deps/uchardet.gyp:libuchardet',
      ],
      'include_dirs': [
        "<!@(node -p \"require('node-addon-api').include\")",
        "deps/uchardet/src",
        "src",
      ],
      'sources': [
        'src/binding.cpp',
        'src/factory.cpp',
      ],
      'cflags!': [
        '-fno-exceptions'
      ],
      'cflags_cc!': [
        '-fno-exceptions'
      ],
      'conditions': [
        ['OS=="mac"', {
          'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
          }
        }]
      ]
    },
    # {
    #   'target_name': 'uchardet-test',
    #   'type': 'executable',
    #   'dependencies': [
    #     'deps/uchardet.gyp:libuchardet',
    #   ],
    #   'include_dirs': [
    #     "deps/uchardet/src",
    #     "src",
    #   ],
    #   'sources': [
    #     'src/test.cpp',
    #     'src/factory.cpp',
    #   ],
    # }
  ]
}
