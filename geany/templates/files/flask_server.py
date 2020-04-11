#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Minimal Flask server template.

@file flask_server.py
@version 2020.04.11
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
"""


from os.path import abspath, dirname

import awsgi
from flask import (
    # abort,
    # current_app,
    Flask,
    g,
    jsonify,
    redirect,
    render_template,
    request,
    # send_from_directory,
    url_for
)
from flask_bcrypt import Bcrypt
from flask_login import current_user, login_required, login_user, LoginManager, logout_user
# from flask_mail import Mail, Message
from flask_sqlalchemy import SQLAlchemy
from flask_wtf import FlaskForm
from wtforms import PasswordField, StringField, SubmitField
from wtforms.validators import DataRequired


# SETUP GLOBALS #


ASSETS_DIR: str = dirname(abspath(__file__))

FLASK_APP = Flask(
    __name__,
    static_url_path=None,
    static_folder=fr'{ASSETS_DIR}/static',
    static_host=None,
    host_matching=False,
    subdomain_matching=False,
    template_folder=fr'{ASSETS_DIR}/templates',
    instance_path=None,
    instance_relative_config=False,
    root_path=None
)

FLASK_APP.config['SECRET_KEY'] = r'66ceb5fA2_2F0d66503cb32fR8db97edd2ba533A9E1371613A53F1B6e5a8e5f58ca1Z3d360494eb417d9dAE11B33FCD602a62fc6701X3de28eb9eaac2cfbf3e8'
FLASK_APP.config[r'SQLALCHEMY_BINDS'] = {
    r'main': fr'sqlite:///{ASSETS_DIR}/database.sqlite3'
}
FLASK_APP.config[r'SQLALCHEMY_DATABASE_URI'] = fr'sqlite:///{ASSETS_DIR}/database.sqlite3'
FLASK_APP.config[r'SQLALCHEMY_ECHO'] = False
FLASK_APP.config[r'SQLALCHEMY_RECORD_QUERIES'] = False
FLASK_APP.config[r'SQLALCHEMY_TRACK_MODIFICATIONS'] = False

BCRYPT = Bcrypt(FLASK_APP)
DB = SQLAlchemy(FLASK_APP)
LOGIN_MANAGER = LoginManager()
# MAIL = Mail()


# CLASSES #


class LoginForm(FlaskForm):
    """User login form object."""
    email = StringField(r'Email: ', validators=[DataRequired()])
    password = PasswordField(r'Password: ', validators=[DataRequired()])
    submit = SubmitField(r'Login')


class User(DB.Model):
    """User model object.

    :param str email: Email address of user
    :param bool is_active: Used to denote if the user account is active
    :param str password: Password of user
    :param int user_id: Unique ID for the user
    :param str username: Username
    """
    __bind_key__: str = r'main'
    __tablename__: str = r'users'
    email = DB.Column(DB.String(64), nullable=False, unique=True)
    is_active = DB.Column(DB.Boolean, default=True, nullable=False)
    password = DB.Column(DB.String(128), nullable=False)
    user_id = DB.Column(DB.Integer, autoincrement=True, primary_key=True, unique=True)
    username = DB.Column(DB.String(32), nullable=False, unique=True)

    sqlite3_str: str = '''CREATE TABLE "users" (
        "user_id" INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,
        "email" TEXT NOT NULL UNIQUE,
        "is_active" INTEGER NOT NULL DEFAULT 1,
        "password" TEXT NOT NULL,
        "username" TEXT NOT NULL UNIQUE
    );'''

    def __str__(self):
        """Return the string representation of a user."""
        return self.username

    def get_id(self):
        """Return the email address to satisfy Flask-Login's requirements."""
        return self.email


# LOGIN FUNCTIONS #


@LOGIN_MANAGER.user_loader
def user_loader(user_id):
    """Given `user_id` (as an email string), return the associated User object."""
    return User.query.get(user_id)


@FLASK_APP.route(r'/get_current_user', methods=[r'GET'])
def get_current_user():
    """API endpoint for retrieving the current user."""
    return jsonify(
        username=g.user.username,
        email=g.user.email,
        user_id=g.user.id
    )


@FLASK_APP.route(r'/login', methods=[r'GET', r'POST'])
def login():
    """For GET requests, display the login form. For POST requests, login the current user by processing the form."""
    form = LoginForm()
    if form.validate_on_submit():
        user = User.query.get(form.email.data)
        if user and BCRYPT.check_password_hash(user.password, form.password.data):
            user.authenticated = True
            DB.session.add(user)
            DB.session.commit()
            login_user(user, remember=True)
            return redirect(url_for(r'index'))
    return render_template(r'login.html', form=form)


@FLASK_APP.route(r'/logout', methods=[r'GET'])
@login_required
def logout():
    """Logout the current user."""
    current_user.authenticated = False
    DB.session.add(current_user)
    DB.session.commit()
    logout_user()
    return render_template(r'logout.html')


# ENDPOINT/PAGE FUNCTIONS #


@FLASK_APP.route(r'/', methods=[r'GET'])
def index() -> str:
    """Main site page."""
    return r'Flask is running!'


@FLASK_APP.route(r'/data/<type_id>', methods=[r'GET'])
def names(type_id: int):
    """JSON endpoint."""
    if type_id:
        return jsonify({r'elements': [r'carbon', r'helium', r'hydrogen', r'oxygen']})
    return jsonify({r'linux': [r'Debian', r'Fedora', r'Slackware', r'Ubuntu']})


@FLASK_APP.route(r'/input', methods=[r'GET'])
def render():
    """Render an HTML template."""
    if r'filename' in request.args:
        return render_template(request.args.get(r'filename'))
    return r'No input file specified'


# MAIN #


def lambda_handler(event, context):
    """Handler function used by AWS-Lambda."""
    return awsgi.response(FLASK_APP, event, context)


if __name__ == '__main__':
    # Make snake-oil certs: openssl req -x509 -newkey rsa:4096 -nodes -out cert.pem -keyout key.pem -days 365
    FLASK_APP.jinja_env.cache = {}  # Cache templates and speed-up Flask
    FLASK_APP.run(
        debug=True,  # nosec
        host=r'127.0.0.1',
        port=8000,
        # ssl_context=(r'cert.pem', r'key.pem')
    )
