add_library(openp2p-util STATIC
	String.cpp
	Timer.cpp
	)
install(TARGETS openp2p-util DESTINATION lib/openp2p)
