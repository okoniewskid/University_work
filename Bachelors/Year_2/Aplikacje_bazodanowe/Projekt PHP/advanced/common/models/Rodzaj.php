<?php

namespace common\models;

use Yii;

/**
 * This is the model class for table "rodzaj".
 *
 * @property integer $id
 * @property string $Rodzaj
 *
 * @property Bron[] $brons
 * @property Pancerz[] $pancerzs
 */
class Rodzaj extends \yii\db\ActiveRecord
{
    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'rodzaj';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['Rodzaj'], 'required'],
            [['Rodzaj'], 'string', 'max' => 255]
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => Yii::t('app', 'ID'),
            'Rodzaj' => Yii::t('app', 'Rodzaj'),
        ];
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getBrons()
    {
        return $this->hasMany(Bron::className(), ['rodzaj_id' => 'id']);
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getPancerzs()
    {
        return $this->hasMany(Pancerz::className(), ['rodzaj_id' => 'id']);
    }
}
