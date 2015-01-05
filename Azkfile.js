/**
 * Documentation: http://docs.azk.io/Azkfile.js
 */

// Adds the systems that shape your system
systems({
  azkfs: {
    // Dependent systems
    depends: [],
    // More images:  http://images.azk.io
    image: "boot2docker/boot2docker",
    workdir: "/azk/#{manifest.dir}",
    shell: "/bin/bash",
    mounts: {
      '/azk/#{manifest.dir}': path("."),
    },
    docker_extra: {
      // extra docker options
      start: {
        Privileged: "true",
      },
    },
  },
});

