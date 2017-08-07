ALLPIX_ENABLE_DEFAULT(OFF)

# Define module and return the generated name as MODULE_NAME
ALLPIX_UNIQUE_MODULE(MODULE_NAME)

# LCIO library is required for LCIO file writing, obviously
FIND_PACKAGE(LCIO REQUIRED)

INCLUDE_DIRECTORIES(SYSTEM ${LCIO_INCLUDE_DIRS} )
TARGET_LINK_LIBRARIES( ${MODULE_NAME} ${LCIO_LIBRARIES} )

# Add source files to library
ALLPIX_MODULE_SOURCES(${MODULE_NAME} 
	LCIOWriterModule.cpp
)

# Provide standard install target
ALLPIX_MODULE_INSTALL(${MODULE_NAME})
