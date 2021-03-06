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

#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

#include "common/unit_test_util/unit_test_util.h"
#include "postgres/query_runner/orm/data_collection.h"
#include "postgres/query_runner/reflection/sql_primitives.h"
#include "postgres/query_runner/resultset/mock_result_set.h"

class User : public e8::SqlEntityInterface {
  public:
    e8::SqlInt id = e8::SqlInt("id");
    e8::SqlStr user_name = e8::SqlStr("user_name");
    User() : SqlEntityInterface{&id, &user_name} {}
    User(User const &other)
        : SqlEntityInterface{&id, &user_name}, id(other.id), user_name(other.user_name) {}
};

class CreditCard : public e8::SqlEntityInterface {
  public:
    e8::SqlInt id = e8::SqlInt("id");
    e8::SqlInt user_id = e8::SqlInt("user_id");
    e8::SqlStr card_number = e8::SqlStr("card_number");
    CreditCard() : SqlEntityInterface{&id, &user_id, &card_number} {}
    CreditCard(CreditCard const &other)
        : SqlEntityInterface{&id, &user_id, &card_number}, id(other.id), user_id(other.user_id),
          card_number(other.card_number) {}
};

class BankAccount : public e8::SqlEntityInterface {
  public:
    e8::SqlInt id = e8::SqlInt("id");
    e8::SqlStr card_number = e8::SqlStr("card_number");
    e8::SqlStr account_number = e8::SqlStr("account_number");
    BankAccount() : SqlEntityInterface{&id, &card_number, &account_number} {}
    BankAccount(BankAccount const &other)
        : SqlEntityInterface{&id, &card_number, &account_number}, id(other.id),
          card_number(other.card_number), account_number(other.account_number) {}
};

bool ToEntityTupleTest() {
    e8::MockResultSet rs(/*num_cells=*/2 + 3 + 3);
    rs.AddRecord(e8::MockResultSet::Record{// User record.
                                           std::make_shared<e8::SqlInt>(1, "id"),
                                           std::make_shared<e8::SqlStr>("user1", "user_name"),
                                           // Credit card record.
                                           nullptr, nullptr, nullptr,
                                           // Bank account record
                                           nullptr, nullptr, nullptr});
    rs.AddRecord(e8::MockResultSet::Record{
        // User record.
        std::make_shared<e8::SqlInt>(2, "id"),
        std::make_shared<e8::SqlStr>("user2", "user_name"),
        // Credit card record.
        std::make_shared<e8::SqlInt>(101, "id"),
        std::make_shared<e8::SqlInt>(2, "user_id"),
        std::make_shared<e8::SqlStr>("1010101002", "card_number"),
        // Bank account record
        std::make_shared<e8::SqlInt>(1001, "id"),
        std::make_shared<e8::SqlStr>("1010101002", "card_number"),
        std::make_shared<e8::SqlStr>("abcdefghij", "account_number"),
    });

    std::vector<std::tuple<User, CreditCard, BankAccount>> results =
        e8::ToEntityTuples<User, CreditCard, BankAccount>(&rs);

    TEST_CONDITION(results.size() == 2);

    TEST_CONDITION(std::get<0>(results[0]).id.Value() == std::optional<int32_t>(1));
    TEST_CONDITION(std::get<0>(results[0]).user_name.Value() ==
                   std::optional<std::string>("user1"));
    TEST_CONDITION(!std::get<1>(results[0]).id.Value().has_value());
    TEST_CONDITION(!std::get<1>(results[0]).user_id.Value().has_value());
    TEST_CONDITION(!std::get<1>(results[0]).card_number.Value().has_value());
    TEST_CONDITION(!std::get<2>(results[0]).id.Value().has_value());
    TEST_CONDITION(!std::get<2>(results[0]).card_number.Value().has_value());
    TEST_CONDITION(!std::get<2>(results[0]).account_number.Value().has_value());

    TEST_CONDITION(std::get<0>(results[1]).id.Value() == std::optional<int32_t>(2));
    TEST_CONDITION(std::get<0>(results[1]).user_name.Value() ==
                   std::optional<std::string>("user2"));
    TEST_CONDITION(std::get<1>(results[1]).id.Value() == std::optional<int32_t>(101));
    TEST_CONDITION(std::get<1>(results[1]).user_id.Value() == std::optional<int32_t>(2));
    TEST_CONDITION(std::get<1>(results[1]).card_number.Value() ==
                   std::optional<std::string>("1010101002"));
    TEST_CONDITION(std::get<2>(results[1]).id.Value() == std::optional<int32_t>(1001));
    TEST_CONDITION(std::get<2>(results[1]).card_number.Value() ==
                   std::optional<std::string>("1010101002"));
    TEST_CONDITION(std::get<2>(results[1]).account_number.Value() ==
                   std::optional<std::string>("abcdefghij"));

    return true;
}

int main() {
    e8::BeginTestSuite("data_collection");
    e8::RunTest("ToEntityTupleTest", ToEntityTupleTest);
    e8::EndTestSuite();
    return 0;
}
