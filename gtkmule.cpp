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

#include "gtkmule.h"

Gtkmule::Gtkmule()
{
    Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
    refBuilder->add_from_file("gtkmule.glade");
    refBuilder->get_widget("topwindow", pTopwin);
    if( pTopwin )
    {
        Glib::RefPtr<Gdk::Pixbuf> mule_icon = Gdk::Pixbuf::create_from_file("img/mule_TrayIcon.ico.xpm");
        pTopwin->set_icon( mule_icon );
        pTopwin->signal_delete_event().connect( sigc::mem_fun(*this, &Gtkmule::hide_topwin) );
        
        refBuilder->get_widget("addlink_window", pAddlinkwin);
        refBuilder->get_widget("search_window", pSearchwin);
        refBuilder->get_widget("preferences_window", pPrefswin);
        refBuilder->get_widget("about_dialog", pAboutdialog);
        
        Gtk::ToolButton * tb_add_link;
        refBuilder->get_widget("tb_add_link", tb_add_link);
        tb_add_link->signal_clicked().connect( sigc::mem_fun(*this, &Gtkmule::show_addlink) );
        
        Gtk::ImageMenuItem * imu_add_link;
        refBuilder->get_widget("imu_add_link", imu_add_link);
        imu_add_link->signal_activate().connect( sigc::mem_fun(*this, &Gtkmule::show_addlink) );
        
        Gtk::ToolButton * tb_search;
        refBuilder->get_widget("tb_search", tb_search);
        tb_search->signal_clicked().connect( sigc::mem_fun(*this, &Gtkmule::show_search) );
        
        Gtk::ImageMenuItem * imu_search;
        refBuilder->get_widget("imu_search", imu_search);
        imu_search->signal_activate().connect( sigc::mem_fun(*this, &Gtkmule::show_search) );
        
        Gtk::ToolButton * tb_preferences;
        refBuilder->get_widget("tb_preferences", tb_preferences);
        tb_preferences->signal_clicked().connect( sigc::mem_fun(*this, &Gtkmule::show_preferences) );
        
        Gtk::ImageMenuItem * imu_preferences;
        refBuilder->get_widget("imu_preferences", imu_preferences);
        imu_preferences->signal_activate().connect( sigc::mem_fun(*this, &Gtkmule::show_preferences) );
        
        Gtk::ImageMenuItem * imu_quit;
        refBuilder->get_widget("imu_quit", imu_quit);
        imu_quit->signal_activate().connect( sigc::mem_fun(*this, &Gtkmule::quit) );
        
        Gtk::ImageMenuItem * imu_quit2;
        refBuilder->get_widget("imu_quit2", imu_quit2);
        imu_quit2->signal_activate().connect( sigc::mem_fun(*this, &Gtkmule::quit) );
        
        Gtk::ImageMenuItem * imu_about;
        refBuilder->get_widget("imu_about", imu_about);
        imu_about->signal_activate().connect( sigc::mem_fun(*this, &Gtkmule::show_about) );
        
        refBuilder->get_widget("chmi_visible", chmi_visible);
        chmi_visible->signal_toggled().connect( sigc::mem_fun(*this, &Gtkmule::change_topwin_visibility) );
        
        Gtk::Button * button_addlink;
        refBuilder->get_widget("button_addlink", button_addlink);
        button_addlink->signal_clicked().connect( sigc::mem_fun(*this, &Gtkmule::add_link) );
        
        /// Init libnotify library
        Notify::init( GTKMULE_NAME );
        
        /// appindicator
        Gtk::Menu * popup;
        refBuilder->get_widget("status_menu", popup);
        if( popup )
        {
            /// mule_icon must be installd with:
            /// sudo xdg-icon-resource install --theme hicolor --novendor --size 16 img/mule_TrayIcon.ico.xpm mule_icon
            indicator = app_indicator_new (GTKMULE_NAME, "mule_icon", APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
            app_indicator_set_status (indicator, APP_INDICATOR_STATUS_ACTIVE);
            app_indicator_set_attention_icon (indicator, "indicator-messages-new");
            app_indicator_set_menu (indicator, popup->gobj());
        }
        
        pTopwin->show();
    }
}

Gtkmule::~Gtkmule()
{
}

void
Gtkmule::change_topwin_visibility()
{
    pTopwin->set_visible( chmi_visible->get_active() );
}

bool
Gtkmule::hide_topwin(GdkEventAny *)
{
    chmi_visible->set_active(false);
    
    /// still running notification
    const char body[] = "gtkmule still running!";
    Glib::RefPtr<Gdk::Pixbuf> mule_icon = Gdk::Pixbuf::create_from_file("img/amule.png");
    Notify::Notification notification(GTKMULE_NAME, body);
    notification.set_icon_from_pixbuf( mule_icon );
    notification.show();
    
    return true;
}

void
Gtkmule::show_addlink()
{
    if( pAddlinkwin )
    {
        pAddlinkwin->show();
    }
}

void
Gtkmule::show_search()
{
    if( pSearchwin )
    {
        pSearchwin->show();
    }
}

void
Gtkmule::show_preferences()
{
    if( pPrefswin )
    {
        pPrefswin->show();
    }
}

void
Gtkmule::show_about()
{
    if( pAboutdialog )
    {
        pAboutdialog->show();
    }
}

void
Gtkmule::add_link()
{
    const char body[] = "Link added!";
    Glib::RefPtr<Gdk::Pixbuf> mule_icon = Gdk::Pixbuf::create_from_file("img/amule.png");
    Notify::Notification notification(GTKMULE_NAME, body);
    notification.set_icon_from_pixbuf( mule_icon );
    notification.show();
}

void
Gtkmule::quit()
{
    Gtk::Main::quit();
}

