#include <cstdint>
#include <SX1280_Regs.h>
#include <FHSS.h>
#include <unity.h>
#include <set>

void test_fhss_first(void)
{
    FHSSrandomiseFHSSsequence(0x01020304L);
    TEST_ASSERT_EQUAL(GetInitialFreq(), FHSSconfig->freq_start + freq_spread * sync_channel / FREQ_SPREAD_SCALE);
}

void test_fhss_assignment(void)
{
    FHSSrandomiseFHSSsequence(0x01020304L);

    const uint32_t numFhss = FHSSgetChannelCount();
    uint32_t initFreq = GetInitialFreq();

    uint32_t freq = initFreq;
    for (unsigned int i = 0; i < 512; i++) {
        if ((i % numFhss) == 0) {
            TEST_ASSERT_EQUAL(initFreq, freq);
        } else {
            TEST_ASSERT_NOT_EQUAL(initFreq, freq);
        }
        freq = FHSSgetNextFreq();
    }
}

void test_fhss_unique(void)
{
    FHSSrandomiseFHSSsequence(0x01020304L);

    const uint32_t numFhss = FHSSgetChannelCount();
    std::set<uint32_t> freqs;

    for (unsigned int i = 0; i < 256; i++) {
        uint32_t freq = FHSSgetNextFreq();

        if ((i % numFhss) == 0) {
            freqs.clear();
            freqs.insert(freq);
        } else {
            bool inserted = freqs.insert(freq).second;
            TEST_ASSERT_TRUE_MESSAGE(inserted, "Should only see a frequency one time per number initial value");
        }
    }
}

void test_fhss_same(void)
{
    FHSSrandomiseFHSSsequence(0x01020304L);

    const uint32_t numFhss = FHSSgetSequenceCount();

    uint32_t fhss[numFhss];

    for (unsigned int i = 0; i < FHSSgetSequenceCount(); i++) {
        uint32_t freq = FHSSgetNextFreq();
        fhss[i] = freq;
    }

    FHSSrandomiseFHSSsequence(0x01020304L);

    for (unsigned int i = 0; i < FHSSgetSequenceCount(); i++) {
        uint32_t freq = FHSSgetNextFreq();
        TEST_ASSERT_EQUAL(fhss[i],freq);
    }
}

void test_fhss_reg_same(void)
{
    FHSSrandomiseFHSSsequence(0x01020304L);

    const uint32_t numFhss = FHSSgetSequenceCount();

    uint32_t fhss[numFhss];

    for (unsigned int i = 1; i < FHSSgetSequenceCount(); i++) {
        uint32_t freq = FHSSgetNextFreq();
        uint32_t reg = FREQ_HZ_TO_REG_VAL((2400400000 + FHSSsequence[i]*1000000));
        TEST_ASSERT_UINT32_WITHIN(1, reg, freq);
    }
}

// Unity setup/teardown
void setUp() {}
void tearDown() {}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_fhss_first);
    RUN_TEST(test_fhss_assignment);
    RUN_TEST(test_fhss_unique);
    RUN_TEST(test_fhss_same);
    RUN_TEST(test_fhss_reg_same);
    UNITY_END();

    return 0;
}
