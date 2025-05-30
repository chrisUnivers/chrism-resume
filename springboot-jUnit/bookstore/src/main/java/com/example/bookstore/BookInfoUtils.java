package com.example.bookstore;

public class BookInfoUtils {
    
    protected String bookInfo_;
    protected int infoInit_ = 0;

    BookInfoUtils() {
        this("no-info");
    }
    BookInfoUtils(String bInfo) {
        this.bookInfo_ = bInfo;
    }

    public String[] returnBookIds() {
        
        initInfo();
        String[] rtIds = this.bookInfo_.split(" ");
        // rtIds[5] = SubmittedTo:BookstoreFourId-BookstoreFiveId
        rtIds = rtIds[5].split(":")[1].split("-");
        
        return rtIds;
    }

    public void initInfo() {
        if (infoInit_ != 1) {
            this.bookInfo_ = removeCommas();
            this.infoInit_ = 1;
        }        
    }

    public String getTitle() {
        initInfo();
        return this.bookInfo_.split(" ")[0];
    }

    public String getFirstName() {
        initInfo();
        return this.bookInfo_.split(" ")[1];
    }

    public String getLastName() {
        initInfo();
        return this.bookInfo_.split(" ")[2];
    }

    public double getBookReviewScore() {
        initInfo();
        float score = Float.parseFloat(this.bookInfo_.split(" ")[6].split(":")[1]);
        return (double)score;
    }

    public String getReleaseDate() {
        initInfo();
        return this.bookInfo_.split(" ")[3];
    }

    private String removeCommas() {
        initInfo();
        String[] pLine = this.bookInfo_.split(" ");
        String rnLine = "";
        int pIndex = 0;
        for (String ln : pLine) {
            if (++pIndex < pLine.length) {
                rnLine += ln.substring(0, ln.length() - 1); // remove comma at the end since csv file.
                rnLine += " ";
            } else {
                rnLine += ln;
            }
        }
        return rnLine;
    }
}
