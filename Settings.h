#pragma once
#include <atomic>
#include <cstddef>
#include <json/value.h>

class Settings
{
public:
    Settings(const Settings& settings) = delete;
    Settings(Settings&& settings) = delete;
    Settings& operator=(Settings&&) = delete;
    Settings& operator=(const Settings&) = delete;
    ~Settings() = default;

    static Settings& getInstance()
    {
        static Settings instance;
        return instance;
    }

    Settings& load(const Json::Value& config)
    {
        const auto& teachers = config["teachers"];
        this->teacher_salary_.store(teachers["salary"].asUInt());
        this->teachers_count.store(teachers["count"].asUInt());
        this->teacher_premium_rate.store(teachers["premium_rate"].asDouble());

        const auto& assistants = config["assistants"];
        this->assistant_salary_.store(assistants["salary"].asUInt());
        this->assistants_count.store(assistants["count"].asUInt());
        this->assistant_premium_rate.store(assistants["premium_rate"].asDouble());
    	return *this;
    }

    auto getTeacherSalary() const
    {
        return this->teacher_salary_.load();
    }

    auto getTeachersCount() const
    {
        return this->teachers_count.load();
    }

    auto getTeacherPremiumRate() const
    {
        return this->teacher_premium_rate.load();
    }

    auto getAssistantSalary() const
    {
        return this->assistant_salary_.load();
    }

    auto getAssistantsCount() const
    {
        return this->assistants_count.load();
    }

    auto getAssistantPremiumRate() const
    {
        return this->assistant_premium_rate.load();
    }

private:
    Settings() = default;
    std::atomic<std::size_t> teacher_salary_;
    std::atomic<std::size_t> teachers_count;
    std::atomic<double> teacher_premium_rate;

    std::atomic<std::size_t> assistant_salary_;
    std::atomic<std::size_t> assistants_count;
    std::atomic<double> assistant_premium_rate;
};

