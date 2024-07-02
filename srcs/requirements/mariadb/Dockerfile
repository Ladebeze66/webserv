FROM debian:buster

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install mariadb-server -y

COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf

RUN service mysql start;
RUN mysql -e "CREATE DATABASE IF NOT EXISTS ${SQL_NAME ;" > SQL.sql
RUN mysql -e "CREATE USER IF NOT EXISTS '${SQL_USER}`@%'IDENTIFIED BY '${SQL_PASSWORD}';" >> SQL.sql
RUN mysql -e "GRANT ALL PRIVILEGES ON $SQL_NAME.* TO `$SQL_USER}`@'%' ;" >> SQL.sql
RUN mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';" >> SQL.sql
RUN mysql -e "FLUSH PRIVILEGES;" >> SQL.sql
RUN mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown
RUN exec mysqld_safe