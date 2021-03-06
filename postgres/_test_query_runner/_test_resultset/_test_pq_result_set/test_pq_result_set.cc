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
#include <ctime>
#include <memory>
#include <string>

#include "common/unit_test_util/unit_test_util.h"
#include "postgres/query_runner/connection/connection_interface.h"
#include "postgres/query_runner/connection/pq_connection.h"
#include "postgres/query_runner/reflection/sql_primitives.h"
#include "postgres/query_runner/resultset/pq_result_set.h"
#include "postgres/query_runner/resultset/result_set_interface.h"

class Record {
  public:
    e8::SqlInt int_field = e8::SqlInt("int_field");
    e8::SqlLong long_field = e8::SqlLong("long_filed");
    e8::SqlBool bool_field = e8::SqlBool("bool_field");
    e8::SqlFloat float_field = e8::SqlFloat("float_field");
    e8::SqlDouble double_field = e8::SqlDouble("double_field");
    e8::SqlTimestamp timestamp_field = e8::SqlTimestamp("timestamp_field");
    e8::SqlStr string_field = e8::SqlStr("string_field");
    e8::SqlIntArr int_array_field = e8::SqlIntArr("int_array_field");
    e8::SqlLongArr long_array_field = e8::SqlLongArr("long_array_field");
    e8::SqlBoolArr bool_array_field = e8::SqlBoolArr("bool_array_field");
    e8::SqlFloatArr float_array_field = e8::SqlFloatArr("float_array_field");
    e8::SqlDoubleArr double_array_field = e8::SqlDoubleArr("double_array_field");
    e8::SqlTimestampArr timestamp_array_field = e8::SqlTimestampArr("date_array_field");
    e8::SqlStrArr string_array_field = e8::SqlStrArr("string_array_field");
};

bool InsertAndRetrieveTest() {
    e8::PqConnection conn(
        /*host_name=*/"localhost",
        /*db_name=*/"demoweb");
    std::string drop_table_stmt = "DROP TABLE IF EXISTS PqResultSetTestTable";
    std::string create_table_stmt = "CREATE TABLE IF NOT EXISTS PqResultSetTestTable ("
                                    "   int_field INT, "
                                    "   long_field BIGINT, "
                                    "   bool_field BOOLEAN, "
                                    "   float_field REAL, "
                                    "   double_field DOUBLE PRECISION, "
                                    "   timestamp_field TIMESTAMP WITHOUT TIME ZONE, "
                                    "   string_field CHARACTER VARYING, "
                                    "   int_array_field INT[], "
                                    "   long_array_field BIGINT[], "
                                    "   bool_array_field BOOLEAN[], "
                                    "   float_array_field REAL[], "
                                    "   double_array_field DOUBLE PRECISION[], "
                                    "   timestamp_array_field TIMESTAMP WITHOUT TIME ZONE[], "
                                    "   string_array_field CHARACTER VARYING[] "
                                    ")";
    conn.RunUpdate(drop_table_stmt, e8::ConnectionInterface::QueryParams());
    conn.RunUpdate(create_table_stmt, e8::ConnectionInterface::QueryParams());

    std::string insert_record_stmt =
        "INSERT INTO PqResultSetTestTable ("
        "   int_field, "
        "   long_field, "
        "   bool_field, "
        "   float_field, "
        "   double_field, "
        "   timestamp_field,"
        "   string_field, "
        "   int_array_field, "
        "   long_array_field, "
        "   bool_array_field, "
        "   float_array_field, "
        "   double_array_field, "
        "   timestamp_array_field, "
        "   string_array_field) "
        "VALUES ("
        "   10, "
        "   100, "
        "   TRUE, "
        "   0.5, "
        "   0.25, "
        "   to_timestamp(CAST(111 AS BIGINT)) AT TIME ZONE 'UTC', "
        "   'string_value', "
        "   ARRAY[10, 11], "
        "   ARRAY[100, 101], "
        "   ARRAY[TRUE, FALSE], "
        "   ARRAY[0.5, 1.5], "
        "   ARRAY[0.25, 1.25], "
        "   ARRAY[to_timestamp(CAST(111 AS BIGINT)) AT TIME ZONE 'UTC', "
        "         to_timestamp(CAST(112 AS BIGINT)) AT TIME ZONE 'UTC'], "
        "   ARRAY['string_value0', 'string_value1'] "
        ")";
    uint64_t num_rows_inserted =
        conn.RunUpdate(insert_record_stmt, e8::ConnectionInterface::QueryParams());
    TEST_CONDITION(num_rows_inserted == 1);

    std::string query_stmt = "SELECT * FROM PqResultSetTestTable";
    std::unique_ptr<e8::ResultSetInterface> rs =
        conn.RunQuery(query_stmt, e8::ConnectionInterface::QueryParams());
    TEST_CONDITION(rs->HasNext());

    Record record;
    rs->SetField(0, &record.int_field);
    rs->SetField(1, &record.long_field);
    rs->SetField(2, &record.bool_field);
    rs->SetField(3, &record.float_field);
    rs->SetField(4, &record.double_field);
    rs->SetField(5, &record.timestamp_field);
    rs->SetField(6, &record.string_field);
    rs->SetField(7, &record.int_array_field);
    rs->SetField(8, &record.long_array_field);
    rs->SetField(9, &record.bool_array_field);
    rs->SetField(10, &record.float_array_field);
    rs->SetField(11, &record.double_array_field);
    rs->SetField(12, &record.timestamp_array_field);
    rs->SetField(13, &record.string_array_field);

    TEST_CONDITION(record.int_field.Value() == 10);
    TEST_CONDITION(record.long_field.Value() == 100);
    TEST_CONDITION(record.bool_field.Value() == true);
    TEST_CONDITION(record.float_field.Value() == 0.5f);
    TEST_CONDITION(record.double_field.Value() == 0.25);
    TEST_CONDITION(record.timestamp_field.Value() == 111000000);
    TEST_CONDITION(record.string_field.Value() == "string_value");
    TEST_CONDITION(record.int_array_field.Value() == std::vector<int32_t>({10, 11}));
    TEST_CONDITION(record.long_array_field.Value() == std::vector<int64_t>({100, 101}));
    TEST_CONDITION(record.bool_array_field.Value() == std::vector<bool>({true, false}));
    TEST_CONDITION(record.float_array_field.Value() == std::vector<float>({0.5f, 1.5f}));
    TEST_CONDITION(record.double_array_field.Value() == std::vector<double>({0.25, 1.25}));
    TEST_CONDITION(record.timestamp_array_field.Value() ==
                   std::vector<std::time_t>({111000000, 112000000}));
    TEST_CONDITION(record.string_array_field.Value() ==
                   std::vector<std::string>({"string_value0", "string_value1"}));

    rs->Next();
    TEST_CONDITION(!rs->HasNext());

    conn.RunUpdate(drop_table_stmt, e8::ConnectionInterface::QueryParams());

    return true;
}

int main() {
    e8::BeginTestSuite("pq_result_set");
    e8::RunTest("InsertAndRetrieveTest", InsertAndRetrieveTest);
    e8::EndTestSuite();
    return 0;
}
