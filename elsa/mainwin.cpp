#include "mainwin.h"
#include "entrydialog.h"
#include <fstream>
#include <sstream>
#include <iomanip>

//add sprint4 sheet!
Mainwin::Mainwin(): store{nullptr}{
  // G U I   S E T U P

//filename = "untitled.elsa";

  set_default_size(900, 700);
  set_title("ELSA SUPER COMPUTER");
  //msg = Gtk::manage(new Gtk::Label());
  //data = Gtk::manage(new Gtk::Label());

  // Put a vertical box container as the Window contents
  Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
  add( *vbox);

//Gtk::GtkWidget *scrolled_window;

//Gtk::scrolled_window = gtk_scrolled_window_new (NULL, NULL);
    
//Gtk::container_set_border_width (GTK_CONTAINER (scrolled_window), 10);

//Gtk::scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),
//                                    GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);

//    Gtk::ScrolledWindow_Class (scrolled_window);

  // M E N U
  // Add a menu bar as the top item in the vertical box
  Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
  vbox -> pack_start( *menubar, Gtk::PACK_SHRINK, 0);

  //F I L E
  // Create a File menu and add to the menu bar
  Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
  menubar -> append( *menuitem_file);
  Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
  menuitem_file -> set_submenu(*filemenu);

  //Q U I T
  // Append Quit to the File menu
  Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
  menuitem_quit->signal_activate().connect([this] {
    this -> on_quit_click();
  });
  filemenu->append(*menuitem_quit);

 //N E W
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Store", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new);



//O P E N
  // Append OPEN to the File menu
  Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
  menuitem_open->signal_activate().connect([this] {this -> on_open_click();});
  filemenu->append(*menuitem_open);

//S A V E
  // Append SAVE to the File menu
  Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
  menuitem_save->signal_activate().connect([this] {this -> on_save_click();});
  filemenu->append(*menuitem_save);

//S A V E A S
  // Append Quit to the File menu
  Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save as", true));
  menuitem_save_as->signal_activate().connect([this] {this -> on_save_as_click();});
  filemenu->append(*menuitem_quit);

  //H E L P
  // Create a Help menu and add to the menu bar
  Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
  menubar->append(*menuitem_help);
  Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
  menuitem_help->set_submenu(*helpmenu);

  //A B O U T
  // Append About to the Help menu
  Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
  menuitem_about -> signal_activate().connect([this] {
    this -> on_about_click();
  });
  helpmenu->append(*menuitem_about);

  //V I E W
  // Create a view menu and add to the menu bar
  Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
  menubar->append(*menuitem_view);
  Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
  menuitem_view->set_submenu(*viewmenu);

  //C U S T O M E R
  // Append customer to the File menu
  Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
  menuitem_customer->signal_activate().connect([this] {
    this -> on_view_customer_click();
  });
  viewmenu-> append(*menuitem_customer);

  //P E R I P H E R A L
  // Append peripheral to the File menu
  Gtk::MenuItem * menuitem_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
  menuitem_peripheral->signal_activate().connect([this] {
    this->on_view_peripheral_click();
  });
  viewmenu->append( *menuitem_peripheral);

  //D E S K T O P
  Gtk::MenuItem *menuitem_desktop = Gtk::manage(new Gtk::MenuItem("Desktop", true));
  menuitem_desktop -> signal_activate().connect([this] {
    this -> on_view_desktop_click();
  });
  viewmenu -> append(*menuitem_desktop);
  //O R D E R
  Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
  menuitem_order -> signal_activate().connect([this] {
    this -> on_view_order_click();
  });
  viewmenu -> append( *menuitem_order);

  //I N S E R T
  // Create a insert menu and add to the menu bar
  Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
  menubar -> append(*menuitem_insert);
  Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
  menuitem_insert -> set_submenu(*insertmenu);

  //C U S T O M E R
  // Append customer to the File menu
  Gtk::MenuItem *menuitem__insert_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
  menuitem__insert_customer -> signal_activate().connect([this] {
    this -> on_insert_customer_click();
  });
  insertmenu -> append( *menuitem__insert_customer);

  //P E R I P H E R A L
  // Append peripheral to the File menu
  Gtk::MenuItem *menuitem_insert_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
  menuitem_insert_peripheral -> signal_activate().connect([this] {
    this -> on_insert_peripheral_click();
  });
  insertmenu -> append( *menuitem_insert_peripheral);

  //D E S K T O P
  Gtk::MenuItem * menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("Desktop", true));
  menuitem_insert_desktop -> signal_activate().connect([this] {
    this -> on_insert_desktop_click();
  });
  insertmenu -> append( *menuitem_insert_desktop);

  //O R D E R
  Gtk::MenuItem *menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
  menuitem_insert_order -> signal_activate().connect([this] {
    this -> on_insert_order_click();
  });
  insertmenu -> append( *menuitem_insert_order);


