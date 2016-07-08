#pragma once

#include <vector>
#include <memory>

#include "GraphicsCommand.h"

class UndoRedoStack
{
public:
    void Register(std::unique_ptr<GraphicsCommand> command);
    void ReDo();
    void UnDo();

private:
    std::vector<std::unique_ptr<GraphicsCommand>> m_commands;
    int m_current_item = -1;
};