INCLUDE(ExternalProject)

SET(KAGUYA_SOURCES_DIR ${THIRD_PARTY_PATH}/source/kaguya)
SET(KAGUYA_INSTALL_DIR ${THIRD_PARTY_PATH}/kaguya/include)

SET(BINARY_DIR ${KAGUYA_SOURCES_DIR}/src/extern_kaguya)
ExternalProject_Add(
    extern_kaguya
    GIT_REPOSITORY  "https://github.com/satoren/kaguya.git"
    GIT_TAG         "v1.3.2"
    PREFIX          ${KAGUYA_SOURCES_DIR}
    UPDATE_COMMAND  ""
    BINARY_DIR ${BINARY_DIR}
    CONFIGURE_COMMAND ""
    #CONFIGURE_COMMAND pwd && ./configure --prefix=${LUA_INSTALL_DIR}
    BUILD_COMMAND ""
    INSTALL_COMMAND mkdir -p ${KAGUYA_INSTALL_DIR} && cp -r ${BINARY_DIR}/include/kaguya ${KAGUYA_INSTALL_DIR}
)

ADD_LIBRARY(kaguya STATIC IMPORTED GLOBAL)
#SET_PROPERTY(TARGET kaguya PROPERTY IMPORTED_LOCATION ${LUA_LIBRARIES})
ADD_DEPENDENCIES(kaguya extern_kaguya)

LIST(APPEND external_project_dependencies kaguya)
