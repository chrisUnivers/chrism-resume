package org.example;

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
        String mainBldrStr = String.format("Main Builder has: %s", builder_.toString());
        return mainBldrStr;

    }
}
