package org.example;


import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;

class PinkArGlassesBuilderTest {
    @Test
    public void test_InstatiatePinkArGlassesBuilder_toStringMethod() {
        PinkArGlassesBuilder pinkglasses = new PinkArGlassesBuilder();
        String expectedStr = "A pink AR glasses build";

        Assertions.assertEquals(expectedStr, pinkglasses.toString());
    }
    @Test
    public void test_InjectPinkArGlassesBuilderInMainBuilder_toStringMethod() {
        PinkArGlassesBuilder pinkglasses = new PinkArGlassesBuilder();
        MainBuilder mainBuilder = new MainBuilder(pinkglasses);

        String expectedStr = "Main Builder has: A pink AR glasses build";

        Assertions.assertEquals(expectedStr, mainBuilder.toString());
    }
}