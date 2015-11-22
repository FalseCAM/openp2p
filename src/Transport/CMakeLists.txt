add_library(openp2p-transport STATIC
	BinaryStream.cpp
	Buffer.cpp
	BufferBuilder.cpp
	BufferedStream.cpp
	BufferIterator.cpp
	StringStream.cpp
	)
install(TARGETS openp2p-transport DESTINATION lib/openp2p)
