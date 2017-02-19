<?php

namespace common\models;

use Yii;

/**
 * This is the model class for table "bron".
 *
 * @property integer $id
 * @property string $Nazwa
 * @property integer $rodzaj_id
 * @property integer $obrazenia_id
 *
 * @property Rodzaj $rodzaj
 * @property Obrazenia $obrazenia
 * @property Postac[] $postacs
 */
class Bron extends \yii\db\ActiveRecord
{
    /**
     * @inheritdoc
     */
    public static function tableName()
    {
        return 'bron';
    }

    /**
     * @inheritdoc
     */
    public function rules()
    {
        return [
            [['Nazwa', 'rodzaj_id', 'obrazenia_id'], 'required'],
            [['rodzaj_id', 'obrazenia_id'], 'integer'],
            [['Nazwa'], 'string', 'max' => 255]
        ];
    }

    /**
     * @inheritdoc
     */
    public function attributeLabels()
    {
        return [
            'id' => Yii::t('app', 'ID'),
            'Nazwa' => Yii::t('app', 'Nazwa'),
            'rodzaj_id' => Yii::t('app', 'Rodzaj ID'),
            'obrazenia_id' => Yii::t('app', 'Obrazenia ID'),
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
    public function getObrazenia()
    {
        return $this->hasOne(Obrazenia::className(), ['id' => 'obrazenia_id']);
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getPostacs()
    {
        return $this->hasMany(Postac::className(), ['bron_id' => 'id']);
    }
}
