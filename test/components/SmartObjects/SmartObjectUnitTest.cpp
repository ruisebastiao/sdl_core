
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "SmartObjects/CSmartObject.hpp"

namespace test { namespace components { namespace SmartObjects { namespace SmartObjectUnitTest {

    using namespace NsAppLink::NsSmartObjects;


    class TestHelper : public ::testing::Test
    {
    protected:

        void makeMapObject(CSmartObject &obj, const int size) const
        {
            char i_key[8], j_key[8], k_key[8], value[8];

            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    for (int k = 0; k < size; k++)
                    {
                        sprintf(i_key, "i_%d", i);
                        sprintf(j_key, "j_%d", j);
                        sprintf(k_key, "k_%d", k);
                        sprintf(value, "%d", i + j + k);
                        obj[i_key][j_key][k_key] = value;
                    }
        }

        void checkMapObject(CSmartObject &obj, const int size) const
        {
            char i_key[8], j_key[8], k_key[8], value[8];

            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    for (int k = 0; k < size; k++)
                    {
                        sprintf(i_key, "i_%d", i);
                        sprintf(j_key, "j_%d", j);
                        sprintf(k_key, "k_%d", k);
                        sprintf(value, "%d", i + j + k);

                        ASSERT_EQ(std::string(value), static_cast<std::string>(obj[i_key][j_key][k_key])) <<
                                "Wrong value in the map at [" << i_key << "][" << j_key << "][" << k_key << "]";
                    }
        }

       void makeArrayObject(CSmartObject &obj, int size, int base=0)
       {
           for (int i = 0; i < size; i++)
               for (int j = 0; j < size; j++)
                   for (int k = 0; k < size; k++)
                   {
                       obj[i][j][k] = base + i + j + k;
                   }
       }

       void checkArrayObject(CSmartObject &obj, int size, int base=0)
       {
           for (int i = 0; i < size; i++)
               for (int j = 0; j < size; j++)
                   for (int k = 0; k < size; k++)
                   {
                       ASSERT_EQ(base + i + j + k, static_cast<int>(obj[i][j][k])) <<
                               "Wrong value in the array at index: " << i << ", " << j << ", " << k;
                   }
       }
    };

    /*
     * Tests different types sequentially
     */
    TEST(BasicMixtedTypes, test_SmartObjectUnitTest)
    {
        CSmartObject obj;

        ASSERT_EQ(invalid_int_value, static_cast<int>(obj)) << "Wrong cast to int just after construction";

        obj = 10;
        ASSERT_EQ(10, static_cast<int>(obj)) << "Wrong cast to int";

        obj = "some string";
        ASSERT_EQ("some string", static_cast<std::string>(obj)) << "Wrong cast to std::string";

        obj = false;
        ASSERT_FALSE(static_cast<bool>(obj)) << "Wrong cast to bool";

        obj = 'A';
        ASSERT_EQ('A', static_cast<char>(obj)) << "Wrong cast to char";

        obj = 3.14;
        ASSERT_EQ(3.14, static_cast<double>(obj)) << "Wrong cast to double";

        // array test
        for (int i = 0; i < 100; i++)
        {
            obj[i] = i;
            ASSERT_EQ(i, static_cast<int>(obj[i]));
        }

        // map test
        for (int i = 0; i < 100; i++)
        {
            char key[8];
            sprintf(key, "%d", i);
            obj[key] = i;
            ASSERT_EQ(i, static_cast<int>(obj[key]));
        }
    }

