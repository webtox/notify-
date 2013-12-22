/***
Copyright (C) 2013 Aniket Deole <aniket.deole@gmail.com>
This program is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License version 2.1, as published
by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranties of
MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program.  If not, see <http://www.gnu.org/licenses/>.
***/

#include <gtkmm/box.h>
#include <gtkmm/widget.h>

#include "maintoolbar.hh"


MainToolbar::MainToolbar () {

 //Create the toolbar and add it to a container widget:
  Gtk::ToolButton* button = Gtk::manage(new Gtk::ToolButton());
  button->set_size_request (40, 40);
  // TODO Change this later to set_icon_widget
  button->set_icon_name("dialog-cancel");
  button->signal_clicked().connect(sigc::mem_fun(*this,
              &MainToolbar::exitNotify) );
  add(*button);

  button = Gtk::manage(new Gtk::ToolButton());
  button->set_size_request (40, 40);
  button->set_icon_name("document-new");
  button->signal_clicked().connect(sigc::mem_fun(*this,
              &MainToolbar::newNote) );
  add(*button);

  button = Gtk::manage(new Gtk::ToolButton());
  button->set_size_request (40, 40);
  button->set_icon_name("address-book-new");
  button->signal_clicked().connect(sigc::mem_fun(*this,
              &MainToolbar::newNotebook) );
    add(*button);

  show_all ();
}

MainToolbar::~MainToolbar () {

}

void MainToolbar::exitNotify () {
  exit (0);
}

void MainToolbar::newNote () {
  app->nlpv->newNote ();
  app->npv->newNote ();
}

void MainToolbar::newNotebook () {
  app->lpv->newNotebook ();
}