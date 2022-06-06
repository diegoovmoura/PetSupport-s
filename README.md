# Projeto-FDS

This is a dedicated repository for the CESAR School's Software Development Fundamentals course project.

## PetSupport's

A website made for donating and adopting pets.

## Table of Contents

- [General Info](#general-info)
- [Technologies](#technologies)
- [Features](#features)
- [Screenshots](#screenshots)
- [Setup](#setup)
- [Run Tests](#run-tests)
- [Usage](#usage)
- [Status](#status)
- [Sources](#sources)
- [Team](#team)
- [License](#license)

## General Info

This is a project where the main goal is to provide a website capable of handling, taking and shipping different kinds and breeds of domesticated animals to costumers. Mainly, it would work as a mean of diminishing the number of cases of abandoned animals living in the streets, or avoid those situations from happening by having an easy-to-use software that people can go to, when they can't take care of their pets anymore. This website may find someone who can.

## Technologies

Project is created with:

- Python 3.7
- JavaScript
- HTML
- CSS
- Flask

## Features

- Account Sign Up and Log In autenthication
- Create a new announcement for a pet
- Browse through the Pets available
- Complete your purchase and adopt a pet
- Search function with filter option

## Screenshots

### ![main](https://i.imgur.com/Y1NQAuO.png)

### ![login](https://i.imgur.com/hn6VOya.png)

### ![addpet](https://i.imgur.com/lYch24C.png)

## Setup

First, you'll need to have the latest version of [Flask](https://flask.palletsprojects.com/en/2.1.x/installation/) installed

To run this project, you'll also need WSL-Linux, simply enter this command in CMD:

```
wsl --install
```

Then, install it using WSL-Linux

```
FLASK_APP = src/app.py
FLASK_ENV = development flask run
```

## Run Tests

First, to run the tests you need to install the last version of [Pytest](https://docs.pytest.org/en/7.1.x/getting-started.html)

After installed, to run the tests open your Terminal and find the directory that containes the Project!

Now use this commad to run the tests:

```
pytest
```

Or you can use for a report with more information:

```
pytest -v
```

## Usage

Demo version of the website: [PETSUPPORT'S](https://petsupports.herokuapp.com/)

## Status

Project is: in progress.

- Main Code: Done
- IDE: Done
- Script: Done
- TDD: in progress

## Sources

- This project was inspired by [JPetStore](https://petstore.octoperf.com/actions/Catalog.action)

## Team

| Student        | Contact                    |
| -------------- | -------------------------- |
| Diego Moura    | diegoovmoura@gmail.com     |
| Flávio Vieira  | flaviotefilho@gmail.com    |
| Rafael Alves   | rjhxalves@gmail.com        |
| Rafael Menezes | rafaelmsabarreto@gmail.com |

## License

MIT License

Copyright (c) 2022 Diego Moura