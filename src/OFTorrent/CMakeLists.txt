add_library(openp2p-oftorrent STATIC BlockStream.cpp XORStream.cpp)
install(TARGETS openp2p-oftorrent DESTINATION lib/openp2p)
