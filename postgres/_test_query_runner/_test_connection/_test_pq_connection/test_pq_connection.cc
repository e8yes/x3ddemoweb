/**
 * e8yes demo web.
 *
 * <p>Copyright (C) 2020 Chifeng Wen {daviesx66@gmail.com}
 *
 * <p>This program is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * <p>This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * <p>You should have received a copy of the GNU General Public License along with this program. If
 * not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdint>
#include <memory>
#include <optional>
#include <string>

#include "common/unit_test_util/unit_test_util.h"
#include "postgres/query_runner/connection/connection_interface.h"
#include "postgres/query_runner/connection/pq_connection.h"
#include "postgres/query_runner/reflection/sql_primitives.h"

bool ConnectionStateTest() {
    e8::PqConnection conn(
        /*host_name=*/"localhost",
        /*db_name=*/"demoweb");
    TEST_CONDITION(!conn.IsClosed());

    return true;
}

bool UpdateAndQueryTest() {
    e8::PqConnection conn(
        /*host_name=*/"localhost",
        /*db_name=*/"demoweb");

    // Prepares table.
    std::string drop_table_stmt = "DROP TABLE IF EXISTS PqConnectionTest";
    conn.RunUpdate(drop_table_stmt, e8::ConnectionInterface::QueryParams());

    std::string createTableStmt = "CREATE TABLE PqConnectionTest("
                                  " id BIGINT NOT NULL,"
                                  " test_name CHARACTER VARYING NOT NULL,"
                                  " PRIMARY KEY (id))";
    conn.RunUpdate(createTableStmt, e8::ConnectionInterface::QueryParams());

    // Insert test records.
    std::string insert_stmt = "INSERT INTO PqConnectionTest(id, test_name) VALUES ($1, $2)";
    e8::ConnectionInterface::QueryParams insertion_params;
    insertion_params.SetParam(1, std::make_shared<e8::SqlLong>(1L));
    insertion_params.SetParam(2, std::make_shared<e8::SqlStr>("test_string", /*field_name=*/""));
    uint64_t num_rows_affected = conn.RunUpdate(insert_stmt, insertion_params);

    TEST_CONDITION(num_rows_affected == 1);

    // Query records.
    std::string query_stmt = "SELECT * FROM PqConnectionTest WHERE id=$1";
    e8::ConnectionInterface::QueryParams query_params;
    query_params.SetParam(1, std::make_shared<e8::SqlLong>(1L));

    std::unique_ptr<e8::ResultSetInterface> rs = conn.RunQuery(query_stmt, query_params);
    TEST_CONDITION(rs->HasNext());

    e8::SqlLong id_field("id");
    e8::SqlStr test_name_field("test_name");
    rs->SetField(0, &id_field);
    rs->SetField(1, &test_name_field);

    TEST_CONDITION(id_field.Value() == std::optional<int64_t>(1L));
    TEST_CONDITION(test_name_field.Value() == std::optional<std::string>("test_string"));

    rs->Next();
    TEST_CONDITION(!rs->HasNext());

    // Clean up.
    conn.RunUpdate(drop_table_stmt, e8::ConnectionInterface::QueryParams());

    return true;
}

int main() {
    e8::BeginTestSuite("pq_connection");
    e8::RunTest("ConnectionStateTest", ConnectionStateTest);
    e8::RunTest("UpdateAndQueryTest", UpdateAndQueryTest);
    e8::EndTestSuite();
    return 0;
}
