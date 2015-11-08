#CONTENTS OF THIS FILE#

* Introduction
* Requirements
* Recommended modules
* Installation
* Configuration
* Troubleshooting
* FAQ
* Maintainers

INTRODUCTION
------------
The IP Viewer module logs the IP address of users whenever they log in. This module is intended to help identify spammers
and make blocking their IP addresses easier for administrators.

REQUIREMENTS
------------

This module requires the following modules:



RECOMMENDED MODULES
-------------------

 * Flood Control (https://www.drupal.org/project/flood_control):
   When enabled, Flood Control gives you browser-based access to the hidden Drupal flood control variables.

 INSTALLATION
 ------------

* Install as you would normally install a contributed Drupal module. See:
  https://drupal.org/documentation/install/modules-themes/modules-7
  for further information.

CONFIGURATION
-------------

* Configure user permissions in Administration » People » Permissions:

   - Use the administration pages and help (System module)

     The top-level administration categories require this permission to be
     accessible. The administration menu will be empty unless this permission
     is granted.

   - Access administration menu

     Users in roles with the "Access administration menu" permission will see
     the administration menu at the top of each page.

   - Display Drupal links

     Users in roles with the "Display drupal links" permission will receive
     links to drupal.org issue queues for all enabled contributed modules. The
     issue queue links appear under the administration menu icon.

 * Customize the menu settings in Administration » Configuration and modules »
   Administration » Administration menu.

 * To prevent administrative menu items from appearing twice, you may hide the
   "Management" menu block.

CONFIGURATION
-------------

The module has no menu or modifiable settings. There is no configuration. When
enabled, the module will prevent the links from appearing. To get the links
back, disable the module and clear caches.


TROUBLESHOOTING
---------------

 * If the menu does not display, check the following:

   - Are the "Access administration menu" and "Use the administration pages
     and help" permissions enabled for the appropriate roles?

   - Does html.tpl.php of your theme output the $page_bottom variable?

FAQ
---

Q: I enabled "Aggregate and compress CSS files", but admin_menu.css is still
   there. Is this normal?

A: Yes, this is the intended behavior. the administration menu module only loads
   its stylesheet as needed (i.e., on page requests by logged-on, administrative
   users).


MAINTAINERS
-----------

Current maintainers:
 * Daniel F. Kudwien (sun) - https://drupal.org/user/54136
 * Peter Wolanin (pwolanin) - https://drupal.org/user/49851
 * Stefan M. Kudwien (smk-ka) - https://drupal.org/user/48898
 * Dave Reid (Dave Reid) - https://drupal.org/user/53892

This project has been sponsored by:
 * UNLEASHED MIND
   Specialized in consulting and planning of Drupal powered sites, UNLEASHED
   MIND offers installation, development, theming, customization, and hosting
   to get you started. Visit https://www.unleashedmind.com for more information.