    TEST_F(TestHelper, BasicArrayTest)
    {
        CSmartObject obj;

        ASSERT_EQ(invalid_int_value, static_cast<int>(obj[0])) << "Wrong value at accessing non existent index";
        ASSERT_EQ(invalid_int_value, static_cast<int>(obj["non_existent_key"])) << "Wrong value at accessing non existent key";

        obj[0] = 1;
        ASSERT_EQ(1, static_cast<int>(obj[0])) << "Wrong value at 0 index";
        obj[1] = 2;
        ASSERT_EQ(2, static_cast<int>(obj[1])) << "Wrong value at 1 index";

        obj[0][0] = 3;
        obj[1][0] = 1;
        ASSERT_EQ(3, static_cast<int>(obj[0][0])) << "Wrong value at index 0, 0";

        obj[0][0][0] = 4;
        obj[0][1][0] = 5;
        ASSERT_EQ(4, static_cast<int>(obj[0][0][0])) << "Wrong value at index 0, 0, 0";

        const int size = 32;
        makeArrayObject(obj, size);

        checkArrayObject(obj, size);
    }


    TEST_F(TestHelper, BasicMapTest)
    {
        CSmartObject obj;

        ASSERT_EQ(invalid_int_value, static_cast<int>(obj["non_existent_key"])) << "Wrong value for non existent key";

        obj["abc"]["def"]["ghi"] = 5;
        ASSERT_EQ(5, static_cast<int>(obj["abc"]["def"]["ghi"])) << "Wrong value for triple map";

        obj["123"]["456"]["789"] = "string test";

        ASSERT_EQ("string test", static_cast<std::string>(obj["123"]["456"]["789"])) << "Wrong value for triple map";

        const int size = 32;

        makeMapObject(obj, size);

        checkMapObject(obj, size);
    }

    TEST(ConstructorsTest, test_SmartObjectUnitTest)
    {
        CSmartObject objInt(5678);
        ASSERT_EQ(5678, static_cast<int>(objInt)) << "Wrong constructor with int param";

        char c_str[] = "test c_string";
        CSmartObject obj_c_str(c_str);
        ASSERT_EQ("test c_string", static_cast<std::string>(obj_c_str)) << "Wrong constructor with c_str param";

        CSmartObject obj_std_str(std::string("test std_string"));
        ASSERT_EQ(std::string("test std_string"), static_cast<std::string>(obj_std_str));

        CSmartObject obj_char('R');
        ASSERT_EQ('R', static_cast<char>(obj_char)) << "Wrong constructor with char param";

        CSmartObject obj_double(-0.4321);
        ASSERT_EQ(-0.4321, static_cast<double>(obj_double)) << "Wrong constructor with double param";

        CSmartObject obj_bool(true);
        ASSERT_TRUE(static_cast<bool>(obj_bool)) << "Wrong constructor with bool param";

        CSmartObject src_obj;

        src_obj["key_1"] = "value_1";     // FIXME: String assignment crashes test
        src_obj["key_2"]["sub_key_1"] = "value_2";

        CSmartObject dst_obj(src_obj);
        ASSERT_EQ("value_1", static_cast<std::string>(dst_obj["key_1"])) << "Copy constructor is not correct";
        ASSERT_EQ("value_2", static_cast<std::string>(dst_obj["key_2"]["sub_key_1"])) << "Copy constructor is not correct";
    }

