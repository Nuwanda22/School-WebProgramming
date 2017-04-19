package com.example.webapp;

import android.os.AsyncTask;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.TextView;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class MainActivity extends AppCompatActivity {

    TextView textView;

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

        /*WebView webView = (WebView)findViewById(R.id.webview);
        webView.setWebViewClient(new WebViewClient());
        WebSettings webSettings = webView.getSettings();
        webSettings.setJavaScriptEnabled(true);
        webSettings.setBuiltInZoomControls(true);
        webView.loadUrl("http://www.android.com");*/

        textView = (TextView)findViewById(R.id.websource);

        String url = "http://www.android.com";
        new DownloadWebpageTask().execute(url);
    }

    private class DownloadWebpageTask extends AsyncTask<String, Void, String>{
        @Override
        protected String doInBackground(String... urls){
            try {
                return (String)downloadUrl((String)urls[0]);
            }
            catch (IOException e){
                return "다운로드 실패";
            }
        }
        @Override
        protected void onPostExecute(String result){
            String word = "";
            int start;
            int end;

            String tagStart = "<title>";
            String tagEnd = "</title>";

            start = result.indexOf(tagStart);
            end = result.indexOf(tagEnd);

            if(start != -1 && end != -1){
                word = result.substring(start + tagStart.length(), end);
                textView.append("제목 : "+ word);
            }
            else{
                textView.append("파싱 실패");
            }
        }
        private String downloadUrl(String myurl) throws IOException{
            HttpURLConnection conn = null;

            try {
                URL url = new URL(myurl);
                conn = (HttpURLConnection)url.openConnection();
                BufferedInputStream bufferedInputStream = new BufferedInputStream(conn.getInputStream());
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(bufferedInputStream, "utf-8"));
                String line = null;
                String page = "";
                while ((line = bufferedReader.readLine()) != null){
                    page += line;
                }
                return page;
            }
            finally {
                conn.disconnect();
            }
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
}
