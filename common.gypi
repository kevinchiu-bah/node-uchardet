{
  'variables': {
    'url_': 'https://www.freedesktop.org/wiki/Software/uchardet/',
    'bugreport_': 'https://bugs.freedesktop.org/enter_bug.cgi?product=uchardet',
    'version_major_': '0',
    'version_minor_': '0',
    'version_revision_': '0',
    'library_name_': 'libuchardet',
  },
  'target_defaults': {
    'variables': {
      'library_dir_': '<!(pwd)/build/$(BUILDTYPE)',
      'builddir': '<(library_dir_)',
    },
    'cflags': [
      '-std=c++11',
      '-stdlib=libc++',
      '-Wall',
    ],
    'cflags!': [
      '-fno-exceptions'
    ],
    'cflags_cc!': [
      '-fno-exceptions'
    ],
    # OSX
    'xcode_settings': {
      'CLANG_CXX_LANGUAGE_STANDARD': 'c++11',
      'CLANG_CXX_LIBRARY': 'libc++',
      'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
      'GCC_ENABLE_CPP_RTTI': 'NO',
      'MACOSX_DEPLOYMENT_TARGET': '10.12',
      'OTHER_LDFLAGS': [
        # LDFlags
      ]
    },
    # Windows
    'msvs_settings': {
      'VCLinkerTool': {
        'AdditionalLibraryDirectories': [
          # LDFlags
        ]
      }
    },
    'configurations': {
      # [Configuration] Debug
      'Debug': {
        'defines': [
          'DEBUG',
          '_DEBUG'
        ],
        # Windows
        'msvs_settings': {
          'VCCLCompilerTool': {
            'RuntimeLibrary': 1,
          },
          'VCLinkerTool': {
            'LinkTimeCodeGeneration': 1,
            'OptimizeReferences': 2,
            'EnableCOMDATFolding': 2,
            'LinkIncremental': 1,
            'GenerateDebugInformation': 'true',
          }
        },
        'xcode_settings': {
          'GENERATE_DEBUG_SYMBOLS': 'YES',
        }
      },
      # [Configuration] Release
      'Release': {
        # Windows
        'msvs_settings': {
          'VCCLCompilerTool': {
            'RuntimeLibrary': 0,
            'Optimization': 3,
            'FavorSizeOrSpeed': 1,
            'InlineFunctionExpansion': 2,
            'WholeProgramOptimization': 'true',
            'OmitFramePointers': 'true',
            'EnableFunctionLevelLinking': 'true',
            'EnableIntrinsicFunctions': 'true'
          },
          'VCLinkerTool': {
            'LinkTimeCodeGeneration': 1,
            'OptimizeReferences': 2,
            'EnableCOMDATFolding': 2,
            'LinkIncremental': 1,
          }
        },
      }
    },
    'conditions': [
      # OSX
      ['OS=="mac"', {
        # TODO
      }],
      # Linux
      ['OS=="linux"', {
        'ldflags': [
          # LDFlags
        ],
      }],
      # Windows
      ['OS=="win"', {
        'cflags_cc+': [
          '-std=c++0x',
        ]
      }]
    ],
  }
}
