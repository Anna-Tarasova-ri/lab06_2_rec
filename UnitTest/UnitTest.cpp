// Unit-тест для рекурсивної версії (проєкт pr6_2_rec)
// Тестується функція IndexOfMinOdd() – повертає індекс найменшого непарного елемента
#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6_2_rec/pr6_2_rec.cpp"       // шлях за потреби змінити

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62Rec
{
	TEST_CLASS(UnitTest62Rec)
	{
	public:

		// непарні 7, 9, 5 – найменше 5 з індексом 4
		TEST_METHOD(MixedElements)
		{
			int a[] = { 4, 7, 2, 9, 5 };
			Assert::AreEqual(4, IndexOfMinOdd(a, 5, 0, -1));
		}

		// непарних немає – очікуємо -1
		TEST_METHOD(NoOddElements)
		{
			int a[] = { 2, 4, 6, 8 };
			Assert::AreEqual(-1, IndexOfMinOdd(a, 4, 0, -1));
		}

		// від'ємні непарні: найменше -7 з індексом 1
		TEST_METHOD(NegativeOddElements)
		{
			int a[] = { 3, -7, -1, 8 };
			Assert::AreEqual(1, IndexOfMinOdd(a, 4, 0, -1));
		}

		// найменше повторюється – індекс першого
		TEST_METHOD(DuplicateMinimum)
		{
			int a[] = { 5, 3, 8, 3 };
			Assert::AreEqual(1, IndexOfMinOdd(a, 4, 0, -1));
		}

		// усі елементи непарні
		TEST_METHOD(AllOdd)
		{
			int a[] = { 9, 7, 11, 1, 5 };
			Assert::AreEqual(3, IndexOfMinOdd(a, 5, 0, -1));
		}

		// найменше непарне першим
		TEST_METHOD(MinOddIsFirst)
		{
			int a[] = { -3, 4, 5, 6, 7 };
			Assert::AreEqual(0, IndexOfMinOdd(a, 5, 0, -1));
		}

		// найменше непарне останнім
		TEST_METHOD(MinOddIsLast)
		{
			int a[] = { 8, 5, 10, 3 };
			Assert::AreEqual(3, IndexOfMinOdd(a, 4, 0, -1));
		}

		// масив з одного елемента
		TEST_METHOD(SingleElement)
		{
			int odd[] = { 9 };
			int even[] = { 8 };
			Assert::AreEqual(0, IndexOfMinOdd(odd, 1, 0, -1));
			Assert::AreEqual(-1, IndexOfMinOdd(even, 1, 0, -1));
		}

		// менші за непарні парні числа не впливають на результат
		TEST_METHOD(SmallerEvenIgnored)
		{
			int a[] = { -10, 0, 3, -4, 1 };
			Assert::AreEqual(4, IndexOfMinOdd(a, 5, 0, -1));
		}
	};
}