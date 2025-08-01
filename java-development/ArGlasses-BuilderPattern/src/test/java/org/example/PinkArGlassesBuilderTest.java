package org.example;


import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;

class PinkArGlassesBuilderTest {
    @Test
    public void test_InstatiatePinkArGlassesBuilder_toStringMethod() {
        PinkArGlassesBuilder pinkglasses = new PinkArGlassesBuilder();
        String expectedStr = "I'm a pink ar glasses build";

        Assertions.assertEquals(expectedStr, pinkglasses.toString());
    }
}