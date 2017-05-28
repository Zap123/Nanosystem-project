#include "state.h"

State::State(QObject *parent, const char *name) : QObject(parent)
{
    this->setObjectName(name);
}

