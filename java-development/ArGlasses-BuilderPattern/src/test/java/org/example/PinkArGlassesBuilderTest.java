package org.example;


import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;

import static org.example.arglasses.utils.ConstUtils.*;


class PinkArGlassesBuilderTest {
    @Test
    public void test_InstatiatePinkArGlassesBuilder_toStringMethod() {
        PinkArGlassesBuilder pinkglasses = new PinkArGlassesBuilder();
        String expectedStr = PINK_AR_GLASSES_BLDR_TOSTRING_STR;

        Assertions.assertEquals(expectedStr, pinkglasses.toString());
    }
    @Test
    public void test_InjectPinkArGlassesBuilderInMainBuilder_toStringMethod() {
        PinkArGlassesBuilder pinkglasses = new PinkArGlassesBuilder();

        MainBuilder mainBuilder = new MainBuilder(pinkglasses);

        String expectedStr = String.format(MAIN_BLDR_TOSTRING_STR, PINK_AR_GLASSES_BLDR_TOSTRING_STR);

        Assertions.assertEquals(expectedStr, mainBuilder.toString());
    }
    @Test
    public void test_UseNoneDefaultValuesForIOProcessor_toStringMethod() {
        PinkArGlassesBuilder pinkglasses = new PinkArGlassesBuilder();
        MainBuilder mainBuilder = new MainBuilder(pinkglasses);
        IArGlasses myGlasses = mainBuilder.MakeGlasses();
        UtilEnums.IOProcessorModels expectedModel = UtilEnums.IOProcessorModels.PINK;
        myGlasses.getIOProcessor().getIOProcessorModel();

        Assertions.assertEquals(expectedModel, myGlasses.getIOProcessor().getIOProcessorModel() );
    }
}