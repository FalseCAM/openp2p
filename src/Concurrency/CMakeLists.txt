add_library(openp2p-concurrency STATIC
	Signal.cpp
	Thread.cpp
	)
install(TARGETS openp2p-concurrency DESTINATION lib/openp2p)
