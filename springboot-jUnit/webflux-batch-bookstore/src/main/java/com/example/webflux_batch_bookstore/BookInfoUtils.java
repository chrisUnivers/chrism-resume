package com.example.webflux_batch_bookstore;

public class BookInfoUtils {

    protected String bookInfo_;
    protected int infoInit_ = 0;

    BookInfoUtils() {
        this("no-info");
        this.bookInfo_ = removeCommas();
        this.infoInit_ = 1;
    }
    BookInfoUtils(String bInfo) {
        this.bookInfo_ = bInfo;
        this.bookInfo_ = removeCommas();
        this.infoInit_ = 1;
    }

    public String[] returnBookStoreIds() {
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
        return this.bookInfo_.split(" ")[0];
    }

    public String getFirstName() {
        return this.bookInfo_.split(" ")[1];
    }

    public String getLastName() {
        return this.bookInfo_.split(" ")[2];
    }

    public double getBookReviewScore() {
        double score = Double.parseDouble(this.bookInfo_.split(" ")[6].split(":")[1]);
        return (double)score;
    }

    public String getReleaseDate() {
        return this.bookInfo_.split(" ")[3];
    }

    private String removeCommas() {
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