// T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);

//     Q U I T
    // Push the quit botton all the way to the right by setting set_expand true
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);
    toolbar->append(*sep);

    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit ELSA");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    toolbar->append(*quit_button);


   // Gtk::Image* customer_image = Gtk::manage(new Gtk::Image{"C.png"});
   // C = Gtk::manage(new Gtk::ToggleToolButton(*customer_image));
   // C->set_tooltip_markup("Enable for Insert Customer");
  //  C->signal_clicked().connect([this] {this->on_insert_customer_click();});
   // toolbar->append(*C);

//     N E W   S T O R E
    // Add a new STORE icon
    Gtk::ToolButton *new_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_store_button->set_tooltip_markup("Create a new store, discarding any in progress");
    new_store_button->signal_clicked().connect([this] {this->on_new_store_click();});
    toolbar->append(*new_store_button);

//     TOOLBAR OPEN
    // Add a new OPEN icon
    Gtk::ToolButton *new_open_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    new_open_button->set_tooltip_markup("Open a file");
    new_open_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*new_open_button);


//     TOOLBAR SAVE
    // Add a new OPEN icon
    Gtk::ToolButton *new_save_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::PRINT));
    new_save_button->set_tooltip_markup("Save a file");
    new_save_button->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*new_save_button);
  // D A T A   D I S P L A Y

  // Provide a text entry box to show the remaining sticks
  data = Gtk::manage(new Gtk::Label {
    "",
    Gtk::ALIGN_START,
    Gtk::ALIGN_START
  });
  data -> set_hexpand();
  // A Gtk::Label is intrinsically transparent - it's background color cannot be set
  // Therefore, we add it to a Gtk::EventBox with background color overridden to white
  Gtk::EventBox *eb = Gtk::manage(new Gtk::EventBox);
  eb -> set_hexpand();
  eb -> override_background_color(Gdk::RGBA("white"));
  eb -> add( *data);
  // PACK_EXPAND_WIDGET tells VBox this widget should be as big as possible
  vbox -> pack_start( *eb, Gtk::PACK_EXPAND_WIDGET, 0);

  // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
  // Provide a status bar for game messages
  msg = Gtk::manage(new Gtk::Label());
  msg -> set_hexpand(true);
  vbox -> pack_start( *msg, Gtk::PACK_SHRINK, 0);
  //vbox -> add( *msg);

  // Make the box and everything in it visible
  vbox -> show_all();
// Start with a new store
    on_new_store_click();

};



Mainwin::~Mainwin() {}


//U T I L I T I E S

//utilities
std::string Mainwin::get_string(std::string prompt) {
  EntryDialog dialog {
    *this, prompt, true
  };
  dialog.set_text(prompt);
  dialog.run();
  return (dialog.get_text()).c_str();
}

double Mainwin::get_double(std::string prompt) {
  EntryDialog dialog( *this, "Cost");
  dialog.set_text(prompt);
  dialog.run();
  return std::stoi((dialog.get_text()));
}

