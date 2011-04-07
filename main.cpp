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

#include <gtkmm.h>
#include "gtkmule.h"

extern "C" {
    #include <unique/unique.h>
}

int
main(int argc, char **argv)
{
    UniqueApp * app;
    Gtk::Main kit(argc, argv);
    app = unique_app_new("org.gtkmule.Gtkmule", NULL);
    
    if( unique_app_is_running(app) )
    {
        printf("app still running!\n");
    }
    else
    {
        Gtkmule mule;
        
        if( mule.pTopwin != NULL )
        {
            kit.run();
        }
    }
    
    return 0;
}

