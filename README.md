# PamAuthentication

This is a qml plugin for Ubuntu Touch apps that need to authentication a user
with their password.

## Usage

~~~
import QtQuick 2.4
import Ubuntu.Components 1.3
import PamAuthentication 0.1

MainView {
    id: root
    applicationName: 'app.name'

    AuthenticationHandler {
        id: authHandler
        serviceName: root.applicationName

        onAuthenticationSucceeded: {
            console.log('Authentication succeeded');
        }

        onAuthenticationAborted: {
            console.log('Authentication aborted');
        }
    }

    Component.onCompleted: authHandler.authenticate(i18n.tr('Enter your password for cool stuff'));
}
~~~

## License

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License version 3, as published
by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranties of MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
