# GameQ
GameQ is a [Drupal](https://www.drupal.org/) module that queries multiple types of online game servers and makes server information available to Drupal entities using the [GameQ](https://github.com/Austinb/GameQ) 3rd party library.

## Requirements
1. [Drupal CMS](https://www.drupal.org/) v7.x
1. [GameQ PHP library](https://github.com/Austinb/GameQ) v2.0.0+

## Installation
1. Download and unpack the `gameq` module to your `your/drupal/root/sites/all/modules/contrib` directory.
2. Download and unpack the [GameQ library v2.0.0+](https://github.com/Austinb/GameQ) to your home directory.
3. Inside the new GameQ folder in your home directory, move and rename the `src/GameQ` directory to `/your/drupal/root/sites/all/libraries/gameq`.
4. Enable the `gameq` module with [Drush](http://www.drush.org/) or through the Drupal UI.
