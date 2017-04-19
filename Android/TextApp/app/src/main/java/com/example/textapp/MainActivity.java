package com.example.textapp;

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

        setTitle("고객목록");

        LinearLayout layout = (LinearLayout)findViewById(R.id.customers);
        //layout.setBackgroundColor(Color.argb(255,255,255,255));

        addCustomer(layout, "홍길동", "서울","02-555-1234");
        addCustomer(layout, "심청", "강원도", "033-777-1234");
    }

    private void addCustomer(LinearLayout layout, String customer, String city, String tel){
        TextView name;
        TextView etc;

        name = new TextView(this);
        name.append(customer);
        name.setTextSize(20);
        name.setTextColor(Color.argb(255, 255, 255, 0));
        name.setBackgroundColor(Color.argb(100, 0, 0, 255));
        layout.addView(name);

        etc = new TextView(this);
        etc.append(city+"\n");
        etc.append(tel);
        etc.setTextColor(Color.argb(255, 0, 0, 0));
        layout.addView(etc);

        etc.setPadding(0,5,0,25);
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
