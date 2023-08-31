function(copy_shaders TARGET)
    message("Copying shaders to ${TARGET}")
    #file(GENERATE OUTPUT filename CONTENT "$<TARGET_FILE_DIR:${TARGET}>")
    # Gather list of all .spv files in the output directory of the renderer
    # file(GLOB shaderFiles $<TARGET_FILE_DIR:gfxlib_opengl_renderer>/shaders/*.spv)
    # TODO: Ideally we wouldnt need to specify this manually we'd use the glob above
    # but i cant get it work just yet XD
    set(shaderFiles quad.frag.spv quad.vert.spv)

    message("Found shaders: ${shaderFiles}")

    foreach(SHADER ${shaderFiles})
        message("Adding custom command for shader ${SHADER}")
        add_custom_command(TARGET ${TARGET} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E
                copy $<TARGET_FILE_DIR:gfxlib_opengl_renderer>/shaders/${SHADER} $<TARGET_FILE_DIR:${TARGET}>/shaders/${SHADER})
    endforeach()
endfunction(copy_shaders)

function(add_shader TARGET SHADER)
    if (${GLSLC_PATH} STREQUAL "")
        message(FATAL_ERROR "GLSLC_PATH is not set. This needs to be defined to compile shaders.")
    endif()

    # We will make this require VULKAN_PATH that is defined from including vulkan.cmake
    # Here we define the executables we require to build. Might need to add something like
    # `if (${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "AMD64")` to support 32bit but we can
    # do that later
    set(GLSLC ${GLSLC_PATH}/glslc.exe)

    # Check the file extension
    get_filename_component(SHADER_EXT ${SHADER} LAST_EXT)
    string(TOLOWER ${SHADER_EXT} SHADER_EXT_LOWER)
    set(ALLOWED_SHADER_EXTENSIONS
            ".vert" # vertex shader
            ".frag" # fragment shader
            ".geom" # geometry shader
            ".tesc" # tessellation control shader
            ".tese" # tessellation evaluation shader
            ".comp" # compute shader
    )
    if (NOT ("${SHADER_EXT_LOWER}" IN_LIST ALLOWED_SHADER_EXTENSIONS))
        message(FATAL_ERROR "Invalid shader extension for file ${SHADER}: ${SHADER_EXT}")
    endif()

    set(SHADER_OUTPUT_NAME ${SHADER})
#    # If the shader has a .glsl file extension then remove it
#    get_filename_component(SHADER_EXT ${SHADER} LAST_EXT)
#    string(TOLOWER ${SHADER_EXT} SHADER_EXT_LOWER)
#    if(SHADER_EXT_LOWER STREQUAL ".glsl")
#        message(DEBUG "Stripping glsl file extension")
#        get_filename_component(SHADER_OUTPUT_NAME ${SHADER} NAME_WLE)
#    endif()

    set(current_shader_path ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER})
    set(current_output_path ${CMAKE_CURRENT_BINARY_DIR}/${SHADER_OUTPUT_NAME}.spv)

    message("Compiling ${current_shader_path} -> ${current_output_path}")
    # Add a custom command to compile GLSL to SPIR-V.
    get_filename_component(current_output_dir ${current_output_path} DIRECTORY)
    file(MAKE_DIRECTORY ${current_output_dir})

    add_custom_command(
            OUTPUT ${current_output_path}
            COMMAND ${GLSLC} -o ${current_output_path} ${current_shader_path}
            DEPENDS ${current_shader_path}
            IMPLICIT_DEPENDS CXX ${current_shader_path}
            VERBATIM)

    # Make sure our build depends on this output.
    set_source_files_properties(${current_output_path} PROPERTIES GENERATED TRUE)
    target_sources(${TARGET} PRIVATE ${current_output_path})
endfunction(add_shader)