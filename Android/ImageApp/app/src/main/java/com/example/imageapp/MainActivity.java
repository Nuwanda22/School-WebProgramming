package com.example.imageapp;

import android.graphics.Color;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });

        LinearLayout layout = (LinearLayout)findViewById(R.id.pictures);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(300, 200);

        addObject(layout, "컵", "책상 위의 컵과 노트", 0, params);
        addObject(layout, "과일", "쟁반 안의 탐스런 과일", 1, params);
    }

    private void addObject(LinearLayout layout, String object, String description, int index, LinearLayout.LayoutParams params){
        TextView name = new TextView(this);
        name.append(object);
        name.setTextSize(20);
        name.setTextColor(Color.rgb(255, 255, 0));
        name.setBackgroundColor(Color.rgb(0, 0, 255));
        layout.addView(name);

        TextView desc = new TextView(this);
        desc.append(description);
        layout.addView(desc);

        ImageView imageView = new ImageView(this);
        imageView.setBackgroundResource(getImageResource(index));
        imageView.setLayoutParams(params);
        imageView.setPadding(0,0,0,25);
        layout.addView(imageView);
    }

    private int getImageResource(int index){
        if(index == 0){
            return R.drawable.img1;
        }
        else if(index == 1){
            return R.drawable.img2;
        }
        else
            return 0;
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
