#pragma once

#include "base-asset-processor.h"

namespace AssetProcessor::Processors {
    class DatShaderIncluder : public shaderc::CompileOptions::IncluderInterface {
        std::vector<std::filesystem::path> includePaths;
        /**
         * Make an include result that contains an error message
         *
         * @param message The error message
         * @return a pointer to a shaderc include result containing an error
         */
        static shaderc_include_result* makeError(const char* message);

        /**
         * Handle a relative include
         *
         * @param filePath The absolute path to the file
         * @return a pointer to a shaderc include result containing an error or the include data
         */
        [[nodiscard]] shaderc_include_result* handleRelativeInclude(const std::filesystem::path& filePath) const;

        /**
         * Handle a standard include
         *
         * @param filePath The relative filepath to the file
         * @return a pointer to a shaderc include result containing an error or the include data
         */
        [[nodiscard]] shaderc_include_result* handleAbsoluteInclude(const std::filesystem::path& filePath) const;
    public:
        explicit DatShaderIncluder(const std::vector<std::filesystem::path>& includePaths);
        shaderc_include_result* GetInclude(
                const char* requested_source,
                shaderc_include_type type,
                const char* requesting_source,
                size_t include_depth
        ) override;
        void ReleaseInclude(shaderc_include_result* data) override;
        ~DatShaderIncluder() override;
    };

    /**
     * An implementation of IBaseAssetProcessor that compiles GLSL shaders using ShaderC
     * This processor can take a list of include directories to use when compiling shaders
     */
    class ShaderProcessor : public IBaseAssetProcessor {
        shaderc::Compiler compiler;
        shaderc::CompileOptions compileOptions;
    public:
        ShaderProcessor(std::vector<std::filesystem::path> shaderPaths);
        virtual ~ShaderProcessor() = default;

        std::vector<std::string> getSupportedFormats() override;
        std::vector<std::filesystem::path> processFile(std::filesystem::path filePath, std::filesystem::path dstDir) override;
    };
}