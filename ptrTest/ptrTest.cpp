#include "pch.h"
#include "CppUnitTest.h"
#include"../ptr/deck.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ptrTest
{
	TEST_CLASS(ptrTest)
	{
	public:
		
		TEST_METHOD(Push_Back_Success)
		{
			Deck Deck;

			Deck.push_back(1);
			Deck.push_back(2);
			Deck.push_back(3);

			std::string actual = Deck.toString();
			std::string expected = "1 2 3 ";

			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(Push_Front_Success)
		{
			Deck Deck;

			Deck.push_front(1);
			Deck.push_front(2);
			Deck.push_front(3);

			std::string actual = Deck.toString();
			std::string expected = "3 2 1 ";

			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(Pop_Success)
		{
			Deck Deck;

			Deck.push_back(1);
			Deck.push_back(2);
			Deck.push_back(3);
			Deck.pop();
			std::string actual = Deck.toString();
			std::string expected = "2 3 ";

			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(Peek_Front_Success)
		{
			Deck Deck;

			Deck.push_back(1);
			Deck.push_back(2);
			Deck.push_back(3);

			int actual = Deck.peekFront();
			int expected = 1;

			Assert::AreEqual(actual, expected);
		}
	};
}
