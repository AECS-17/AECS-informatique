package aecs.source.aecsandroidapp;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.view.View;

public class AECSAndroidApp extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView text = (TextView)findViewById(R.id.my_text);
        text.setText("Bienvenue à l'AECS !");
    }

    public void onButtonClicked(View view) {
        TextView text = (TextView)findViewById(R.id.my_text);
        text.setText("Bouton cliqué !");
    }
}
