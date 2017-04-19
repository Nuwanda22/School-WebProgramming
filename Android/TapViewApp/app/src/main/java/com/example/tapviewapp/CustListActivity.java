package com.example.tapviewapp;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

/**
 * Created by 전성우 on 2016-01-19.
 */
public class CustListActivity extends Activity{
    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        TextView textView = new TextView(this);
        textView.setText("고객목록 화면");
        setContentView(textView);
    }
}
