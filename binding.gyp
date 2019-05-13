{
  "targets": [
    {
      "target_name": "robot",
      "sources": ["src/robot.cc", "src_logic/Logic.cpp"  ],
      'include_dirs': [
          "src_logic",
          "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'dependencies': [
          "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}