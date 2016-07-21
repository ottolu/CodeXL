//==================================================================================
// Copyright (c) 2016 , Advanced Micro Devices, Inc.  All rights reserved.
//
/// \author AMD Developer Tools Team
/// \file gsPipelineMonitor.h
///
//==================================================================================
#ifndef __gsPipelineMonitor_h
#define __gsPipelineMonitor_h

#include <AMDTBaseTools/Include/gtVector.h>
#include <AMDTAPIClasses/Include/apGLPipeline.h>

class gsPipelineMonitor
{
public:
    gsPipelineMonitor();
    ~gsPipelineMonitor();

    void GenProgramPipelines(GLuint pipelinesCount, const GLuint* pPipelinesArr);

    void DeleteProgramPipelines(GLuint pipelinesCount, const GLuint* pPipelinesArr);

    // Binds the pipeline object named pipelineName as the current pipeline.
    // Returns false if no pipeline named pipelineName was found (which means
    // that the name has not been returned by GenProgramPipelines, or that it
    // has been deleted after it was generated).
    bool BindProgramPipeline(GLuint pipelineName);

    GLuint GetCurrentlyBoundPipeline() const;

    // Sets program to be the active shader program for pipeline.
    // Returns false if pipeline is not a name previously returned by
    // GenProgramPipelines, or if pipeline has been deleted after being
    // generated).
    bool ActiveShaderProgram(GLuint pipeline, GLuint program);

    // Sets program as the current program for the shader stages specified by stages,
    // for pipeline.
    bool UseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);

    size_t GetAmountOfPipelineObjects() const;

    // Returns a pointer to the pipeline object:
    const apGLPipeline* GetPipelineDetails(GLuint pipelineName) const;

    // Returns the name of the program pipeline which is stored at index pipelineIndex.
    // False is returned if on program pipeline is stored at that index, otherwise true is returned.
    bool GetPipelineNameByIndex(size_t pipelineIndex, GLuint& pipelineNameBuffer) const;

private:

    // Returns true if pipeline exists. Otherwise returns false.
    // To "exist" pipeline needs to have been generated by GenProgramPipelines()
    // and not to be deleted by DeleteProgramPipelines().
    bool isPipelineExists(GLuint pipelineName) const;

    gtVector<apGLPipeline*> m_glPipelines;

    // This member holds the currently bound pipeline.
    // If it is set to zero, it means that currently no pipeline is bound.
    GLuint mCurrentlyBoundPipelineName;
};

#endif // __gsPipelineMonitor_h
