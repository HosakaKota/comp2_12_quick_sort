#include "pch.h"

// ���������[�N�̃L���v�`��
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "CppUnitTest.h"
#include "../include/libsort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_MODULE_CLEANUP(test_module_cleanup) {
		Assert::IsFalse(_CrtDumpMemoryLeaks());// ���������[�N�`�F�b�N
	}

	TEST_CLASS(UnitTest)
	{
	public:

		// ������̏ꍇ�����؂���
		TEST_METHOD(TestMethod1)
		{
			// ������
			array* a = create(1);

			a->nodes[0].key = 1; strcpy_s(a->nodes[0].value, 256, "hello world!");

			// �\�[�g
			quick_sort(a);

			// ���ʂ̌���
			Assert::AreEqual("hello world!", a->nodes[0].value);

			// �Еt��
			finalize(a);
		}

		// 2�̏ꍇ�����؂���
		TEST_METHOD(TestMethod2)
		{
			// ������
			array* a = create(2);

			a->nodes[0].key = 2; strcpy_s(a->nodes[0].value, 256, "world!");
			a->nodes[1].key = 1; strcpy_s(a->nodes[1].value, 256, "hello");

			// �\�[�g
			quick_sort(a);

			// ���ʂ̌���
			for (int i = 0; i < a->num; i++) {
				const static char* expected[] = {
					"hello" ,
					"world!" };
				Assert::AreEqual(expected[i], a->nodes[i].value);
			}

			// �Еt��
			finalize(a);
		}

		// 3�̏ꍇ�����؂���
		TEST_METHOD(TestMethod3)
		{
			// ������
			array* a = create(3);

			a->nodes[0].key = 3; strcpy_s(a->nodes[0].value, 256, "!");
			a->nodes[1].key = 2; strcpy_s(a->nodes[1].value, 256, "world");
			a->nodes[2].key = 1; strcpy_s(a->nodes[2].value, 256, "hello");

			// �\�[�g
			quick_sort(a);

			// ���ʂ̌���
			for (int i = 0; i < a->num; i++) {
				const static char* expected[] = {
					"hello" ,
					"world",
					"!" };
				Assert::AreEqual(expected[i], a->nodes[i].value);
			}

			// �Еt��
			finalize(a);
		}

		// 6�̏ꍇ(�����A2��ڂ̃\�[�g������ꍇ)�����؂���
		TEST_METHOD(TestMethod6)
		{
			// ������
			array* a = create(6);

			a->nodes[0].key = 1; strcpy_s(a->nodes[0].value, 256, "1");
			a->nodes[1].key = 5; strcpy_s(a->nodes[1].value, 256, "5");
			a->nodes[2].key = 3; strcpy_s(a->nodes[2].value, 256, "3");
			a->nodes[3].key = 0; strcpy_s(a->nodes[3].value, 256, "0");
			a->nodes[4].key = 2; strcpy_s(a->nodes[4].value, 256, "2");
			a->nodes[5].key = 7; strcpy_s(a->nodes[5].value, 256, "7");

			// �\�[�g
			quick_sort(a);

			// ���ʂ̌���
			for (int i = 0; i < a->num; i++) {
				static char expected[2] = "0";
				expected[0] = '0' + a->nodes[i].key;
				Assert::AreEqual(0, strcmp(expected, a->nodes[i].value));
			}

			// �Еt��
			finalize(a);
		}
	};
}
