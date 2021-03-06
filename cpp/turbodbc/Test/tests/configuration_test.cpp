#include <turbodbc/configuration.h>

#include <gtest/gtest.h>
#include <sqlext.h>

#include "mock_classes.h"

using turbodbc_test::mock_connection;


TEST(ConfigurationTest, OptionsDefaults)
{
    turbodbc::options options;
    EXPECT_EQ(boost::get<turbodbc::megabytes>(options.read_buffer_size).value, 20);
    EXPECT_EQ(options.parameter_sets_to_buffer, 1000);
    EXPECT_FALSE(options.use_async_io);
    EXPECT_FALSE(options.prefer_unicode);
}


TEST(ConfigurationTest, CapabilitiesDependOnDatabase)
{
    auto connection = std::make_shared<mock_connection>();
    EXPECT_CALL(*connection, do_supports_function(SQL_API_SQLDESCRIBEPARAM))
        .WillOnce(testing::Return(false));

    turbodbc::capabilities capabilities(*connection);
    EXPECT_FALSE(capabilities.supports_describe_parameter);
}


TEST(ConfigurationTest, ConfigurationComprisesOptionsAndCapabilities)
{
    auto connection = std::make_shared<mock_connection>();
    EXPECT_CALL(*connection, do_supports_function(SQL_API_SQLDESCRIBEPARAM))
        .WillOnce(testing::Return(true));

    turbodbc::capabilities capabilities(*connection);
    turbodbc::options options;
    options.parameter_sets_to_buffer = 2000;

    turbodbc::configuration config(options, capabilities);
    EXPECT_EQ(config.options.parameter_sets_to_buffer, options.parameter_sets_to_buffer);
    EXPECT_EQ(config.capabilities.supports_describe_parameter, capabilities.supports_describe_parameter);
}
