package org.example;

import static org.example.arglasses.utils.ConstUtils.MAIN_BLDR_TOSTRING_STR;

public class MainBuilder {

    protected IArGlassesBuilder builder_;

    public MainBuilder(IArGlassesBuilder builder) {
        this.builder_ = builder;
    }

    public IArGlasses MakeGlasses() {

        this.builder_.BuildIOProcessor();
        return this.builder_.MakeARGlasses();
    }

    @Override
    public String toString() {

        String mainBldrStr = String.format(MAIN_BLDR_TOSTRING_STR, builder_.toString());
        return mainBldrStr;

    }
}