int Mainwin::get_int(std::string prompt) {
  EntryDialog dialog( *this, "Order/Desktop");
  dialog.set_text(prompt);
  dialog.run();
  return std::stoi((dialog.get_text()));
}
void Mainwin::set_data(std::string s) {
  std::ostringstream oss;
  data -> set_text(s);
  oss.str();
}

void Mainwin::set_msg(std::string s) {
  msg -> set_text(s);
}

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_store_click() {
    delete store;
    store = new Store;
    filename = "untitled.elsa";
    set_data("");
    set_msg("New store created");
}

void Mainwin::on_save_click() {
    try {
            std::ofstream ofs{filename};
            store->save(ofs);
            if(!ofs) throw std::runtime_error{"Error writing file"};
            set_msg("Saved " + filename);
    } catch(std::exception& e) {
            std::string err = "Unable to save store to " + filename;
            set_msg("<b>ERROR:</b> " + err);
            Gtk::MessageDialog{*this, err, false, Gtk::MESSAGE_WARNING}.run();
    }

}

void Mainwin::on_save_as_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1) {
        filename = dialog.get_filename();
        on_save_click();
    }
}
//
// The user wants to open a store from the filesystem
//
void Mainwin::on_open_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            delete store; store = nullptr;
            filename = dialog.get_filename();
            std::ifstream ifs{filename};
            store = new Store{ifs};
            if(!ifs) throw std::runtime_error{"Invalid file contents"};
            on_view_customer_click();
            set_msg("Loaded " + filename);
        } catch (std::exception& e) {
            std::string err = "Unable to open store from " + filename + " (" + e.what() + " )";
            on_new_store_click();
            set_msg("<b>ERROR:</b>: " + err);
            Gtk::MessageDialog{*this, err, false, Gtk::MESSAGE_WARNING}.run();
        }
    }
}

void Mainwin::on_quit_click() {
  close();
}

void Mainwin::on_about_click() {
  Gtk::AboutDialog dialog;
  dialog.set_transient_for( *this); // Avoid the discouraging warning
  dialog.set_program_name("The ELSA Application");
  // auto logo = Gdk::Pixbuf::create_from_file("128px-Pyramidal_matches.png");
  // dialog.set_logo(logo);
  dialog.set_version("Version 1.2.1");
  dialog.set_copyright("Copyright 2020");
  dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
  std::vector < Glib::ustring > authors = {
    "Devasri Warrier"
  };
  dialog.set_authors(authors);
  std::vector < Glib::ustring > artists = {
    "No LOGO in this  sprint..next one"
    "no image yet"
  };
  dialog.set_artists(artists);
  dialog.run();
}

void Mainwin::on_view_customer_click() {
  //std::ostringstream oss;
  //Glib::ustring s = R"(
  //<span size='20000' weight='bold'>Customers:</span>)";

  //for(int i=0; i < store->num_customers(); ++i) {
  // oss << i << ") " << store->customer(i) << "\n";
  //std:: string s = oss.str();
  //std::cout << s;
  //}
  // msg->set_markup(s);
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2);
  oss << "Customers\n\n";
  for (int i = 0; i < store -> num_customers(); ++i)
    oss << i << ") " << store -> customer(i) << "\n";
  set_data(oss.str());
  set_msg("");
}
void Mainwin::on_view_peripheral_click() {
  //std::ostringstream oss;
  //Glib::ustring s = R"(
  //<span size='20000' weight='bold'>Peripherals::</span>)";
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2);
  oss << "Peripherals\n\n";
  for (int i = 0; i < store -> num_options(); ++i)
    oss << i << ") " << store -> option(i) << "\n";
  oss << "</tt>";
  set_data(oss.str());
  set_msg("");
  //std:: string s = oss.str();
  //std::cout << s;

}
void Mainwin::on_view_desktop_click() {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2);
  oss << "Products\n\n";
  for (int i = 0; i < store -> num_desktops(); ++i)
    oss << i << ") " << store -> desktop(i) << "\n";
  set_data(oss.str());
  set_msg("");
}

