add_library(openp2p-tcp STATIC Acceptor.cpp Resolver.cpp Stream.cpp)
install(TARGETS openp2p-tcp DESTINATION lib/openp2p)
