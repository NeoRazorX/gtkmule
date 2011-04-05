#include "gtkmule.h"

Gtkmule::Gtkmule()
{
    Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
    refBuilder->add_from_file("gtkmule.glade");
    refBuilder->get_widget("topwindow", pTopwin);
    if( pTopwin )
    {
        Glib::RefPtr<Gdk::Pixbuf> mule_icon = Gdk::Pixbuf::create_from_file("mule_TrayIcon.ico.xpm");
        pTopwin->set_icon( mule_icon );
        
        refBuilder->get_widget("addlink_window", pAddlinkwin);
        refBuilder->get_widget("search_window", pSearchwin);
        refBuilder->get_widget("preferences_window", pPrefswin);
        refBuilder->get_widget("about_dialog", pAboutdialog);
        
        Gtk::ToolButton * tb_add_link;
        refBuilder->get_widget("tb_add_link", tb_add_link);
        tb_add_link->signal_clicked().connect( sigc::mem_fun(*this, &Gtkmule::show_addlink) );
        
        Gtk::ToolButton * tb_search;
        refBuilder->get_widget("tb_search", tb_search);
        tb_search->signal_clicked().connect( sigc::mem_fun(*this, &Gtkmule::show_search) );
        
        Gtk::ToolButton * tb_preferences;
        refBuilder->get_widget("tb_preferences", tb_preferences);
        tb_preferences->signal_clicked().connect( sigc::mem_fun(*this, &Gtkmule::show_preferences) );
        
        /// Init libnotify library
        const char name[] = "gtkmule";
        Notify::init(name);
        
        /// appindicator
        Gtk::Menu * popup;
        refBuilder->get_widget("status_menu", popup);
        if( popup )
        {
            /// mule_icon must be installd with:
            /// sudo xdg-icon-resource install --theme hicolor --novendor --size 16 mule_TrayIcon.ico.xpm mule_icon
            indicator = app_indicator_new (name, "mule_icon", APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
            app_indicator_set_status (indicator, APP_INDICATOR_STATUS_ACTIVE);
            app_indicator_set_attention_icon (indicator, "indicator-messages-new");
            app_indicator_set_menu (indicator, popup->gobj());
        }
    }
}

Gtkmule::~Gtkmule()
{
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
}

void
Gtkmule::add_link()
{
    const char name[] = "gtkmule";
    const char body[] = "Link added!";
    Glib::RefPtr<Gdk::Pixbuf> mule_icon = Gdk::Pixbuf::create_from_file("amule.png");
    Notify::Notification notification(name, body);
    notification.set_icon_from_pixbuf( mule_icon );
    notification.show();
}

