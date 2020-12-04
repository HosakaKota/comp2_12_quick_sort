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
	};
}
