/*
* Copyright (C) 2020, KylinSoft Co., Ltd.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
*
*/

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QStyledItemDelegate>
#include <QListView>
#include <QFileDialog>
#include <QCoreApplication>
#include <QFont>
#include <QPixmap>
#include <QLineEdit>
#include <QFile>
#include <QHash>
#include "customcombobox.h"
#include "sendmail.h"
#include "scanner.h"
#include "theme.h"

class KYCScanSettingsWidget  : public QWidget
{
    Q_OBJECT

public:
    explicit KYCScanSettingsWidget(QWidget *parent = nullptr);
    ~KYCScanSettingsWidget();

    void initWindow();
    void initLayout();
    void initStyle();
    void initSettings();
    void initConnect();

    void setKylinComboBox(bool curIndexChanged);
    void setKylinComboBoxScanDeviceName();
    void setkylinScanStatus(bool status);
    void setKylinScanSetNotEnable();
    void setKylinScanSetBtnNotEnable();
    void setKylinScanSetBtnEnable();
    void setKylinScanSetEnable();
    void setKylinComboBoxAttributes(KYCComboBox *combo, QStringList strList);
    void setKylinComboBoxTextDeviceAttributes(KYCComboBox *combo, QStringList strList);
    void setKylinLable();
    void setKylinLabelAttributes(QLabel *label);
    void setKylinHBoxLayout();
    void setKylinHBoxLayoutAttributes(QHBoxLayout *layout, QLabel *labelFirst, QLabel *labelSecond);
    void setKylinHBoxLayoutAttributes(QHBoxLayout *layout, QLabel *labelFirst, KYCComboBox *combo);
    void setFontSize(QLabel *label, int n);
    void setTextNameToolTip();
    void setBtnSaveText();
    void setOcrFlagInit();
    void setFlagTextDeviceChangedWork();
    void warnMsg(QString msg);
    void modifyBtnSave();

    QString getTextResolution();
    QString getTextSize();
    QString getTextFormat();
    QString getTextName();
    QString getTextLocation();

private:
    int flag = 0; // ????????????????????????????????????????????????????????????
    int flagTextDeviceChangedWork = 0; // textDeviceChanged will not work before openSaneDevice() successfully
    int scanOpenFlag = 0;
    int scanExecFlag = 0;

    QStringList stylelist;
    QStringList iconthemelist;
    QGSettings *style_settings;
    QGSettings *icon_theme_settings;
    QLabel *labDevice;              /**< ???????????? */
    QLabel *labType;                /**< ???????????? */
    QLabel *labColor;               /**< ???????????? */
    QLabel *labResolution;          /**< ??????????????? */
    QLabel *labSize;                /**< ???????????? */
    QLabel *labFormat;              /**< ???????????? */
    QLabel *labName;                /**< ???????????? */
    QLabel *labLocation;            /**< ??????????????? */

    QFrame *line3;
    QFrame *line4;

    QPushButton *btnMail;           /**< ??????????????? */
    QPushButton *btnSave;           /**< ????????? */
    QPushButton *btnLocation;       /**< ????????? */
    QString curPath;

    KYCComboBox *textDevice;      /**< ?????? */
    QLabel *textType;               /**< ?????? */
    KYCComboBox *textColor;       /**< ?????? */
    KYCComboBox *textResolution;  /**< ????????? */
    KYCComboBox *textSize;        /**< ?????? */
    KYCComboBox *textFormat;      /**< ?????? */
    QLineEdit *textName;            /**< ?????? */

    QHBoxLayout *hBoxDevice;
    QHBoxLayout *hBoxType;
    QHBoxLayout *hBoxColor;
    QHBoxLayout *hBoxResolution;
    QHBoxLayout *hBoxSize;
    QHBoxLayout *hBoxFormat;
    QHBoxLayout *hBoxName;
    QHBoxLayout *hBoxLocation;
    QHBoxLayout *hBoxLine3;
    QHBoxLayout *hBoxLine4;
    QHBoxLayout *hBoxMailText;
    QHBoxLayout *hBoxScanSet;
    QVBoxLayout *vBoxScanSet;
    QVBoxLayout *vBoxScanSet1;

Q_SIGNALS:
    void saveImageSignal(QString);
    void openDeviceStatusSignal(bool);
    void sendMailSignal();

private slots:
    void onBtnLocationClicked();
    void onBtnMailClicked();
    void onBtnSaveClicked();
    void onTextDeviceCurrentTextChanged(QString device);
    void onTextColorCurrentTextChanged(QString color);
    void onTextResolutionCurrentTextChanged(QString resolution);
    void onTextSizeCurrentTextChanged(QString size);
    void onTextNameTextChanged(QString);
    void scanset_style_changed(QString); // ????????????????????????
};

#endif // SETTINGS_H
