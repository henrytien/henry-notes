using System;
using System.Collections.Generic;
using System.Data;
using DatabaseWrapper;
using DatabaseWrapper.Core;

namespace ConsoleApp2
{
    class Program
    {

        /*
         * create table person(
            id int PRIMARY key auto_increment,
            first_name varchar(40) NOT NULL,
            last_name varchar(40) NOT NULL,
            notes varchar(40) NOT NULL
          )ENGINE=InnoDB DEFAULT CHARSET=utf8;
        */
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            String hostname = "127.0.0.1";
            Int32 port = 3306;
            string user = "root";
            string password = "game123456" + ";SslMode=None";
            string databasename = "cq";

            object DatabaseClient = null;

            // Sqlite
            //client = new DatabaseClient("[databasefilename]");

            // SQL Server, MySQL, or PostgreSQL
            //client = new DatabaseClient(DbTypes.SqlServer, "[hostname]", [port], "[user]", "[password]", "[databasename]");
            DatabaseClient client = new DatabaseClient(DbTypes.Mysql, hostname, port, user, password, databasename);
            //client = new DatabaseClient(DbTypes.Postgresql, "[hostname]", [port], "[user]", "[password]", "[databasename]");

            // SQL Express
            //client = new DatabaseClient(DbTypes.SqlServer, "[hostname]", [port], "[user]", "[password]", "[instance]", "[databasename]");

            // some variables we'll be using
            Dictionary<string, object> d;
            Expression e;
            List<string> fields;
            DataTable result;

            // add a record
            d = new Dictionary<string, object>();
            d.Add("first_name", "Joel");
            d.Add("last_name", "Christner");
            d.Add("notes", "Author");
            result = client.Insert("person", d);

            // update a record
            d = new Dictionary<string, object>();
            d.Add("notes", "The author :)");
            e = new Expression("first_name", Operators.Equals, "Joel");
            result = client.Update("person", d, e);

            // retrieve 10 records
            fields = new List<string> { "first_name", "last_name" }; // leave null for *
            e = new Expression("last_name", Operators.Equals, "Christner");
            ResultOrder[] order = new ResultOrder[1];
            order[0] = new ResultOrder("first_name", OrderDirection.Ascending);
            result = client.Select("person", 0, 10, fields, e, order);

            // delete a record
            e = new Expression("first_name", Operators.Equals, "Joel");
            client.Delete("person", e);

            // execute a raw query
            //result = client.RawQuery("SELECT customer_id FROM customer WHERE customer_id > 10");
        }
    }
}
