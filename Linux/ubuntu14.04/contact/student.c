#include <stdio.h>
#include <string.h>
#include <mysql.h>

#define HOST "127.0.0.1"
#define USER "root"
#define PASS "root"
#define NAME "test"
#define CHOP(x) x[strlen(x) - 1] = ' '

int create_sql(MYSQL *conn)
{
	MYSQL con_err;
	int query_stat;
	char *sqlquery = "create table address (name varchar(20), address varchar(30), tel varchar(20));";
	query_stat = mysql_query(conn, sqlquery);

	if(query_stat != 0){
		fprintf(stderr, "Mysql query error : %s\n", mysql_error(&con_err));
		return 1;
	}
	return 0;
}

int main()
{
	MYSQL *connection = NULL, conn;
	MYSQL_RES *sql_result;
	MYSQL_ROW sql_row;

	int query_stat;

	char name[12];
	char address[80];
	char tel[12];
	char query[255];

	mysql_init(&conn);

	connection = mysql_real_connect(&conn, HOST, USER, PASS, NAME, 3306, (char *)NULL, 0);
	if(connection == NULL){
		fprintf(stderr, "Mysql connection error : %s\n", mysql_error(&conn));
		return 1;
	}

	query_stat = mysql_query(connection, "select * from address");
	if(query_stat != 0){
		fprintf(stderr, "Mysql query error : %s\n", mysql_error(&conn));
#ifdef _SQL_CREATE_
		if(create_sql(connection)!=0)
			return 1;
#endif
		mysql_close(connection);
		return 1;
	}
		
	sql_result = mysql_store_result(connection);
	printf("%+11s    %-30s   %-10s\n", "Name", "Address", "Tel");
	while((sql_row = mysql_fetch_row(sql_result)) != NULL){
		printf("%+11s    %-30s   %-10s\n", sql_row[0], sql_row[1], sql_row[2]);
	}
	mysql_free_result(sql_result);
	
	printf("Name : "); fgets(name, 12, stdin); CHOP(name);
	printf("Addrese : "); fgets(address, 30, stdin); CHOP(address);
	printf("Tel : "); fgets(tel, 12, stdin); CHOP(tel);
	sprintf(query, "insert into address values " "('%s', '%s', '%s')", name, address, tel);
	query_stat = mysql_query(connection, query);
	if(query_stat != 0){
		fprintf(stderr, "Mysql every error : %s", mysql_error(&conn));
		return 1;
	}
	mysql_close(connection);
}
