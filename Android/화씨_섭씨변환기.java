package com.example.for_exer_1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Switch;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    TextView textView;
    EditText editText;
    Button button;
    Switch sw;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = findViewById(R.id.textView);
        editText = findViewById(R.id.editTextNumberSigned);
        button = findViewById(R.id.button);
        sw = findViewById(R.id.swtich);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //문자열 입력
                if(sw.isChecked()){
                    String strF = editText.getText().toString();
                    if(strF.equals(""))
                        return;
                    //처리 : F -> C
                    double f = Double.parseDouble(strF); //실수형으로 변환
                    double c = (f - 32) * 0.55;
                    // text view에 출력
                    textView.setText("F->C "+c);
                }
                else{
                    String strC = editText.getText().toString();
                    if(strC.equals(""))
                        return;
                    //처리 : C ->F
                    double c = Double.parseDouble(strC); //실수형으로 변환
                    double f = 9/5.0 * c +32;
                    // text view에 출력
                    textView.setText("C->F "+f);
                }

            }
        });
    }
}
