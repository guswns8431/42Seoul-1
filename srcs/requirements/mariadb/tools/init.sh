#!bin/bash

if [ ! -d /var/lib/mysql/$DB_NAME ]; then
	#Start MariaDB
	service mysql start
	#Create database & create user & alter root password & grant privileges
	mysql -e "CREATE DATABASE IF NOT EXISTS $DB_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;\
		CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_USER_PW';\
		GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';\
		ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PW'; FLUSH PRIVILEGES;"
	#End MariaDB
	mysqladmin -uroot -p$DB_ROOT_PW shutdown
fi
#daemon
exec mysqld_safe
