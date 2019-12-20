#include "gtest/gtest.h"
extern "C" {
#include "KVPstorage.h"
}

TEST(get_key_from_line, basic)
{
	char str[KEYSIZE + 1];
	EXPECT_EQ(get_key_from_line("key test", str), 3);
	str[3] = 0;
	EXPECT_STREQ(str, "key");
}

TEST(get_key_from_line, error)
{
	testing::internal::CaptureStderr();

	char str[KEYSIZE + 1];
	EXPECT_EQ(get_key_from_line(
		"0123456789012345678901234567890123456789012345678901234567890123456789", str), -1);

	std::string output = testing::internal::GetCapturedStderr();
	EXPECT_STREQ(output.c_str(), "Invalid input.\nKey length too long. Max key size is 64.\n");
}

TEST(exec_command, toplayer_test)
{
	t_kvp		*settings;
	t_fileinfo	fileinfo;

	settings = NULL;
	fileinfo.filepath = init_filepath(".settings");
	fileinfo.stream = open_settings_file(fileinfo.filepath);
	settings = init_settings_list(fileinfo.stream);
	testing::internal::CaptureStdout();
	exec_command(&settings, &fileinfo, "SET key value");
	exec_command(&settings, &fileinfo, "GET key");
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "OK\nvalue\n");

	// EXPECT_EQ(get_key_from_line("key test", str), 3);
	// str[3] = 0;
	// EXPECT_STREQ(str, "key");
}

// void	exec_command(t_kvp **settings, t_fileinfo *fileinfo, char *line)