    // TODO: Fix test agains conversion table
//     TEST(ConversionTest, test_SmartObjectUnitTest)
//     {
//         CSmartObject obj;
// 
//         ASSERT_EQ(0, static_cast<int>(obj)) << "Initial value is not 0";
//         ASSERT_FALSE(static_cast<bool>(obj)) << "Initial value is not false";
//         ASSERT_EQ("null", static_cast<std::string>(obj)) << "Initial value is not an empty string";
//         ASSERT_EQ('\0', static_cast<char>(obj)) << "Initial value of a char is not \\0";
//         ASSERT_EQ(0, static_cast<double>(obj)) << "Initial value of a double is not 0";
// 
//         obj = 1;
//         ASSERT_TRUE(static_cast<bool>(obj)) << "1 is not true";
//         ASSERT_EQ("1", static_cast<std::string>(obj)) << "string representation is not correct";
//         ASSERT_EQ('\0', static_cast<char>(obj)) << "char representation is not correct";
//         ASSERT_EQ(1, static_cast<double>(obj)) << "double representation is not correct";
// 
//         // FIXME: Conversion from string to int doesn't work
//         obj = "54321";
//         ASSERT_EQ(54321, static_cast<int>(obj)) << "String to int is not correct";
// 
//         obj = "-1234";
//         ASSERT_EQ(-1234, static_cast<int>(obj)) << "String to int is not correct";
// 
//         obj = "true";
//         ASSERT_TRUE(static_cast<bool>(obj)) << "String to bool is not correct";
// 
//         obj = "false";
//         ASSERT_FALSE(static_cast<bool>(obj)) << "String to bool is not correct";
// 
//         obj = "TRUE";
//         ASSERT_TRUE(static_cast<bool>(obj)) << "Uppercase TRUE is not recognised as true";
// 
//         obj = "-3.1234";
//         ASSERT_EQ(-3.1234, static_cast<double>(obj)) << "String to double is not correct";
// 
//         obj = "-43.43.5something";
//         ASSERT_EQ(-1, static_cast<double>(obj)) << "Wrong conversion invalid string to double";
//     }

    TEST_F(TestHelper, AssignmentTest)
    {
        CSmartObject objSrc, objDst;

        objSrc = -6;
        objDst = 7;
        objDst = objSrc;
        ASSERT_EQ(-6, static_cast<int>(objDst)) << "Wrong assignment for int object";

        objSrc = "Some test string";
        objDst = "Other string";
        objDst = objSrc;
        ASSERT_EQ("Some test string", static_cast<std::string>(objDst)) << "Wrong assignment for std::string object";

        objSrc = 0.5;
        objDst = 4;
        objDst = objSrc;
        ASSERT_EQ(0.5, static_cast<double>(objDst)) << "Wrong assignment for double object";

        objSrc = true;
        objDst = false;
        objDst = objSrc;
        ASSERT_TRUE(static_cast<bool>(objDst)) << "Wrong assignment for bool object";

        const int size = 32;
        makeMapObject(objSrc, size);
        objDst["a"]["b"] = 4;
        objDst = objSrc;
        checkMapObject(objDst, size);

        makeArrayObject(objSrc, size, 5);
        makeArrayObject(objDst, 23, 6);
        objDst = objSrc;
        checkArrayObject(objDst, size, 5);
    }

    TEST_F(TestHelper, SizeTest)
    {
        CSmartObject obj;

        ASSERT_EQ(0, obj.length()) << "Wrong size for the uninitialized object";

        obj = 1234;
        ASSERT_EQ(0, obj.length()) << "Wrong size for the int object";

        std::string str("Some test very long string");
        obj = str;
        ASSERT_EQ(str.size(), obj.length()) << "The size of the object containing string is not correct";

        obj = true;
        ASSERT_EQ(0, obj.length()) << "Wrong size of the true";

        obj = 0.1234;
        ASSERT_EQ(0, obj.length()) << "Wrong size of the double";

        obj = 'A';
        ASSERT_EQ(0, obj.length()) << "Wrong size of the char";

        makeMapObject(obj, 12);
        ASSERT_EQ(12, obj.length()) << "Wrong size of the object containing map";

        makeArrayObject(obj, 21);
        ASSERT_EQ(21, obj.length()) << "Wrong size of the object containing array";
    }

   TEST(CopyObjectsTest, SmartObjectTest)
   {
       CSmartObject obj;

       obj[0] = "test string";

       obj = obj[0];

       ASSERT_EQ("test string", static_cast<std::string>(obj));
   }
   
    TEST(CopyConstructorTest, SmartObjectTest)
    {
        CSmartObject srcObj;
        
        srcObj[0] = "test string";
        
        CSmartObject dstObj = srcObj[0];
        
        ASSERT_EQ("test string", static_cast<std::string>(dstObj));
    }



    int main(int argc, char **argv)
    {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

}}}}

