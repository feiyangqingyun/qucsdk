#ifndef XLINEEDIT_H
#define XLINEEDIT_H

/**
 * 多功能文本框 作者:feiyangqingyun(QQ:517216493) 2023-08-06
 * 1. 可设置双击明文显示。
 * 2. 可设置显示密文按钮。
 */

#include <QLineEdit>
class QPushButton;

#ifdef quc
class Q_DECL_EXPORT XLineEdit : public QLineEdit
#else
class XLineEdit : public QLineEdit
#endif

{
    Q_OBJECT

    Q_PROPERTY(bool doubleShowPwd READ getDoubleShowPwd WRITE setDoubleShowPwd)
    Q_PROPERTY(bool showPwdButton READ getShowPwdButton WRITE setShowPwdButton)

public:
    explicit XLineEdit(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    QFont iconFont;         //图形字体
    QPushButton *pwdButton; //密码按钮

    bool doubleShowPwd;     //是否双击明文
    bool showPwdButton;     //密码明文按钮

private slots:
    void clicked();

public Q_SLOTS:
    //设置双击明文显示
    bool getDoubleShowPwd() const;
    void setDoubleShowPwd(bool doubleShowPwd);

    //设置显示密码按钮
    bool getShowPwdButton() const;
    void setShowPwdButton(bool showPwdButton);
};

#endif // XLINEEDIT_H
