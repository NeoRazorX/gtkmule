#include <gtkmm.h>
#include "gtkmule.h"

int
main(int argc, char **argv)
{
    Gtk::Main kit(argc, argv);
    Gtkmule mule;
    
    if( mule.pTopwin != NULL )
    {
        kit.run( *mule.pTopwin );
    }
    
    return 0;
}

