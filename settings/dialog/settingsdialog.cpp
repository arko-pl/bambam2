#include "settingsdialog.hpp"

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "igeneralsettings.hpp"
#include "widgets/generalsettingswidget.hpp"
#include "widgets/scalingpolicysettingswidget.hpp"
#include "widgets/dataproviderssettingswidget.hpp"

class SettingsDialogImpl {
public:
    SettingsDialogImpl() {}
    friend class SettingsDialog;
private:
    GeneralSettingsWidget* m_generalSettings;
    ScalingPolicySettingsWidget* m_scalingPolicySettings;
    DataProvidersSettingsWidget* m_dataProvidersSettings;
};

SettingsDialog::SettingsDialog(QDialog *parent) : QDialog(parent)
{
    pImpl = std::make_unique<SettingsDialogImpl>();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    QPushButton *buttonCancel = new QPushButton(QObject::tr("Cancel"));
    QPushButton *buttonApply = new QPushButton(QObject::tr("Apply"));

    QObject::connect(buttonCancel, &QPushButton::clicked,
                     this, &QDialog::reject);
    QObject::connect(buttonApply, &QPushButton::clicked,
                     this, &QDialog::accept);

    buttonLayout->addStretch();
    buttonLayout->addWidget(buttonCancel);
    buttonLayout->addWidget(buttonApply);

    pImpl->m_generalSettings = new GeneralSettingsWidget;
    pImpl->m_scalingPolicySettings = new ScalingPolicySettingsWidget;
    pImpl->m_dataProvidersSettings = new DataProvidersSettingsWidget;
    mainLayout->addWidget(pImpl->m_generalSettings);
    mainLayout->addWidget(pImpl->m_scalingPolicySettings);
    mainLayout->addWidget(pImpl->m_dataProvidersSettings);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}

const IScalingPolicySettings* SettingsDialog::getScalingPolicySettings() const
{
    return pImpl->m_scalingPolicySettings;
}

const IDataProviderSettings* SettingsDialog::getDataProviderSettings() const
{
    return pImpl->m_dataProvidersSettings;
}

const IGeneralSettings* SettingsDialog::getGeneralSettings() const
{
    return pImpl->m_generalSettings;
}

SettingsDialog::~SettingsDialog() = default;
