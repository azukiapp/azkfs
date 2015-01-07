/**
 * Documentation: http://docs.azk.io/Azkfile.js
 */

// Adds the systems that shape your system
systems({

  // Build and load azkfs
  azkfs: {
    // Dependent systems
    depends: [],
    // More images:  http://images.azk.io
    image: "boot2docker/boot2docker",
    workdir: "/azk/#{manifest.dir}",
    shell: "/bin/bash",
    mounts: {
      '/azk/#{manifest.dir}': path("."),
      '/root/.tmux.conf': path("tmux.conf"),
    },
    docker_extra: {
      // extra docker options
      start: {
        Privileged: "true",
      },
    },
  },

  // Test event io
  iotest: {
    image: "node",
    workdir: "/azk/#{manifest.dir}",
    shell: "/bin/bash",
    mounts: {
      '/azk/#{manifest.dir}': path("."),
      '/azk/#{manifest.dir}/node_modules': persistent("node_modules"),
      '/root/.tmux.conf': path("tmux.conf"),
    },
    docker_extra: {
      // extra docker options
      start: {
        Privileged: "true",
      },
    },
  },

});

