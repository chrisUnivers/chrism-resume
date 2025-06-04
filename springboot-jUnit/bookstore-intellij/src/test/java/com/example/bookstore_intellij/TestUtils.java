package com.example.bookstore_intellij;



public class TestUtils {
    public static final String SQL_ONE_BKS_ID = "SELECT bks_name, bks_address, bks_id, bks_collection FROM bookstores WHERE bks_id = ?";
    public static final String SQL_TWO_BKS_IDS = "SELECT bks_name, bks_address, bks_id, bks_collection FROM bookstores WHERE bks_id = ? OR bks_id = ?";
    public static final String SQL_FINDSTONE_STANCE = "SELECT bks_name, bks_address, bks_id, bks_collection FROM bookstores WHERE bks_collection LIKE ?";

    public static final String ID_ONE = "IDONE";
    public static final String ID_TWO = "IDTWO";
    public static final String NOT_ID = "IDSIX";
    public static final String INPUT_FINDSTONE_STANCE = "%(My_Book_Title, Emily, Findstone, June-08-2016, 8.1),(Service, Emily, Stance, Aug-08-2013, 8.3)%";
}
