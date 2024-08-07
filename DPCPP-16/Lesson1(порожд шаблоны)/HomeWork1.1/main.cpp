#include <iostream>
#include <string>
#include <vector>

class SqlSelectQueryBuilder 
{
protected:
    std::string m_tableName;
    std::vector<std::string> m_columns;
    std::vector<std::pair<std::string, std::string>> m_whereConditions;
    

public:
    
    void AddColumn(const std::string& column) 
    {
        m_columns.push_back(column);
    }

    void AddFrom(const std::string& tableName) {
        m_tableName = tableName;
    }

    void AddWhere(const std::string& column, const std::string& value) {
        m_whereConditions.emplace_back(column, value);
    }

    bool BuildQuery() const
    {
        std::vector<std::string> m_columns;
        if (m_columns.empty()) 
        {
            m_columns.push_back(" * "); 
        }

        std::string query = "SELECT ";
        for (const auto& column : m_columns) {
            query += column + ", ";
        }
        query.pop_back();
        query += "FROM " + m_tableName;

        if (!m_whereConditions.empty()) {
            query += " WHERE ";
            for (size_t i = 0; i < m_whereConditions.size(); ++i) {
                query += m_whereConditions[i].first + "=" + m_whereConditions[i].second;
                if (i != m_whereConditions.size() - 1) {
                    query += " AND ";
                }
            }
        }

        query += ";";
        return true;
    }
};

int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name");
    query_builder.AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42");
    query_builder.AddWhere("name", "John");
     static_assert(query_builder.BuildQuery(), "SELECT name, phone FROM students WHERE id=42 AND name=John;");

    return 0;
}