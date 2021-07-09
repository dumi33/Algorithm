package com.example.exhelloworld;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    TextView textview;
    EditText editText;
    Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textview = findViewById(R.id.textView);
        editText = findViewById(R.id.editTextNumberSigned);
        button = findViewById(R.id.button);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //문자열을 입력
                String strC = editText.getText().toString();
                if(strC.equals(""))
                    return;
                //처리 : c -> F
                double c = Double.parseDouble(strC); //실수로 변환
                double f = 9/5.0 * c + 32;
                //textview 출력

                textview.setText(""+f);
            }
        });
    }

}
