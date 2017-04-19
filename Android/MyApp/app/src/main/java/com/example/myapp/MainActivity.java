package com.example.myapp;

import android.app.AlertDialog;
import android.app.DatePickerDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.Spinner;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity implements Button.OnClickListener {
    String[] data = new String[5];

    // 성명
    private EditText name;
    // 성별
    private RadioButton male;
    private RadioButton female;
    // 수신 여부
    private CheckBox sms;
    private CheckBox email;
    // 관심분야
    private Spinner spinner;
    // 생일
    private EditText dataDisplay;
    private int year;
    private int mouth;
    private int day;
    static final int DATE_DIALOG_ID = 0;
    private DatePickerDialog.OnDateSetListener dateSetListener = new DatePickerDialog.OnDateSetListener() {
        @Override
        public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
            MainActivity.this.year = year;
            mouth = monthOfYear;
            day = dayOfMonth;
            updateDisplay();
        }
    };
    // 전송
    private Button button;

    public DialogInterface.OnClickListener onClickListener = new DialogInterface.OnClickListener() {
        @Override
        public void onClick(DialogInterface dialog, int which) {
            finish();
            makeNewActivity();
        }
    };

    private void makeNewActivity(){
        Intent it = new Intent(this, CustomerInfo.class);
        it.putExtra("string_array_data", data);
        startActivity(it);
    }

    @Override
    public void onClick(View view){
        data[0] = this.name.getText().toString();
        if(male.isChecked()) data[1] = male.getText().toString();
        else if(female.isChecked()) data[1] = female.getText().toString();
        else data[1] = "?";
        if(this.sms.isChecked() && this.email.isChecked()) data[2] = "SMS e-mail";
        else if(this.sms.isChecked()) data[2] = "SMS";
        else if(this.email.isChecked()) data[2] = "e-mail";
        else data[2] = "미수신";
        data[3] = spinner.getSelectedItem().toString();
        data[4] = dataDisplay.getText().toString();

        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        if(data[0].compareTo("") == 0 || data[1].compareTo("?") == 0) {
            builder.setTitle("경고");
            builder.setMessage("다시해주세요!");
            builder.setIcon(R.mipmap.ic_launcher);
            builder.setPositiveButton("확인", null);
        }
        else {
            builder.setTitle("전송");
            builder.setMessage("하시겠습니까?");
            builder.setIcon(R.mipmap.ic_launcher);
            builder.setPositiveButton("확인", onClickListener);
            builder.setNegativeButton("취소", null);
        }
        builder.show();
    }

    @Override
    protected Dialog onCreateDialog(int id){
        switch (id){
            case DATE_DIALOG_ID:
                return new DatePickerDialog(this, dateSetListener, year, mouth, day);
        }
        return null;
    }

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
        // 성명
        name = (EditText)findViewById(R.id.edit_name);
        // 성별
        male = (RadioButton)findViewById(R.id.radio_male);
        female = (RadioButton)findViewById(R.id.radio_female);
        // 수신여부
        sms = (CheckBox)findViewById(R.id.checkbox_sms);
        email = (CheckBox)findViewById(R.id.checkbox_email);
        // 관심 분야
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this, R.array.interest_array, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner = (Spinner)findViewById(R.id.spinner_interest);
        spinner.setAdapter(adapter);
        // 생일
        dataDisplay = (EditText)findViewById(R.id.edit_birthday);
        dataDisplay.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                showDialog(DATE_DIALOG_ID);
            }
        });
        final Calendar calendar = Calendar.getInstance();
        year = calendar.get(Calendar.YEAR);
        mouth = calendar.get(Calendar.MONTH);
        day = calendar.get(Calendar.DAY_OF_MONTH);
        updateDisplay();
        // 전송
        button = (Button)findViewById(R.id.button_send);
        button.setOnClickListener(this);
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

    private void updateDisplay(){
        //dataDisplay.setText(year+"-"+(mouth+1)+"-"+day+" ");
        dataDisplay.setText(new StringBuilder().append(year).append("-").append(mouth + 1).append("-").append(day).append(" "));
    }
}
