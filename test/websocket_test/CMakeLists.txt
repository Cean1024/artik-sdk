CMAKE_MINIMUM_REQUIRED	( VERSION 2.8 )
PROJECT		  	( websocket-test )

FIND_PACKAGE ( ArtikBase )
FIND_PACKAGE ( ArtikConnectivity )

SET ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-parameter" )

SET ( EXE_WEBSOCKET_CLOUD_TEST websocket-cloud-test )

SET ( SRC_TEST_WEBSOCKET_CLOUD	artik_websocket_cloud_test.c)

ADD_EXECUTABLE		( ${EXE_WEBSOCKET_CLOUD_TEST} ${SRC_TEST_WEBSOCKET_CLOUD} )

TARGET_INCLUDE_DIRECTORIES ( ${EXE_WEBSOCKET_CLOUD_TEST}
								PUBLIC ${ARTIK_BASE_INCLUDE_DIR}
			     				PUBLIC ${ARTIK_CONNECTIVITY_INCLUDE_DIR}
)

TARGET_LINK_LIBRARIES	( ${EXE_WEBSOCKET_CLOUD_TEST}
								${ARTIK_BASE_LIBRARIES}
)

INSTALL ( TARGETS ${EXE_WEBSOCKET_CLOUD_TEST} RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}/artik-sdk/tests" )

SET ( EXE_WEBSOCKET_TEST websocket-test )

SET ( SRC_TEST_WEBSOCKET artik_websocket_test.c)

ADD_EXECUTABLE		( ${EXE_WEBSOCKET_TEST} ${SRC_TEST_WEBSOCKET} )

TARGET_INCLUDE_DIRECTORIES ( ${EXE_WEBSOCKET_TEST}
								PUBLIC ${ARTIK_BASE_INCLUDE_DIR}
			     				PUBLIC ${ARTIK_CONNECTIVITY_INCLUDE_DIR}
)

TARGET_LINK_LIBRARIES	( ${EXE_WEBSOCKET_TEST}
								${ARTIK_BASE_LIBRARIES}
)

INSTALL ( TARGETS ${EXE_WEBSOCKET_TEST} RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}/artik-sdk/tests" )

SET ( EXE_WEBSOCKET_CLIENT_TEST websocket-client-test )

SET ( SRC_CLIENT_TEST_WEBSOCKET artik_websocket_client_test.c)

ADD_EXECUTABLE		( ${EXE_WEBSOCKET_CLIENT_TEST} ${SRC_CLIENT_TEST_WEBSOCKET} )

TARGET_INCLUDE_DIRECTORIES ( ${EXE_WEBSOCKET_CLIENT_TEST}
								PUBLIC ${ARTIK_BASE_INCLUDE_DIR}
			     				PUBLIC ${ARTIK_CONNECTIVITY_INCLUDE_DIR}
)

TARGET_LINK_LIBRARIES	( ${EXE_WEBSOCKET_CLIENT_TEST}
								${ARTIK_BASE_LIBRARIES}
)

INSTALL ( TARGETS ${EXE_WEBSOCKET_CLIENT_TEST} RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}/artik-sdk/tests" )
