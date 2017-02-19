<?php

namespace common\models;

use Yii;

/**
 * This is the model class for table "obrazenia".
 *
 * @property integer $id
 * @property string $Obrazenia
 *
 * @property Bron[] $brons
 */
class Obrazenia extends \yii\db\ActiveRecord
{
    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'obrazenia';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['Obrazenia'], 'required'],
            [['Obrazenia'], 'string', 'max' => 255]
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => Yii::t('app', 'ID'),
            'Obrazenia' => Yii::t('app', 'Obrazenia'),
        ];
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getBrons()
    {
        return $this->hasMany(Bron::className(), ['obrazenia_id' => 'id']);
    }
}
