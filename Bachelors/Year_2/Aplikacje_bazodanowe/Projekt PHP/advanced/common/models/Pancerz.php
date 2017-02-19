<?php

namespace common\models;

use Yii;

/**
 * This is the model class for table "pancerz".
 *
 * @property integer $id
 * @property string $Nazwa
 * @property integer $rodzaj_id
 * @property integer $Obrona
 *
 * @property Rodzaj $rodzaj
 * @property Postac[] $postacs
 */
class Pancerz extends \yii\db\ActiveRecord
{
    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'pancerz';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['Nazwa', 'rodzaj_id', 'Obrona'], 'required'],
            [['rodzaj_id', 'Obrona'], 'integer', 'min' => 0],
            [['Nazwa'], 'string', 'max' => 20]
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => 'ID',
            'Nazwa' => 'Nazwa',
            'rodzaj_id' => 'Rodzaj ID',
            'Obrona' => 'Obrona',
        ];
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getRodzaj()
    {
        return $this->hasOne(Rodzaj::className(), ['id' => 'rodzaj_id']);
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getPostacs()
    {
        return $this->hasMany(Postac::className(), ['pancerz_id' => 'id']);
    }
}
