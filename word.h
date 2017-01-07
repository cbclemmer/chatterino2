#ifndef WORD_H
#define WORD_H

#include "lazyloadedimage.h"
#include "fonts.h"
#include "link.h"

#include <QRect>
#include <QString>

class Word
{
public:
    enum Type : long int {
        None = 0,
        Misc = 1,
        Text = 2,

        TimestampNoSeconds   = 4,
        TimestampWithSeconds = 8,

        TwitchEmoteImage = 0x10,
        TwitchEmoteText = 0x20,
        BttvEmoteImage = 0x40,
        BttvEmoteText = 0x80,
        BttvGifEmoteImage = 0x100,
        BttvGifEmoteText = 0x200,
        FfzEmoteImage = 0x400,
        FfzEmoteText = 0x800,

        Bits = 0x1000,
        BitsAnimated = 0x2000,

        BadgeStaff = 0x4000,
        BadgeAdmin = 0x8000,
        BadgeGlobalMod = 0x10000,
        BadgeModerator = 0x20000,
        BadgeTurbo = 0x40000,
        BadgeBroadcaster = 0x80000,
        BadgePremium = 0x100000,
        BadgeChatterino = 0x200000,
        BadgeCheer = 0x400000,
        Badges = BadgeStaff
            | BadgeAdmin
            | BadgeGlobalMod
            | BadgeModerator
            | BadgeTurbo
            | BadgeBroadcaster
            | BadgePremium
            | BadgeChatterino
            | BadgeCheer,

        Username = 0x800000,
        BitsAmount = 0x1000000,

        Default = TimestampNoSeconds | Badges | Username | Bits | FfzEmoteImage | BttvEmoteImage | BttvGifEmoteImage | TwitchEmoteImage | BitsAmount
    };

    explicit Word(LazyLoadedImage* m_image, Type type, const QString& copytext, const QString& tooltip, const Link& link = Link());
    explicit Word(const QString& m_text, Type type, const QColor& color, const QString& copytext, const QString& tooltip, const Link& link = Link());

    LazyLoadedImage& getImage() const {
        return *m_image;
    }

    const QString& getText() const {
        return m_text;
    }

    int width() const {
        return m_width;
    }

    int height() const {
        return m_height;
    }

    int x() const {
        return m_x;
    }

    int y() const {
        return m_y;
    }

    int right() const {
        return m_x + m_width;
    }

    int bottom() const {
        return m_y + m_height;
    }

    QRect rect() const {
        return QRect(m_x, m_y, m_width, m_height);
    }

    bool isImage() const {
        return m_isImage;
    }

    const QString& copyText() const {
        return m_copyText;
    }

    bool hasTrailingSpace() const {
        return m_hasTrailingSpace;
    }

    QFont& getFont() const {
        return Fonts::getFont(m_font);
    }

    Type type() const {
        return m_type;
    }

    const QString& tooltip() const {
        return m_tooltip;
    }

    const QColor& color() const {
        return m_color;
    }

    const Link& link() const {
        return m_link;
    }

private:
    LazyLoadedImage* m_image;
    QString m_text;
    QColor m_color;
    bool m_isImage;

    Type m_type;
    QString m_copyText;
    QString m_tooltip;
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    bool m_hasTrailingSpace;
    Fonts::Type m_font = Fonts::Medium;
    Link m_link;
};

#endif // WORD_H
