<?php

namespace common\models;

use Yii;

/**
 * This is the model class for table "postac".
 *
 * @property integer $id
 * @property integer $rasa_id
 * @property string $Imie
 * @property integer $Wiek
 * @property string $Wzrost
 * @property string $Waga
 * @property string $Zloto
 * @property integer $bron_id
 * @property integer $pancerz_id
 * @property string $Data_utworzenia
 *
 * @property Bron $bron
 * @property Pancerz $pancerz
 * @property Rasa $rasa
 */
class Postac extends \yii\db\ActiveRecord
{
    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'postac';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['rasa_id', 'Imie', 'Wiek', 'Wzrost', 'Waga', 'bron_id', 'pancerz_id', 'Data_utworzenia'], 'required'],
            [['rasa_id', 'bron_id', 'pancerz_id'], 'integer'],
            [['Wzrost', 'Waga','Zloto'], 'number', 'min' => 0],
            [['Wiek'], 'integer', 'min' => 0],
            [['Data_utworzenia'], 'safe'],
            [['Data_utworzenia'], 'date', 'format' => 'yyyy-MM-dd'],
            [['Data_utworzenia'],'compare', 'operator' => '<=', 'compareValue' => date('Y-m-d')],
            [['Imie'], 'string', 'max' => 45]
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => Yii::t('app', 'ID'),
            'rasa_id' => Yii::t('app', 'Rasa ID'),
            'Imie' => Yii::t('app', 'Imie'),
            'Wiek' => Yii::t('app', 'Wiek'),
            'Wzrost' => Yii::t('app', 'Wzrost'),
            'Waga' => Yii::t('app', 'Waga'),
            'Zloto' => Yii::t('app', 'Zloto'),
            'bron_id' => Yii::t('app', 'Bron ID'),
            'pancerz_id' => Yii::t('app', 'Pancerz ID'),
            'Data_utworzenia' => Yii::t('app', 'Data Utworzenia'),
        ];
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getBron()
    {
        return $this->hasOne(Bron::className(), ['id' => 'bron_id']);
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getPancerz()
    {
        return $this->hasOne(Pancerz::className(), ['id' => 'pancerz_id']);
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getRasa()
    {
        return $this->hasOne(Rasa::className(), ['id' => 'rasa_id']);
    }
}
