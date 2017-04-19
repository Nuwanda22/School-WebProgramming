package com.example.gridviewapp;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;

/**
 * Created by 전성우 on 2016-01-19.
 */
public class ImageAdapter extends BaseAdapter {
    private Context mContext;
    private Integer[] mThumdIds = {
            R.drawable.sample_0,
            R.drawable.sample_1,
            R.drawable.sample_2,
            R.drawable.sample_3,
            R.drawable.sample_4,
            R.drawable.sample_5,
            R.drawable.sample_6,
            R.drawable.sample_7,
            R.drawable.brooklyn_0,
            R.drawable.brooklyn_1,
            R.drawable.brooklyn_2,
            R.drawable.brooklyn_3,
            R.drawable.brooklyn_4,
            R.drawable.brooklyn_5,
            R.drawable.brooklyn_6,
            R.drawable.brooklyn_7
    };

    public ImageAdapter(Context c){
        mContext = c;
    }

    @Override
    public int getCount() {
        return mThumdIds.length;
    }

    @Override
    public Object getItem(int position){
        return null;
    }

    @Override
    public long getItemId(int position){
        return 0;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent){
        ImageView imageView;

        if(convertView == null){
            imageView = new ImageView(mContext);
            imageView.setLayoutParams(new GridView.LayoutParams(300, 300));
            imageView.setScaleType(ImageView.ScaleType.CENTER_CROP);
            imageView.setPadding(8,8,8,8);
        }
        else {
            imageView = (ImageView)convertView;
        }

        imageView.setImageResource(mThumdIds[position]);
        return imageView;
    }
}
