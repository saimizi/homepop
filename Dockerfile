FROM    joukan/rpi4-appimg:latest
LABEL   org.opencontainers.image.source=https://github.com/saimizi/homepop

USER    root

ADD     appsdk_build/qml_homepop_cpp /usr/bin/homepop