void Mainwin::on_view_order_click() {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2);
  oss << "Orders\n\n";
  for (int i = 0; i < store -> num_orders(); ++i)
    oss << i << ") " << store -> order(i) << "\n\n";
  set_data(oss.str());
  set_msg("");
}

void Mainwin::on_insert_customer_click() {
	Gtk::Dialog dialog{"Insert Customer", *this};
	Gtk::Grid grid;
	Gtk::Label t_name{"Name"};
	Gtk::Entry e_name;
	grid.attach(t_name, 0, 0, 1, 1);
	grid.attach(e_name, 1, 0, 2, 1);

	Gtk::Label a_name{"Phone"};
	Gtk::Entry b_name;
	grid.attach(a_name, 0, 1, 1, 1);
	grid.attach(b_name, 1, 1, 2, 1);

	Gtk::Label c_name{"Email"};
	Gtk::Entry d_name;
	grid.attach(c_name, 0, 2, 1, 1);
	grid.attach(d_name, 1, 3, 2, 1);

	dialog.get_content_area()->add(grid);
	dialog.add_button("Insert", Gtk::RESPONSE_OK);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	dialog.show_all();
	int response;
while((response = dialog.run()) ==Gtk::RESPONSE_OK){
if(e_name.get_text().size() == 0) {e_name.set_text("*REQUIRED*"); continue;}

    std::string Name = e_name.get_text();
    std::string Phone = b_name.get_text();
    std::string Email = d_name.get_text();
    Customer customer {Name, Phone, Email};
    store->add_customer(customer);
    on_view_customer_click();
    set_msg("Added customer " + Name);
}

}

void Mainwin::on_insert_peripheral_click() {

Gtk::Dialog dialog{"Insert Peripheral Type", *this};
	Gtk::Grid grid;
	Gtk::Label P_name{"Type"};
	Gtk::Entry Pr_name;
	grid.attach(P_name, 0, 0, 1, 1);
	grid.attach(Pr_name, 1, 0, 2, 1);
dialog.get_content_area()->add(grid);
	dialog.add_button("Insert", Gtk::RESPONSE_OK);
	dialog.show_all();
	int response;
while((response = dialog.run()) ==Gtk::RESPONSE_OK){
  std::string peripheral = Pr_name.get_text();
  double cost = get_double("Cost?");

  Options option {peripheral,cost};
  store -> add_option(option);

  on_view_peripheral_click();
  set_msg("Added peripheral " + peripheral);
}
}
void Mainwin::on_insert_desktop_click() {
    on_view_peripheral_click();
    int desktop = store -> new_desktop();
    while (true) {
      std::ostringstream oss;
      oss << store -> desktop(desktop) << "\n\nAdd which peripheral (-1 when done)? ";

      int option = get_int(oss.str());
      if (option == -1) break;
      try {
        store -> add_option(option, desktop);
      } catch (std::exception & e) {
        Gtk::MessageDialog {
          *this, "#### INVALID OPTION ####\n\n"
        }.run();
      }
      on_view_desktop_click();
      set_msg("Added desktop " + std::to_string(desktop));
    }
}
    void Mainwin::on_insert_order_click() {
      on_view_customer_click();
      int customer = get_int("Customer?");
      if (customer == -1) return;
      int order = store -> new_order(customer);
      on_view_desktop_click();
      while (true) {
        int desktop = get_int("Desktop (-1 when done)?");
        if (desktop == -1) {
          break;
        }
        store -> add_desktop(desktop, order);
      }
      on_view_order_click();
      set_msg("Added order " + std::to_string(order) + " for $" + std::to_string(store -> order(order).price()));
    }


