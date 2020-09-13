/*
 * Copyright (C) 2020  Arkadiusz Bubała <arek2407066@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DATAPROVIDERFACTORY_HPP
#define DATAPROVIDERFACTORY_HPP

template<typename T>
class QList;
class QString;

namespace DataProvider {
enum class Provider {
    ConfigBased,
    Text,
    Unknown
};
}

class IDataProvider;

/**
 * @brief Data Provider Factory Class.
 *
 * Class responsible for creating IDataProvider instances.
 */
class DataProviderFactory
{
public:
    /**
     * @brief The constructor.
     *
     */
    explicit DataProviderFactory();
    /**
     * @brief The destructor.
     *
     */
    ~DataProviderFactory();
    // TODO: consider moving this outside this class and make makeProvider
    // public.
    /**
     * @brief Generate providers list enabled in configuration.
     *
     * @param providersList Providers list that will be filled.
     * @return QList<IDataProvider *> reference to @p providersList.
     */
    QList<IDataProvider*>& buildProvidersList(
            QList<IDataProvider*>& providersList) const;
private:
    DataProviderFactory(const DataProviderFactory&) = delete;
    DataProviderFactory& operator=(const DataProviderFactory&) = delete;
    /**
     * @brief Create data provider of @p type.
     *
     * @param type Type of data provider.
     * @return IDataProvider Pointer to created data provider.
     */
    IDataProvider* makeProvider(const DataProvider::Provider& type) const;
};

#endif // DATAPROVIDERFACTORY_HPP
