package com.example.audioapp;

import android.graphics.Color;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    MediaPlayer[] mp = new MediaPlayer[2];
    TextView[] tv = new TextView[2];

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

        for(int i = 0; i < tv.length; i++){
            if(i == 0){
                mp[i] = MediaPlayer.create(this, R.raw.bibidibabidibuu);
            }
            else if(i == 1){
                mp[i] = MediaPlayer.create(this, R.raw.lovemetender);
            }
            mp[i].setLooping(false);
        }

        LinearLayout layout = (LinearLayout)findViewById(R.id.album);

        for(int i = 0; i<tv.length; i++){
            tv[i] = new TextView(this);
            tv[i].setId(i);

            if(i == 0){
                tv[i].append("Bibidi Badibi Buu");
            }
            else if(i == 1){
                tv[i].append("Love Me Tender");
            }

            tv[i].setTextSize(20);
            tv[i].setTextColor(Color.YELLOW);
            tv[i].setOnClickListener(this);
            layout.addView(tv[i]);
        }
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

    @Override
    public void onClick(View v) {
        int tvId = v.getId();

        for(int i = 0; i<tv.length; i++){
            if(i == tvId){
                if(mp[i].isPlaying()){
                    mp[i].pause();
                    tv[i].setTextColor(Color.YELLOW);
                    tv[i].setBackgroundColor(Color.WHITE);
                }
                else {
                    mp[i].start();
                    tv[i].setTextColor(Color.BLACK);
                    tv[i].setBackgroundColor(Color.YELLOW);
                }
            }
            else {
                if(mp[i].isPlaying()){
                    mp[i].pause();
                    tv[i].setTextColor(Color.YELLOW);
                    tv[i].setBackgroundColor(Color.WHITE);
                }
            }
        }
    }

    @Override
    protected void onDestroy()
    {
        for(int i = 0; i < mp.length; i++) {
            // TODO
            if(mp[i]!=null) {
                mp[i].release();
                mp[i].stop();
            }
        }
        super.onDestroy();
    }

}
