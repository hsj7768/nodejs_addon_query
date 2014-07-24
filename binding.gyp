{
    "targets": [
    {
        'target_name': 'QtQuery',
            'sources': [
                "AddonQtQuery.cc",
                "QtQuery.cc"
            ],

            'include_dirs': [
                '-I/usr/local/include/'
            ],

            'cflags!': ['-fno-exceptions'],

            'cflags_cc!': ['-fno-exceptions'],

            'conditions': [[

                'OS=="linux"', 
                {
                    'libraries': [
                        '<!@(pkg-config --libs-only-l QtCore QtXml)',
                        '-L/usr/local/lib',
                        '/usr/local/lib/libocilib.so.3',
                        '-locilib',
                    ]
                }
            ]]   
    }
    ]
}
