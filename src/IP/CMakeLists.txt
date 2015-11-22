add_library(openp2p-ip STATIC Address.cpp V4Address.cpp V6Address.cpp)
install(TARGETS openp2p-ip DESTINATION lib/openp2p)
