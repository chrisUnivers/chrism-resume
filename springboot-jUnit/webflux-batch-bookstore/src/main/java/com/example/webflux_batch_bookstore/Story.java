package com.example.webflux_batch_bookstore;

public class Story {

    private String bkStory;

    public Story(){
    }

    public Story(String bkStory) {
        this.bkStory = bkStory;
    }

    public String getBkStory() {
        return this.bkStory;
    }

    public void setBkStory(String bkStory) {
        this.bkStory = bkStory;
    }

    @Override
    public String toString() {
        return "Story{" + "story='" + this.bkStory + '\'' + '}';
    }
}
