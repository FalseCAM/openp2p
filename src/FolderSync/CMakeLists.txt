add_library(openp2p-foldersync STATIC
	Block.cpp
	BlockCache.cpp
	BlockCacheMap.cpp
	BlockId.cpp
	BlockPath.cpp
	Directory.cpp
	FileDatabase.cpp
	Journal.cpp
	MemDatabase.cpp
	Node.cpp
	NodeBlockStore.cpp
	NodeReader.cpp
	NodeWriter.cpp
	)
install(TARGETS openp2p-foldersync DESTINATION lib/openp2p)
