#include "pch.h"
#include "CppUnitTest.h"
#include "../Shopping platform/Client.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShoppingPlatformTest
{
	TEST_CLASS(ShoppingPlatformTest)
	{
	public:

		TEST_METHOD(CheckIfPasswordIsCorrect)
		{
			Client client;
			Assert::IsTrue(client.GetPassword().size() > 8);
		}

		TEST_METHOD(CheckIfPhoneIsCorrect)
		{
			Client client;
			Assert::IsTrue(client.GetPhone().size() == 10);
		}

		TEST_METHOD(CheckIfCreditCardIsCorrect)
		{
			Client client;
			Assert::IsTrue(client.GetCreditCard().size() >= 12);
		}
	};
}