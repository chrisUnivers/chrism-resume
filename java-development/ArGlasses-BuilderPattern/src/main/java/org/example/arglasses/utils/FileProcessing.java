package org.example.arglasses.utils;


import java.util.concurrent.BlockingDeque;
import java.util.concurrent.LinkedBlockingDeque;

public class FileProcessing {
    public static final BlockingDeque<String> fileQueue_ = new LinkedBlockingDeque<>();
}