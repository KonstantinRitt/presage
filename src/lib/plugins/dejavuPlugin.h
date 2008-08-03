
/******************************************************
 *  Presage, an extensible predictive text entry system
 *  ---------------------------------------------------
 *
 *  Copyright (C) 2008  Matteo Vescovi <matteo.vescovi@yahoo.co.uk>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
                                                                             *
                                                                **********(*)*/

#ifndef PRESAGE_DEJAVUPLUGIN
#define PRESAGE_DEJAVUPLUGIN

#include "plugins/plugin.h"

#include <list>
#include <string>
#include <fstream>

/** Dejavu plugin is provided here to show how to implement real plugins.
 *
 */
class DejavuPlugin : public Plugin {
public:
    DejavuPlugin(Configuration*, ContextTracker*);
    ~DejavuPlugin();

    virtual Prediction predict(const size_t) const;

    virtual void learn();
    virtual void extract();
    virtual void train();

private:
    bool init_memory_trigger(std::list<std::string>&) const;
    bool match(const std::list<std::string>&, const std::list<std::string>&) const;
    bool init_rolling_window(std::list<std::string>&, std::ifstream&) const;
    void update_rolling_window(std::list<std::string>&, const std::string&) const;

    static const Variable LOGGER;
    static const Variable MEMORY;
    static const Variable TRIGGER;

    std::string memory;
    int trigger;
	
};

#endif // SOOTH_DEJAVUPLUGIN