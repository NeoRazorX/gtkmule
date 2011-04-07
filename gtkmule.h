/*
    This file is part of Gtkmule.
    
    Copyright (c) 2011  Carlos Garcia Gomez ( neorazorx@gmail.com )
    
    Gtkmule is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Gtkmule is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Gtkmule.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _GTKMULE_H_
#define _GTKMULE_H_

#include <gtkmm.h>
#include <libnotifymm/init.h>
#include <libnotifymm/notification.h>

extern "C" {
    #include <libappindicator/app-indicator.h>
}

#define GTKMULE_NAME "gtkmule"

using namespace std;

class Gtkmule
{
    public:
        Gtkmule();
        ~Gtkmule();
        void change_topwin_visibility();
        bool hide_topwin(GdkEventAny *);
        void show_addlink();
        void show_search();
        void show_preferences();
        void show_about();
        void add_link();
        void quit();
        
        Gtk::Window * pTopwin;
    
    private:
        Gtk::Window * pAddlinkwin;
        Gtk::Window * pSearchwin;
        Gtk::Window * pPrefswin;
        AppIndicator * indicator;
        Gtk::AboutDialog * pAboutdialog;
        Gtk::CheckMenuItem * chmi_visible;
};

#endif

