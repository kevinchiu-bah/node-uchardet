{
  'targets': [
    {
      'target_name': '<(product_name)',
      'product_prefix': 'lib',
      'defines': [
        'PACKAGE_NAME="<(product_name)"',
        'PACKAGE_URL="<(url)"',
        'PACKAGE_BUGREPORT="<(bugreport)"',
        'UCHARDET_VERSION="<(version_major).<(version_minor).<(version_revision)"',
        'VERSION="$(UCHARDET_VERSION)"',
      ],
      'include_dirs': [
        'uchardet/src',
      ],
      'sources': [
        'uchardet/src/CharDistribution.cpp',
        'uchardet/src/JpCntx.cpp',
        'uchardet/src/LangModels/LangArabicModel.cpp',
        'uchardet/src/LangModels/LangBulgarianModel.cpp',
        'uchardet/src/LangModels/LangCroatianModel.cpp',
        'uchardet/src/LangModels/LangCzechModel.cpp',
        'uchardet/src/LangModels/LangEsperantoModel.cpp',
        'uchardet/src/LangModels/LangEstonianModel.cpp',
        'uchardet/src/LangModels/LangFinnishModel.cpp',
        'uchardet/src/LangModels/LangFrenchModel.cpp',
        'uchardet/src/LangModels/LangDanishModel.cpp',
        'uchardet/src/LangModels/LangGermanModel.cpp',
        'uchardet/src/LangModels/LangGreekModel.cpp',
        'uchardet/src/LangModels/LangHungarianModel.cpp',
        'uchardet/src/LangModels/LangHebrewModel.cpp',
        'uchardet/src/LangModels/LangIrishModel.cpp',
        'uchardet/src/LangModels/LangItalianModel.cpp',
        'uchardet/src/LangModels/LangLithuanianModel.cpp',
        'uchardet/src/LangModels/LangLatvianModel.cpp',
        'uchardet/src/LangModels/LangMalteseModel.cpp',
        'uchardet/src/LangModels/LangPolishModel.cpp',
        'uchardet/src/LangModels/LangPortugueseModel.cpp',
        'uchardet/src/LangModels/LangRomanianModel.cpp',
        'uchardet/src/LangModels/LangRussianModel.cpp',
        'uchardet/src/LangModels/LangSlovakModel.cpp',
        'uchardet/src/LangModels/LangSloveneModel.cpp',
        'uchardet/src/LangModels/LangSwedishModel.cpp',
        'uchardet/src/LangModels/LangSpanishModel.cpp',
        'uchardet/src/LangModels/LangThaiModel.cpp',
        'uchardet/src/LangModels/LangTurkishModel.cpp',
        'uchardet/src/LangModels/LangVietnameseModel.cpp',
        'uchardet/src/nsHebrewProber.cpp',
        'uchardet/src/nsCharSetProber.cpp',
        'uchardet/src/nsBig5Prober.cpp',
        'uchardet/src/nsEUCJPProber.cpp',
        'uchardet/src/nsEUCKRProber.cpp',
        'uchardet/src/nsEUCTWProber.cpp',
        'uchardet/src/nsEscCharsetProber.cpp',
        'uchardet/src/nsEscSM.cpp',
        'uchardet/src/nsGB2312Prober.cpp',
        'uchardet/src/nsMBCSGroupProber.cpp',
        'uchardet/src/nsMBCSSM.cpp',
        'uchardet/src/nsSBCSGroupProber.cpp',
        'uchardet/src/nsSBCharSetProber.cpp',
        'uchardet/src/nsSJISProber.cpp',
        'uchardet/src/nsUTF8Prober.cpp',
        'uchardet/src/nsLatin1Prober.cpp',
        'uchardet/src/nsUniversalDetector.cpp',
        'uchardet/src/uchardet.cpp',
      ],
      'link_settings': {
        'conditions': [
          ['OS=="linux" or OS=="android"', {
            'libraries': [
              '-lstdc++',
            ],
            'library_dirs': [
              '<(module_root_dir)/build/$(BUILD_TYPE)',
            ],
            'ldflags': [
              '-Wl,-R<(module_root_dir)/build/$(BUILDTYPE)',
              '-Wl,-rpath=$$ORIGIN/lib.target/',
              '-Wl,-rpath-link=$(builddir)/lib.target/',
              '-Wl,-soname,<(product_name).so',
              '-L<(module_root_dir)/build/$(BUILDTYPE)',
              '-L$(pwd)',
              #'-Wl,--version-script=<(module_root_dir)/deps/version.script',
            ],
          }],
        ],
        'xcode_settings': {
          'OTHER_LDFLAGS': [
            '-L>(PRODUCT_DIR)'
          ]
        },
        'msvs_settings': {
          'VCLinkerTool': {
            'AdditionalLibraryDirectories': [
              '-L>(PRODUCT_DIR)'
            ]
          }
        },
      },
      'conditions': [
        ['OS=="mac"', {
          'type': 'static_library',
          'cflags': [
            '-Wl,-exported_symbols_list <!(pwd)/symbols.list',
          ],
        }],
        ['OS=="linux" or OS=="android"', {
          'type': 'shared_library',
        }],
      ]
    }
  ]
}
