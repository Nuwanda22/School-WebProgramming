package com.example.myapp;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ActionMenuView;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

/**
 * Created by 전성우 on 2016-01-21.
 */
public class CustomerInfo extends AppCompatActivity{
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.customer_info);
        setTitle("고객정보");

        LinearLayout layout = (LinearLayout)findViewById(R.id.customer_layout);
        TextView[] textView = new TextView[5];
        Button button = new Button(this);
        button.setText("이전");
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
                goPrevActivity();
            }
        });
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        button.setLayoutParams(params);

        Intent it = getIntent();
        String[] data = it.getStringArrayExtra("string_array_data");
        String[] sub = {"이름 : ", "성별 : ", "수신 여부 : ", "관심분야 : ", "생일 : "};

        for(int i = 0; i < textView.length; i++) {
            textView[i] = new TextView(this);
            data[i] = sub[i] + data[i];
            textView[i].setText(data[i]);
            textView[i].setTextSize(15);
            layout.addView(textView[i]);
        }
        layout.addView(button);
    }

    private void goPrevActivity(){
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }


    @Override
    protected void onDestroy(){
        goPrevActivity();
        super.onDestroy();
    }
}
