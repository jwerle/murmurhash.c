murmur(1) -- Command line MurmurHash3 Utility
=============================================

## SYNOPSIS

`murmur` \[-hV\] \[options\]

## OPTIONS

  -V, --version
      output program version

  -h, --help
      output help information

  --seed=[seed]
      hash seed (optional)

## EXAMPLES

  ``
  $ echo -n kinkajou | murmur
  3067714808
  ``

  ``
  $ echo -n panda | murmur --seed=10
  1406483717
  ``

## AUTHOR

  - Joseph Werle <joseph.werle@gmail.com>

## REPORTING BUGS

  - <https://github.com/jwerle/murmurhash.c/issues>

## SEE ALSO

  - <https://github.com/jwerle/murmurhash.c>

## LICENSE

MIT
