#pragma once
#include "common.h"

class SSView
  : public QQuickItem
{
    Q_OBJECT
public:
    SSView();
    // TODO: custom transform node
    // TODO: custom textureProvider node that preserves RGBAF texture data, avoiding 24-bit RGB888
    // quantization step

signals:

public slots:
};