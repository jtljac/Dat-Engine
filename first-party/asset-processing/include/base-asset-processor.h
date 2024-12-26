#pragma once

#include <filesystem>
#include <vector>

namespace AssetProcessor::Processors {
    /**
     * Interface for processing a file and converting it into an engine asset
     */
    class IBaseAssetProcessor {
    protected:
        ~IBaseAssetProcessor() = default;
    public:
        /**
         * Get the assets this Asset Processor can process
         *
         * @return The formats supported by this Asset Processor
         */
        virtual std::vector<std::string> getSupportedFormats();

        /**
         * Process the given file and write the result into the given output directory
         *
         * @param filePath The path to the file to process
         * @param dstDir The destination directory to write the processed asset result  to
         * @return A list of output files
         */
        virtual std::vector<std::filesystem::path> processFile(std::filesystem::path filePath, std::filesystem::path dstDir);
    };
}