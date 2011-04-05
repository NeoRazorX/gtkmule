#ifndef _GTKMULE_H_
#define _GTKMULE_H_

#include <gtkmm.h>
#include <libnotifymm/init.h>
#include <libnotifymm/notification.h>

extern "C" {
    #include <libappindicator/app-indicator.h>
}

using namespace std;

class Gtkmule
{
    public:
        Gtkmule();
        ~Gtkmule();
        void show_addlink();
        void show_search();
        void show_preferences();
        void show_about();
        void add_link();
        Gtk::Window * pTopwin;
    
    private:
        AppIndicator * indicator;
        Gtk::Window * pAddlinkwin;
        Gtk::Window * pSearchwin;
        Gtk::Window * pPrefswin;
        Gtk::AboutDialog * pAboutdialog;
};

#endif

