from distutils.core import setup, Extension

hashBomb_module = Extension('hashBomb_hash',
    sources = [
        'hashBomb_module.c',
        'hashBomb.c',
        '0-sha2/sha2.c',
        '1-blake/blake.c',
        '2-groestl/groestl.c',
        '3-keccak/keccak.c'],
    include_dirs=[
        '.', 
        './0-sha2',
        './1-blake',
        './2-groestl',
        './3-keccak'])


setup (name = 'hashBomb_hashs',
    version = '1.0',
    description = 'Proof of concept',
    ext_modules = [hashBomb_module])