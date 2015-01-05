FROM boot2docker/boot2docker

RUN apt-get update \
  && apt-get install -yq vim \
  && apt-get clean -qq \
  && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
