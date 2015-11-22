add_library(openp2p-event STATIC
	Generator.cpp
	IOService.cpp
	MultiGenerator.cpp
	Signal.cpp
	Source.cpp
	Timer.cpp
	UnionGenerator.cpp
	Wait.cpp
	)

install(TARGETS openp2p-event DESTINATION lib/openp2p)
