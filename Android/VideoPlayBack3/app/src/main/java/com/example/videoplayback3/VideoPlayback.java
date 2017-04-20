package com.example.videoplayback3;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.MediaController;
import android.widget.VideoView;

/**
 * Created by 전성우 on 2016-01-15.
 */
public class VideoPlayback extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.video_playback);
        // 타이틀 설정
        setTitle("비디오 재생");
        // 인텐트 받아옴
        Intent it = getIntent();
        // 인텐드에서 넣어온 비디오 아이디 값을 가져옴
        int id_video = it.getIntExtra("it_id_video", 0); // 0은 디폴트 값
        // 가져온 아이디 값으로 uri를 만듬
        Uri uri = Uri.parse("android.resource://com.example.videoplayback3/"+id_video);
        // 비디오 뷰를 불러온 후
        VideoView videoView = (VideoView)findViewById(R.id.videoview);
        // 비디오 뷰에 만든 uri를 넘김
        videoView.setVideoURI(uri);
        // 시작!
        videoView.start();
        // 비디오 컨트롤러도 만듬
        videoView.setMediaController(new MediaController(this));
    }

    public void closeVideo(View v){
        finish();
    }
}
