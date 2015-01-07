'use strict';

module.exports = function(grunt) {
  grunt.initConfig({
    watch: {
      ls: {
        options: {
          atBegin: true,
        },
        files: [
          'Gruntfile.js',
          '**/*.c',
          '/iotest/**/*',
        ],
        tasks: ["exec:ls"],
      },
    },

    exec: {
      ls: {
        cmd: "ls -la --color=auto /iotest",
      },
    },
  });

  // load all grunt tasks matching the `grunt-*` pattern
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-exec');

  grunt.registerTask('default', ["watch:ls"]);
}
