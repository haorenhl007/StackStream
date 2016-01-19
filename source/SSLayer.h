#pragma once
#include "common.h"
#include "SSImage.h"
#include "SSQuickFramebufferObject.h"

class SSLayer
  : public SSQuickFramebufferObject
{
    Q_OBJECT
    Q_PROPERTY(bool isValid READ isValid NOTIFY isValidChanged)
    Q_PROPERTY(SSImage* image READ image WRITE setImage)
    Q_PROPERTY(std::size_t imageSerial READ imageSerial NOTIFY imageSerialChanged)
    Q_PROPERTY(float min READ min WRITE setMin RESET resetMin NOTIFY minChanged)
    Q_PROPERTY(float max READ max WRITE setMax RESET resetMax NOTIFY maxChanged)
    Q_PROPERTY(float gamma READ gamma WRITE setGamma RESET resetGamma NOTIFY gammaChanged)
    Q_PROPERTY(QColor tint READ tint WRITE setTint RESET resetTint NOTIFY tintChanged)
public:
    explicit SSLayer(QQuickItem* parent=nullptr);
    explicit SSLayer(const SSLayer& rhs, QQuickItem* parent=nullptr);
    virtual ~SSLayer();
    SSLayer& operator = (const SSLayer& rhs);
    bool operator == (const SSLayer& rhs) const;
    bool operator != (const SSLayer& rhs) const;

    Renderer* createRenderer() const override;

    bool isValid() const;

    SSImage* image();
    const SSImage* image() const;
    void setImage(SSImage* image);

    std::size_t imageSerial() const;

    float min() const;
    void setMin(float min);
    void resetMin();

    float max() const;
    void setMax(float max);
    void resetMax();

    float gamma() const;
    void setGamma(float gamma);
    void resetGamma();

    const QColor& tint() const;
    void setTint(const QColor& tint);
    void resetTint();

    QSGTextureProvider* textureProvider() const override;

signals:
    void isValidChanged(bool);
    void imageSerialChanged(std::size_t);
    void minChanged(float);
    void maxChanged(float);
    void gammaChanged(float);
    void tintChanged(QColor);

public slots:
    void aboutQt() const;

protected:
    SSImage* m_image;
    float m_min;
    float m_max;
    float m_gamma;
    QColor m_tint;
    std::forward_list<QMetaObject::Connection> m_imageSignalConnections;

    void onSerialChanged(std::size_t serial);
    void onImageSizeChanged(QSize size);
};
