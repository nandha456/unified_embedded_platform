#pragma once

#include <string>

class ProjectGenerator
{
public:
    // Main public interface
    bool createProject(const std::string& name);

private:
    // Helper methods for separation of concerns
    void createDirectoryStructure(const std::string& projectPath);
    
    void generateReadme(const std::string& projectPath, const std::string& name);
    void generateToml(const std::string& projectPath, const std::string& name);
    void generateMainC(const std::string& projectPath);
    void generateCMakeLists(const std::string& projectPath);
};