#pragma once

#include "GraphicsState.h"
#include "GraphicsCommand.h"

#include <memory>
#include <stack>

#include <QGraphicsScene>

class GraphicsScene: public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene(QObject* parent = 0);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* mouse_event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouse_event) override;

private:
    std::unique_ptr<GraphicState> m_state;

    std::stack<std::unique_ptr<GraphicsCommand>> m_commands;
};