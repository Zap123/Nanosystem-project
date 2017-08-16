/**
    State class definition, uses the State design pattern

    @author Luca Costa
    @version 1
*/

#include "state.h"

State::State(QObject *parent, const char *name) : QObject(parent)
{
    this->setObjectName(name);
}

