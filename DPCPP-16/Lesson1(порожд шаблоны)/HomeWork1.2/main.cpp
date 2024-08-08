#include <iostream>
#include <vector>
#include <map>
#include <string>

class SqlSelectQueryBuilder {
private:
    std::string query;

public:
    SqlSelectQueryBuilder() : query("SELECT  *  FROM ") {}

    // Метод для добавления нескольких столбцов в запрос
    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept {
        if (!columns.empty()) {
            for (const auto& column : columns) {
                query += column + ", ";
            }
            // Удаляем последний разделитель (запятую), если он есть
            if (!query.empty() && query.back() == ',') {
                query.pop_back();
            }
        }
        return  *this;
    }

    // Метод для добавления нескольких условий WHERE в запрос
    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
        if (!kv.empty()) {
            query += "WHERE ";
            bool first = true;
            for (const auto& condition : kv) {
                if (!first) {
                    query += " AND ";
                }
                else {
                    first = false;
                }
                query += condition.first + " = '" + condition.second + "'";
            }
        }
        return  *this;
    }

    // Метод для получения финального запроса
    const std::string& GetQuery() const {
        return query;
    }
};

int main() {
    SqlSelectQueryBuilder builder;
    std::vector<std::string> columns = { "column1", "column2" };
    std::map<std::string, std::string> conditions = { {"condition1", "value1"}, {"condition2", "value2"} };

    // Добавляем столбцы в запрос
    builder.AddColumns(columns);
    // Добавляем условия WHERE в запрос
    builder.AddWhere(conditions);

    // Выводим сформированный запрос
    std::cout << builder.GetQuery() << std::endl;

    return 0;
}