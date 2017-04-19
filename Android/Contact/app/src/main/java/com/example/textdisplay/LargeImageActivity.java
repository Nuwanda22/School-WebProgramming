package com.example.textdisplay;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageView;

/**
 * Created by 전성우 on 2016-01-13.
 */
public class LargeImageActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.large_image);

        Intent it = getIntent();
        String tag = it.getStringExtra("it_tag");

        int id_image = getResources().getIdentifier(tag, "drawable", getPackageName());
        ImageView imageView = (ImageView)findViewById(R.id.large_image);
        imageView.setImageResource(id_image);
    }

    public void disappear(View v){
        finish();
    }
}
