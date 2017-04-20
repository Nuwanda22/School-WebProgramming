package com.example.videoapp;

import android.graphics.Color;
import android.net.Uri;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.LinearLayout;
import android.widget.MediaController;
import android.widget.TextView;
import android.widget.VideoView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    TextView[] tv = new TextView[5];
    String[] title = {"지하철1", "자동차2", "지하철3", "자동차4", "지하철5"};
    LinearLayout videoViewLayout;
    VideoView videoView;
    Uri[] uri = new Uri[5];
    int[] rawResources = {R.raw.subway, R.raw.street, R.raw.subway, R.raw.street, R.raw.subway};

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

        LinearLayout videoListLayout = (LinearLayout)findViewById(R.id.videolist_area);
        videoViewLayout = (LinearLayout)findViewById(R.id.videoview_area);

        for(int i = 0; i < tv.length; i++){
            tv[i] = new TextView(this);
            tv[i].setId(i);
            tv[i].append(title[i]);
            tv[i].setTextSize(25);
            tv[i].setTextColor(Color.YELLOW);
            tv[i].setOnClickListener(this);
            videoListLayout.addView(tv[i]);

            uri[i] = Uri.parse("android.resource://com.example.videoapp/"+rawResources[i]);
            videoView = new VideoView(this);
            videoViewLayout.addView(videoView);

            videoView.setMediaController(new MediaController(this));
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
    public void onClick(View v){
        int tvId = v.getId();

        for(int i = 0; i < tv.length; i++){
            if(i == tvId){
                tv[i].setTextColor(Color.BLUE);
                tv[i].setBackgroundColor(Color.YELLOW);
            }
            else{
                tv[i].setTextColor(Color.YELLOW);
                tv[i].setBackgroundColor(Color.BLUE);
            }
        }

        videoView.setVideoURI(uri[tvId]);
        videoView.start();
    }
}
