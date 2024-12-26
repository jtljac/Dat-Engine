#include "../include/shader-processor.h"

#include <cstring>

/* -------------------------------------------- */
/* DatShaderIncluder                            */
/* -------------------------------------------- */

shaderc_include_result* AssetProcessor::Processors::DatShaderIncluder::makeError(const char* message) {
    return new shaderc_include_result {"", 0, message, strlen(message), nullptr};
}

AssetProcessor::Processors::DatShaderIncluder::DatShaderIncluder(const std::vector<std::filesystem::path>& includePaths
) : includePaths(includePaths) {}

shaderc_include_result* AssetProcessor::Processors::DatShaderIncluder::handleRelativeInclude(const std::filesystem::path& filePath) const {
    if (!exists(filePath)) {
        std::string message = "Failed to find requested relative file: ";
        message += filePath;
        return makeError(message.c_str());
    }

    return getIncludeResult(filePath);
}

shaderc_include_result* AssetProcessor::Processors::DatShaderIncluder::handleAbsoluteInclude(const std::filesystem::path& filePath) const {
    for (const auto& includePath: includePaths) {
        std::filesystem::path path(includePath);
        path /= filePath;

        if (!exists(filePath))
            continue;
        
        return getIncludeResult(path);
    }

    char buf[];
    int message = sprintf("Failed to find any files in the include paths that match the path: %s", filePath.c_str());
    return makeError(message);
}

shaderc_include_result* AssetProcessor::Processors::DatShaderIncluder::GetInclude(
        const char* requested_source,
        shaderc_include_type type,
        const char* requesting_source,
        size_t include_depth
) {
    if (type == shaderc_include_type_relative) {
        return handleRelativeInclude(std::filesystem::path(requesting_source).parent_path() / requested_source);
    }

    if (!this->includePaths.empty()){
        return handleAbsoluteInclude(std::filesystem::path(requested_source));
    }

    return makeError("Regular includes are disabled");
}


AssetProcessor::Processors::ShaderProcessor::ShaderProcessor(std::vector<std::filesystem::path> shaderPaths) {
    compileOptions.SetIncluder(std::make_unique<DatShaderIncluder>(shaderPaths));
}

/* -------------------------------------------- */
/* ShaderProcessor                              */
/* -------------------------------------------- */

std::vector<std::string> AssetProcessor::Processors::ShaderProcessor::getSupportedFormats() {
    return {"vert", "frag", "geom", "comp"};
}

std::vector<std::filesystem::path>
AssetProcessor::Processors::ShaderProcessor::processFile(std::filesystem::path filePath, std::filesystem::path dstDir) {

}
