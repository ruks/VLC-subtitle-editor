/*
 * File:   newtestclass.h
 * Author: rukshan
 *
 * Created on Sep 9, 2013, 6:52:14 PM
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testChangePosition);
    CPPUNIT_TEST(testChangeVolume);
    CPPUNIT_TEST(testGetLength);
    CPPUNIT_TEST(testGetMP);
    CPPUNIT_TEST(testGetPer);
    CPPUNIT_TEST(testGetPosition);
    CPPUNIT_TEST(testGetTime);
    CPPUNIT_TEST(testIsPLay);
    CPPUNIT_TEST(testLoad);
    CPPUNIT_TEST(testMute);
    CPPUNIT_TEST(testOpen);
    CPPUNIT_TEST(testPause);
    CPPUNIT_TEST(testPlay);
    CPPUNIT_TEST(testPlayer);
    CPPUNIT_TEST(testPlayer2);
    CPPUNIT_TEST(testSetStartTime);
    CPPUNIT_TEST(testStop);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testChangePosition();
    void testChangeVolume();
    void testGetLength();
    void testGetMP();
    void testGetPer();
    void testGetPosition();
    void testGetTime();
    void testIsPLay();
    void testLoad();
    void testMute();
    void testOpen();
    void testPause();
    void testPlay();
    void testPlayer();
    void testPlayer2();
    void testSetStartTime();
    void testStop();

};

#endif	/* NEWTESTCLASS_H */

