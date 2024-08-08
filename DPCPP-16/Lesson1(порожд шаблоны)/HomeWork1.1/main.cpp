#include <iostream>
#include <string>
#include <vector>
#include <cassert>


class SqlSelectQueryBuilder {
private:
    std::string m_query;
    std::vector<std::pair<std::string, std::string>> m_whereConditions;
    std::vector<std::string> m_columns;
    std::string m_fromTable;

public:
    SqlSelectQueryBuilder() 
    {
        m_query = "SELECT  * ";
    }

    void AddColumn(const std::string& column) 
    {
        if (!column.empty()) {
            m_columns.push_back(column);
        }
    }

    void AddFrom(const std::string& table) {
        if (!table.empty()) {
            m_fromTable = table;
        }
    }

    void AddWhere(const std::string& column, const std::string& value) {
        if (!column.empty() && !value.empty()) {
            m_whereConditions.emplace_back(column, value);
        }
    }

    std::string BuildQuery() const {
        std::string result = m_query;
        if (!m_columns.empty()) {
            result += " " + std::string(m_columns.size(), ',') + " FROM " + m_fromTable;
        }
        else {
            result += " FROM " + m_fromTable;
        }
        if (!m_whereConditions.empty()) {
            for (const auto& cond : m_whereConditions) {
                result += " WHERE " + cond.first + "=" + cond.second;
            }
        }
        result += ";";
        return result;
    }
};

int main() {
    //check empty
    {
        SqlSelectQueryBuilder query_builder;
        auto query = query_builder.BuildQuery();
        assert(query.find("SELECT  * ") == 0); //start from SELECT  * 
        assert(query.rfind(";") == (query.size() - 1)); //ends with ;
    }
    //check tz
    {
        SqlSelectQueryBuilder query_builder;
        query_builder.AddColumn("name");
        query_builder.AddColumn("phone");
        query_builder.AddFrom("students");
        query_builder.AddWhere("id", "42");
        query_builder.AddWhere("name", "John");
        auto query = query_builder.BuildQuery();
        std::cout << query << std::endl;
        assert(query == "SELECT name, phone FROM students WHERE id=42 AND name=John;");
    }
    //check tz change order + rename table
    {
        SqlSelectQueryBuilder query_builder;
        query_builder.AddColumn("name");
        query_builder.AddColumn("phone");
        query_builder.AddFrom("students");
        query_builder.AddWhere("id", "42");
        query_builder.AddWhere("name", "John");
        auto query = query_builder.BuildQuery();
        query_builder.AddFrom("prepods");
        auto query = query_builder.BuildQuery();
        assert(query == "SELECT name, phone FROM prepods WHERE id=42 AND name=John;");
    }

 
    return 0;
}