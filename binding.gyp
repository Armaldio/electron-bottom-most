{
  "targets": [
    {
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "target_name": "bottom-most",
      "sources": [ "lib.cc" ]
    }
  ]
}