#ifndef COLORCOMBOBOX_H
#define COLORCOMBOBOX_H

/**
 * 颜色下拉框控件 作者:feiyangqingyun(QQ:517216493) 2016-12-28
 * 1. 支持内置所有颜色下拉选择。
 * 2. 可设置是否显示对应颜色的名称。
 * 3. 可指定当前颜色为哪个颜色。
 * 4. 发出颜色改变信号通知。
 */

#include <QComboBox>

#ifdef quc
class Q_DECL_EXPORT ColorComboBox : public QComboBox
#else
class ColorComboBox : public QComboBox
#endif

{
    Q_OBJECT

    Q_PROPERTY(bool showColorName READ getShowColorName WRITE setShowColorName)

public:
    explicit ColorComboBox(QWidget *parent = 0);

private:
    bool showColorName;     //是否显示颜色名称
    QString colorName;      //当前颜色

private slots:
    void currentIndexChanged(int index);

public:
    //获取和设置是否显示颜色名称
    bool getShowColorName() const;
    void setShowColorName(bool showColorName);

    //获取和设置当前颜色名称
    QString getColorName() const;
    void setColorName(const QString &colorName);

    //初始化下拉框节点集合
    void initItems();

Q_SIGNALS:
    //颜色改变信号
    void colorChanged(const QString &colorName);
    void colorChanged(const QColor &color);
};

#endif // COLORCOMBOBOX_H
