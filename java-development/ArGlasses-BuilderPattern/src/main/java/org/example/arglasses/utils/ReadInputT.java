package org.example.arglasses.utils;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ReadInputT implements Runnable{
    protected String filename_;

    public ReadInputT(String filename) { filename_ = filename; }
    public String getFilename() { return filename_; }

    public void setFilename(String file) {filename_ = file; }

    @Override
    public void run() {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename_))) {
            String line;
            int notreading = 0;
            while ( (line = reader.readLine() ) != null) {

                FileProcessing.fileQueue_.put(line);
                int reading = 1;
            }
            FileProcessing.fileQueue_.put("EOF");
        }catch (IOException | InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
