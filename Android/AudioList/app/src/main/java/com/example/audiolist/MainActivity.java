package com.example.audiolist;

import android.content.res.AssetFileDescriptor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.media.MediaMetadataRetriever;
import android.media.MediaPlayer;
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
import android.widget.MediaController;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    MediaPlayer[] mp = new MediaPlayer[3];
    byte[] album = new byte[1];
    LinearLayout prevLayout;
    int curIndex;
    int prevIndex = -1;

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

        // 메타데이터 추출기 생성
        MediaMetadataRetriever[] mmr = new MediaMetadataRetriever[3];
        for(int i = 0; i < mmr.length; i++)
            mmr[i] = new MediaMetadataRetriever();

        AssetFileDescriptor[] afd =  new AssetFileDescriptor[3];
        for(int i = 0; i <afd.length; i++)
            afd[i] = getResources().openRawResourceFd(getSongResource(i));

        for(int i = 0; i < mmr.length; i++)
            mmr[i].setDataSource(afd[i].getFileDescriptor(), afd[i].getStartOffset(), afd[i].getLength());

        // 제목, 가수, 시간을 담을 공간 선언
        String[] title = new String[3];
        String[] artist = new String[3];
        String[] time = new String[3];

        // 제목 추출
        for(int i = 0; i < mmr.length; i++)
            title[i] = mmr[i].extractMetadata(MediaMetadataRetriever.METADATA_KEY_TITLE);
        // 가수 추출
        for(int i = 0; i < mmr.length; i++)
            artist[i] = mmr[i].extractMetadata(MediaMetadataRetriever.METADATA_KEY_ARTIST);
        // 시간 추출
        for(int i = 0; i < mmr.length; i++) {
            String milliSec = mmr[i].extractMetadata(MediaMetadataRetriever.METADATA_KEY_DURATION);
            time[i] = toString(Integer.parseInt(milliSec));
        }

        // 추출된 데이터를 화면에 출력
        for(int i = 0; i < 9; i++) {
            if(0 <= i && i <= 2) {
                ((TextView) findViewById(getTextViewId(i,0))).setText(title[i]);
            }
            else if(3 <= i && i <=5){
                ((TextView) findViewById(getTextViewId(i-3,1))).setText(artist[i-3]);
            }
            else{
                ((TextView) findViewById(getTextViewId(i-6,2))).setText(time[i-6]);
            }
        }
    }

    private int getTextViewId(int index, int mode){
        if(mode == 0){
            if(index == 0){
                return R.id.title1;
            }
            else if(index == 1){
                return R.id.title2;
            }
            else if(index == 2) {
                return R.id.title3;
            }
            else
                return 0;
        }
        else if(mode == 1){
            if(index == 0){
                return R.id.artist1;
            }
            else if(index == 1){
                return R.id.artist2;
            }
            else if(index == 2) {
                return R.id.artist3;
            }
            else
                return 0;
        }
        else if(mode == 2){
            if(index == 0){
                return R.id.time1;
            }
            else if(index == 1){
                return R.id.time2;
            }
            else if(index == 2) {
                return R.id.time3;
            }
            else
                return 0;
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

    private int indexOf(int id){
        if(getResources().getIdentifier("new_thang", "raw", getPackageName()) == id){
            return 0;
        }
        else if(getResources().getIdentifier("bangarang", "raw", getPackageName()) == id){
            return 1;
        }
        else if(getResources().getIdentifier("gdfr", "raw", getPackageName()) == id){
            return 2;
        }
        else
            return -1;
    }

    private void musicStart(MediaPlayer mp, LinearLayout layout, int color){
        mp.start();
        layout.setBackgroundColor(color);
    }

    private void musicPause(MediaPlayer mp, LinearLayout layout, int color){
        mp.pause();
        layout.setBackgroundColor(color);
    }

    public void play(View v){
        // 레이아웃 추출
        LinearLayout layout = (LinearLayout)findViewById(v.getId());
        // 재생할 노래 추출
        String tag = (String)layout.getTag();
        int id_audio = getResources().getIdentifier(tag, "raw", getPackageName());
        // 기본 색 추출
        int defaultColor = layout.getDrawingCacheBackgroundColor();
        // 노래 id를 통해 mp를 구함
        curIndex = indexOf(id_audio);
        // mp가 첫 실행이면
        if(mp[curIndex] == null){
            // 할당 후 노래 생성 및 설정
            mp[curIndex] = new MediaPlayer();
            mp[curIndex] = MediaPlayer.create(this, id_audio);
            mp[curIndex].setLooping(false);
            // 이전에 실행되고 있다면 멈춤
            if(prevIndex != -1){
                if(mp[prevIndex].isPlaying()){
                    musicPause(mp[prevIndex],prevLayout, defaultColor);
                }
            }
            // 노래 시작
            musicStart(mp[curIndex], layout, Color.YELLOW);
            // 현재는 이전이 됨
            prevIndex = curIndex;
            prevLayout = layout;
            /*// 노래가 시작된 후, 노래 시간이 출력됨
            TextView txt = (TextView)findViewById(timeOf(curIndex));
            txt.setText(toString(mp[curIndex].getDuration()));*/
        } // 클릭한 노래가 재생 중이면 멈춤
        else if(mp[curIndex].isPlaying()){
            musicPause(mp[curIndex], layout, defaultColor);
        }
        else {  // 아니라면 재생
            // 이전에 실행되고 있다면 멈추고
            if(mp[prevIndex].isPlaying()){
                musicPause(mp[prevIndex],prevLayout, defaultColor);
            }
            // 재생
            musicStart(mp[curIndex], layout, Color.YELLOW);
            prevIndex = curIndex;
            prevLayout = layout;
        }
    }

    public void tos(View v){
        TextView textView = (TextView)findViewById(v.getId());
        String tag = (String)textView.getTag();
        int id_audio = getResources().getIdentifier(tag, "raw", getPackageName());
        Toast.makeText(this,"현재 시간 : " + toString(mp[indexOf(id_audio)].getCurrentPosition()),Toast.LENGTH_SHORT).show();
    }

    private String toString(int milliSec){
        int time = milliSec / 1000;
        int min = time / 60;
        int sec = time % 60;

        if(min == 0)
            return sec + "초";
        else
            return min + "분 " + sec + "초";
    }

    private int getSongResource(int index){
        if(index == 0){
            return R.raw.new_thang;
        }
        else if(index == 1){
            return R.raw.bangarang;
        }
        else if(index == 2){
            return  R.raw.gdfr;
        }
        else
            return 0;
    }

    public void test(View v){
        MediaMetadataRetriever mmr =  new MediaMetadataRetriever();
        AssetFileDescriptor afd = getResources().openRawResourceFd(R.raw.new_thang);
        mmr.setDataSource(afd.getFileDescriptor(), afd.getStartOffset(), afd.getLength());

        byte[] data = mmr.getEmbeddedPicture();
        ImageView albumArt = (ImageView)findViewById(R.id.album_art);
        Bitmap bitmap = BitmapFactory.decodeByteArray(data, 0, data.length);
        albumArt.setImageBitmap(bitmap);

        int length = ((LinearLayout)findViewById(R.id.mainLayout)).getWidth() * 3 / 4;
        setSquare(albumArt, length);
        /*albumArt.setAdjustViewBounds(true);
        albumArt.setLayoutParams(new LinearLayout.LayoutParams(500, 500));*/
    }

    private void setSquare(ImageView imageView, int length){
        imageView.setMaxHeight(length);
        imageView.setMinimumHeight(length);
        imageView.setMaxWidth(length);
        imageView.setMinimumWidth(length);
    }

    @Override
    protected void onDestroy(){
        for(int i = 0; i < mp.length; i++) {
            if(mp[i] == null)
                continue;
            else {
                mp[i].stop();
                mp[i].release();
            }
        }
        super.onDestroy();
    }
}
